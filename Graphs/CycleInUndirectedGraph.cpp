// Given an undirected graph having A nodes labelled from 1 to A with M edges given in a form of matrix B of size M x 2 where (B[i][0], B[i][1]) represents two nodes B[i][0] and B[i][1] connected by an edge.

// Find whether the graph contains a cycle or not, return 1 if cycle is present else return 0.

// NOTE:

// The cycle must contain atleast three nodes.
// There are no self-loops in the graph.
// There are no multiple edges between two nodes.
// The graph may or may not be connected.
// Nodes are numbered from 1 to A.
// Your solution will run on multiple test cases. If you are using global variables make sure to clear them.


// Problem Constraints
// 1 <= A, M <= 3105

// 1 <= B[i][0], B[i][1] <= A



// Input Format
// The first argument given is an integer A representing the number of nodes in the graph.

// The second argument given is an matrix B of size M x 2 which represents the M edges such that there is a edge between node B[i][0] and node B[i][1].



// Output Format
// Return 1 if cycle is present else return 0.



// Example Input
// Input 1:

//  A = 5
//  B = [  [1. 2]
//         [1, 3]
//         [2, 3]
//         [1, 4]
//         [4, 5]
//      ]
// Input 2:

//  A = 3
//  B = [  [1. 2]
//         [1, 3]
//      ]


// Example Output
// Output 1:

//  1
// Output 2:

//  0


// Example Explanation*
// Explanation 1:

//  There is a cycle in the graph i.e 1 -> 2 -> 3 -> 1 so we will return 1
// Explanation 2:

//  No cycle present in the graph so we will return 0.

bool dfsCycle(int i, int p, vector<int>& vis, vector<vector<int>>& adj){
    vis[i] = 1;
    for(auto x:adj[i]){
        if(!vis[x]){
            if(dfsCycle(x, i, vis, adj)) return true;
        }
        else if(x != p) return true;
    }
    return false;
}
int Solution::solve(int n, vector<vector<int> > &b) {
    vector<vector<int>> adj(n+1);
    for(int i=0;i<b.size();i++){
        adj[b[i][0]].push_back(b[i][1]);
        adj[b[i][1]].push_back(b[i][0]);
    }
    
    vector<int> vis(n+1, 0);
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            if(dfsCycle(i, -1, vis, adj)) return 1;
        }
    }
    return 0;
}