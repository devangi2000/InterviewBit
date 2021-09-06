// Given an undirected tree with an even number of nodes. Consider each connection between a parent and child node to be an edge.

// You need to remove maximum number of these edges, such that the disconnected subtrees that remain each have an even number of nodes.

// Return the maximum number of edges you can remove.



// Problem Constraints
// 2 <= A <= 105

// 1 <= B[i][0], B[i][1] <= A

// Integer A will be even.



// Input Format
// First argument is an integer A denoting the number of nodes in the tree.

// Second argument is a 2D array B of size (A-1) * 2, denoting the edge between nodes B[i][0] and B[i][1].



// Output Format
// Return an integer, denoting the maximum number of edges you can remove.



// Example Input
// Input 1:

//  A = 6
//  B = [
//        [1, 2]
//        [1, 3]
//        [1, 4]
//        [3, 5]
//        [4, 6]
//      ]
// Input 2:

//  A = 2
//  B = [
//        [1, 2]
//      ]


// Example Output
// Output 1:

//  2
// Output 2:

//  0


// Example Explanation
// Explanation 1:

//       1
//     / | \
//    2  3  4
//       |   \
//       5    6
//  Maximum number of edges we can remove is 2, i.e (1, 3) and (1, 4)
// Explanation 2:

//  We can't remove any edges.

void dfs(int start, vector<int> adj[], vector<int> &count, vector<int> &visited){
    visited[start] = 1;
    for(auto it : adj[start]){
        if(!visited[it]){
            dfs(it, adj, count, visited);
            count[start] += count[it]+1;
        }
    }
}

int Solution::solve(int n, vector<vector<int> > &v){
    vector<int> adj[n];
    for(int i = 0; i < v.size(); i++){
        adj[v[i][0]-1].push_back(v[i][1]-1);
        adj[v[i][1]-1].push_back(v[i][0]-1);
    }
    vector<int> count(n, 0), visited(n, 0);
    int ans = 0;
    dfs(0, adj, count, visited);
    for(int i = 0; i < n; i++){
        if(count[i]%2 != 0 and i != 0) ans++;
    }
    return ans;
}
