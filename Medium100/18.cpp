#include <bits/stdc++.h>

#include <algorithm>
#include <cmath>    // abs() for float, and fabs()
#include <cstdlib>  // abs() for integer
#include <iostream>
#include <string>

using namespace std;

bool debug_flag = true;

void logint1(int n) {
    if (debug_flag) cout << "arg_1 = " << n << endl;
}
void logint2(int n, int m) {
    if (debug_flag) cout << "arg_1 = " << n << " arg_2 = " << m << endl;
}
void logint3(int n, int m, int l) {
    if (debug_flag)
        cout << "arg_1 = " << n << " arg_2 = " << m << " arg_3 = " << l << endl;
}

void logstr1(string n) {
    if (debug_flag) cout << "arg_1 = " << n << endl;
}
void logstr2(string n, string m) {
    if (debug_flag) cout << "arg_1 = " << n << " arg_2 = " << m << endl;
}
void logstr3(string n, string m, string l) {
    if (debug_flag)
        cout << "arg_1 = " << n << " arg_2 = " << m << " arg_3 = " << l << endl;
}

int main() {
    int c[3][3];
    int sum = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> c[i][j];
            sum += c[i][j];
        }
    }

    bool flag = true;
    if (sum % 3 != 0) {
        flag = false;
    }

    int temp_sum = c[0][0] + c[1][1] + c[2][2];
    if (temp_sum * 3 != sum) {
        flag = false;
    }

    // int cnt = 0;
    // for (int i = 0; i < 3; i++) {
    //     int temp_sum = 0;
    //     for (int j = 0; j < 3; j++) {
    //         temp_sum += c[i][j];
    //     }
    //     if (temp_sum == 0) {
    //         cnt++;
    //     }
    // }
    // for (int j = 0; j < 3; j++) {
    //     int temp_sum = 0;
    //     for (int i = 0; i < 3; i++) {
    //         temp_sum += c[i][j];
    //     }
    //     if (temp_sum == 0) {
    //         cnt++;
    //     }
    // }
    // if (cnt != 0 && cnt % 2 == 0) {
    //     flag = false;
    // }

    if (flag) {
        cout << "Yes";
    } else {
        cout << "No";
    }

    return 0;
}
