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
    int N;
    int M;
    cin >> N >> M;

    int s[M + 1];
    char c[M + 1];

    for (int i = 1; i <= M; i++) {
        cin >> s[i] >> c[i];
    }
    if (M == 0) {
        s[1] = 0;
        c[1] = N;
    }

    string ans = "-1";
    int loopCnt = 0;
    if (N == 3) {
        loopCnt = 1000;
    }
    if (N == 2) {
        loopCnt = 100;
    }
    if (N == 1) {
        loopCnt = 10;
    }

    for (int i = 0; i < 1000; i++) {
        string S = to_string(i);
        if (S.length() != N) {
            continue;
        }

        bool flag = true;
        for (int j = 1; j <= M; j++) {
            if (S[s[j] - 1] != c[j]) {
                flag = false;
            }
        }
        if (N == 3 && S[0] == '0') {
            continue;
        }
        if (flag == true) {
            ans = S;
            break;
        }
    }

    cout << stoi(ans);

    return 0;
}
