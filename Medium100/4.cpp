#include <bits/stdc++.h>

#include <algorithm>
#include <cmath>    // abs() for float, and fabs()
#include <cstdlib>  // abs() for integer
#include <iostream>
#include <string>

using namespace std;

bool debug_flag = true;

void log1(int n) {
    if (debug_flag) cout << "arg_1 = " << n << endl;
}
void log2(int n, int m) {
    if (debug_flag) cout << "arg_1 = " << n << "arg_2 = " << m << endl;
}
void log3(int n, int m, int l) {
    if (debug_flag)
        cout << "arg_1 = " << n << "arg_2 = " << m << "arg_3 = " << l << endl;
}

int main() {
    string S;
    cin >> S;

    string temp = S;
    int cnt = 0;
    while (true) {
        cnt++;
        temp.pop_back();
        int temp_size = temp.size();
        if (temp_size % 2 != 0) {
            continue;
        }
        // cout << "temp = " << temp << endl;
        string before_str = temp.substr(0, temp_size / 2);
        // cout << before_str << endl;
        string aftere_str = temp.substr(temp_size / 2, temp_size - 1);
        // cout << aftere_str << endl;
        if (before_str == aftere_str) {
            break;
        }
    }
    cout << temp.size();

    return 0;
}