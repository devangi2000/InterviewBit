// Given a string A.

// Return the string A after reversing the string word by word.

// NOTE:

// A sequence of non-space characters constitutes a word.

// Your reversed string should not contain leading or trailing spaces, even if it is present in the input string.

// If there are multiple spaces between words, reduce them to a single space in the reversed string.



// Input Format

// The only argument given is string A.
// Output Format

// Return the string A after reversing the string word by word.
// For Example

// Input 1:
//     A = "the sky is blue"
// Output 1:
//     "blue is sky the"

// Input 2:
//     A = "this is ib"
// Output 2:
//     "ib is this"


string Solution::solve(string A) {
    string res = "";
    stack<string> st;
    int i = 0, n = A.length();
    while(i < n){
        string temp = "";
        while(i < n and A[i] != ' ')
            temp += A[i++];
        if(temp!="") st.push(temp);
        i++;
    }
    while(st.size() > 1){
        res += st.top() + " ";
        st.pop();
    }
    res += st.top();
    st.pop();
    return res;
}