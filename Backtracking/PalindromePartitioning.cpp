// Given a string s, partition s such that every string of the partition is a palindrome.

// Return all possible palindrome partitioning of s.

// For example, given s = "aab",
// Return

//   [
//     ["a","a","b"]
//     ["aa","b"],
//   ]
//  Ordering the results in the answer : Entry i will come before Entry j if :
// len(Entryi[0]) < len(Entryj[0]) OR
// (len(Entryi[0]) == len(Entryj[0]) AND len(Entryi[1]) < len(Entryj[1])) OR
// *
// *
// *
// (len(Entryi[0]) == len(Entryj[0]) AND … len(Entryi[k] < len(Entryj[k]))
// In the given example,
// ["a", "a", "b"] comes before ["aa", "b"] because len("a") < len("aa")

vector<vector<string>> res;
bool isPalindrome(string s){
    int start = 0, end = s.size()-1;
    while(start <= end){
        if(s[start++] != s[end--])
            return false;
    }
    return true;
}

void solve(int start, string s, vector<string> &path){
    if(start == s.size()){
        res.push_back(path);
        return;
    }
    for(int i = start; i < s.size(); i++){
        string temp = s.substr(start, i-start+1);
        if(isPalindrome(temp)){
            path.push_back(temp);
            solve(i+1, s, path);
            path.pop_back();
        }
    }
}

vector<vector<string> > Solution::partition(string s) {
    vector<string> path;
    res.clear();
    solve(0, s, path);
    return res;
}
