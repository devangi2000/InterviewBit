// Given a set of non-overlapping intervals, insert a new interval into the intervals 
// (merge if necessary).
// You may assume that the intervals were initially sorted according to their start times.
// Example 1:
// Given intervals [1,3],[6,9] insert and merge [2,5] would result in [1,5],[6,9].
// Example 2:
// Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] would result in [1,2],[3,10],[12,16].
// This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
// Make sure the returned intervals are also sorted.

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newinterval) {
    int n = intervals.size(), begin = 0;
    vector<Interval> v;
    // First insert all intervals smaller than the start index of the newinterval
    while(begin < n and intervals[begin].end < newinterval.start)
        v.push_back(intervals[begin++]);
    // Second, merge overlapping intervals
    while(begin < n and intervals[begin].start <= newinterval.end){
        newinterval.start = min(newinterval.start, intervals[begin].start);
        newinterval.end = max(newinterval.end, intervals[begin].end);
        begin++;
    }
    v.push_back(newinterval);
    while(begin < n){
        v.push_back(intervals[begin++]);
    }
    return v;
}

