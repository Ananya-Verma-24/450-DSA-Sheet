/*
Given an array of positive integers. Find the length of the longest sub-sequence such that elements in the subsequence are consecutive integers, the consecutive numbers can be in any order.
 

Example 1:

Input:
N = 7
a[] = {2,6,1,9,4,5,3}
Output:
6
Explanation:
The consecutive numbers here
are 1, 2, 3, 4, 5, 6. These 6 
numbers form the longest consecutive
subsquence.
Example 2:

Input:
N = 7
a[] = {1,9,3,10,4,20,2}
Output:
4
Explanation:
1, 2, 3, 4 is the longest
consecutive subsequence.

Your Task:
You don't need to read input or print anything. Your task is to complete the function findLongestConseqSubseq() which takes the array arr[] and the size of the array as inputs and returns the length of the longest subsequence of consecutive integers. 


Expected Time Complexity: O(R), where R is the maximum integer in the array.
Expected Auxiliary Space: O(N).


Constraints:
1 <= N <= 105
0 <= a[i] <= 105
*/
// cant beleive I did it on my own ....adsdfgsasdfghj
// first sort the array
// then maintain previous and check if upcoming element is 'prev + 1' ....increase the count (also maintain a maximum)
// if it is same as prev just continue
// else reset count = 1 and prev = arr[i]

int findLongestConseqSubseq(int arr[], int N)
    {
      //Your code here
      sort(arr,arr+N);
      
      int count = 1;
      int prev = arr[0];
      
      int maxi = 1;
      
      
      for(int i=1;i<N;i++){
          if(arr[i] == prev+1){
              count++;
              maxi = max(maxi,count);
              prev = arr[i];
          }
          else if(arr[i] == prev){
              continue;
          }else{
              count = 1;
              prev = arr[i];
          }
      }
      
      return maxi;
    }
