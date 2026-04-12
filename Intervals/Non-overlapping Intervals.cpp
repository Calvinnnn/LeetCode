#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:


    bool overlap(vector<int> a, vector<int> b){
        if(a[0]>=b[1]) return false;
        if(a[1]<=b[0]) return false;


        return true;

    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int answer=0;
        int length = intervals.size();
        if(length==0) return 0;
        sort(intervals.begin(),intervals.end());
        int p1=0 , p2 =1;
        while(p2<length){
            if(overlap(intervals[p1],intervals[p2])){
                p2++;
                answer++;
            }
            else{
                p1 =p2;
                p2++;
            }
        }
        
        return answer;
    }
};



int main(){




    return 0;
}