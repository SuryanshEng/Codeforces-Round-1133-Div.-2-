#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        int N, Hi = 0; cin >> N;
        vector<int> A(N + 2), D(N + 2), C(N + 1);
        for (int i = 1; i <= N; i++) cin >> A[i];
        for (int i = 1; i < N; i++) Hi = max(Hi, D[i] = abs(A[i] - A[i + 1]));

        auto Faf = [&](int X) {
            int P = 0, Tattu = 0;
            for (int i = 1; i < N; i++) {
                C[i] = C[i - 1] + (2 * D[i] > X);
                if (D[i] > X) Tattu++, P = P ? P : i;
            }
            if (Tattu < 1) return 1;
            if (Tattu > 2) return 0;
            auto Ok = [&](int L, int r) {
                return L >= 1 && r <= N && L <= r && C[r - 1] == C[L - 1] &&
                       Tattu == (D[L - 1] > X) + (D[r] > X) &&
                       (L == 1 || abs(A[L - 1] - 2 * A[r]) <= X) &&
                       (r == N || abs(2 * A[L] - A[r + 1]) <= X);
            };
            for (int t = 1; t <= N; t++)
                if (Ok(P + 1, t) || Ok(t, P)) return 1;
            return 0;
        };

        int Lo = 0;
        while (Lo < Hi) {
            int M = (Lo + Hi) >> 1;
            Faf(M) ? Hi = M : Lo = M + 1;
        }
        cout << Lo << '\n';
    }
}