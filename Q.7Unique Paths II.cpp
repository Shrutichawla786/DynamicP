Q. Unique Paths II
Problem statement
Given a ‘N’ * ’M’ maze with obstacles, count and return the number of unique paths to reach the right-bottom cell from the top-left cell. A cell in the given maze has a value '-1' if it is a blockage or dead-end, else 0. From a given cell, we are allowed to move to cells (i+1, j) and (i, j+1) only. Since the answer can be large, print it modulo 10^9 + 7.

For Example :
Consider the maze below :
0 0 0 
0 -1 0 
0 0 0

There are two ways to reach the bottom left corner - 

(1, 1) -> (1, 2) -> (1, 3) -> (2, 3) -> (3, 3)
(1, 1) -> (2, 1) -> (3, 1) -> (3, 2) -> (3, 3)

Hence the answer for the above test case is 2.

code-->#include <bits/stdc++.h> 

// Function to calculate the maximum money that can be robbed from a linear sequence of houses
long long int call(std::vector<long long int>& arr) {
    long long int prev = arr[0]; // previous robbed amount
    long long int prev2 = 0;     // previous to previous robbed amount
    long long int n = arr.size();

    for(long long int i = 1; i < n; i++) {
        long long int take = arr[i]; // money if we rob the current house
        if (i > 1) {
            take += prev2; // add the previous-to-previous robbed amount if we rob the current house
        }
        long long int notTake = prev; // money if we skip the current house
        long long int curri = std::max(take, notTake); // choose the max of taking or not taking the current house

        prev2 = prev; // update prev2 to the previous robbed amount
        prev = curri; // update prev to the current maximum amount
    }

    return prev;
}

long long int houseRobber(std::vector<int>& valueInHouse) {
    long long int n = valueInHouse.size();

    // Special case: If there is only one house, return its value
    if (n == 1) {
        return valueInHouse[0];
    }

    std::vector<long long int> temp1, temp2;
    // Exclude the first house (temp1) and exclude the last house (temp2)
    for (long long int i = 0; i < n; i++) {
        if (i != 0) {
            temp1.push_back(valueInHouse[i]); // skip first house
        }
        if (i != n - 1) {
            temp2.push_back(valueInHouse[i]); // skip last house
        }
    }

    // Solve the two subproblems
    long long int first = call(temp1);
    long long int second = call(temp2);

    // Return the maximum of both cases
    return std::max(first, second);
}

Approach	Time Complexity	Space Complexity
Recursive with Memoization	O(n*m)	O(n*m)+O(n+m)
Tabulation (Iterative Dynamic Programming)	O(n*m)	O(n*m)
Space-Optimized Tabulation	O(n*m)	O(m)

