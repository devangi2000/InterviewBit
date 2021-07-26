// Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

// Example:

// "A man, a plan, a canal: Panama" is a palindrome.

// "race a car" is not a palindrome.

// Return 0 / 1 ( 0 for false, 1 for true ) for this problem

int Solution::isPalindrome(string A) {
    string s = "";
    transform(A.begin(), A.end(), A.begin(), ::tolower);
    for(auto a: A){
        if(isalnum(a)) s+=a;
    }
    int i = 0, j = s.size()-1;
    while(i<j){
        if(s[i]!=s[j])
        return 0;
        i++;
        j--;
    }
    return 1;
}
