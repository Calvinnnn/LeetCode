#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Interval {
public:
    int start, end;
    Interval(int start, int end) {
    this->start = start;
    this->end = end;
  }
};


class Solution {
public:
    bool overlap(Interval &a,Interval &b){
        if(a.start>=b.end) return false;
        if(a.end<=b.start)return false;

        return true;
    }
    bool canAttendMeetings(vector<Interval>& intervals) {
       
        sort(intervals.begin(),intervals.end(),
        [](Interval &a , Interval &b){
            return a.start<b.start && a.end<b.end;
        }
    );
        Interval v = intervals[0];
        for(int i=1; i<intervals.size();i++){
            Interval p = intervals[i];
            if(overlap(v,p)){
                return false;
            }
            else{
                v =p;

            }
        }
        

        return true;
    }
};



int main(){

    Solution s1 = Solution();
    vector<Interval> v1= {Interval(5,8),Interval(9,15)};
    cout<<s1.canAttendMeetings(v1);

    return 0;
}