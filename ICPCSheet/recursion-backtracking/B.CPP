#include <iostream>

using namespace std;



int Calculate(int t) {
    if (t == 1) return 1;

    if (t % 2 == 0) {
        return 1 + Calculate(t / 2);
    } else {
        return 1 + Calculate(3 * t + 1);
    }
}



int main() {
    int t;
    cin >> t;
    cout<<Calculate(t);
    return 0;
}