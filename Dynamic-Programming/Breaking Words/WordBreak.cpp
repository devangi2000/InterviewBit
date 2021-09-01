// Given a string A and a dictionary of words B, determine if A can be segmented into a 
// space-separated sequence of one or more dictionary words.
// Input Format:
// The first argument is a string, A.
// The second argument is an array of strings, B.
// Output Format:
// Return 0 / 1 ( 0 for false, 1 for true ) for this problem.
// Constraints:
// 1 <= len(A) <= 6500
// 1 <= len(B) <= 10000
// 1 <= len(B[i]) <= 20
// Examples:
// Input 1:
//     A = "myinterviewtrainer",
//     B = ["trainer", "my", "interview"]
// Output 1:
//     1
// Explanation 1:
//     Return 1 ( corresponding to true ) because "myinterviewtrainer" can be segmented as "my interview trainer".
    // Input 2:
//     A = "a"
//     B = ["aaa"]
// Output 2:
//     0
// Explanation 2:
//     Return 0 ( corresponding to false ) because "a" cannot be segmented as "aaa".


