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
    long long sx;
    cin >> sx;
    long long sy;
    cin >> sy;
    long long tx;
    cin >> tx;
    long long ty;
    cin >> ty;

    // 1times
    for (int i = 0; i < abs(sy - ty); i++) {
        if (ty - sy > 0) {
            cout << 'U';
        } else {
            cout << 'D';
        }
    }
    for (int i = 0; i < abs(sx - tx); i++) {
        if (tx - sx > 0) {
            cout << 'R';
        } else {
            cout << 'L';
        }
    }

    // 2tims
    for (int i = 0; i < abs(sy - ty); i++) {
        if (ty - sy > 0) {
            cout << 'D';
        } else {
            cout << 'U';
        }
    }
    for (int i = 0; i < abs(sx - tx); i++) {
        if (tx - sx > 0) {
            cout << 'L';
        } else {
            cout << 'R';
        }
    }

    // 3 times
    if (tx - sx > 0) {
        cout << 'L';
    } else if (sx - tx > 0) {
        cout << 'R';
    }
    if (ty - sy > 0) {
        cout << 'U';
    } else if (sy - ty > 0) {
        cout << 'D';
    }
    for (int i = 0; i < abs(sy - ty); i++) {
        if (ty - sy > 0) {
            cout << 'U';
        } else {
            cout << 'D';
        }
    }
    for (int i = 0; i < abs(sx - tx); i++) {
        if (tx - sx > 0) {
            cout << 'R';
        } else {
            cout << 'L';
        }
    }
    if (tx - sx > 0) {
        cout << 'R';
    } else if (sx - tx > 0) {
        cout << 'L';
    }
    if (ty - sy > 0) {
        cout << 'D';
    } else if (sy - ty > 0) {
        cout << 'U';
    }

    // 4 times
    if (tx - sx > 0) {
        cout << 'R';
    } else if (sx - tx > 0) {
        cout << 'L';
    }
    if (ty - sy > 0) {
        cout << 'D';
    } else if (sy - ty > 0) {
        cout << 'U';
    }
    for (int i = 0; i < abs(sy - ty); i++) {
        if (ty - sy > 0) {
            cout << 'D';
        } else {
            cout << 'U';
        }
    }
    for (int i = 0; i < abs(sx - tx); i++) {
        if (tx - sx > 0) {
            cout << 'L';
        } else {
            cout << 'R';
        }
    }
    if (tx - sx > 0) {
        cout << 'L';
    } else if (sx - tx > 0) {
        cout << 'R';
    }
    if (ty - sy > 0) {
        cout << 'U';
    } else if (sy - ty > 0) {
        cout << 'D';
    }

    return 0;
}
