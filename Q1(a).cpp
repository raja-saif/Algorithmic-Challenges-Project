#include <iostream>
using namespace std;

int combi(int v, int c, int** dp) {
   
    if (v <= 2) {
        return 0;
    }
    if (dp[v][c] != -1) {
        return dp[v][c];
    }
    int s = 0;
    for (int i = 1; i <= v; ++i) {
        int vp = v - i;
        int cp = c + i;
        if (cp > vp) {
            s += combi(vp, cp - vp, dp);
        }
        else if (cp == vp) {
            s += combi(cp, 0, dp);
        }
        else {
            s += 1 + combi(cp, 0, dp);
        }
    }
    dp[v][c] = s;
    return s;
}

int main() {
    int n;
    cin >> n;
    if (n < 0 || n>200)
        cout << "enter value between 0 and 200\n";
    else {
        int** dp = new int* [n + 1];
        for (int i = 0; i <= n; ++i) {
            dp[i] = new int[n + 1];
            for (int j = 0; j <= n; ++j) {
                dp[i][j] = -1;
            }
        }
        cout << combi(n, 0, dp) << endl;
    }
    return 0;
}
