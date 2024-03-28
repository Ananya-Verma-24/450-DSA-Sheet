/*
Given an integer N, find its factorial. return a list of integers denoting the digits that make up the factorial of N.

Example 1:

Input: N = 5
Output: 120
Explanation : 5! = 1*2*3*4*5 = 120
Example 2:

Input: N = 10
Output: 3628800
Explanation :
10! = 1*2*3*4*5*6*7*8*9*10 = 3628800

Your Task:
You don't need to read input or print anything. Complete the function factorial() that takes integer N as input parameter and returns a list of integers denoting the digits that make up the factorial of N.


Expected Time Complexity : O(N2)
Expected Auxilliary Space : O(1)


Constraints:
1 ≤ N ≤ 1000
*/

// take a temporary vector in which multiples of every iteration is stored (in reverse order)
// at every iteration, multiply i with arr[j] and then store carry in next block also update the value of carry
// reverse the array in arr and store in ans vector

vector<int> factorial(int N){
        // code here
        vector<int>  arr(10000,0);
        vector<int> ans;
        
        int size = 1;
        arr[0] = 1;
        
        
        for(int i=2; i<=N; i++){
            int carry = 0;
            
            for(int j=0; j<size; j++){
                int res = i * arr[j];
                
                res = res + carry;
                
                arr[j] = res %10;
                carry = res/10;
                
            }
            
            while(carry > 0){
                arr[size] = carry % 10;
                size++;
                carry = carry / 10;
            }
        }
        
        
        for(int i=size-1; i>=0; i--){
            ans.push_back(arr[i]);
        }
        
        return ans;
    }
