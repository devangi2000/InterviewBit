// Another question which belongs to the category of questions which are intentionally stated vaguely.
// Expectation is that you will ask for correct clarification or you will state your assumptions before
//  you start coding.
// Given an integer A, convert it to a roman numeral, and return a string corresponding to its roman
//  numeral version
//  Note : This question has a lot of scope of clarification from the interviewer. Please take a 
// moment to think of all the needed clarifications and see the expected response using “See Expected Output” For the purpose of this question, https://projecteuler.net/about=roman_numerals has very detailed explanations. 

// Input Format
// The only argument given is integer A.
// Output Format
// Return a string denoting roman numeral version of A.
// Constraints

// 1 <= A <= 3999
// For Example

// Input 1:
//     A = 5
// Output 1:
//     "V"

// Input 2:
//     A = 14
// Output 2:
//     "XIV"

// METHOD 1

string Solution::intToRoman(int A) {
    string res = "";
    int nums[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
    string symbols[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
    int i = 12;
    while(A > 0){
        int quo = A/nums[i];
        A = A % nums[i];
        while(quo){
            res += symbols[i];
            quo--;
        }
        i--;
    }
    return res;
}

// METHOD 2

string Solution::intToRoman(int A) {
string s = "";
int m = A / 1000;
for(int i = 1;i<=m;i++)
s += "M";
A %= 1000;
if(A >= 900)
{
    s += "CM";
    A -= 900;
}
if(A >= 500)
{
    s += "D";
    A -= 500;
}
if(A >= 400)
{
    s += "CD";
    A -= 400;
}
if(A >= 100)
{
    m = A/100;
    for(int i=1;i<=m;i++)
    s += "C";
    A %= 100;
}
if(A >= 90)
{
    s += "XC";
    A -= 90;
}
if(A >= 50)
{
    s += "L";
    A -= 50;
}
if(A >= 40)
{
    s += "XL";
    A -= 40;
}
if(A >= 10)
{
    m = A/10;
    for(int i=1;i<=m;i++)
    s += "X";
    A %= 10;
}
if(A == 9)
{
    s += "IX";
    A -= 9;
}
if(A >= 5)
{    
    s += "V";
    A -= 5;
}
if(A == 4)
s += "IV";
else if(A > 0)
{
    for(int i=1;i<=A;i++)
    s += "I";
}
return s;
}