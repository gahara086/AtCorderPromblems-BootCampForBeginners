#include <bits/stdc++.h>

#include <algorithm>
#include <cmath>    // abs() for float, and fabs()
#include <cstdlib>  // abs() for integer
#include <iostream>
#include <string>

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
    if (S == "keyence") {
        cout << "YES";
        return 0;
    }
    const string key_result = "keyence";
    int key_num = 0;
    bool key_flag = false;

    int prev_i = 0;
    int erace_num = 0;

    // for (int i = 0; i < S.length(); i++) {
    bool result = false;
    for (int j = 0; j < S.length(); j++) {
        for (int k = 1; k < S.length() - j; k++) {
            string calc_S = S;
            int erace_length = k;
            calc_S = calc_S.erase(j, erace_length);
            // logstr1(calc_S);

            if (calc_S == key_result) {
                result = true;
                break;
            }
        }
    }
    if (result) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    // }

    // for (int i = 0; i < S.length(); i++) {
    //     // if (S[i] == 'k') {
    //     //     key_num = 0;
    //     //     prev_i = i;
    //     //     erace_num = 0;
    //     // }
    //     if (key_num >= key_result.length()) {
    //         break;
    //     }
    //     logint1(erace_num);

    //     if (S[i] == key_result[key_num]) {
    //         key_num++;
    //         int hantei = i - prev_i;
    //         // logint2(hantei, erace_num);
    //         if (hantei == erace_num) {
    //             cout << "hante==erace_num" << endl;
    //             erace_num = 0;
    //         } else if (erace_num == 0) {
    //             cout << "erace_num==0" << endl;
    //             erace_num = 0;
    //         } else {
    //             // logint2(hantei, erace_num);
    //             key_num = 0;
    //             erace_num = 0;
    //         }
    //         prev_i = i;
    //     } else {
    //         erace_num++;
    //     }
    // }
    // if (key_num >= key_result.length()) {
    //     cout << "YES";
    // } else {
    //     cout << "NO";
    // }
    return 0;
}
