// Given a string A representing a roman numeral.
// Convert A into integer.
// A is guaranteed to be within the range from 1 to 3999.

// NOTE: Read more
// details about roman numerals at Roman Numeric System

// Input Format
// The only argument given is string A.
// Output Format
// Return an integer which is the integer verison of roman numeral string.
// For Example

// Input 1:
//     A = "XIV"
// Output 1:
//     14

// Input 2:
//     A = "XX"
// Output 2:
//     20

int Solution::romanToInt(string A) {
    map<char,int> m;
    m['I']=1;
    m['V']=5;
    m['X']=10;
    m['L']=50;
    m['C']=100;
    m['D']=500;
    m['M']=1000;
    int ans=0, n=A.size(), i=0;
    while(i<n-1)
    {
        if(m[A[i]<m[A[i+1]]])ans-=m[A[i]];
        else ans+=m[A[i]];
        i++;
    }
    ans+=m[A[i]];
    return ans;
}


