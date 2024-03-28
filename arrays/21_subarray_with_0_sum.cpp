/*
Given an array of integers. Find if there is a subarray (of size at-least one) with 0 sum. You just need to return true/false depending upon whether there is a subarray present with 0-sum or not. Printing will be taken care by the driver code.

Example 1:

Input:
n = 5
arr = {4,2,-3,1,6}
Output: 
Yes
Explanation: 
2, -3, 1 is the subarray with sum 0.
Example 2:

Input:
n = 5
arr = {4,2,0,1,6}
Output: 
Yes
Explanation: 
0 is one of the element in the array so there exist a subarray with sum 0.
Your Task:
You only need to complete the function subArrayExists() that takes array and n as parameters and returns true or false.

Expected Time Complexity: O(n).
Expected Auxiliary Space: O(n).

Constraints:
1 <= n <= 104
-105 <= a[i] <= 105
*/

// The concept here we will use is of "Prefix Sum"
// Taking Sum and start putting it in unordered_set
// if same prefix sum is already present in set , it means some sum of subarray in between becomes 0, thats why old prefix sum is coming
// so return true
//otherwise return false

 bool subArrayExists(int arr[], int n)
    {
        //Your code here
        unordered_set<int> sumSet;
 
        // Traverse through array
        // and store prefix sums
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
     
            // If prefix sum is 0 or
            // it is already present
            if (sum == 0 || sumSet.find(sum) != sumSet.end())
                return true;
     
            sumSet.insert(sum);
        }
        return false;
        }
