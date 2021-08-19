// Given a string A denoting an expression. It contains the following operators ’+’, ‘-‘, ‘*’, ‘/’.
// Chech whether A has redundant braces or not.
// Return 1 if A has redundant braces, else return 0.
// Note: A will be always a valid expression.

// Input Format
// The only argument given is string A.
// Output Format
// Return 1 if string has redundant braces, else return 0.
// For Example
// Input 1:
//     A = "((a + b))"
// Output 1:
//     1
//     Explanation 1:
//         ((a + b)) has redundant braces so answer will be 1.

// Input 2:
//     A = "(a + (a + b))"
// Output 2:
//     0
//     Explanation 2:
//         (a + (a + b)) doesn't have have any redundant braces so answer will be 0.

int Solution::braces(string A) {
   stack<char> st;
   int flag = 0;
   for(auto a : A){
       if(a == ')'){
           int count = 0;
           while(!st.empty() and st.top() != '('){
               count++;
               st.pop();
           }
           if(count <= 1){
               flag++;
               break;
           }
           st.pop();
       }
       else
           st.push(a);
   }
   if(flag) return 1;
   return 0;
}