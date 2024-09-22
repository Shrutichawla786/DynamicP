Q House Robber II
Problem statement
Mr. X is a professional robber planning to rob houses along a street. Each house has a certain amount of money hidden.
All houses along this street are arranged in a circle. That means the first house is the neighbour of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses are broken into on the same night.
You are given an array/list of non-negative integers 'ARR' representing the amount of money of each house. Your task is to return the maximum amount of money Mr. X can rob tonight without alerting the police.
It is possible for Mr. X to rob the same amount of money by looting two different sets of houses. Just print the maximum possible robbed amount, irrespective of sets of houses robbed.
For example:
(i) Given the input array arr[] = {2, 3, 2} the output will be 3 because Mr X cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses. So, he’ll rob only house 2 (money = 3)

(ii) Given the input array arr[] = {1, 2, 3, 1} the output will be 4 because Mr X rob house 1 (money = 1) and then rob house 3 (money = 3).

(iii) Given the input array arr[] = {0} the output will be 0 because Mr. X has got nothing to rob.

code-->
#include <bits/stdc++.h> 

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

Approach	            Time Complexity	Space Complexity
Recursive with Memoization	O(n)	O(n)+O(n)
Tabulation (Iterative Dynamic Programming)	O(n)	O(n)
Space-Optimized Tabulation	O(n)	O(1)


