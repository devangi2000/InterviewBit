// Say you have an array, A, for which the ith element is the price of a given stock on day i.
// Design an algorithm to find the maximum profit.
// You may complete as many transactions as you like (i.e., buy one and sell one share of the
//  stock multiple times).
// However, you may not engage in multiple transactions at the same time (ie, you must sell 
// the stock before you buy again).
// Input Format:  The first and the only argument is an array of integer, A. 
// Output Format:  Return an integer, representing the maximum possible profit. 
// Constraints:  0 <= len(A) <= 1e5 1 <= A[i] <= 1e7  Example:
// Input 1:
//     A = [1, 2, 3]
// Output 1:
//     2
// Explanation 1:
//     => Buy a stock on day 0.
//     => Sell the stock on day 1. (Profit +1)
//     => Buy a stock on day 1.
//     => Sell the stock on day 2. (Profit +1)
// Overall profit = 2
// Input 2:
//     A = [5, 2, 10]
// Output 2:
//     8
// Explanation 2:
//     => Buy a stock on day 1.
//     => Sell the stock on on day 2. (Profit +8)
// Overall profit = 8

int Solution::maxProfit(const vector<int> &A) {
    int n = A.size(), profit = 0;
    for(int i = 1; i < n; i++)
        if(A[i] > A[i-1])
            profit += A[i] - A[i-1];
    return profit;
}