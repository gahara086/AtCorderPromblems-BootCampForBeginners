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
    int R;
    int G;
    int B;
    int N;
    cin >> R >> G >> B >> N;

    int loop_R = N / R;
    int loop_G = N / G;
    int loop_B = N / B;

    int cnt = 0;
    for (int i = 0; i <= loop_R; i++) {
        if (i * R == N) {
            cnt++;
            break;
        }
        if (i * R > N) {
            break;
        }
        for (int j = 0; j <= loop_G; j++) {
            if (i * R + j * G == N) {
                cnt++;
                break;
            }
            if (i * R + j * G > N) {
                break;
            }
            int sum = i * R + j * G;
            int temp = N - sum;
            if (temp % B == 0) {
                cnt++;
            }
        }
    }

    cout << cnt;

    return 0;
}