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

template <int MOD>
struct ModInt {
    static const int Mod = MOD;
    unsigned x;
    ModInt() : x(0) {}
    ModInt(signed sig) { x = sig < 0 ? sig % MOD + MOD : sig % MOD; }
    ModInt(signed long long sig) { x = sig < 0 ? sig % MOD + MOD : sig % MOD; }
    int get() const { return (int)x; }
    ModInt &operator+=(ModInt that) {
        if ((x += that.x) >= MOD) x -= MOD;
        return *this;
    }
    ModInt &operator-=(ModInt that) {
        if ((x += MOD - that.x) >= MOD) x -= MOD;
        return *this;
    }
    ModInt &operator*=(ModInt that) {
        x = (unsigned long long)x * that.x % MOD;
        return *this;
    }
    ModInt &operator/=(ModInt that) { return *this *= that.inverse(); }
    ModInt operator+(ModInt that) const { return ModInt(*this) += that; }
    ModInt operator-(ModInt that) const { return ModInt(*this) -= that; }
    ModInt operator*(ModInt that) const { return ModInt(*this) *= that; }
    ModInt operator/(ModInt that) const { return ModInt(*this) /= that; }
    ModInt inverse() const {
        long long a = x, b = MOD, u = 1, v = 0;
        while (b) {
            long long t = a / b;
            a -= t * b;
            std::swap(a, b);
            u -= t * v;
            std::swap(u, v);
        }
        return ModInt(u);
    }
    bool operator==(ModInt that) const { return x == that.x; }
    bool operator!=(ModInt that) const { return x != that.x; }
    ModInt operator-() const {
        ModInt t;
        t.x = x == 0 ? 0 : Mod - x;
        return t;
    }
};
template <int MOD>
ostream &operator<<(ostream &st, const ModInt<MOD> a) {
    st << a.get();
    return st;
};
template <int MOD>
ModInt<MOD> operator^(ModInt<MOD> a, unsigned long long k) {
    ModInt<MOD> r = 1;
    while (k) {
        if (k & 1) r *= a;
        a *= a;
        k >>= 1;
    }
    return r;
}
typedef ModInt<1000000007> mint;

// 習得するマクロ
#define rep(i, a, b) for (int i = a; i < b; i++)
#define rrep(i, a, b) for (int i = a; i >= b; i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;

// 長いのは全部短く
#define pb push_back
#define mp make_pair
#define F first
#define S second

// でかい数字
const int inf = INT_MAX / 2;
const ll infl = 1LL << 60;

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

int main() {
    // int N;
    long long N;
    cin >> N;
    // int M;
    long long M;
    cin >> M;
    // int H;
    long long H;
    cin >> H;
    // int W;
    long long W;
    cin >> W;

    string S;
    // string S[H + 1];
    cin >> S;

    long long K;
    cin >> K;

    // int A[N+1];
    long long A[N + 1];
    long long B[N + 1];
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        cin >> B[i];
    }

    return 0;
}
