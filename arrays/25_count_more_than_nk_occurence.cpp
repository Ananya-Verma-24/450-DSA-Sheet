/*
Given an array arr of size N and an element k. The task is to find the count of elements in the array that appear more than n/k times.

Example 1:

Input:
N = 8
arr = [3,1,2,2,1,2,3,3]
k = 4
Output: 
2
Explanation: 
In the given array, 3 and 2 are the only elements that appears more than n/k times.
Example 2:

Input:
N = 4
arr = [2,3,3,2]
k = 3
Output: 
2
Explanation: In the given array, 3 and 2 are the only elements that appears more than n/k times. So the count of elements are 2.
Your Task:
The task is to complete the function countOccurence() which returns count of elements with more than n/k times appearance.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= N <= 105
1 <= a[i] <= 109
1 <= k <= N
*/

// store freq in map
// return freq with more than n/k

int countOccurence(int arr[], int n, int k) {
        // Your code here
        int check = n/k;
        map<int,int> mp;
        
        int count = 0;
        
        
        
        for(int i=0; i<n ; i++){
            mp[arr[i]]++;
        }
        
        for( auto it=mp.begin(); it != mp.end(); it++){
            if(it->second > check){
                count++;
            }
        }
        
        return count;
        
        
    }
