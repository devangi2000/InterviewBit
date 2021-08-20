// Given an integer array A of size N, find the first repeating element in it.

// We need to find the element that occurs more than once and whose index of first occurrence is smallest.

// If there is no repeating element, return -1.



// Problem Constraints
// 1 <= N <= 105

// 1 <= A[i] <= 109



// Input Format
// First and only argument is an integer array A of size N.



// Output Format
// Return an integer denoting the first repeating element.



// Example Input
// Input 1:

//  A = [10, 5, 3, 4, 3, 5, 6]
// Input 2:

//  A = [6, 10, 5, 4, 9, 120]


// Example Output
// Output 1:

//  5
// Output 2:

//  -1


// Example Explanation
// Explanation 1:

//  5 is the first element that repeats
// Explanation 2:

//  There is no repeating element, output -1


int Solution::solve(vector<int> &A) {
    
    unordered_map<int,int>map;
    int min_index=INT_MAX;
    int element=-1;
    
    for(int i=0;i<A.size();i++)
    {
        if(map.find(A[i])!=map.end())
        {
            if(min_index>map[A[i]])
            {
                min_index=map[A[i]];
                element=A[i];
            }
        }
        map[A[i]]=i;
    }
    
    return element;
}