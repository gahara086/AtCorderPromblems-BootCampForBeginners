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
    long long H;
    cin >> H;
    long long W;
    cin >> W;
    long long K;
    cin >> K;

    string tempA[H + 1];
    for (int i = 0; i < H; i++) {
        cin >> tempA[i];
    }

    string A[H + 1][W + 1];
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            A[i][j] = tempA[i][j];
        }
    }

    int cnt = 1;
    // string B[H + 1];
    string B[H + 1][W + 1];
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            B[i][j] = '.';
        }
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (A[i][j] == "#") {
                B[i][j] = to_string(cnt);
                cnt++;
            }
        }
    }

    // 右
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            string temp;
            if (B[i][j] != ".") {
                temp = B[i][j];
                for (int k = j + 1; k < W; k++) {
                    if (B[i][k] == ".") {
                        B[i][k] = B[i][j];
                    } else {
                        break;
                    }
                }
            }
        }
    }

    // 左
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            string temp;
            if (B[i][j] != ".") {
                temp = B[i][j];
                for (int k = j - 1; k >= 0; k--) {
                    if (B[i][k] == ".") {
                        B[i][k] = B[i][j];
                    } else {
                        break;
                    }
                }
            }
        }
    }
    // 下
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            string temp;
            if (B[i][j] != ".") {
                temp = B[i][j];
                for (int k = i + 1; k < W; k++) {
                    if (B[k][j] == ".") {
                        B[k][j] = B[i][j];
                    } else {
                        break;
                    }
                }
            }
        }
    }
    // 上
    for (int j = 0; j < W; j++) {
        for (int i = 0; i < H; i++) {
            string temp;
            if (B[i][j] != ".") {
                temp = B[i][j];
                for (int k = i - 1; k >= 0; k--) {
                    if (B[k][j] == ".") {
                        B[k][j] = B[i][j];
                    } else {
                        break;
                    }
                }
            }
        }
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cout << B[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}
