#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 998244353;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        vector<array<ll, 4>> D(3 * N + 5);
        ll Ans = (N + 1LL * N * (N - 1) / 2) % MOD;
        for (int i = 0, X; i < N; i++) {
            cin >> X, X += 2;
            auto &P = D[X - 1], &Q = D[X - 2];
            ll C = P[0] * (1 + P[1]) % MOD, K = P[2], G = q[0] * (1 + Q[2] + Q[3]) % MOD;
            D[X] = {1, G, C, K};
            Ans = (Ans + G + C + K + 2 * MOD - P[0] - Q[0]) % MOD;
        }
        cout << Ans << '\n';
    }
}