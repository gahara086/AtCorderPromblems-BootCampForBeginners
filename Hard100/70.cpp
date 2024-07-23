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

// 習得するマクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = (int)(n - 1); i >= 0; i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;

// 長いのは全部短く
#define pb push_back
#define mp make_pair
#define F first
#define S second

// 打ち間違え防止
#define itn int

// 今はまだ早いマクロ
// 最大値、最小値を更新する関数
template <class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}
int N;
vector<int> A;
vector<int> B;
vector<int> C;
ll cnt;
void dfs(int n, int size) {
    if (n == 2) {
        cnt++;
        return;
    }
    if (n == 0) {
        rep(i, N) {
            if (size < B[i]) {
                dfs(n + 1, B[i]);
            } else {
                // cout << "size = " << size << " B[i] = " << B[i] << endl;
                break;
            }
        }
    }
    if (n == 1) {
        rep(i, N) {
            if (size < C[i]) {
                dfs(n + 1, C[i]);
            } else {
                // cout << "size = " << size << " C[i] = " << C[i] << endl;
                break;
            }
        }
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        A.push_back(temp);
    }
    rep(i, N) {
        int temp;
        cin >> temp;
        B.push_back(temp);
    }
    rep(i, N) {
        int temp;
        cin >> temp;
        C.push_back(temp);
    }
    sort(rall(A));
    sort(rall(B));
    sort(rall(C));

    cnt = 0;
    rep(i, N) { dfs(0, A[i]); }
    cout << cnt;

    return 0;
}
