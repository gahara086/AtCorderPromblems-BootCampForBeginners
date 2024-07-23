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
    string S;
    cin >> S;
    string temp_s;
    int Q;
    cin >> Q;
    int q;
    bool rev_flag = false;
    pair<string, bool> for_push;
    vector<pair<string, bool>> que;
    for (int i = 0; i < Q; i++) {
        cin >> q;
        if (q == 1) {
            // reverse(S.begin(), S.end());
            rev_flag = !rev_flag;
        }
        if (q == 2) {
            cin >> q;
            cin >> temp_s;
            for_push.first = temp_s;

            if (q == 1 && rev_flag == false) {
                for_push.second = false;
                // S = temp_s + S;
            }
            if (q == 1 && rev_flag == true) {
                for_push.second = true;
                // S = S + temp_s;
            }
            if (q == 2 && rev_flag == false) {
                for_push.second = true;
                // S = S + temp_s;
            }
            if (q == 2 && rev_flag == true) {
                for_push.second = false;
                // S = temp_s + S;
            }
            que.push_back(for_push);
        }
    }
    for (int i = 0; i < que.size(); i++) {
        if (que[i].second == false) {
            S = que[i].first + S;
        } else {
            S = S + que[i].first;
        }
    }
    if (rev_flag == true) {
        reverse(S.begin(), S.end());
    }
    cout << S;

    return 0;
}
