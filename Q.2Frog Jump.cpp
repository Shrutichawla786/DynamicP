Q.Frog Jump
There is a frog on the '1st' step of an 'N' stairs long staircase.
The frog wants to reach the 'Nth' stair. 'HEIGHT[i]' is the height of the '(i+1)th' stair.
If Frog jumps from 'ith' to 'jth' stair, the energy lost in the jump is given by absolute value of ( HEIGHT[i-1] - HEIGHT[j-1] ). 
If the Frog is on 'ith' staircase, he can jump either to '(i+1)th' stair or to '(i+2)th' stair. Your task is to find the minimum total energy used by the frog to reach from '1st' stair to 'Nth' stair.
If the given ‘HEIGHT’ array is [10,20,30,10], the answer 20 as the frog can jump from 1st stair to 2nd stair (|20-10| = 10 energy lost) and then a jump from 2nd stair to last stair (|10-20| = 10 energy lost). So, the total energy lost is 20.
  #include <bits/stdc++.h> 
int call(int ind , vector<int> &arr , vector<int>&dp ){
    if(ind==0){
        return 0;
    }
    if(dp[ind]!=-1){
        return dp[ind];
    }
    int left= abs(arr[ind]-arr[ind-1])+call(ind-1 , arr ,dp);
    int right= INT_MAX;
    if(ind>1){
        right= abs(arr[ind]-arr[ind-2])+call(ind-2 , arr , dp);
        
    }
    return dp[ind]= min (left, right);
}
int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    // vector<int>dp(n+1 , -1);
    // // return call(n-1 ,heights , dp);

    // dp[0]=0;
    // for(int i=1;i<n;i++){
    //     int first= dp[i-1] +abs(heights[i]-heights[i-1]);
    //     int second= 1e9;
    //     if(i>1){
    //         second= dp[i-2]+abs(heights[i]-heights[i-2]);
    //     }
    //     dp[i]= min(first , second);
    // }
    // return  
    
    // dp[n-1];

    int prev=0;
    int prev1=0;
    for(int i=1;i<n;i++){
        int fs= prev+abs(heights[i]-heights[i-1]);
        int sec= 1e9;
        if(i>1){
            sec= prev1+abs(heights[i]-heights[i-2]);
        }
        int curri= min(fs, sec);
        prev1= prev;
        prev= curri;
    }
    return prev;
}

the time complexity of the memoized solution is:O(n).
the space complexity of the memoized solution is:O(n)+O(n)=O(n).



the time complexity of the Taabulation is:O(n).
the space complexity of the Taabulation is:O(n).


  
the time complexity Space-Optimized Iterative is:O(n).
the space complexity Space-Optimized Iterative is:O(1).


