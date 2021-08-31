// Given a tree with N nodes numbered from 1 to N.
// Each edge is bi-directional and has a certain weight assigned to it.
// You are given Q queries, in each query you are given two integers u and v and
//  you are required to find the maximum weighted edge in a simple path from u to v.
// You have to return the weight of the edge for each queries.
// Problem Constraints
// 2 <= N, Q <= 105
// 1 <= u, v <= N and u != v

// 1 <= weight of any edge <= 108
// Input Format
// First argument is a 2-D array A of size (N-1) x 3 where (A[i][0], A[i][1]) denotes an edge
//  of the tree from node A[i][0] to node A[i][1] with weight A[i][2].
// Second argument is a 2-D array B of size Q x 2 denoting the queries, B[i][0] denotes u and 
// B[i][1] denotes v.

// Output Format
// Return an integer array of size Q denoting the answer for each queries.

// Example Input
// Input 1:

//  A = [  [1, 2, 11]
//         [1, 3, 1]
//         [2, 4, 12]
//         [2, 5, 100]
//      ]
//  B = [  [3, 5]
//         [2, 3]
//      ]

// Example Output
// Output 1:

//  [100, 11]
// Example Explanation
// Explanation 1:
//  Query 1: u  = 3 and v = 5 so edge (2 -> 5) is the maximum weighted in the path from u to v so
//  we will return the
//  edge weight as the answer for this query.
//  Query 2: u = 2 and  v= 3 so edge (2 -> 1) is the maximum weighted in the path from u to v so we
//  will return the
//  edge weight as the answer for this query.

