/*
Given an array of size N containing only 0s, 1s, and 2s; sort the array in ascending order.


Example 1:

Input: 
N = 5
arr[]= {0 2 1 2 0}
Output:
0 0 1 2 2
Explanation:
0s 1s and 2s are segregated 
into ascending order.
Example 2:

Input: 
N = 3
arr[] = {0 1 0}
Output:
0 0 1
Explanation:
0s 1s and 2s are segregated 
into ascending order.

Your Task:
You don't need to read input or print anything. Your task is to complete the function sort012() that takes an array arr and N as input parameters and sorts the array in-place.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)


Constraints:
1 <= N <= 10^6
0 <= A[i] <= 2
*/

void sort012(int a[], int n)
    {
        // code here 
        int c0=0, c1=0, c2=0;
        for(int i=0; i<n ; i++){
            if(a[i] == 0) c0+=1;
            else if(a[i] == 1) c1+=1;
            else if(a[i] == 2) c2+=1;
        }
        
        int ptr=0;
        
        for(int i=c0; i>0; i--){
            a[ptr] = 0;
            ptr++;
        }
        
        for(int i=c1; i>0; i--){
            a[ptr] = 1;
            ptr++;
        }
        
        for(int i=c2; i>0; i--){
            a[ptr] = 2;
            ptr++;
        }
    }


/* there is one more interesting solution
keep track of low, mid, high
  low=0, mid=0, high=n-1;
now run loop till mid<high and swap arr[mid] according to condition

 while (mid <= high) {
        switch (a[mid]) {
 
        // If the element is 0
        case 0:
            swap(a[low++], a[mid++]);
            break;
 
        // If the element is 1 .
        case 1:
            mid++;
            break;
 
        // If the element is 2
        case 2:
            swap(a[mid], a[high--]);
            break;
        }
    }
}
*/
