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
    int H;
    cin >> H;
    int W;
    cin >> W;
    // string S[H];
    char S[H + 2][W + 2];
    for (int i = 0; i <= H + 1; i++) {
        for (int j = 0; j <= W + 1; j++) {
            S[i][j] = '#';
        }
    }

    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            cin >> S[i][j];
        }
    }
    bool ans = true;
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            if (S[i][j] == '#') {
                if (S[i - 1][j] != '#' && S[i][j - 1] != '#' &&
                    S[i + 1][j] != '#' && S[i][j + 1] != '#') {
                    ans = false;
                }
            }
        }
    }
    // for (int i = 0; i <= H + 1; i++) {
    //     for (int j = 0; j <= W + 1; j++) {
    //         cout << S[i][j];
    //     }
    //     cout << endl;
    // }
    if (ans == true) {
        cout << "Yes";
    } else {
        cout << "No";
    }

    return 0;
}