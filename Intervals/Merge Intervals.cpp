#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    bool overlap(vector<int> a, vector<int> b){
        if(b[0]>a[1]){
            return false;
        }
        if(b[1]<a[0]){
            return false;

        }
        return true;
    }
    vector<int> mergeOverlapedIntervals(vector<int> a, vector<int>b){
        return {min(a[0],b[0]),max(a[1],b[1])};
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size()==1) return {intervals[0]};
        vector<vector<int>> result;
        
        sort(intervals.begin(),intervals.end());
        vector<int> v1 = intervals[0];
        
        for(int i=1; i<intervals.size();i++){
            vector<int> p = intervals[i];
            if(overlap(v1,p)){
                v1 = mergeOverlapedIntervals(v1,p);

            }
            else{
                result.push_back(v1);
                v1 = p;
            }

        }
        result.push_back(v1);
        return result;
    }
};

int main(){




    return 0;
}