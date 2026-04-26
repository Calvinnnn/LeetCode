#include <cmath>
#include <iostream>
#include <math.h>

using namespace std;



long long power(long long n, long long m) {

    if (m==1) return n;

    return  n * pow(n, m-1);
}

long long calcululate_mod_power(long long n,long long m) {
    return power(n,m) % 1000000007;
}



int main() {
    long long n,m;
    cin >> n>>m;
    cout<<calcululate_mod_power(n,m);

    return 0;
}