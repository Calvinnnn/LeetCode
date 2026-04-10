#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;


class MedianFinder {
public:
    vector<int>v1;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        v1.push_back(num);
        sort(v1.begin(),v1.end());
    }
    
    double findMedian() {
        if(v1.size()%2==0){
            int middle_index = floor((v1[0]+v1[v1.size()-1])/2);
            int middle = v1[middle_index -1];
            return (middle+v1[middle_index])/2;
        }
        else{
            int middle_index = v1.size()/2;
            return v1[middle_index];
        }
    }
};



int main(){

    MedianFinder medianFinder = MedianFinder();
    medianFinder.addNum(1);    // arr = [1]
    cout<<medianFinder.findMedian()<<endl; // return 1.0
    medianFinder.addNum(3);    // arr = [1, 3]
   cout<<medianFinder.findMedian()<<endl; // return 2.0
    medianFinder.addNum(2);    // arr[1, 2, 3]
    cout<<medianFinder.findMedian()<<endl; // return 2.0


    return 0;
}