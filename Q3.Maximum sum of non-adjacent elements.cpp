Q. Maximum sum of non-adjacent elements
Problem statement
You are given an array/list of ‘N’ integers. You are supposed to return the maximum sum of the subsequence with the constraint that no two elements are adjacent in the given array/list.
A subsequence of an array/list is obtained by deleting some number of elements (can be zero) from the array/list, leaving the remaining elements in their original order.

code-->
#include <bits/stdc++.h> 
int call( int i , vector<int>&arr , vector<int>&dp){
    if(i==0 ){
        return arr[i];
    }
    if(i<0){
        return 0;
    }
    if(dp[i]!=-1){
        return dp[i];
    }
    int pick= arr[i]+call( i-2 , arr , dp);
    int nPick= 0+call(i-1 , arr,dp );
    return dp[i]=max(pick , nPick);
}
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n= nums.size();
    //  vector<int>dp(n+1 , -1);
    // dp[0]= nums[0];
    // int neg=0;
    // for(int i=1;i<n;i++){
    //    int take=nums[i];
    //    if(i>1){
    //         take+=dp[i-2];
    //     }
    //     int notTake= 0+dp[i-1];
    //     dp[i]= max(take , notTake);
    // }
    // return dp[n-1];

    int prev=nums[0];
    int prev2= 0;
    for(int i=1;i<n;i++){
        int take= nums[i];
        if(i>1){
            take+=prev2;
        }
        int nottake=0+prev;
        int curri= max(take , nottake);
        prev2= prev;
        prev= curri;
    }
    return prev;

}

time complexity Recursive with Memoization is:O(n)
the space complexity  Recursive with Memoization is:O(n)+O(n)=O(n)

time complexity tABULATION is:O(n)
the space complexity  TABULATION is:O(n)+O(n)=O(n)

the time complexity Space-Optimized Iterative is:O(n)
he space complexity Space-Optimized Iterative is:O(1)

