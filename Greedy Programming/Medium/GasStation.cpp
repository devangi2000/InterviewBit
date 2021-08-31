// Given two integer arrays A and B of size N.
// There are N gas stations along a circular route, where the amount of gas at station i is A[i].

// You have a car with an unlimited gas tank and it costs B[i] of gas to travel from station i
// to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

// Return the minimum starting gas station’s index if you can travel around the circuit once, otherwise return -1.
// You can only travel in one direction. i to i+1, i+2, … n-1, 0, 1, 2.. Completing the circuit means starting at i and
// ending up at i again.

// Input Format

// The first argument given is the integer array A.
// The second argument given is the integer array B.
// Output Format

// Return the minimum starting gas station's index if you can travel around the circuit once, otherwise return -1.
// For Example

// Input 1:
//     A =  [1, 2]
//     B =  [2, 1]
// Output 1:
//     1
//     Explanation 1:
//         If you start from index 0, you can fill in A[0] = 1 amount of gas. Now your tank has 1 unit of gas. But you need B[0] = 2 gas to travel to station 1. 
//         If you start from index 1, you can fill in A[1] = 2 amount of gas. Now your tank has 2 u

int Solution::canCompleteCircuit(const vector<int> &gas, const vector<int> &cost) {
    int n = gas.size(), start = 0, tank = 0, total = 0;
    for(int i = 0; i < n; i++){
        total += gas[i] - cost[i];
        tank += gas[i] - cost[i];
        if(tank < 0){
            tank = 0;
            start = i + 1;
        }
    }
    return total < 0 ? -1 : start;
}

            
