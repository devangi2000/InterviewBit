// You are given two positive integers A and B. For all permutations of [1, 2, …, A], we create a BST.
//  Count how many of these have height B.
// Notes:
// Values of a permutation are sequentially inserted into the BST by general rules i.e in increasing
//  order of indices.
// Height of BST is maximum number of edges between root and a leaf.
// Return answer modulo 109 + 7.
// Expected time complexity is worst case O(N4).
// 1 ≤ N ≤ 50
// For example,
// A = 3, B = 1
// Two permutations [2, 1, 3] and [2, 3, 1] generate a BST of height 1.
// In both cases the BST formed is
//     2
//    / \
//   1   3  
// Another example,
// A = 3, B = 2
// Return 4.
// Next question, can you do the problem in O(N3)?

#define MOD 1000000007ll
typedef long long LL;

//adds y to x, modulo MOD
void add(int &x, int y){
    x += y;
    if(x>=MOD)x-=MOD;
}

//choose and dp tables
vector< vector<int > > choose,dp;

//build choose table
void build(int N){
    choose[0][0]=1;
    for(int i=1; i<=2*N; i++){
        choose[i][0]=1;
        for(int j=1; j<=i; j++){
            choose[i][j]=choose[i-1][j];
            add(choose[i][j], choose[i-1][j-1]);
        }
    }
}

//reccurence function as defined in hint_2
int rec(int n, int h){ 
    if(n<=1)return (h==0);
    if(h<0)return 0;
    int &ret=dp[n][h];
    if(ret!=-1)return ret;
    ret=0;
    int x, y;
    for(int i=1; i<=n; i++){
        x=i-1;
        y=n-x-1;
        int sum1=0,sum2=0,ret1=0;
        for(int j=0; j<=h-2; j++){
            add(sum1, rec(x, j));
            add(sum2, rec(y, j));
        }
        add(ret1, ((LL)sum1*(LL)rec(y, h-1))%MOD);
        add(ret1, ((LL)sum2*(LL)rec(x, h-1))%MOD);
        add(ret1, ((LL)rec(x, h-1)*(LL)rec(y, h-1))%MOD);
        ret1 = ((LL)ret1*(LL)choose[x+y][y])%MOD;
        add(ret, ret1);
    }
    return ret;
}

int Solution::cntPermBST(int A, int B) {
    int n=50;
    choose.clear();
    dp.clear();
    choose.resize(2*n+1,vector<int>(2*n+1, 0));
    dp.resize(n+1,vector<int>(n+1, -1));
    build(n);
    return rec(A, B);
}

// OR

using ll = long long;
const int kMod = 1e9 + 7;
struct ModInt {
	long long n;
	ModInt(long long n = 0) : n(n % kMod) {}
	ModInt operator+(const ModInt& oth) { return n + oth.n; }
	ModInt operator-(const ModInt& oth) { return n - oth.n; }
	ModInt operator*(const ModInt& oth) { return n * oth.n; }
	long long get() { return n < 0 ? n + kMod : n; }
	friend ostream& operator<<(ostream& os, ModInt const& a) { return os << ModInt(a.n).get(); }
};
ModInt lgpow(ModInt b, int e = -1) {
	if (b.get() == 0) return 0;
	ModInt r; e = e % (kMod - 1);
	if (e < 0) e += kMod - 1;
	for (r = 1; e; e >>= 1, b = b * b)
		if (e & 1) r = r * b;
	return r;
}
vector<ModInt> fact, invfact;
void factorials(int n) {
    if (fact.size() > 1) return;
	fact.resize(n + 1, 1);
	invfact.resize(n + 1, 1);
	for (int i = 1; i <= n; ++i)
		fact[i] = fact[i - 1] * i;
	invfact[n] = lgpow(fact[n]);
	for (int i = n - 1; i >= 1; --i)
		invfact[i] = invfact[i + 1] * (i + 1);
}
ModInt choose(int n, int k) {
	return fact[n] * invfact[k] * invfact[n - k];
}
using vi = vector<int>;
const int N = 105;
vector<vi> dp(N, vi(N, -1));
ModInt solve(int n, int h) {
    if (n <= 1) return (h == 0);
    if (dp[n][h] != -1) return dp[n][h];
    ModInt ans = 0;
    for (int i = 0; i < n; i++) {
        ModInt res = 0;
        for (int j = 0; j < h - 1; j++) {
            res = res + solve(i, j) * solve(n - i - 1, h - 1);
            res = res + solve(n - i - 1, j) * solve(i, h - 1);
        }
        res = res + solve(i, h - 1) * solve(n - i - 1, h - 1);
        ans = ans + choose(n - 1, i) * res;
    }
    return dp[n][h] = ans.get();
}
int Solution::cntPermBST(int n, int h) {
    factorials(N);
    ModInt ans = solve(n, h);
    return ans.get();
}