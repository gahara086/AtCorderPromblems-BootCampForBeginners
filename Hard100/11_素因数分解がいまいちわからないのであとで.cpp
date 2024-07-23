#include <bits/stdc++.h>

#include <algorithm>  // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <bitset>     // bitset
#include <cassert>
#include <cctype>    // isupper, islower, isdigit, toupper, tolower
#include <cstdint>   // int64_t, int*_t
#include <cstdio>    // printf
#include <deque>     // deque
#include <iostream>  // cout, endl, cin
#include <map>       // map
#include <numeric>
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
int gcd(int a, int b) {
    if (a % b == 0) {
        return b;
    } else {
        return gcd(b, a % b);
    }
}
bool isPrime(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

int main() {
    long long A;
    cin >> A;
    long long B;
    cin >> B;
    // gcd_ABを素因数分解すればOK?
    // AとBを素因数分解して、共通点の数が答えになる
    long long min_AB = min(A, B);
    long long max_AB = max(A, B);
    long long gcd_AB = gcd(A, B);

    // cout << "min_AB = " << min_AB << endl;
    // cout << "gcd_AB = " << gcd_AB << endl;

    bool Deleted[gcd_AB + 1];
    for (int i = 0; i <= gcd_AB; i++) {
        Deleted[i] = false;
    }

    for (int i = 2; i * i <= gcd_AB; i++) {
        if (Deleted[i] == true) {
            continue;
        }
        for (int j = i * 2; j <= gcd_AB; j += i) {
            Deleted[j] = true;
        }
    }

    // long long array_div = [gcd_AB + 1];
    vector<int> array_div;
    for (int i = 2; i <= gcd_AB; i++) {
        if (Deleted[i] == false) {
            array_div.push_back(i);
        }
    }

    long long ans = 0;
    ans++;
    // for (const auto& e : array_div) {
    //     // cout << "e = " << e << endl;
    //     if (gcd_AB % e == 0) {
    //         ans++;
    //     }
    // }

    for (int i = 0; i < array_div.size(); i++) {
        if (gcd_AB % array_div[i] == 0) {
            ans++;
        }
    }

    // for (int i = 2; i <= gcd_AB; i++) {
    //     if (Deleted[i] == false) {
    //         ans++;
    //         cout << "i = " << i << endl;
    //     }
    // }

    // for (long long i = 2; i <= gcd_AB; i++) {
    //     if (gcd_AB % i == 0) {
    //         if (Deleted[i] == false) {
    //             ans++;
    //         }

    //         // if (isPrime(i)) {
    //         //     ans++;
    //         // }
    //         // cout << "i = " << i << endl;
    //         // cout << "Deleted[i] = " << Deleted[i] << endl;
    //         // cout << "isPrime(i) = " << isPrime(i) << endl;
    //     }
    // }
    cout << ans;

    return 0;
}
