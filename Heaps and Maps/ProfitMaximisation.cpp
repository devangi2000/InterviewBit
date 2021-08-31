// Given an array A , representing seats in each row of a stadium. You need to sell tickets to B people.

// Each seat costs equal to the number of vacant seats in the row it 
// belongs to. The task is to maximize the profit by selling the tickets to B people.
// Problem Constraints
// 1 <= |A| <= 100000
// 1 <= B <= 1000000
// Input Format
// First argument is the array A.
// Second argument is integer B.
// Output Format
// Return one integer, the answer to the problem.
// Example Input
// Input 1:
// A = [2, 3]
// B = 3
// Input 2:
// A = [1, 4]
// B = 2
// Example Output
// Output 1:
// 7
// Output 2:
// 7
// Example Explanation
// Explanation 1:
//  First you serve the seat with number = 3. Then with 2 and then with 2.
//  hence answer = 3 + 2 + 2 = 7.
// Explanation 2:
//  You give bith tickets from the row with 4 seats. 4 + 3 = 7.


int Solution::solve(vector<int> &A, int B) {
    int n = A.size(), sum = 0;
    priority_queue<int> pq;
    for(auto a : A)
        pq.push(a);
    while(B-- and pq.top()!=0){
        int x = pq.top();
        pq.pop();
        sum += x;
        pq.push(x-1);
    }
    return sum;
}
