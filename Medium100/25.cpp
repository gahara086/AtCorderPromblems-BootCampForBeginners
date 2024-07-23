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
    long long N;
    long long K;
    cin >> N;
    cin >> K;

    long long A[N + 1];
    long long cnt[N + 1];
    long long ball_kind = 0;
    vector<long long> cnt_v;
    for (int n = 0; n <= N; n++) {
        cnt[n] = 0;
    }
    for (int n = 1; n <= N; n++) {
        cin >> A[n];
        cnt[A[n]]++;
    }
    for (int n = 0; n <= N; n++) {
        if (cnt[n] > 0) {
            ball_kind++;
        }
    }
    for (int n = 1; n <= N; n++) {
        cnt_v.push_back(cnt[n]);
    }

    // calc
    sort(cnt_v.begin(), cnt_v.end());

    long long delete_num = ball_kind - K;
    long long cnt_delete = 0;
    long long result = 0;
    for (int n = 1; n <= N; n++) {
        if (cnt_v[n] > 0) {
            cnt_delete++;
            result += cnt_v[n];
        }
        if (cnt_delete >= delete_num) {
            break;
        }
    }
    cout << result;

    return 0;
}
