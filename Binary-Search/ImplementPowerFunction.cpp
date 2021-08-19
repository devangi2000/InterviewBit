// Implement pow(x, n) % d.
// In other words, given x, n and d,

// find (xn % d)

// Note that remainders on division cannot be negative. In other words, 
// make sure the answer you return is non negative.

// Input : x = 2, n = 3, d = 3
// Output : 2

// 2^3 % 3 = 8 % 3 = 2.

int Solution::pow(int x, int n, int d) {
    if(x==0) return 0;
if(n==1 && x<0) return d+x;
if(n==1) return x;
if(n==0) return 1;
long long int ans=1;
long long h = x%d;
while(n>0)
{
    if(n&1)
        ans = (ans*h)%d;
    h = (h*h)%d;
    n /= 2;
        
}
if(ans<0) return d+ans;
return ans;
}