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
    int minMeetingRooms(vector<Interval>& intervals) {
        if(! intervals.size())
            return 0;
        sort(intervals.begin() , intervals.end(),
        [](auto& x, auto& y){
            return x.start < y.start;
        });
        priority_queue<int , vector<int> , greater<int>>minHeap;
        minHeap.push(intervals[0].end);
        for(int i=1 ; i<intervals.size() ; i++)
        {
            if(intervals[i].start >= minHeap.top())
            {
                minHeap.pop();
            }
            minHeap.push(intervals[i].end);
        }
        return minHeap.size();
    }
};
