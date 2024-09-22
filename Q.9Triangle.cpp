Q.9 Triangle
Problem statement
You are given a triangular array/list 'TRIANGLE'. Your task is to return the minimum path sum to reach from the top to the bottom row.

The triangle array will have N rows and the i-th row, where 0 <= i < N will have i + 1 elements.

You can move only to the adjacent number of row below each step. For example, if you are at index j in row i, then you can move to i or i + 1 index in row j + 1 in each step.

For Example :
If the array given is 'TRIANGLE' = [[1], [2,3], [3,6,7], [8,9,6,1]] the triangle array will look like:

1
2,3
3,6,7
8,9,6,10

For the given triangle array the minimum sum path would be 1->2->3->8. Hence the answer would be 14.

code-->#include <bits/stdc++.h> 
// int solve(int i , int j, vector<vector<int>>&triangle , int n , vector<vector<int>>&dp){
// 	if(i==n-1){
// 		return triangle[n-1][j];
// 	}
// 	if(dp[i][j]!=-1){
// 		return dp[i][j];
// 	}
// 	int down= triangle[i][j]+solve(i+1, j, triangle,  n , dp);
// 	int dig= triangle[i][j]+solve(i+1,  j+1, triangle, n , dp);
// 	return dp[i][j]=min(down,dig);
// }
int minimumPathSum(vector<vector<int>>& triangle, int n){
	// Write your code here.
	// vector<vector<int>>dp(n , vector<int>(n,-1));
	// return solve(0 , 0 , triangle , n , dp);

	// int dp[n][n];
	// for(int j=0;j<n;j++){
	// 	dp[n-1][j]= triangle[n-1][j];
	// }
	// for(int i=n-2 ;i>=0;i--){
	// 	for(int j=i;j>=0;j--){
	// 			int down= INT_MAX;
	// 			int dig= INT_MAX;
	// 			if(i<n-1){
	// 				down=triangle[i][j]+dp[i+1][j];
	// 			}
	// 			if(j<n-1){
	// 				dig= triangle[i][j]+dp[i+1][j+1];
	// 			}
	// 			dp[i][j]= min(down , dig);
	// 		}
	// 	}
	
	// return dp[0][0];






	vector<int>front(n ,0) , curr(n,0);
	for(int j=0;j<n;j++){
		front[j]= triangle[n-1][j];
	}
	for(int i=n-2;i>=0;i--){
		
		for(int j=i;j>=0;j--){
			int d= triangle[i][j]+front[j];
			int dg= triangle[i][j]+front[j+1];
			curr[j]= min(d , dg);
		}
		front= curr;
	}
	return front[0];
}

Approach	Time Complexity	Space Complexity
Recursive with Memoization	O(2^n)	O(n*n)+o(n+n)
Tabulation (Iterative Dynamic Programming)	O(n*n)	O(n*n)
Space-Optimized Tabulation	O(n*n)	O(n)
