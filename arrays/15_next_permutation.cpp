/*
Implement the next permutation, which rearranges the list of numbers into Lexicographically next greater permutation of list of numbers. If such arrangement is not possible, it must be rearranged to the lowest possible order i.e. sorted in an ascending order. You are given an list of numbers arr[ ] of size N.

Example 1:

Input: N = 6
arr = {1, 2, 3, 6, 5, 4}
Output: {1, 2, 4, 3, 5, 6}
Explaination: The next permutation of the 
given array is {1, 2, 4, 3, 5, 6}.
Example 2:

Input: N = 3
arr = {3, 2, 1}
Output: {1, 2, 3}
Explaination: As arr[] is the last 
permutation. So, the next permutation 
is the lowest one.
Your Task:
You do not need to read input or print anything. Your task is to complete the function nextPermutation() which takes N and arr[ ] as input parameters and returns a list of numbers containing the next permutation.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ N ≤ 10000
*/

// there is an STL in c++ for finding next permuation
//    next_permutation(arr.begin(),arr.end());
//    return arr;

// we can implement this function on our own, its very simple
// start iterating from back and find the index where arr[i]<arr[i+1]
// then find the next number for that index by start iterating from back and find the index where arr[ind]<arr[i] for the first time 
// swap those places
// at the end sort from ind+1 to end


vector<int> nextPermutation(int n, vector<int> arr){
      
        int ind = -1;
        
        for(int i=n-2; i>=0; i--){
            if(arr[i]<arr[i+1]){
                ind = i;
                break;
            }
        }
        
        if(ind == -1){
            sort(arr.begin(), arr.end());
            return arr;
        }
        
        
        for(int i=n-1; i>ind; i--){
            if(arr[i]>arr[ind]){
                swap(arr[i],arr[ind]);
                break;
            }
        }
        
        sort(arr.begin()+ind+1, arr.end());
        
        return arr;
    }
