#include <iostream>
#include <climits>

using namespace std;

long long val( int d[], int s, int e) {
    long long v = 0;
    for (int i = s; i < e; ++i) {
        for (int j = i + 1; j < e; ++j) {
           v += d[i] * d[j];
        }
    }
    return v;
}

long long minVal( int depo[], int n, int attacks) {
   
    long long** dp = new long long* [n + 1];
    for (int i = 0; i <= n; ++i) {
        dp[i] = new long long[attacks + 1];
    }

    for (int i = 0; i <= n; ++i) {
        dp[i][0] = val(depo, 0, i);
    }

    for (int j = 1; j <= attacks; ++j) {
        for (int i = 1; i <= n; ++i) {
            dp[i][j] = INT_MAX;
            for (int k = j; k <= i; ++k) {
                long long v = val(depo, k, i);
                dp[i][j] = min(dp[i][j], v + dp[k][j - 1]);
            }
        }
    }

    return dp[n][attacks];
   
}
int main() {
    while (true) {
        int n, attacks;
        cin >> n >> attacks;
        if (n == 0 && attacks == 0) {
            break;
        }
        int* depo = new int[n];
        for (int i = 0; i < n; i++)
            cin >> depo[i];
        long long res = minVal(depo, n, attacks);
        cout << "Minimum Value: " << res << endl;
    }

    return 0;
}