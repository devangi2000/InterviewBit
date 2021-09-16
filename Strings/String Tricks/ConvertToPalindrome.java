// Given a string A consisting only of lowercase characters, we need to check whether it is possible to 
// make this string a palindrome after removing exactly one character from this.
// If it is possible then return 1 else return 0.

// Problem Constraints
// 3 <= |A| <= 105
// A[i] is always a lowercase character.

// Input Format
// First and only argument is an string A.
// Output Format
// Return 1 if it is possible to convert A to palindrome by removing exactly one character else return 0.

// Example Input
// Input 1:
//  A = "abcba"
// Input 2:
//  A = "abecbea"
// Example Output
// Output 1:
//  1
// Output 2:
//  0

// Example Explanation
// Explanation 1:

//  We can remove character ‘c’ to make string palindrome
// Explanation 2:
//  It is not possible to make this string palindrome just by removing one character 

public class Solution {
    public int solve(String s) {
        int count = 0, left = 0, right = s.length() - 1;
        while(left <= right){
            if(s.charAt(left) == s.charAt(right)){
                left++; right--;
            }
            else{
               if(isPalindrome(s, left+1, right) || isPalindrome(s, left, right-1))
                  return 1;
                else return 0;
            } 
        }
        return s.length() % 2 != 0 ? 1 : 0;
        }
        
   private boolean isPalindrome(String s, int start, int end){
    while(start <= end){
        if(s.charAt(start++) != s.charAt(end--)) return false;
    }
    return true;
}
     
}

