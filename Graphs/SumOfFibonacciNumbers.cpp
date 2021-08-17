// How many minimum numbers from fibonacci series are required such that sum
//  of numbers should be equal to a given Number N?
// Note : repetition of number is allowed.

// Example:

// N = 4
// Fibonacci numbers : 1 1 2 3 5 .... so on
// here 2 + 2 = 4 
// so minimum numbers will be 2 

int Solution::fibsum(int n) {
    vector<int> fib;
    fib.push_back(1);
    fib.push_back(1);
    int i = 2;
    while(fib[i-1] + fib[i-2] < n){
        fib.push_back(fib[i-1] + fib[i-2]);
        i++;
    }
    if(fib[i-1] + fib[i-2] == n)
        return 1;
    int count = 0;
    while(n > 0){
        int num = 0;
        for(int i = fib.size() - 1; i >= 0; i--){
            if(fib[i] <= n){
                num += fib[i];
                break;
            }
        }
        n -= num;
        count++;
    }
    return count;
}
