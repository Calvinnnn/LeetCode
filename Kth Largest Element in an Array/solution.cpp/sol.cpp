#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <queue>
using namespace std;


class Solution {
public:

    
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>q1;
        for(int i=0;i<nums.size();i++){
            q1.push(nums[i]);
        }
        while(q1.size()!=k){
            q1.pop();
        }

        return q1.top();
    }
};


int main(){




    return 0;
}