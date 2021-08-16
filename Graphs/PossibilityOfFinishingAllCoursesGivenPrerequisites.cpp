// There are a total of A courses you have to take, labeled from 1 to A.
// Some courses may have prerequisites, for example to take course 2 you
//  have to first take course 1, which is expressed as a pair: [1,2].
// Given the total number of courses and a list of prerequisite pairs,
//  is it possible for you to finish all courses?
// Return 1 if it is possible to finish all the courses, or 0 if it is
//  not possible to finish all the courses.
// Input Format:
// The first argument of input contains an integer A, representing the number of courses.
// The second argument of input contains an integer array, B.
// The third argument of input contains an integer array, C.
// Output Format:
// Return a boolean value:
//     1 : If it is possible to complete all the courses.
//     0 : If it is not possible to complete all the courses.
// Constraints:
// 1 <= A <= 6e4
// 1 <= length(B) = length(C) <= 1e5
// 1 <= B[i], C[i] <= A
// Example:
// Input 1:
//     A = 3
//     B = [1, 2]
//     C = [2, 3]
// Output 1:
//     1
// Explanation 1:
//     It is possible to complete the courses in the following order:
//         1 -> 2 -> 3
// Input 2:
//     A = 2
//     B = [1, 2]
//     C = [2, 1]
// Output 2:
//     0
// Explanation 2:
//     It is not possible to complete all the courses.

// METHOD 1 :
// BFS + QUEUE : KAHN'S ALGORITHM

int Solution::solve(int A, vector<int> &B, vector<int> &C){
    vector<int> indegree(A+1, 0);
    vector<vector<int>> adj(A+1);
    for(int i = 0; i < B.size(); i++)
        adj[B[i]].push_back(C[i]);
    
    for(int i = 1; i <= A; i++){
        for(auto el : adj[i])
            indegree[el]++;
    }
    queue<int> q;
    for(int i = 1; i <= A; i++)
        if(indegree[i]==0)
            q.push(i);
    int count = 0;        
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        count++;
        for(auto el : adj[curr]){
            indegree[el]--;
            if(indegree[el] == 0){
                q.push(el);
            }
        }
    }
    return count == A ? 1 : 0;
}


// METHOD 2 : 
// DFS 

bool isCycleDFS(vector<vector<int>> &adj, vector<int> &visited, vector<int> &path, int node){
    visited[node] = 1;
    path[node] = 1;
    for(auto el : adj[node]){
        if(!visited[el]){
            if(isCycleDFS(adj, visited, path, el))
                return true;
        }
        else if(visited[el] and path[el])
            return true;
    }
    path[node] = 0;
    return false;
}

int Solution::solve(int A, vector<int> &B, vector<int> &C){
    vector<vector<int>> adj(A+1);
    for(int i = 0; i < B.size(); i++)
        adj[B[i]].push_back(C[i]);
        
    vector<int> visited(A+1, 0), path(A+1, 0);
    for(int i = 1; i <= A; i++){
       if(!visited[i]){
            if(isCycleDFS(adj, visited, path, i))
                return 0;
        }
    }
    return 1;
}

