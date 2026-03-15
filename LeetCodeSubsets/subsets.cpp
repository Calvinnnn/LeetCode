#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res = {{}};  // start with empty set
        
        for (int num : nums) {
            int sz = res.size();
            for (int i = 0; i < sz; ++i) {
                vector<int> temp = res[i];
                temp.push_back(num);
                res.push_back(temp);
            }
        }
        return res;
    }
};

int main(){
    
    return 0;
}