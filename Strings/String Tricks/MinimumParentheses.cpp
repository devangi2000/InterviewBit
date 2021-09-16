// Given a string A of parantheses ‘(‘ or ‘)’.
// The task is to find minimum number of parentheses ‘(‘ or ‘)’ (at any positions) we must add to make
//  the resulting parentheses string valid.
// An string is valid if:
// Open brackets must be closed by the corresponding closing bracket.
// Open brackets must be closed in the correct order.

// Problem Constraints
// 1 <= |A| <= 105
// A[i] = '(' or A[i] = ')'

// Input Format
// First and only argument is an string A.

// Output Format
// Return a single integer denoting the minimumnumber of parentheses ‘(‘ or ‘)’ (at any positions) we must add in A to make the resulting parentheses string valid.

// Example Input
// Input 1:
//  A = "())"
// Input 2:
//  A = "((("
// Example Output
// Output 1:
//  1
// Output 2:
//  3
// Example Explanation
// Explanation 1:
//  One '(' is required at beginning.
// Explanation 2:
//  Three ')' is required at end.

int Solution::solve(string str) {
    stack<char> st;
    int n = str.size();
    st.push(str[0]);
    for(int i = 1; i < n; i++){
        if(!st.empty() and st.top() == '(' and str[i] == ')')
            st.pop();
        else st.push(str[i]);
    }
    return st.size();
}