Q. Maximum Path Sum in the matrix
You have been given an N*M matrix filled with integer numbers, find the maximum sum that can be obtained from a path starting from any cell in the first row to any cell in the last row.

From a cell in a row, you can move to another cell directly below that row, or diagonally below left or right. So from a particular cell (row, col), we can move in three directions i.e.

Down: (row+1,col)
Down left diagonal: (row+1,col-1)
Down right diagonal: (row+1, col+1)

  Input 1 :
2
4 4
1 2 10 4
100 3 2 1
1 1 20 2
1 2 2 1
3 3
10 2 3
3 7 2
8 1 5
Output 1 :
105
25

  code-->
  #include <bits/stdc++.h> 
// int solve(int i , int j , vector<vector<int>>&mat , int n , int m , vector<vector<int>>&dp){
//     if(j<0 ||j>=m){
//         return -1e8;
//     }
//     if(i==0){
//         return mat[0][j];
//     }
//     if(dp[i][j]!=-1){
//         return dp[i][j];
//     }
//     int u= mat[i][j]+solve(i-1 , j , mat , n , m , dp);
//     int ld= mat[i][j]+solve(i-1 ,j-1 , mat , n ,m , dp);
//     int rd= mat[i][j]+solve(i-1 , j+1  , mat , n ,m , dp);
//     return dp[i][j]=max(u , max(ld , rd));
// }
int getMaxPathSum(vector<vector<int>> &matrix)
{
    //  Write your code here.
    int n= matrix.size();
    int m= matrix[0].size();
    // int maxi=-1e8;
    // vector<vector<int>>dp(n , vector<int>(m , -1));
    // for(int j=0;j<m;j++){
    //     maxi= max(maxi ,solve(n-1 , j , matrix , n , m , dp) );
    // }
    // return maxi;

    vector<int>prev(m ,0);
    vector<int>curr(m ,0);

    for(int j=0;j<m;j++){
        prev[j]= matrix[0][j];
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            int u= matrix[i][j]+prev[j];
            int ld= matrix[i][j];
            if(j-1>=0){
                ld+=prev[j-1];
            }
            else{
                ld+=-1e8;
            }
            int rd= matrix[i][j];
            if(j+1<m){
                rd+=prev[j+1];
            }
            else{
                rd+=-1e8;
            }
            curr[j]= max(u , max(ld , rd));
        }
        prev= curr;
        

    }
    int maxi=-1e8;
    for(int j=0;j<m;j++){
        maxi = max(maxi , prev[j]);

    }
    return maxi;

}
the time complexity of Recursive Approach with Memoization is O(n * m).
the Space complexity of Recursive Approach with Memoization is O(n * m)+ O(n).


the time complexity of Tabulation Approach (Bottom-Up Dynamic Programming) is O(n * m).
the Space complexity of Tabulation Approach (Bottom-Up Dynamic Programming) is O(n * m).

the time complexity of Recursive Approach with Memoization is O(n * m).
the Space complexity of Recursive Approach with Memoization is O(n).
