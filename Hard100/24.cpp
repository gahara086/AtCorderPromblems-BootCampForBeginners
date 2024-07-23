#include <bits/stdc++.h>

#include <algorithm>  // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <bitset>     // bitset
#include <cassert>
#include <cctype>         // isupper, islower, isdigit, toupper, tolower
#include <cstdint>        // int64_t, int*_t
#include <cstdio>         // printf
#include <deque>          // deque
#include <iostream>       // cout, endl, cin
#include <map>            // map
#include <numeric>        // gcd
#include <queue>          // queue, priority_queue
#include <set>            // set
#include <stack>          // stack
#include <string>         // string, to_string, stoi
#include <tuple>          // tuple, make_tuple
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
    int N;
    cin >> N;

    int X[N + 1];
    int L[N + 1];
    pair<int, int> robo[N + 1];
    for (int i = 0; i < N; i++) {
        cin >> X[i];
        cin >> L[i];
        robo[i].first = X[i];
        robo[i].second = L[i];
    }
    sort(robo, robo + N);

    pair<int, int> range[N + 1];
    for (int i = 0; i < N; i++) {
        range[i].first = robo[i].first + robo[i].second;
        range[i].second = robo[i].first - robo[i].second;
    }
    sort(range, range + N);

    // for (int i = 0; i < N; i++) {
    //     logint2(range[i].first, range[i].second);
    // }

    // int cnt = N;
    int cnt = 1;
    pair<int, int> prev = range[0];
    for (int i = 1; i < N; i++) {
        if (prev.first <= range[i].second) {
            prev = range[i];
            cnt++;
        }
    }
    cout << cnt;

    return 0;
}
