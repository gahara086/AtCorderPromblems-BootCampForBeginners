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
    long long K;
    cin >> K;

    long long R, S, P;
    cin >> R >> S >> P;

    string T;
    cin >> T;

    char hand[N];
    char hand_NG = 'n';
    long long score = 0;
    for (int i = 0; i < T.length(); i++) {
        if (i >= K) {
            hand_NG = hand[i - K];
        }
        switch (T[i]) {
            case 'r':
                if (hand_NG == 'p') {
                    if (i + K < N) {
                        hand[i] = T[i + K];
                    } else {
                    }
                } else {
                    hand[i] = 'p';
                    score += P;
                }
                break;
            case 's':
                if (hand_NG == 'r') {
                    hand[i] = T[i + K];
                } else {
                    hand[i] = 'r';
                    score += R;
                }
                break;
            case 'p':
                if (hand_NG == 's') {
                    hand[i] = T[i + K];
                } else {
                    hand[i] = 's';
                    score += S;
                }
                break;
            default:
                break;
        }
    }
    cout << score;

    return 0;
}
