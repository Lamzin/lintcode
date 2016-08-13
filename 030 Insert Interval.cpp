/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */
class Solution {
public:
    /**
     * Insert newInterval into intervals.
     * @param intervals: Sorted interval list.
     * @param newInterval: new interval.
     * @return: A new interval list.
     */
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // write your code here
        vector<Interval> result;

        int i = 0;
        for (; i < intervals.size() && intervals[i].end < newInterval.start; i++) {
            result.push_back(intervals[i]);
        }

        for (; i < intervals.size() && this->haveIntersection(intervals[i], newInterval); i++) {
            if (intervals[i].start < newInterval.start) {
                newInterval.start = intervals[i].start;
            }
            if (intervals[i].end > newInterval.end) {
                newInterval.end = intervals[i].end;
            }
        }
        result.push_back(newInterval);

        for (; i < intervals.size(); i++) {
            result.push_back(intervals[i]);
        }

        return result;
    }

    bool haveIntersection(Interval &a, Interval &b) {
        return (a.start <= b.start && a.end >= b.start)
            || (b.start <= a.start && b.end >= a.start);
    }
};
