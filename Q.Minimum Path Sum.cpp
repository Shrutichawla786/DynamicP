Q. Minimum Path Sum
Problem statement
Ninjaland is a country in the shape of a 2-Dimensional grid 'GRID', with 'N' rows and 'M' columns. Each point in the grid has some cost associated with it.
Find a path from top left i.e. (0, 0) to the bottom right i.e. ('N' - 1, 'M' - 1) which minimizes the sum of the cost of all the numbers along the path. You need to tell the minimum sum of that path.
Note:
You can only move down or right at any point in time.
Sample Input 1:
2
2 3
5 9 6
11 5 2
1 1
5
Sample Output 1:
21
5

code-->#include <bits/stdc++.h>
// long solve(int i , int j , vector<vector<int>>&grid , vector<vector<int>>&dp){
//     if(i==0 && j==0){
//         return grid[0][0];
//     }
//     else if(i<0 ||j<0){
//         return INT_MAX;
//     }
//     if(dp[i][j]!=-1){
//         return dp[i][j];
//     }
//     long up= grid[i][j]+ solve(i-1 , j , grid , dp);
//     long left= grid[i][j]+solve(i , j-1 , grid, dp);
//     return dp[i][j]=min(up,left);
// } 
int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
    int n= grid.size();
    int m= grid[0].size();
    // vector<vector<int>>dp(n , vector<int>(m , -1));
    // return solve(n-1 , m-1 , grid ,dp);

    // int dp[n][m];
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         if(i==0 && j==0){
    //             dp[i][j]=grid[i][j];
    //         } else {
    //             int  up = grid[i][j];
    //             int left = grid[i][j];
    //             if (i > 0)
    //               up += dp[i - 1][j];
    //             else up+=1e9;
                
    //             if (j > 0)
    //               left += dp[i][j - 1];
    //             else left+=1e9;
    //             dp[i][j] = min(up, left);
    //         }
    //     }
    // }
    // return dp[n-1][m-1];

    vector<int>prev(m , 0);
    for(int i=0;i<n;i++){
        vector<int>curr(m,0);
        for(int j=0;j<m;j++){
            if(i==0 && j==0){
                curr[j]= grid[i][j];
            }
            else{
                int up= grid[i][j];
                int left= grid[i][j];
                if(i>0){
                    up+= prev[j];
                }
                else{
                    up+=1e9;
                }
                if(j>0){
                    left+=curr[j-1];

                } else {
                    left += 1e9;
                }
                curr[j]= min(up , left);
            }
        }
        prev = curr;
    }
    return prev[m-1];
}

Approach	Time Complexity	Space Complexity
Recursive with Memoization	O(n*m)	O(n*m)+O(n+m)
Tabulation (Iterative Dynamic Programming)	O(n*m)	O(n)
Space-Optimized Tabulation	O(n*m)	O(m)
