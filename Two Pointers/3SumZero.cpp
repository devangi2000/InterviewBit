vector<vector<int> > Solution::threeSum(vector<int> &A) {
    sort(A.begin(), A.end());
vector<vector<int>>ans;
set<vector<int>>s;

if(A.size()<3)return ans;
for(int i=0; i<A.size()-2;i++){
    
    if(i>0&&A[i]==A[i-1]) continue;
    
    int end=A.size()-1;
    int start=i+1;
    
    while(start<end){
        long long sum=(long long)A[i]+(long long)A[start]+(long long)A[end];
        if(sum==0){
            vector<int>triplets={A[i], A[start], A[end]};
            s.insert(triplets);
            end--;
        }
        
        else if(sum>0)end--;
        
        else start++;
    }
}
for(auto i=s.begin();i!=s.end();i++)ans.push_back(*i);
return ans;
}
