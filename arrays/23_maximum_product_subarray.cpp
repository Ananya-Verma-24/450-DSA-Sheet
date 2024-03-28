/*
Given an array Arr[] that contains N integers (may be positive, negative or zero). Find the product of the maximum product subarray.

Example 1:

Input:
N = 5
Arr[] = {6, -3, -10, 0, 2}
Output: 180
Explanation: Subarray with maximum product
is [6, -3, -10] which gives product as 180.
Example 2:

Input:
N = 6
Arr[] = {2, 3, 4, 5, -1, 0}
Output: 120
Explanation: Subarray with maximum product
is [2, 3, 4, 5] which gives product as 120.
Your Task:
You don't need to read input or print anything. Your task is to complete the function maxProduct() which takes the array of integers arr and n as parameters and returns an integer denoting the answer.
Note: Use 64-bit integer data type to avoid overflow.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ N ≤ 500
-102 ≤ Arri ≤ 102
*/

// approach is simple we have to maintain prefix and suffix product
// which ever is greater put it in Maxi
// take care of '0' , if gets zero then replace pref or suff with '1' ie again from the start.

long long maxProduct(vector<int> arr, int n) {
	    // code here
	    
	    long long pref = 1;
	    long long suff = 1;
	    long long maxi = INT_MIN;
	    
	    for(int i=0; i<n ; i++){
	        if(pref == 0) pref =1;
	        if(suff == 0) suff =1;
	        
	        pref = pref * arr[i];
	        suff = suff * arr[n-i-1];
	        
	        maxi = max(maxi, max(pref, suff));
	    }
	    
	    return maxi;
	}
