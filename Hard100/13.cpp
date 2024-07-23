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
    string S;
    cin >> S;

    map<char, int> cnt;
    map<char, int> cnt2;
    for (int i = 0; i < N; i++) {
        cnt[S[i]] = 0;
        cnt2[S[i]] = 0;
    }

    set<string> all_case;
    set<string> temp_case;
    for (int i = 0; i < N - 2; i++) {
        string temp;
        temp = S[i];
        if (cnt[S[i]] >= 2) {
            continue;
        }
        // cnt[S[i]]++;

        for (int j = i + 1; j < N - 1; j++) {
            string temp2 = temp;
            temp2 = temp2 + S[j];
            // if (cnt2[S[j]] >= 3) {
            // continue;
            // }
            // cnt2[S[j]]++;
            if (temp_case.count(temp2)) {
                continue;
                // break;
            }
            temp_case.insert(temp2);

            for (int k = j + 1; k < N; k++) {
                string temp3 = temp2;
                temp3 = temp3 + S[k];
                // cout << temp3 << endl;
                all_case.insert(temp3);
            }
        }
    }
    long long ans = all_case.size();
    cout << ans;

    return 0;
}
