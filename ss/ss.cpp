#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> answer;
        auto cmp = [](vector<int>&a,vector<int>&b){
            return sqrt(pow(a[0],2)+pow(a[1],2)) > sqrt(pow(b[0],2)+pow(b[1],2));
        };
        priority_queue<vector<int>,vector<vector<int>>,decltype(cmp)>pq(cmp);

        for(int i=0; i<points.size();i++){
            pq.push(points[i]);

        }
        for(int i=0;i<k;i++){
            answer.push_back(pq.top());
            pq.pop();
        }
        return answer;
    }
};
