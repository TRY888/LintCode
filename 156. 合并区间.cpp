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
    /*
     * @param intervals: interval list.
     * @return: A new interval list.
     */
    // 自定义排序：从低到高
    struct compare{
        bool operator()(Interval a, Interval b)
        {
            return a.start < b.start;
        }
    };

    vector<Interval> merge(vector<Interval> &intervals) {
        // write your code here
        sort(intervals.begin(), intervals.end(), compare());
        vector<Interval> res;
        if(intervals.size()==0)
            return res;
        else if(intervals.size()==1)
            res.push_back(intervals[0]);
        else
        {
            bool ok = false;
            Interval compare = intervals[0];
            for(int i=1; i<intervals.size(); i++)
            {
                if(intervals[i].start >=compare.start &&
                   intervals[i].start <=compare.end)
                {
                    if(intervals[i].end>compare.end)
                    {
                        compare.end = intervals[i].end;
                    }
                    ok = true;
                }
                else
                {
                    res.push_back(compare);
                    compare.start = intervals[i].start;
                    compare.end = intervals[i].end;
                }
            }
            if(ok == true)
                res.push_back(compare);
        }
        return res;
    }
};
