/*
Given an array arr[] and an integer K where K is smaller than size of array, the task is to find the Kth smallest element in the given array. It is given that all array elements are distinct.

Note :-  l and r denotes the starting and ending index of the array.

Example 1:

Input:
N = 6
arr[] = 7 10 4 3 20 15
K = 3
L=0 R=5

Output : 7
Explanation :
3rd smallest element in the given 
array is 7.
Example 2:

Input:
N = 5
arr[] = 7 10 4 20 15
K = 4 L=0 R=4
Output : 15
Explanation :
4th smallest element in the given 
array is 15.
Your Task:
You don't have to read input or print anything. Your task is to complete the function kthSmallest() which takes the array arr[], integers l and r denoting the starting and ending index of the array and an integer K as input and returns the Kth smallest element.
 
 
Expected Time Complexity: O(n*log(n) )
Expected Auxiliary Space: O(log(n))
Constraints:
1 <= N <= 105
 L==0
 R==N-1
1<= arr[i] <= 105
1 <= K <= N
*/
// **************************************************************** Solution ********************************************************
// this is simplest solution with time complexity : O(nlogn)
// int kthSmallest(int arr[], int l, int r, int k) {
//         sort(arr,arr+r+1);
//         return arr[k-1];
//     }


// but for Time Complexity: O(nlogk) we will use HEAP

// simple funda for heap:
// for finding maximum use Min Heap
// for finding minimum use Max Heap


// max heap keaps the largest number at top of stack
// maintain size of heap equal to k
// if size exceeds k, pop the top element

int kthSmallest(int arr[], int l, int r, int k) {
        
        priority_queue<int> maxh;
        
        for(int i=0; i<=r; i++){
            maxh.push(arr[i]);
            
            if(maxh.size()>k){
                maxh.pop();
            }
        }
        
        return maxh.top();
    }
