Q. Chocolate Pickup
Problem statement
Ninja has a 'GRID' of size 'R' X 'C'. Each cell of the grid contains some chocolates. Ninja has two friends Alice and Bob, and he wants to collect as many chocolates as possible with the help of his friends.
Initially, Alice is in the top-left position i.e. (0, 0), and Bob is in the top-right place i.e. (0, ‘C’ - 1) in the grid. Each of them can move from their current cell to the cells just below them. When anyone passes from any cell, he will pick all chocolates in it, and then the number of chocolates in that cell will become zero. If both stay in the same cell, only one of them will pick the chocolates in it.
If Alice or Bob is at (i, j) then they can move to (i + 1, j), (i + 1, j - 1) or (i + 1, j + 1). They will always stay inside the ‘GRID’.
Your task is to find the maximum number of chocolates Ninja can collect with the help of his friends by following the above rules.
Example:
Input: ‘R’ = 3, ‘C’ = 4
       ‘GRID’ = [[2, 3, 1, 2], [3, 4, 2, 2], [5, 6, 3, 5]]
Output: 21

Initially Alice is at the position (0,0) he can follow the path (0,0) -> (1,1) -> (2,1) and will collect 2 + 4 + 6 = 12 chocolates.
Initially Bob is at the position (0, 3) and he can follow the path (0, 3) -> (1,3) -> (2, 3) and will colllect 2 + 2 + 5 = 9 chocolates.
Hence the total number of chocolates collected will be 12 + 9 = 21. there is no other possible way to collect a greater number of chocolates than 21.
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= ‘T’ <= 10
2 <= 'R', 'C' <= 50
0 <= 'GRID[i][j]'<= 10^2
Time Limit: 1sec
Sample Input 1 :
2
3 4
2 3 1 2
3 4 2 2
5 6 3 5
2 2
1 1
1 2
Sample Output 1 :
21
5
code-->
#include <bits/stdc++.h> 
// int solve(int i , int j1 , int j2 ,vector<vector<int>> &grid , int n , int m , vector<vector<vector<int>>>&dp ){
//     if(i==n-1){
//         if(j1==j2){
//             return grid[i][j1];
//         }
//         else{
//             return grid[i][j1]+grid[i][j2];
//         }
//     }
//     if(j1<0 ||j1>=m||j2<0||j2>=m){
//         return -1e8;
//     }
//     if(dp[i][j1][j2]!=-1){
//         return dp[i][j1][j2];
//     }
//     int maxi= -1e8;
//     for(int dj1=-1;dj1<=1;dj1++){
//         for(int dj2=-1;dj2<=1;dj2++){
//             int val=0;
//             if(j1==j2){
//                 val+=grid[i][j1];
//             }
//             else{
//                 val+=grid[i][j1]+grid[i][j2];
//             }
//             val+=solve(i+1 , j1+dj1 , j2+dj2 , grid , n , m , dp);
//             maxi=max(maxi , val);
//         }
//     }
//     return dp[i][j1][j2]=maxi;
// }
int maximumChocolates(int n, int m, vector<vector<int>> &grid) {
    // Write your code here.
    vector<vector<vector<int>>>dp(n , vector<vector<int>>(m , vector<int>(m,0)));
    // return solve(0 ,0 ,c-1 , grid , r , c , dp);

    for(int j1=0;j1<m;j1++){
        for(int j2=0;j2<m;j2++){
            if(j1==j2){
                dp[n-1][j1][j2]= grid[n-1][j1];
            }
            else{
                dp[n-1][j1][j2]= grid[n-1][j1]+grid[n-1][j2];
            }
        }
    }

    for(int i=n-2;i>=0;i--){
        for(int j1=0;j1<m;j1++){
            for(int j2=0;j2<m;j2++){
                int maxi= -1e8;
                for(int dj1=-1;dj1<=1;dj1++){
                    for(int dj2=-1;dj2<=1;dj2++){
                        int val=0;
                        if(j1==j2){
                            val+=grid[i][j1];
                        }
                        else{
                            val+=grid[i][j1]+grid[i][j2];
                        }
                        if(j1+dj1>=0 && j1+dj1<m && j2+dj2>=0 && j2+dj2<m){
                            val+=dp[i+1][j1+dj1][j2+dj2];
                        }
                        else{
                            val+=-1e8;
                        }
                        maxi=max(maxi , val);
                    }
                }
                dp[i][j1][j2]=maxi;
                
            }
        }
    }
    return dp[0][0][m-1];
}
the time complexity of Recursive Approach with Memoization is:O(n∗m∗m∗9)=O(n∗m ^2)
the space complexity of Recursive Approach with Memoization is:O(n∗m∗m)

the time complexity of Recursive Approach with Memoization is:O(n∗m∗m∗9)=O(n∗m ^2)
the space complexity of Recursive Approach with Memoization is:O(n∗m∗m)+ O(n).
