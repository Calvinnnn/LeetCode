#include <iostream>

#include <vector>
#include <queue>
using namespace std;

class KthLargest {
public:
    int k ;
    vector<int> nums;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        this->nums = nums;
        
    }
    
    int add(int val) {
        nums.push_back(val);
        priority_queue<int>q;
        int length = nums.size();
        for(int i =0;i<length;i++){
            q.push(nums[i]);    

        }
        for(int i=0;i<k-1;i++){
            q.pop();
        }

        return q.top();
    }
};

int main(){

    

    return 0;
}
