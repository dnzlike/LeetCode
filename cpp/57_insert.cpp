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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> res;
        bool done = false;
        for (auto i : intervals) {
            if (i.end < newInterval.start) res.push_back(i);
            else if (i.start == newInterval.end && !done) {
                done = true;
                res.push_back(Interval(newInterval.start, i.end));
            }
            else if (i.start > newInterval.end && !done) {
                done = true;
                res.push_back(newInterval);
                res.push_back(i);
            }
            else if (i.start > newInterval.end && done) {
                res.push_back(i);
            }
            else {
                newInterval.start = min(newInterval.start, i.start);
                newInterval.end = max(newInterval.end, i.end);
            }
        }
        if (!done) res.push_back(newInterval);
        return res;
    }
};