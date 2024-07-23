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

    int S_l = S.length();
    // string sort_S = S;
    vector<char> sort_S;
    for (int i = 0; i < S.length(); i++) {
        sort_S.push_back(S[i]);
    }
    sort(sort_S.begin(), sort_S.end());

    // char max_word = sort_S[0];
    int cnt = 1;
    char prev_word = sort_S[0];
    int max_cnt = -1;

    for (int i = 1; i < S.length(); i++) {
        if (sort_S[i] == prev_word) {
            cnt++;
        } else {
            max_cnt = max(max_cnt, cnt);
            cnt = 1;
        }

        prev_word = sort_S[i];
    }
    // max_cnt = max(max_cnt, cnt);
    // cout << max_cnt;

    int result = 9999999;
    for (int i = 0; i < S.length(); i++) {
        string s_temp = S;
        // string next_temp = S;
        char set_s = S[i];
        int cnt = 0;
        while (true) {
            string next_temp = s_temp;
            for (int i = 0; i < S.length(); i++) {
                // if (i % 2) {
                if (s_temp[i] == set_s) {
                    next_temp[i] = set_s;
                } else if (s_temp[i + 1] == set_s) {
                    next_temp[i] = set_s;
                } else {
                    if (i - 1 >= 0) {
                        if (s_temp[i - 1] == set_s) {
                            next_temp[i] = set_s;
                        }
                    } else {
                        next_temp[i] = S[i];
                    }
                }

                // }
            }
            cout << "next_temp = " << next_temp << endl;
            s_temp = next_temp;

            bool flag = true;
            for (int i = 0; i < S.length(); i++) {
                if (set_s != s_temp[i]) {
                    flag = false;
                    break;
                }
            }
            if (flag == true) {
                break;
            }

            cnt++;
        }
        cout << "set_s = " << set_s << endl;
        cout << "cnt = " << cnt << endl;
        result = min(result, cnt);
    }
    cout << result;

    return 0;
}
