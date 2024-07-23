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
    int H;
    cin >> H;
    int W;
    cin >> W;

    string A[H];
    string result_A[H];
    for (int i = 0; i < H; i++) {
        cin >> A[i];
        result_A[i] = A[i];
    }

    int delete_h = 0;
    // calc for H
    for (int i = 0; i < H; i++) {
        int space_num = 0;
        for (int j = 0; j < W; j++) {
            if (A[i][j] == '.') {
                space_num++;
            }
        }
        if (space_num == W) {
            logint1(space_num);
            delete_h++;
            for (int k = i; k < H - 1; k++) {
                A[k] = A[k + 1];
                // result_A[k] = A[k + 1];
            }
        }
    }
    for (int i = delete_h; i < H; i++) {
        // for (int j = 0; j < W - delete_W; j++) {
        for (int j = 0; j < W; j++) {
            cout << A[i][j];
        }
        cout << endl;
    }

    // calc for W
    int delete_W = 0;
    for (int j = 0; j < W; j++) {
        int space_num = 0;
        for (int i = 0; i < H; i++) {
            // for (int i = 0; i < H - delete_h; i++) {
            if (A[i][j] == '.') {
                space_num++;
            }
            logint1(space_num);
            // if (space_num == H) {
            //     delete_W++;
            //     // for (int k = j; k < W; k++) {
            //     for (int k = j; k < W; k++) {
            //         A[i][k - 1] = A[i][k];
            //         if (k = W - 1) {
            //             // A[i][k - 1] = '.';
            //         }
            //     }
            // }
        }
        if (space_num == H) {
            delete_W++;
            for (int i = 0; i < H; i++) {
                // for (int i = 0; i < H - delete_h; i++) {
                A[i][j] = A[i][j - 1];
                // result_A[i][j] = A[i][j - 1];
            }
        }
    }
    // cout << "-----" << endl;

    logint2(delete_h, delete_W);
    // for (int i = delete_h; i < H; i++) {
    for (int i = 0; i < H - delete_h; i++) {
        // for (int i = 0; i < H; i++) {
        for (int j = 0; j < W - delete_W; j++) {
            // for (int j = 0; j < W; j++) {
            // for (int j = delete_W; j < W; j++) {
            // for (int j = 0; j < W - ; j++) {
            cout << A[i][j];
            // cout << result_A[i][j];
        }
        cout << endl;
    }
    return 0;
}