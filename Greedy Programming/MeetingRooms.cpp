// Given an 2D integer array A of size N x 2 denoting time intervals of different meetings.

// Where:

// A[i][0] = start time of the ith meeting.
// A[i][1] = end time of the ith meeting.
// Find the minimum number of conference rooms required so that all meetings can be done.



// Problem Constraints
// 1 <= N <= 10

// 0 <= A[i][0] < A[i][1] <= 2 * 109



// Input Format
// The only argument given is the matrix A.



// Output Format
// Return the minimum number of conference rooms required so that all meetings can be done.



// Example Input
// Input 1:

//  A = [      [0, 30]
//             [5, 10]
//             [15, 20]
//      ]

// Input 2:

//  A =  [     [1, 18]
//             [18, 23]
//             [15, 29]
//             [4, 15]
//             [2, 11]
//             [5, 13]
//       ]


// Example Output
// Output 1:

//  2
// Output 2:

//  4


// Example Explanation
// Explanation 1:

//  Meeting one can be done in conference room 1 form 0 - 30.
//  Meeting two can be done in conference room 2 form 5 - 10.
//  Meeting one can be done in conference room 2 form 15 - 20 as it is free in this interval.
// Explanation 2:

//  Meeting one can be done in conference room 1 from 1 - 18.
//  Meeting five can be done in conference room 2 from 2 - 11.
//  Meeting four can be done in conference room 3 from 4 - 15.
//  Meeting six can be done in conference room 4 from 5 - 13.
//  Meeting three can be done in conference room 2 from 15 - 29 as it is free in this interval.
//  Meeting two can be done in conference room 4 from 18 - 23 as it is free in this interval.


int Solution::solve(vector<vector<int> > &A) 
{
    int n = A.size();
    vector<int> start(n), finish(n);
    for(int i = 0; i < n; i++){
        start[i] = A[i][0];
        finish[i] = A[i][1];
    }
    int i = 0, j = 0, rooms = 0, ans = 0;
    sort(start.begin(), start.end());
    sort(finish.begin(), finish.end());
    while(i < n and j < n){
        if(start[i] < finish[j]){
            rooms++;
            i++;
        }
        else{
            rooms--;
            j++;
        }
        ans = max(ans, rooms);
    }
    return ans;
}

