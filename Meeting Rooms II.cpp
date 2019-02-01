/*
Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.

Example 1:
Input: [[0, 30],[5, 10],[15, 20]]
Output: 2

Example 2:
Input: [[7,10],[2,4]]
Output: 1
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
    static bool sortIntervals(Interval& int1, Interval& int2){
        return int1.start < int2.start;
    }
    int minMeetingRooms(vector<Interval>& intervals) {
        if(intervals.size() == 0)
            return 0;
        priority_queue<int, vector<int>, greater<int> > pq; 
        int rooms = 1;
        sort(intervals.begin(), intervals.end(), &sortIntervals);
        pq.push(intervals[0].end);
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i].start < pq.top())
                rooms++;
            else 
                pq.pop();
            pq.push(intervals[i].end); 
        }
        return rooms;
    }
};