Q. Partition Equal Subset Sum
You are given an array 'ARR' of 'N' positive integers. Your task is to find if we can partition the given array into two subsets such that the sum of elements in both subsets is equal.
For example, let’s say the given array is [2, 3, 3, 3, 4, 5], then the array can be partitioned as [2, 3, 5], and [3, 3, 4] with equal sum 10.
Follow Up:
Can you solve this using not more than O(S) extra space, where S is the sum of all elements of the given array?

Sample Input 1:
2
6
3 1 1 2 2 1
5
5 6 5 11 6
Sample Output 1:
true
false    

code-->
bool solve(int i , int k ,vector<int> &arr ,vector<vector<int>>&dp) {
    if(k==0){
        return true;
    }
    if(i==0){
        return (arr[0]==k);
    }
    if(dp[i][k]!=-1){
        return dp[i][k];
    }
    
    bool notpick= solve(i-1 , k , arr , dp);
    bool pick=false;
    if(arr[i]<=k){
        pick=solve(i-1 , k-arr[i] , arr , dp);
    }
    
    
    return dp[i][k]=pick | notpick;
}
bool canPartition(vector<int> &arr, int n)
{
	// Write your code here.
	int totSum=0;
	for(int i=0;i<n;i++){
		totSum+=arr[i];
	}
	if(totSum%2!=0){
		return false;
	}
    int k=totSum/2;
	vector<vector<int>>dp(n+1 , vector<int>(k+1,-1));
	return solve(n ,k,arr , dp );
}

Approach	            Time Complexity	Space Complexity
Recursion with Memoization	O(n * k)	O(n * k + n) 
Tabulation (Bottom-Up)	O(n * k)	O(n * (k + 1))
Space Optimized Tabulation	O(n * k)	O(k)
