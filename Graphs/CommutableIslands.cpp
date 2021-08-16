// There are A islands and there are M bridges connecting them. Each bridge has some cost attached to it.

// We need to find bridges with minimal cost such that all islands are connected.

// It is guaranteed that input data will contain at least one possible scenario in which all islands are connected with each other.

// Input Format:

// The first argument contains an integer, A, representing the number of islands.
// The second argument contains an 2-d integer matrix, B, of size M x 3:
//     => Island B[i][0] and B[i][1] are connected using a bridge of cost B[i][2].
// Output Format:

// Return an integer representing the minimal cost required.
// Constraints:

// 1 <= A, M <= 6e4
// 1 <= B[i][0], B[i][1] <= A
// 1 <= B[i][2] <= 1e3
// Examples:

// Input 1:
//     A = 4
//     B = [   [1, 2, 1]
//             [2, 3, 4]
//             [1, 4, 3]
//             [4, 3, 2]
//             [1, 3, 10]  ]

// Output 1:
//     6

// Explanation 1:
//     We can choose bridges (1, 2, 1), (1, 4, 3) and (4, 3, 2), where the total cost incurred will be (1 + 3 + 2) = 6.

// Input 2:
//     A = 4
//     B = [   [1, 2, 1]
//             [2, 3, 2]
//             [3, 4, 4]
//             [1, 4, 3]   ]

// Output 2:
//     6

// Explanation 2:
//     We can choose bridges (1, 2, 1), (2, 3, 2) and (1, 4, 3), where the total cost incurred wi


// PRIM'S ALGO
int Solution::solve(int a, vector<vector<int>> &b) {
   vector<vector<pair<int, int>>> adj(a+1);
   priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
   for(auto el: b){
       adj[el[0]].push_back({el[1], el[2]});
       adj[el[1]].push_back({el[0], el[2]});
   }
   vector<bool> visited(a+1, false);
   vector<int> weights(a+1, INT_MAX);
   weights[1] = 0;
   pq.push({0, 1});
   for(int i = 2; i <= a; i++)
        pq.push({weights[i], i});
        
    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        visited[u] = true;
        for(int v = 0; v < adj[u].size(); v++){
            if(!visited[adj[u][v].first] and weights[adj[u][v].first] > adj[u][v].second){
                weights[adj[u][v].first] = adj[u][v].second;
                pq.push({adj[u][v].second, adj[u][v].first});
            }
        }
    }
    int ans = 0;
    for(int i = 1; i < weights.size(); ++i)
        ans += weights[i];
    return ans;
}
 

 // KRUSKAL'S ALGO USING DISJOINT SET UNION FIND:
 