/*
Given a collection of Intervals, the task is to merge all of the overlapping Intervals.

Example 1:

Input:
Intervals = {{1,3},{2,4},{6,8},{9,10}}
Output: {{1, 4}, {6, 8}, {9, 10}}
Explanation: Given intervals: [1,3],[2,4]
[6,8],[9,10], we have only two overlapping
intervals here,[1,3] and [2,4]. Therefore
we will merge these two and return [1,4],
[6,8], [9,10].
Example 2:

Input:
Intervals = {{6,8},{1,9},{2,4},{4,7}}
Output: {{1, 9}}
Your Task:
Complete the function overlappedInterval() that takes the list N intervals as input parameters and returns sorted list of intervals after merging.

Expected Time Complexity: O(N*Log(N)).
Expected Auxiliary Space: O(Log(N)) or O(N).

Constraints:
1 ≤ N ≤ 100
0 ≤ x ≤ y ≤ 1000
*/

// solution is simple but have to remember the process
// first and foremost we will sort the interval array
// we have to maintain a start and end which is the start and end of any interval
// we will compare end of previous interval with start of next interval , if end>start then update end = max(end[prev] , end[next])
// else push_back in temp then in ans

 vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
         // Code here
        
    int n = intervals.size();
    sort(begin(intervals), end(intervals));
    vector<vector<int>> ans;
    int i = 1;
    int start = intervals[0][0], end = intervals[0][1];
    while(i<n){
        int new_start = intervals[i][0], new_end = intervals[i][1];
        if(new_start <= end){
            end = max(end, new_end);
        }else{
            vector<int> temp;
            temp.push_back(start);
            temp.push_back(end);
            ans.push_back(temp);
            start = new_start;
            end = new_end;
        }
        i++;
    }
    vector<int> temp;
    temp.push_back(start);
    temp.push_back(end);
    ans.push_back(temp);
    return ans;
         
    }
