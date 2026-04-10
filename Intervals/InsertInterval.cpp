#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:

    bool overlap(vector<int>Interval, vector<int> newInterval){
        
        return (newInterval[0]>=Interval[0])&&(newInterval[0]<=Interval[1])
        ? true:false;
    }
    vector<vector<int>> merge(vector<vector<int>> intervals){

        return {{intervals[0][0],intervals[intervals.size()-1][1]}};
    }

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int length = intervals.size();
        vector<vector<int>> v1;
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end());
        for(int i=0; i<length;i++){
            if(overlap(intervals[i],newInterval)){
                v1 = merge(intervals);
            }
            else{
                return intervals;
            }
        }

        return {{}};

    }
};



int main(){


    vector<vector<int>>intervals ={{1,3},{4,6}};
    Solution s1 = Solution();
    vector<int> inserted = {2,5};
    intervals = s1.insert(intervals,inserted);
    
    return 0;
}