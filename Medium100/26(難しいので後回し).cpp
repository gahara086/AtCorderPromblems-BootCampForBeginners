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
    for (int n = 1; n <= N; n++) {
        cin >> A[n];
    }

    bool zouka = false;
    bool gensho = false;
    bool not_judge = true;
    long long now = A[1];
    long long result = 0;

    long long calc[N + 1];
    for (int n = 2; n <= N; n++) {
        long long value = A[n] - A[n - 1];
        calc[n - 1] = value;
        // logint1(value);
        // if (zouka == true) {
        //     cout << "hoge" << endl;
        //     if (value >= 0) {
        //         continue;
        //     } else {
        //         result++;
        //         zouka = false;
        //         not_judge = true;
        //     }
        // }
        // if (gensho == true) {
        //     cout << "foo" << endl;
        //     if (value <= 0) {
        //         continue;
        //     } else {
        //         result++;
        //         gensho = false;
        //         not_judge = true;
        //     }
        // }
        // if (not_judge == true) {
        //     cout << "fga" << endl;
        //     if (value > 0) {
        //         zouka = true;
        //         not_judge = false;
        //     }
        //     if (value < 0) {
        //         gensho = true;
        //         not_judge = false;
        //     }
        // }
    }

    int prev_calc = calc[1];
    int prev_fugo = (prev_calc >= 0) ? 1 : -1;
    for (int n = 2; n < N; n++) {
        prev_calc = calc[n];
        int now_fugo = (prev_calc >= 0) ? 1 : -1;
        if (prev_fugo != now_fugo) {
            result++;
        }
        prev_fugo = (prev_calc >= 0) ? 1 : -1;
        
    }

    cout << result;

    return 0;
}
