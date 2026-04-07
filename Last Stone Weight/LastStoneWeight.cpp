
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if(stones.size()==1) return stones[0];

        priority_queue<int>q1;
        int pop1,pop2,diff;
        
        for(int i=0; i<stones.size();i++){
            q1.push(stones[i]);
        }
        while(q1.size()>1){
            pop1= q1.top(); q1.pop();
            pop2= q1.top(); q1.pop();
            if(pop1==pop2) continue;
            diff = pop1-pop2;
            q1.push(diff);
        }


        if(q1.size()==1) return q1.top();
        

        return 0;
    }
};
