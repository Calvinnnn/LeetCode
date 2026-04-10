#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:

    bool overlap(vector<int> Interval, vector<int> newInterval){
        return (Interval[0] <= newInterval[1] && newInterval[0] <= Interval[1]);
    }

    vector<int> merge(vector<int> a, vector<int> b){
        return {min(a[0], b[0]), max(a[1], b[1])};
    }

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> result;
        vector<int> current = intervals[0];

        for(int i = 1; i < intervals.size(); i++){
            if(overlap(current, intervals[i])){
                current = merge(current, intervals[i]);
            } else {
                result.push_back(current);
                current = intervals[i];
            }
        }

        result.push_back(current);
        return result;
    }
};


int main(){


    vector<vector<int>>intervals ={{1,3},{4,6}};
    Solution s1 = Solution();
    vector<int> inserted = {2,5};
    intervals = s1.insert(intervals,inserted);
    
    return 0;
}