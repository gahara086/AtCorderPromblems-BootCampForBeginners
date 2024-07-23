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
    int N;
    cin >> N;
    // int M;
    int M;
    cin >> M;

    int A[M + 1];
    int B[M + 1];
    // int A;
    // int B;
    vector<int> A_v;
    vector<int> B_v;
    pair<int, int> ship_create[M];
    map<int, int> ship[M];
    for (int i = 0; i < M; i++) {
        cin >> A[i];
        cin >> B[i];
        ship_create[i].first = A[i];
        ship_create[i].second = B[i];
    }
    sort(A, A + M);
    sort(ship_create, ship_create + M);
    for (int i = 0; i < M; i++) {
        ship[i][ship_create[i].first] = ship_create[i].second;
    }
    // calc
    int point = 1;
    bool ans = false;
    for (int i = 0; i < M; i++) {
        // cout << "ship_create[i].first  = " << ship_create[i].first << endl;
        // cout << "ship_create[i].second = " << ship_create[i].second << endl;
        if (ship_create[i].first == 1) {
            point = ship_create[i].second;
            auto itr = lower_bound(A, A + M, point);
            for (int j = itr - A; j < M; j++) {
                // cout << "ship_create[i].first  = " <<
                // ship_create[i].first
                //      << endl;
                // cout << "point = " << point << endl;
                // cout << "ship_create[i].second = " <<
                // ship_create[i].second
                //      << endl;
                // cout << "N = " << N << endl;
                if (ship_create[j].first == point &&
                    ship_create[j].second == N) {
                    ans = true;
                    break;
                }
            }
            if (ans) {
                break;
            }
        }
        if (ans) {
            break;
        }
    }

    // result
    if (ans) {
        cout << "POSSIBLE";
    } else {
        cout << "IMPOSSIBLE";
    }

    return 0;
}
