/*
Given a collection of intervals, merge all overlapping intervals.

Example 1:
Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].

Example 2:
Input: [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    // sort intervals by the start time
    static bool sortIntervals(Interval& interval1, Interval& interval2){
        return interval1.start < interval2.start;
    }
    
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> output;
        if(intervals.size() == 0) 
            return output;
        
        sort(intervals.begin(), intervals.end(), &sortIntervals);
        output.push_back(intervals[0]);
        
        for(int i = 1; i < intervals.size(); i++){
            Interval& curr = output.back();
            if(intervals[i].start <= curr.end){     // if intervals overlap
                if(intervals[i].end > curr.end)     // if curr is included
                    curr.end = intervals[i].end;    // merge
            } else { 
                output.push_back(intervals[i]);     // no overlap
            }
        }
        return output;
    }
};