Q. Unique Paths
Problem statement
You are present at point ‘A’ which is the top-left cell of an M X N matrix, your destination is point ‘B’, which is the bottom-right cell of the same matrix. Your task is to find the total number of unique paths from point ‘A’ to point ‘B’.In other words,
you will be given the dimensions of the matrix as integers ‘M’ and ‘N’, your task is to find the total number of unique paths from the cell MATRIX[0][0] to MATRIX['M' - 1]['N' - 1].
To traverse in the matrix, you can either move Right or Down at each step. For example in a given point MATRIX[i] [j], you can move to either MATRIX[i + 1][j] or MATRIX[i][j + 1].

code-->#include <bits/stdc++.h> 
// int solve(int i , int j , vector<vector<int>>&dp){
// 	if(i==0 && j==0){
// 		return 1;
// 	}
// 	if(i<0|| j<0){
// 		return 0;
// 	}
// 	if(dp[i][j]!=-1){
// 		return dp[i][j];
// 	}
// 	int left= solve(i-1 , j , dp);
// 	int right= solve(i , j-1 , dp);
// 	return dp[i][j]=left+right;
// }
int uniquePaths(int m, int n) {
	// vector<vector<int>>dp(m , vector<int>(n+1 , -1));
	// // return solve(m-1 , n-1 , dp);
	// Write your code here.
	// vector<vector<int>> dp(m, vector<int>(n, -1));

    //    for(int i=0;i<m;i++){

    //         for(int j=0;j<n;j++){

    //             if(i == 0 && j == 0) dp[0][0] = 1;

    //             else{

    //                 int up = 0, left = 0;

    //                 if(i>0) up = dp[i-1][j];

    //                 if(j>0) left = dp[i][j-1];

 

    //                 dp[i][j] = up + left;

    //             }

    //         }

    //     }

        // return dp[m-1][n-1];






        vector<int>prev(n , 0);
        for(int i=0;i<m;i++){
            vector<int>curr(n , 0);
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                    curr[j]=1;
                }
                else{
                    int up=0;
                    int left=0;
                    if(i>0) up=prev[j];
                    if(j>0) left= curr[j-1];
                   curr[j]= up+left;
                }
            }
            prev= curr;
        }
        return prev[n-1];
}
Approach	Time Complexity	Space Complexity
Recursive with Memoization	O(n*m)	O(n-1)(m-1) +O(n*m)
Tabulation (Iterative Dynamic Programming)	O(n*m)	O(n*m)
Space-Optimized Tabulation	O(n*m)	O(m)
