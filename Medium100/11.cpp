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
    cin >> N;
    int M;
    cin >> M;

    long long A[N + 1];
    long long B[N + 1];
    for (int n = 1; n <= N; n++) {
        cin >> A[n] >> B[n];
    }

    long long C[M + 1];
    long long D[M + 1];
    for (int n = 1; n <= M; n++) {
        cin >> C[n] >> D[n];
    }

    int result[N + 1];
    // calc
    for (int i = 1; i <= N; i++) {
        long long min_distance = 9999999999;
        int checkpoint = 0;
        for (int j = 1; j <= M; j++) {
            long long pre_min_distance = min_distance;
            long long distance = abs(A[i] - C[j]) + abs(B[i] - D[j]);
            min_distance = min(min_distance, distance);
            if (pre_min_distance != min_distance) {
                checkpoint = j;
            }
        }
        result[i] = checkpoint;
    }

    for (int i = 1; i <= N; i++) {
        cout << result[i] << endl;
    }
    return 0;
}