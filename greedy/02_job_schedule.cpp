/*
Given a set of N jobs where each jobi has a deadline and profit associated with it.

Each job takes 1 unit of time to complete and only one job can be scheduled at a time. We earn the profit associated with job if and only if the job is completed by its deadline.

Find the number of jobs done and the maximum profit.

Note: Jobs will be given in the form (Jobid, Deadline, Profit) associated with that Job. Deadline of the job is the time before which job needs to be completed to earn the profit.


Example 1:

Input:
N = 4
Jobs = {(1,4,20),(2,1,10),(3,1,40),(4,1,30)}
Output:
2 60
Explanation:
Job1 and Job3 can be done with
maximum profit of 60 (20+40).
Example 2:

Input:
N = 5
Jobs = {(1,2,100),(2,1,19),(3,2,27),
        (4,1,25),(5,1,15)}
Output:
2 127
Explanation:
2 jobs can be done with
maximum profit of 127 (100+27).

Your Task :
You don't need to read input or print anything. Your task is to complete the function JobScheduling() which takes an integer N and an array of Jobs(Job id, Deadline, Profit) as input and returns the count of jobs and maximum profit as a list or vector of 2 elements.


Expected Time Complexity: O(NlogN)
Expected Auxilliary Space: O(N)


Constraints:
1 <= N <= 105
1 <= Deadline <= N
1 <= Profit <= 500
*/

// first sort wrt profit in descending order
// then make a schedule array of length of max deadline and fill with -1
// then for every job check if the slot is available then fill it , if not then check slot less than that
// thats why start 'j' with currdead and keep on decreasing

struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};


bool comp(Job a, Job b){
    return a.profit > b.profit;
}

vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        
        sort(arr,arr+n,comp);
        
       int maxideadline = INT_MIN;
       
       for(int i=0; i<n; i++){
           maxideadline = max(maxideadline, arr[i].dead);
       }
       
       // this will be my slot vector/array
       vector<int> schedule(maxideadline+1,-1);
       
       int cnt=0, pro = 0;
       
       for(int i=0;i<n; i++){
           int currprofit = arr[i].profit;
           int currdead = arr[i].dead;
           int currid = arr[i].id;
           
           for(int j=currdead; j>0 ; j--){
               if(schedule[j] == -1){
                   cnt++;
                   pro += currprofit;
                   schedule[j] = currid;
                   break;
               }
           }
       }
        
        vector<int> ans;
        ans.push_back(cnt);
        ans.push_back(pro);
        
        return ans;
    } 
