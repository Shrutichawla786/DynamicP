Q. Array partition with minimum difference

You are given an array 'arr' containing 'n' non-negative integers.
Your task is to partition this array into two subsets such that the absolute difference between subset sums is minimum.
You just need to find the minimum absolute difference considering any valid division of the array elements.
Note:
1. Each array element should belong to exactly one of the subsets.

2. Subsets need not always be contiguous.
For example, for the array : [1, 2, 3], some of the possible divisions are 
   a) {1,2} and {3}
   b) {1,3} and {2}.

3. Subset-sum is the sum of all the elements in that subset. 

Sample Input 1:
4
1 2 3 4
Sample Output 1:
0
Explanation for sample input 1:
We can partition the given array into {2,3} and {1,4}.
This will give us the minimum possible absolute difference i.e. (5 - 5 = 0) in this case.


code->int minSubsetSumDifference(vector<int>& arr, int n)
{
	// Write your code here.
	 int totalSum=0;
	    for(int i=0;i<n;i++){
	        totalSum+=arr[i];
	    }
	    int k = totalSum;
	    
	    vector<bool>prev(k+1 ,0), curr(k+1 ,0);
	    prev[0]= curr[0]=true;
	    prev[arr[0]]=true;
	    for(int i=1;i<n;i++){
	        for(int target=1;target<=k;target++){
	            bool nottake=prev[target];
	            bool take= false;
	            if(arr[i]<=target){
	                 take= prev[target-arr[i]];
	                
	            }
	            curr[target]=take|nottake;
	            
	        }
			prev=curr;
	    }
	    int mini=1e9;
	    for(int s1=0;s1<=totalSum/2;s1++){
	        if(prev[s1]==true){
	            mini= min(mini ,abs((totalSum-s1)-s1));
	        }
	    }
	    return mini;
	} 

Approach	              Time Complexity	Space Complexity
Recursion with Memoization	O(n * totalSum)	O(n * totalSum)
Tabulation (Bottom-Up)	O(n * totalSum)	O(n * totalSum)
Space Optimized Tabulation	O(n * totalSum)	O(totalSum)
