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
    if (debug_flag) cout << "arg_1 = " << n << "arg_2 = " << m << endl;
}
void logint3(int n, int m, int l) {
    if (debug_flag)
        cout << "arg_1 = " << n << "arg_2 = " << m << "arg_3 = " << l << endl;
}

void logstr1(string n) {
    if (debug_flag) cout << "arg_1 = " << n << endl;
}
void logstr2(string n, string m) {
    if (debug_flag) cout << "arg_1 = " << n << "arg_2 = " << m << endl;
}
void logstr3(string n, string m, string l) {
    if (debug_flag)
        cout << "arg_1 = " << n << "arg_2 = " << m << "arg_3 = " << l << endl;
}

int main() {
    long long H;
    cin >> H;
    long long W;
    cin >> W;
    string S[H + 1];
    for (int i = 0; i < H; i++) {
        cin >> S[i];
    }

    long long map[H + 1][W + 1];

    for (int h = 0; h <= H; h++) {
        for (int w = 0; w <= W; w++) {
            map[h][w] = 0;
        }
    }

    for (int h = 0; h <= H; h++) {
        for (int w = 0; w <= W; w++) {
            if (S[h][w] == '#') {
                if (h - 1 >= 0 && w - 1 >= 0) map[h - 1][w - 1]++;
                if (h - 1 >= 0 && w >= 0) map[h - 1][w]++;
                if (h - 1 >= 0 && w + 1 <= W) map[h - 1][w + 1]++;

                if (h >= 0 && w - 1 >= 0) map[h][w - 1]++;
                if (h >= 0 && w + 1 <= W) map[h][w + 1]++;

                if (h + 1 <= H && w - 1 >= 0) map[h + 1][w - 1]++;
                if (h + 1 <= H && w >= 0) map[h + 1][w]++;
                if (h + 1 <= H && w + 1 <= W) map[h + 1][w + 1]++;
            }
        }
    }
    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            // cout << S[h][w];
            if (S[h][w] != '#') {
                cout << map[h][w];
            } else {
                cout << S[h][w];
            }
        }
        cout << endl;
    }
    return 0;
}
