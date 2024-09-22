Q. Ninja’s Training
Problem statement
Ninja is planing this ‘N’ days-long training schedule. Each day, he can perform any one of these three activities. (Running, Fighting Practice or Learning New Moves). Each activity has some merit points on each day. As Ninja has to improve all his skills, he can’t do the same activity in two consecutive days. Can you help Ninja find out the maximum merit points Ninja can earn?
You are given a 2D array of size N*3 ‘POINTS’ with the points corresponding to each day and activity. Your task is to calculate the maximum number of merit points that Ninja can earn.
For Example
If the given ‘POINTS’ array is [[1,2,5], [3 ,1 ,1] ,[3,3,3] ],the answer will be 11 as 5 + 3 + 3.

code-->int solve(int days ,int last, vector<vector<int>>& points , vector<vector<int>>&dp){
    if(days==0){
        int maxi=0;
        for(int task=0;task<3;task++){
            if(task!=last){
                maxi = max(maxi , points[0][task]);
            }
        }
        return maxi;
    }
    if(dp[days][last]!=-1){
        return dp[days][last];
    }
    int maxi=0;
    for(int task=0;task<3;task++){
        
        if(task!=last){
            int point= points[days][task]+solve(days-1 , task , points , dp);
            maxi=max(maxi , point);
        }
    }
    return dp[days][last]=maxi;
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<vector<int>>dp(n ,vector<int>(4,-1));
    return solve(n-1 , 3 , points , dp);

}

Approach	Time Complexity	Space Complexity
Recursive with Memoization	O(n*4)*3	O(n)+O(n*4)
Tabulation (Iterative Dynamic Programming)	O(n)	O(n)
