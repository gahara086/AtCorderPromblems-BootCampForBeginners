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
    int M;
    cin >> N;
    cin >> M;

    int P[M + 1];
    int Y[M + 1];
    set<int> city[N + 1];
    vector<int> City[N + 1];

    for (int i = 0; i < M; i++) {
        cin >> P[i];
        cin >> Y[i];
        city[P[i]].insert(Y[i]);
    }
    string id[M + 1];
    for (int i = 0; i < M; i++) {
        string temp_pre = "";
        int pre_length = 6 - to_string(P[i]).length();
        for (int j = 0; j < pre_length; j++) {
            temp_pre += '0';
        }
        temp_pre = temp_pre + to_string(P[i]);

        string temp_post = "";

        auto itr = city[P[i]].lower_bound(Y[i]);
        int cnt = distance(city[P[i]].begin(), itr) + 1;

        int post_length = 6 - to_string(cnt).length();
        for (int j = 0; j < post_length; j++) {
            temp_post += '0';
        }
        temp_post = temp_post + to_string(cnt);
        // cout << "temp_post = " << temp_post << endl;
        id[i] = temp_pre + temp_post;
    }
    for (int i = 0; i < M; i++) {
        cout << id[i] << endl;
    }

    return 0;
}
