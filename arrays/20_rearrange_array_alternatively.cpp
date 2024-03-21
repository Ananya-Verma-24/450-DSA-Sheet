/*
Given a sorted array of positive integers. Your task is to rearrange the array elements alternatively i.e first element should be max value, second should be min value, third should be second max, fourth should be second min and so on.
Note: Modify the original array itself. Do it without using any extra space. You do not have to return anything.

Example 1:

Input:
n = 6
arr[] = {1,2,3,4,5,6}
Output: 6 1 5 2 4 3
Explanation: Max element = 6, min = 1, 
second max = 5, second min = 2, and 
so on... Modified array is : 6 1 5 2 4 3.
Example 2:

Input:
n = 11
arr[]={10,20,30,40,50,60,70,80,90,100,110}
Output:110 10 100 20 90 30 80 40 70 50 60
Explanation: Max element = 110, min = 10, 
second max = 100, second min = 20, and 
so on... Modified array is : 
110 10 100 20 90 30 80 40 70 50 60.
Your Task:
The task is to complete the function rearrange() which rearranges elements as explained above. Printing of the modified array will be handled by driver code.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= n <= 10^6
1 <= arr[i] <= 10^7
*/

//bakwaas yet innovative solution
//instead of replacing or swapping just keep both values at same index by multiplying with 10 (or the largest constraint)
// arr[i] = (newValue % 10)*10 + arr[oldvalue]
// once done divinde whole array by 10 (or largest constraint)

void rearrange(long long *arr, int n) 
    { 
    	int left = 0;
    	int right = n-1;
    	
    	
    	int max = 10000001; // max contraint for arr[i] ie 10^7
    	
    	for(int i=0; i<n ; i++){
    	    if(i%2 == 0){
    	        arr[i] = (arr[right]%max)*max + arr[i];
    	        right--;
    	    }else{
    	        arr[i] = (arr[left]%max)*max + arr[i];
    	        left++;
    	    }
    	}
    	
    	for(int i=0 ; i<n ; i++){
    	    arr[i] = arr[i]/max;
    	}
    }
