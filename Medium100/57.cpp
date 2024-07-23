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
    int N;
    cin >> N;

    string A[N];
    vector<string> A_v;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        A_v.push_back(A[i]);
    }

    // sort
    for (int i = 0; i < N; i++) {
        string temp = A[i];
        // cout << temp << endl;
        sort(temp.begin(), temp.end());
        // cout << "sort = ";
        // cout << temp << endl;
        A[i] = temp;
    }

    // init for calc map
    map<string, long long> calc;
    for (int i = 0; i < N; i++) {
        calc[A[i]] = 0;
    }
    for (int i = 0; i < N; i++) {
        calc[A[i]]++;
    }
    // for (int i = 0; i < N; i++) {
    //     cout << A[i] << " = ";
    //     cout << calc[A[i]] << endl;
    // }

    long long ans = 0;
    auto begin = calc.begin();
    auto end = calc.end();
    for (auto iter = begin; iter != end; iter++) {
        // cout << iter->first << endl;
        // cout << iter->second << endl;
        long long num = iter->second;
        long long temp = num * (num - 1) / 2;
        ans += temp;
    }
    cout << ans;

    return 0;
}
