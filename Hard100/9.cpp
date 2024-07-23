#include <bits/stdc++.h>

#include <algorithm>  // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <bitset>     // bitset
#include <cctype>     // isupper, islower, isdigit, toupper, tolower
#include <cstdint>    // int64_t, int*_t
#include <cstdio>     // printf
#include <deque>      // deque
#include <iostream>   // cout, endl, cin
#include <map>        // map
#include <queue>      // queue, priority_queue
#include <set>        // set
#include <stack>      // stack
#include <string>     // string, to_string, stoi
#include <tuple>      // tuple, make_tuple
#include <unordered_map>  // unordered_map
#include <unordered_set>  // unordered_set
#include <utility>        // pair, make_pair
#include <vector>         // vector
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
    // int N;
    long long N;
    cin >> N;
    // int M;
    long long M;
    cin >> M;

    // int A[N+1];
    string A[N + 1];
    vector<string> A_v;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        A_v.push_back(A[i]);
    }

    string B[M + 1];
    vector<string> B_v;
    for (int i = 0; i < M; i++) {
        cin >> B[i];
        B_v.push_back(B[i]);
    }

    long long A_N = A[0].length();
    long long B_N = B[0].length();

    for (int i = 0; i < N; i++) {
        for (int a_n = 0; a_n < A_N; a_n++) {
            if (A[i][a_n] == B[0][0]) {
                bool ok = true;
                for (int j = 0; j < M; j++) {
                    for (int b_n = 0; b_n < B_N; b_n++) {
                        if (A[i + j][a_n + b_n] != B[j][b_n]) {
                            ok = false;
                            break;
                        }
                    }
                    if (ok == false) {
                        break;
                    }
                }
                if (ok == true) {
                    cout << "Yes";
                    return 0;
                }
            }
        }
    }
    cout << "No";

    return 0;
}
