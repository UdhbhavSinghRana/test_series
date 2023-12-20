#include <iostream>
#include <string>
#include <cmath>
using namespace std;

string half_left(string x) {
    string left = "";
    for (int i = x.size() - 1; i >= x.size() / 2; i--) {
        left += x[i];
    }
    return left;
}

string half_right(string y) {
    string right = "";
    for (int i = 0; i < y.size() / 2; i++) {
        right += y[i];
    }
    return right;
}


long long Algo (string A, string B) {
   if (A.size() == 0) return 0;
   if (A.size() == 1) {
       int a = stoi(A);
       int b = stoi(B);
       return a * b;
   }
   string A_left = half_left(A); // 1
   string A_right = half_right(A); // 1

   string B_left = half_left(B); // 0
   string B_right = half_right(B); // 1

   long long X = Algo(A_left, B_left); // 0
   long long Y = Algo(A_left + A_right, B_right + B_left); // what is this? 
   long long Z = Algo(A_right, B_right); // 1

   long long ans = pow(2, A.size()) * X + pow(2, A.size() / 2) * (Y - (stoi(A_left) + stoi(A_right)) - Z) + Z;
   return ans;
}

long long karatsubaAlgo(string A, string B) { // 11 01
    if (A.size() > B.size()) {
        int diff = A.size() - B.size();
        string add = "";
        while (diff >= 0) {
            add += '0';
            diff--;
        }
        add += B;
        B = add;
    }
    if (B.size() > A.size()) {
        int diff = B.size() - A.size();
        string add = "";
        while (diff >= 0) {
            add += '0';
            diff--;
        }
        add += A;
        A = add;
    }
    return Algo(A, B);
}
int main() {
    string num1, num2;
    cout << "Enter the first number: ";
    cin >> num1;
    cout << "Enter the second number: ";
    cin >> num2;

    long long result = karatsubaAlgo(num1, num2);
    cout << "The product of " << num1 << " and " << num2 << " is: " << result << endl;

    return 0;
}          
