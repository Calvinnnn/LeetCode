#include <cmath>
#include <iostream>
#include <math.h>

using namespace std;



void  weird(long long n) {
    cout<<n<<" ";
    if (n==1) return;
    if (n%2==0) {
        weird(n/2);
    }
    else {
        weird(n*3+1);
    }
}



int main() {
    long long  n;
    cin>>n;
    weird(n);

    return 0;
}