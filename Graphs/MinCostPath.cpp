// You are given a AB character matrix named C. Every cell in C has a character U,R,L or D indicating up,right,left and down.

// Your target is to go from top left corner to the bottom right corner of the matrix.

// But there are some restrictions while moving along the matrix:

// If you follow what is written in the cell then you can move freely.
// But if you don't follow what is written in the cell then you have to pay 1 unit of cost.
// Like: If a cell contains character U and you go right instead of Up you have to pay 1 unit of cost.

// So your task is to find the minimum cost to go from top-left corner to the bottom-right corner.



// Problem Constraints
// 1 <= A,B <= 103
// C[i][j] can be either U,R,L or D.


// Input Format
// First Argument represents a integer A (number of rows).
// Second Argument represents a integer B (number of columns).
// Third Argument represents a string array C which contains A strings each of length B.


// Output Format
// Return an integer denoting the minimum cost to travel from top-left corner to bottom-right corner.



// Example Input
// Input:1

//  A = 3
//  B = 3
//  C = ["RRR","DDD","UUU"]
// Input:2

//  A = 1
//  B = 4
//  C = ["LLLL"]


// Example Output
// Output-1 :

//  1
// Output-2 :

//  3


// Example Explanation*
// Explanation for Input-1:

//  Matrix looks like: RRR
//                     DDD
//                     UUU
//  We go right two times and down two times.
//  So from top-right cell we are going down though right is given so this incurs a cost of 1.
// Explanation for Input-2:

//  Matrix looks like: LLLL
//  We go right three times.


// DIJKSTRA'S ALGO
#define PII pair<int,pair<int,int>>

char dir[]={'U', 'R', 'L', 'D'};
int X[]={-1,0,0,1};
int Y[]={0,1,-1,0};

int Solution::solve(int A, int B, vector<string> &C) {

vector<vector<int>>dist(A,vector<int>(B));

for(int i=0;i<A;++i)
    for(int j=0;j<B;++j)
      dist[i][j]=INT_MAX;
dist[0][0]=0;
priority_queue<PII,vector<PII>,greater<PII>>q;
q.push({dist[0][0],{0,0}});
int x,y;
while(!q.empty()){
    x=q.top().second.first;
    y=q.top().second.second;
    q.pop();
    for(int i=0;i<4;++i){
        int newx=x+X[i];
        int newy=y+Y[i];
        int add=(C[x][y]==dir[i])?0:1;
        if(newx>=0&&newx<A&&newy>=0&&newy<B&&(dist[x][y]+add)<dist[newx][newy]){
            dist[newx][newy]=dist[x][y]+add;
            q.push({dist[newx][newy],{newx,newy}});
        }
    }
}
        
return dist[A-1][B-1];
}
