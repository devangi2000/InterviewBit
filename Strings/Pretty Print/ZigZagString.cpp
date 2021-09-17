// The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

// P.......A........H.......N
// ..A..P....L....S....I...I....G
// ....Y.........I........R
// And then read line by line: PAHNAPLSIIGYIR
// Write the code that will take a string and make this conversion given a number of rows:

// string convert(string text, int nRows);
// convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR"
// **Example 2 : **
// ABCD, 2 can be written as

// A....C
// ...B....D
// and hence the answer would be ACBD.

string Solution::convert(string A, int B) {
    if(B == 1) return A;
    string res = "";
    for(int i = 0; i < B; i++){
        int increment = 2 * (B-1);
        for(int j = i; j < A.size(); j+=increment){
            res += A[j];
            if(i > 0 and i < B-1 and j+increment-2*(i) < A.size()){
                res += A[j+increment-(2*i)];
            }
        }
    }
    return res;
}
