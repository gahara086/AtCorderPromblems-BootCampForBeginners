#include <bits/stdc++.h>

#include <algorithm>
#include <cmath>    // abs() for float, and fabs()
#include <cstdlib>  // abs() for integer
#include <iostream>
#include <string>

using namespace std;

bool debug_flag = false;

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
    cin >> N;

    string S;
    cin >> S;

    int S_max = 0;
    for (int i = 1; i < N; i++) {
        string before = S.substr(0, i);
        string after = S.substr(i, N - 1);
        sort(before.begin(), before.end());
        sort(after.begin(), after.end());
        before.erase(unique(before.begin(), before.end()), before.end());
        after.erase(unique(after.begin(), after.end()), after.end());
        logint1(i);
        logstr2(before, after);
        int min_length = min(before.length(), after.length());
        int temp_max = 0;
        for (int j = 0; j < before.length(); j++) {
            for (int k = 0; k < after.length(); k++) {
                if (before[j] == after[k]) {
                    temp_max++;
                }
            }
        }
        S_max = max(S_max, temp_max);
    }
    cout << S_max;

    return 0;
}