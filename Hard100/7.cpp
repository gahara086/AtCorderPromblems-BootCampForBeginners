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

    long long A[N + 1];
    // Aは昇順ソート
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    // BCは降順ソートする
    vector<pair<int, int>> BC;
    long long B[M + 1];
    long long C[M + 1];
    for (int i = 0; i < M; i++) {
        cin >> B[i];
        cin >> C[i];
        pair<int, int> temp;
        temp.first = C[i];
        temp.second = B[i];
        BC.push_back(temp);
    }

    sort(A, A + N);
    sort(BC.rbegin(), BC.rend());

    // cout << "-------" << endl;
    // for (int i = 0; i < N; i++) {
    //     cout << "A[i] = " << A[i] << endl;
    // }

    long long cnt = 0;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < BC[i].second; j++) {
            // if (BC[i].first > A[j]) {
            if (BC[i].first > A[cnt]) {
                // A[j] = BC[i].first;
                A[cnt] = BC[i].first;
                cnt++;
            } else {
                break;
            }
        }
    }

    // cout << "-------" << endl;
    // for (int i = 0; i < N; i++) {
    //     cout << "A[i] = " << A[i] << endl;
    // }
    // cout << "-------" << endl;

    long long sum = 0;
    for (int i = 0; i < N; i++) {
        sum += A[i];
    }
    cout << sum;

    return 0;
}
