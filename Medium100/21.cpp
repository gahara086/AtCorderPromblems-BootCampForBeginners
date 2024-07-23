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
    cin >> N;

    long long A[N + 1];
    long long cnt[N + 1];
    long long result[N + 1];
    for (long long n = 0; n <= N; n++) {
        cnt[n] = 0;
        result[n] = 0;
    }
    for (long long n = 1; n <= N; n++) {
        cin >> A[n];
        cnt[A[n]]++;
    }
    long long calc_combi[N + 1];
    long long calc_combi_minus[N + 1];
    long long sum = 0;
    for (long long n = 1; n <= N; n++) {
        calc_combi[n] = cnt[n] * (cnt[n] - 1) / 2;
        calc_combi_minus[n] = (cnt[n] - 1) * (cnt[n] - 2) / 2;
        // logint2(calc_combi[n], calc_combi_minus[n]);
        sum += cnt[n] * (cnt[n] - 1) / 2;
        // logint1(cnt[A[n]]);
    }
    // logint1(sum);

    for (long long i = 1; i <= N; i++) {
        long long temp_sum = sum;
        temp_sum -= cnt[A[i]] * (cnt[A[i]] - 1) / 2;
        temp_sum += (cnt[A[i]] - 1) * (cnt[A[i]] - 2) / 2;
        result[i] = temp_sum;
    }
    for (long long i = 1; i <= N; i++) {
        cout << result[i] << endl;
    }
    return 0;
}
