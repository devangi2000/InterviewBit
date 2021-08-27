// Given a non-negative number represented as an array of digits, add 1 to the number 
// ( increment the number represented by the digits ).
// The digits are stored such that the most significant digit is at the head of the list.
// NOTE: Certain things are intentionally left unclear in this question which you should 
// practice asking the interviewer. For example: for this problem, following are some good
//  questions to ask :
// Q : Can the input have 0's before the most significant digit. Or in other words, is 0 1 2 3
//  a valid input?
// A : For the purpose of this question, YES
// Q : Can the output have 0's before the most significant digit? Or in other words, is 0 1 2 4 a
//  valid output?
// A : For the purpose of this question, NO. Even if the input has zeroes before the most significant
//  digit.
// Input Format
// First argument is an array of digits.
// Output Format
// Return the array of digits after adding one.
// Example Input
// Input 1:
// [1, 2, 3]
// Example Output
// Output 1:
// [1, 2, 4]
// Example Explanation
// Explanation 1:
// Given vector is [1, 2, 3].
// The returned vector should be [1, 2, 4] as 123 + 1 = 124.


// THIS WORKS IN LEETCODE BUT NOT INTERVIEWBIT
vector<int> Solution::plusOne(vector<int> &digits) {
    int i = digits.size()-1;
    while(i >= 0){
        if(digits[i] == 9)
            digits[i] = 0;
        else{
            digits[i]++;
            return digits;
        }
        i--;
    }
    digits.insert(digits.begin(), 1);
    return digits;
}


// CARRY CHAIN LOGIC: Works

vector<int> Solution::plusOne(vector<int> &a) {
int n = a.size();0;
int carry = 1;

for(int i=n-1; i>=0; i--)
{
        int temp = a[i] + carry;
        a[i] = temp%10;
        carry = temp/10;
}
if(!carry){
    while(a[0]==0)
    {
        a.erase(a.begin());
    }
}
else{
    a.insert(a.begin(),1);
}
return a;
}