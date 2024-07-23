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
    // int N;
    long long N;
    cin >> N;

    long long A[N + 1];
    vector<long long> A_v;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        A_v.push_back(A[i]);
    }

    // calc
    map<long long, long long> same_cnt_odd;
    map<long long, long long> same_cnt_even;
    for (int i = 0; i < N; i++) {
        same_cnt_odd[A[i]] = 0;
        same_cnt_even[A[i]] = 0;
    }

    for (int i = 0; i < N; i = i + 2) {
        same_cnt_even[A[i]]++;
    }
    auto begin_even = same_cnt_even.begin();
    auto end_even = same_cnt_even.end();
    long long max_even_cnt = 0;
    long long second_even_cnt = 0;
    long long max_even = -1;
    for (auto iter = begin_even; iter != end_even; iter++) {
        // cout << iter->first << endl;
        // cout << iter->second << endl;
        long long temp = max_even_cnt;
        // max_even_cnt = max(max_even_cnt, iter->second);
        if (iter->second > max_even_cnt) {
            second_even_cnt = max_even_cnt;
            max_even_cnt = iter->second;
        } else if (second_even_cnt < iter->second) {
            second_even_cnt = iter->second;
        }
        if (second_even_cnt < max_even_cnt) {
            // second_even_cnt = max(second_even_cnt, iter->second);
        }
        if (temp != max_even_cnt) {
            // second_even_cnt = temp;
        }
        if (max_even_cnt == iter->second) {
            max_even = iter->first;
        }
    }

    for (int i = 1; i < N; i = i + 2) {
        same_cnt_odd[A[i]]++;
    }
    auto begin_odd = same_cnt_odd.begin();
    auto end_odd = same_cnt_odd.end();
    long long max_odd_cnt = 0;
    long long second_odd_cnt = 0;
    long long max_odd = -1;
    for (auto iter = begin_odd; iter != end_odd; iter++) {
        // cout << iter->first << ' ';
        // cout << iter->second << endl;
        long long temp = max_odd_cnt;
        // max_odd_cnt = max(max_odd_cnt, iter->second);
        if (iter->second > max_odd_cnt) {
            second_odd_cnt = max_odd_cnt;
            max_odd_cnt = iter->second;
        } else if (second_odd_cnt < iter->second) {
            second_odd_cnt = iter->second;
        }

        if (second_odd_cnt < max_odd_cnt) {
            // second_odd_cnt = max(second_odd_cnt, iter->second);
        }
        if (temp != max_odd_cnt) {
            // second_odd_cnt = temp;
        }
        if (max_odd_cnt == iter->second) {
            max_odd = iter->first;
        }
    }

    logint2(max_even, max_odd);
    logint2(max_even_cnt, max_odd_cnt);
    logint2(second_even_cnt, second_odd_cnt);

    long long ans = 0;
    if (max_even == max_odd) {
        long long temp_ans = 0;
        temp_ans += (N / 2) - second_even_cnt;
        temp_ans += (N / 2) - max_odd_cnt;
        long long temp_ans_2 = 0;
        temp_ans_2 += (N / 2) - max_even_cnt;
        temp_ans_2 += (N / 2) - second_odd_cnt;
        ans = min(temp_ans, temp_ans_2);
    } else {
        ans += (N / 2) - max_even_cnt;
        ans += (N / 2) - max_odd_cnt;
    }
    cout << ans;

    return 0;
}
