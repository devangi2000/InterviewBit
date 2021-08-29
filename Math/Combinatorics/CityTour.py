# // There are A cities numbered from 1 to A. You have already visited M cities, the
# //  indices of which are given in an array B of M integers.
# // If a city with index i is visited, you can visit either the city with index i-1
# //  (i >= 2) or the city with index i+1 (i < A) if they are not already visited.
# //  Eg: if N = 5 and array M consists of [3, 4], then in the first level of moves,
# //  you can either visit 2 or 5.
# // You keep visiting cities in this fashion until all the cities are not visited.
# //  Find the number of ways in which you can visit all the cities modulo 10^9+7.
# // Input Format  The 1st argument given is an integer A, i.e total number of cities.
# //  The 2nd argument given is an integer array B, where B[i] denotes ith city you already visited. 
# // Output Format  Return an Integer X % (1e9 + 7), number of ways in which you can visit all the cities.  Constraints  1 <= A <= 1000 1 <= M <= A 1 <= B[i] <= A 
# // For Example
# // // Input:  A = 5 B = [2, 5]  Output:  6  Explanation:  All possible ways to visit remaining cities are : 1. 1 -> 3 -> 4 2. 1 -> 4 -> 3 3. 3 -> 1 -> 4 4. 3 -> 4 -> 1 5. 4 -> 1 -> 3 6. 4 -> 3 -> 1 

from math import factorial

class Solution:
    def solve(self, A, B):
        B = sorted(B)
        first_gap = B[0] - 1
        last_gap = A - B[-1]
        gaps = [b - a - 1 for a, b in zip(B[:-1], B[1:])]
        
        res = factorial(A - len(B))
        for g in gaps:
            res //= factorial(g)
            if g > 0:
                res *= 2 ** (g-1)
            
        res //= factorial(first_gap)
        res //= factorial(last_gap)
        
        return res % (10**9+7)