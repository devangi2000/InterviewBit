// Problem Description
// Given an directed graph having A nodes. A matrix B of size M x 2 is given which represents the M edges such that there is a edge directed from node B[i][0] to node B[i][1].
// Find whether the graph contains a cycle or not, return 1 if cycle is present else return 0.
// NOTE:
// The cycle must contain atleast two nodes.
// There are no self-loops in the graph.
// There are no multiple edges between two nodes.
// The graph may or may not be connected.
// Nodes are numbered from 1 to A.
// Your solution will run on multiple test cases. If you are using global variables make sure to clear them.

// Problem Constraints
// 2 <= A <= 105
// 1 <= M <= min(200000,A(A-1))
// 1 <= B[i][0], B[i][1] <= A

// Input Format
// The first argument given is an integer A representing the number of nodes in the graph.
// The second argument given a matrix B of size M x 2 which represents the M edges such that there is a edge directed from node B[i][0] to node B[i][1].

// Output Format
// Return 1 if cycle is present else return 0.

// Example Input
// Input 1:

//  A = 5
//  B = [  [1, 2] 
//         [4, 1] 
//         [2, 4] 
//         [3, 4] 
//         [5, 2] 
//         [1, 3] ]
// Input 2:

//  A = 5
//  B = [  [1, 2]
//         [2, 3] 
//         [3, 4] 
//         [4, 5] ]


// Example Output
// Output 1:

//  1
// Output 2:

//  0


// Example Explanation*
// Explanation 1:

//  The given graph contain cycle 1 -> 3 -> 4 -> 1 or the cycle 1 -> 2 -> 4 -> 1
// Explanation 2:

//  The given graph doesn't contain any cycle.

// DFS 

bool checkCycleDFS(vector<vector<int>> &adj, vector<int> &visited, vector<int> &path, int current){
    visited[current] = 1;
    path[current] = 1;
    for(auto it : adj[current]){
        if(!visited[it]){
            if(checkCycleDFS(adj, visited, path, it))
                return true;
        }
        else if(path[it] and visited[it]) return true;
    }
    path[current] = 0;
    return false;
}

int Solution::solve(int N, vector<vector<int> > &B) 
{
    vector<vector<int>> adj(N+1);
    vector<int> visited(N+1, 0), path(N+1, 0);
    for(auto it : B){
        adj[it[0]].push_back(it[1]);
    }
    for(int i = 1; i <= N; i++){
        if(!visited[i]){
            if(checkCycleDFS(adj, visited, path, i))
                return 1;
        }
    }
    return 0;
}

// BFS : Kahn's Algo

int Solution::solve(int N, vector<vector<int> > &B) 
{
    queue<int> q;
    vector<int> indegree(N+1, 0);
    vector<vector<int>> adj(N+1);
    for(int i = 0; i < B.size(); i++)
        adj[B[i][0]].push_back(B[i][1]);
    
    for(int i = 1; i <= N; i++){
        for(auto el : adj[i])
            indegree[el]++;
    }
    
    for(int i = 1; i <= N; i++){
        if(indegree[i] == 0)
            q.push(i);
    }
    
    int count = 0;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        count++;
        for(auto it : adj[curr]){
            indegree[it]--;
            if(indegree[it] == 0)
                q.push(it);
        }
    }
    if(count == N) return 0;
    return 1;
}
