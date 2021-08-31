// Given a 2D binary matrix filled with 0’s and 1’s, find the largest rectangle containing all 
// ones and return its area.
// Bonus if you can solve it in O(n^2) or less.
// Example :
// A : [  1 1 1
//        0 1 1
//        1 0 0 
//     ]
// Output : 4 
// As the max area rectangle is created by the 2x2 rectangle created by (0,1), (0,2), (1,1) and (1,2)


int largestRectangle(vector<int> &heights){
    stack<pair<int, int>> st, st2;
    vector<int> nsl, nsr;
    for(int i=0; i < heights.size(); i++){
        if(st.empty()) nsl.push_back(-1);
        else if(!st.empty() and heights[i] <= st.top().first){
            while(!st.empty() and heights[i] <= st.top().first)
                st.pop();
            if(st.empty()) nsl.push_back(-1);
            else nsl.push_back(st.top().second);
        }
        else nsl.push_back(st.top().second);
        st.push({heights[i], i});
    }
    
    for(int i = heights.size()-1; i >= 0; i--){
        if(st2.empty()) nsr.push_back(heights.size());
        else if(!st2.empty() and heights[i] <= st2.top().first){
            while(!st2.empty() and heights[i] <= st2.top().first)
                st2.pop();
            if(st2.empty()) nsr.push_back(heights.size());
            else nsr.push_back(st2.top().second);
        }
        else nsr.push_back(st2.top().second);
        st2.push({heights[i], i});
    }
    reverse(nsr.begin(), nsr.end());
    int ans = INT_MIN;
    for(int i = 0; i < nsl.size(); i++){
        ans = max(ans, heights[i]*(nsr[i]-nsl[i]-1));
    }
    return ans;
}

int Solution::maximalRectangle(vector<vector<int> > &A) {
    int n = A.size();
    vector<int> hist(A[0].size());
    hist = A[0];
    int ans = largestRectangle(hist);
    for(int i = 1; i < A.size(); i++){
        for(int j = 0; j < A[i].size(); j++){
            hist[j] = ((A[i][j] == 0) ? 0 : 1 + hist[j]);
        }
        ans = max(ans, largestRectangle(hist));
    }
    return ans;
}