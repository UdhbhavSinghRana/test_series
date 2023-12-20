#include <iostream>
#include <string>
using namespace std;

int main() {
    int a;
    int b;
    cin >> a; // 110
    cin >> b; // 001
    int count = 0;
    int xorRes = a ^ b;
    while (xorRes) {
        count += xorRes & 1;
        xorRes >>= 1;
    }
    cout << count;
    return 0;
}
