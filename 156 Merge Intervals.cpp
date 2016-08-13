/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 */
class Solution {
public:
    /**
     * @param intervals: interval list.
     * @return: A new interval list.
     */
    vector<Interval> merge(vector<Interval> &intervals) {
        // write your code here
        if (intervals.size() == 0) return intervals;

        struct {
            bool operator()(const Interval &a, const Interval &b)
            {
                if (a.start != b.start) return a.start < b.start;
                return a.end < b.end;
            }
        } customLess;
        sort(intervals.begin(), intervals.end(), customLess);

        vector<Interval> result;
        Interval current = intervals[0];

        for (int i = 1; i < intervals.size(); i++) {
            if (this->haveIntersection(current, intervals[i])) {
                current = this->Intersection(current, intervals[i]);
            } else {
                result.push_back(current);
                current = intervals[i];
            }
        }
        result.push_back(current);
        return result;
    }

    bool haveIntersection(const Interval &a, const Interval &b) {
        return (a.start <= b.start && a.end >= b.start)
            || (b.start <= a.start && b.end >= a.start);
    }

    Interval Intersection(const Interval &a, const Interval &b) {
        return Interval(min(a.start, b.start), max(a.end, b.end));
    }

};
