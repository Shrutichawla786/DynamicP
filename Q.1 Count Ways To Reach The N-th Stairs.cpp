Q. Count Ways To Reach The N-th Stairs
Problem statement
You have been given a number of stairs. Initially, you are at the 0th stair, and you need to reach the Nth stair.
Each time, you can climb either one step or two steps.
You are supposed to return the number of distinct ways you can climb from the 0th step to the Nth step.

Code-->
  #include <bits/stdc++.h> 
int mod = 1e9 + 7;
int solve( int n , vector<int>&dp){
    if(n==0 ||n==1){
        return 1;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    int one= solve(n-1,dp )%mod;
    int two=  solve(n-2,dp)%mod;
    return dp[n]=(one+two)%mod;
}
int countDistinctWays(int nStairs) {
    //  Write your code here.
    vector<int>dp(nStairs+1 , -1);
    return solve(nStairs , dp);
}

TimeComplexcity-->O(n)
Space Complexcity-->O(n)
