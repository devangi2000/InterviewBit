// Given a collection of intervals, merge all overlapping intervals.
// For example:
// Given [1,3],[2,6],[8,10],[15,18],
// return [1,6],[8,10],[15,18].
// Make sure the returned intervals are sorted.

static bool cmp(Interval a, Interval b){
    return a.start < b.start;
}

vector<Interval> Solution::merge(vector<Interval> &A) {
   vector<Interval> res;
   sort(A.begin(), A.end(), cmp);
   int n = A.size(), low = A[0].start, high = A[0].end;
   for(int i = 1; i < n; i++){
       if(A[i].start <= high){
           low = min(low, A[i].start);
           high = max(high, A[i].end);
       }
       else{
           res.push_back(Interval(low, high));
           low = A[i].start;
           high = A[i].end;
       }
   }
   res.push_back(Interval(low, high));
   return res;
}