class Solution {
public:

    bool overlappingInterval(vector<int> interval1, vector<int> interval2){
        return interval1[1] > interval2[0];  // intersection is not an overlappping
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // sort according to the first element
        // traverse this sorted array of pairs, i -> 1 to n-1
        // at each i, check if overlapping with prev taken pair
        // if yes, then take the one which have min 2nd element among prev, curr
        // if no, take the curr
        sort(intervals.begin(), intervals.end());
        vector<int> previousInterval = intervals[0];
        int excludedIntervals = 0;
        for(int i=1; i<intervals.size(); i++){
            vector<int> currentInterval = intervals[i];
            if(overlappingInterval(previousInterval, currentInterval)){
                excludedIntervals++;
                if(previousInterval[1] > currentInterval[1]){
                    previousInterval = currentInterval;
                }
            }else{
                previousInterval = currentInterval;
            }
        }
        return excludedIntervals;
    }
};