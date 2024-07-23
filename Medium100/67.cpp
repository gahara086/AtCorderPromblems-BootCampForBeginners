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
    string Sa;
    cin >> Sa;
    string Sb;
    cin >> Sb;
    string Sc;
    cin >> Sc;

    long long teban = 0;
    int Sa_length = Sa.length();
    int Sb_length = Sb.length();
    int Sc_length = Sc.length();
    bool flag = false;
    while (true) {
        char moji;
        switch (teban) {
            case 0:
                if (Sa.empty()) {
                    cout << 'A';
                    flag = true;
                    break;
                }
                moji = Sa[0];
                Sa.erase(0, 1);
                break;
            case 1:
                if (Sb.empty()) {
                    cout << 'B';
                    flag = true;
                    break;
                }
                moji = Sb[0];
                Sb.erase(0, 1);
                break;
            case 2:
                if (Sc.empty()) {
                    cout << 'C';
                    flag = true;
                    break;
                }
                moji = Sc[0];
                Sc.erase(0, 1);
                break;
            default:
                break;
        }

        if (flag == true) {
            break;
        }

        switch (moji) {
            case 'a':
                teban = 0;
                break;
            case 'b':
                teban = 1;
                break;
            case 'c':
                teban = 2;
                break;
            default:
                break;
        }
    }

    return 0;
}
