// Given a list of non negative integers, arrange them such that they form the largest number.

// For example:

// Given [3, 30, 34, 5, 9], the largest formed number is 9534330.

// Note: The result may be very large, so you need to return a string instead of an integer.

static bool cmp(string A, string B){
    return A+B > B+A;
}

string Solution::largestNumber(const vector<int> &A) {
    vector<string> v;
    string res = "";
    for(auto a : A)
        v.push_back(to_string(a));
    sort(v.begin(), v.end(), cmp);
    for(auto a: v)
        res += a;
    if(res[0] == '0') return "0";
    return res;
}