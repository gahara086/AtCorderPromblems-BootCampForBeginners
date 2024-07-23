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
    int A, B, C;
    cin >> A >> B >> C;

    if (A == 1) {
        cout << "YES";
        return 0;
    }
    if (B == 1) {
        cout << "NO";
        return 0;
    }
    if (A % B == 0) {
        cout << "NO";
        return 0;
    }
    if (C == 0) {
        cout << "YES";
        return 0;
    }

    bool odd_A = false;
    if (A % 2 == 0) {
        odd_A = false;
    } else {
        odd_A = true;
    }
    bool odd_B = false;
    if (B % 2 == 0) {
        odd_B = false;
    } else {
        odd_B = true;
    }
    bool odd_C = false;
    if (C % 2 == 0) {
        odd_C = false;
    } else {
        odd_C = true;
    }

    if (odd_A == true && odd_B == true) {
        cout << "YES";
        return 0;
    }
    if (odd_A == true && odd_B == false) {
        if (odd_C == false) {
            cout << "NO";
            return 0;
        } else {
            cout << "YES";
            return 0;
        }
    }
    if (odd_A == false && odd_B == true) {
        // if (odd_C == true) {
        cout << "YES";
        return 0;
        // } else {
        //     cout << "NO";
        //     return 0;
        // }
    }
    if (odd_A == false && odd_B == false) {
        if (odd_C == false) {
            cout << "YES";
            return 0;
        } else {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";

    return 0;
}