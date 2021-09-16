// Given a string A consisting of lowercase characters.
// We need to tell minimum characters to be appended (insertion at end) to make the string A a palindrome.
// Problem Constraints
// 1 <= |A| <= 105
// A consists only of lower-case characters.

// Input Format
// First argument is an string A.

// Output Format
// Return a integer denoting the minimum characters to be appended (insertion at end) to make the string A a palindrome.

// Example Input
// Input 1:
//  A = "abede"
// Input 2:
//  A = "aabb"
// Example Output
// Output 1:
//  2
// Output 2:
//  2
// Example Explanation
// Explanation 1:
//  We can make string palindrome as "abedeba" by adding ba at the end of the string.
// Explanation 2:
//  We can make string palindrome as "aabbaa" by adding aa at the end of the string.

public class Solution {
    public int solve(String A) {
        int left = 0, right = A.length() - 1, count = 0;
        while(left < right){
            if(A.charAt(left) == A.charAt(right)){
                left++; right--;
            }
            else{
                left = ++count;
                right = A.length() - 1;
            }
        }
        return count;
    }
}