Q. Subset Sum Equal To K
You are given an array/list ‘ARR’ of ‘N’ positive integers and an integer ‘K’. Your task is to check if there exists a subset in ‘ARR’ with a sum equal to ‘K’.
Note: Return true if there exists a subset with sum equal to ‘K’. Otherwise, return false.
For Example :
If ‘ARR’ is {1,2,3,4} and ‘K’ = 4, then there exists 2 subsets with sum = 4. These are {1,3} and {4}. Hence, return true.
Sample Input 1:
2
4 5
4 3 2 1
5 4
2 5 1 6 7
Sample Output 1:
true
false

code-->#include <bits/stdc++.h>
// bool solve(int i , int k ,vector<int> &arr ,vector<vector<int>>&dp) {
//     if(k==0){
//         return true;
//     }
//     if(i==0){
//         return (arr[0]==k);
//     }
//     if(dp[i][k]!=-1){
//         return dp[i][k];
//     }
    
//     bool notpick= solve(i-1 , k , arr , dp);
//     bool pick=false;
//     if(arr[i]<=k){
//         pick=solve(i-1 , k-arr[i] , arr , dp);
//     }
    
    
//     return dp[i][k]=pick | notpick;
// }
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    // vector<vector<int>>dp(n , vector<int>(k+1 , -1));
    // return solve(n-1 , k , arr , dp);
    // vector<vector<bool>>dp(n , vector<bool>(k+1 , 0));
    // // int dp[n][k];
    // for(int i=0;i<n;i++){
    //     dp[i][0]=true;
    // }
    // dp[0][arr[0]]=true;
    // for(int i=1;i<n;i++){
    //     for(int target=1;target<=k;target++){
    //         bool notpick= dp[i-1][target];
    //         bool pick=false;
    //         if(arr[i]<=target){
    //             pick=dp[i-1][target-arr[i]];
    //         }
    //         dp[i][target]=pick|notpick;
    //     }
    // }
    // return dp[n-1][k];
    vector<bool>prev(k+1 ,0);
    vector<bool>curr(k+2 ,0);
    prev[0]= curr[0]= true;
    prev[arr[0]]= true;

    for(int i=1;i<n;i++){
        for(int target=1;target<=k;target++){
            bool nottake= prev[target];
            bool take=false;
            if(arr[i]<=target){
                take= prev[target-arr[i]];
            }
            curr[target]= take|nottake;
        }
        prev= curr;
    }
    return prev[k];

}





Approach	            Time Complexity	Space Complexity
Recursion with Memoization	O(n * k)	O(n * k +n)
Tabulation (Bottom-Up)	O(n * k)	O(n * k)
Space Optimized Tabulation	O(n * k)	O(k)
