// There is a rod of length N lying on x-axis with its left end at x = 0 and right end at x = N. Now, there are M weak points on this rod denoted by positive integer values(all less than N) A1, A2, …, AM. You have to cut rod at all these weak points. You can perform these cuts in any order. After a cut, rod gets divided into two smaller sub-rods. Cost of making a cut is the length of the sub-rod in which you are making a cut.

// Your aim is to minimise this cost. Return an array denoting the sequence in which you will make cuts. If two different sequences of cuts give same cost, return the lexicographically smallest.

// Notes:

// Sequence a1, a2 ,…, an is lexicographically smaller than b1, b2 ,…, bm, if and only if at the first i where ai and bi differ, ai < bi, or if no such i found, then n < m.
// N can be upto 109.
// For example,

// N = 6
// A = [1, 2, 5]

// If we make cuts in order [1, 2, 5], let us see what total cost would be.
// For first cut, the length of rod is 6.
// For second cut, the length of sub-rod in which we are making cut is 5(since we already have made a cut at 1).
// For third cut, the length of sub-rod in which we are making cut is 4(since we already have made a cut at 2).
// So, total cost is 6 + 5 + 4.

// Cut order          | Sum of cost
// (lexicographically | of each cut
//  sorted)           |
// ___________________|_______________
// [1, 2, 5]          | 6 + 5 + 4 = 15
// [1, 5, 2]          | 6 + 5 + 4 = 15
// [2, 1, 5]          | 6 + 2 + 4 = 12
// [2, 5, 1]          | 6 + 4 + 2 = 12
// [5, 1, 2]          | 6 + 5 + 4 = 15
// [5, 2, 1]          | 6 + 5 + 2 = 13


// So, we return [2, 1, 5].


using ll = long long;
using vl = vector<ll>;
using vi = vector<int>;
const ll inf = 1e18 + 7;
vi Solution::rodCut(int n, vi &a) {
    a.insert(a.begin(), 0);
    a.push_back(n);
    int m = a.size();
    vector<vl> dp(m, vl(m, inf));
    for (int i = 0; i < m; i++) 
        for (int j = 0; j < m; j++)
            if (j - i < 2) dp[i][j] = 0;
    for (int l = 3; l <= m; l++)
        for (int i = 0, j = l - 1; j < m; i++, j++)
            for (int k = i + 1; k < j; k++)
                dp[i][j] = min(dp[i][j], a[j] - a[i] + dp[i][k] + dp[k][j]);
    function<vi(int, int)> build = [&](int l, int r) {
        if (r - l < 2) return vi();
        for (int i = l + 1; i < r; i++) {
            if (dp[l][r] == a[r] - a[l] + dp[l][i] + dp[i][r]) {
                vi v1 = build(l, i);
                vi v2 = build(i, r);
                if (v1 > v2) swap(v1, v2);
                vi v(1, a[i]);
                for (int c : v1) v.push_back(c);
                for (int c : v2) v.push_back(c);
                return v;
            }
        }
    };
    return build(0, m - 1);
}