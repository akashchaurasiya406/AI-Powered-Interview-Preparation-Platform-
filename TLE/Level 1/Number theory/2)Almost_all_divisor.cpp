// method 1
// BM+chatgpt


#include <bits/stdc++.h>
using namespace std;

long long countDivisors(long long x) {
    long long ans = 1;

    for (long long p = 2; p * p <= x; p++) {
        if (x % p == 0) {
            int cnt = 0;

            while (x % p == 0) {
                x /= p;
                cnt++;
            }

            ans *= (cnt + 1);
        }
    }

    if (x > 1)
        ans *= 2;

    return ans;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<long long> d(n);

        for (auto &x : d)
            cin >> x;

        sort(d.begin(), d.end());

        long long x = d[0] * d[n - 1];            // is nothing but LCM

        bool possible = true;

        // Every given number must divide x
        for (long long val : d) {
            if (x % val != 0) {
                possible = false;
                break;
            }
        }

        // x must have exactly n + 2 divisors
        if (possible && countDivisors(x) == n + 2)
            cout << x << '\n';
        else
            cout << -1 << '\n';
    }

    return 0;
}

