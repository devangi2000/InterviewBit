// You are given an integer N. You have to find smallest multiple of N 
// which consists of digits 0 and 1 only. Since this multiple could be 
// large, return it in form of a string.

// Note:

// Returned string should not contain leading zeroes.
// For example,

// For N = 55, 110 is smallest multiple consisting of digits 0 and 1.
// For N = 2, 10 is the answer.

string Solution::multiple(int N) {
    if(N==1) return "1";
    // parent state
    vector<int> parent(N, -1);
    // step from parent to current
    vector<int> steps(N, -1);
    int options[2] = {0, 1};
    // BFS
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        if(curr == 0) break;
        for(int option : options){
            int next = (curr * 10 + option) % N;
            if(parent[next] == -1){
                parent[next] = curr;
                steps[next] = option;
                q.push(next);
            }
        }
    }
    
    string number;
    for(int it = 0; it != 1; it = parent[it])
        number.push_back('0'+steps[it]);
    number.push_back('1');
    reverse(number.begin(), number.end());
    return number;
}

   