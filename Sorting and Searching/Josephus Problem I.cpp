/*
    Author: kamine
    Created: 2025-09-05 10:08:48
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> nxt(n + 1);
    for (int i = 1; i <= n; i++) {
        nxt[i] = (i + 1);
    }
    nxt[n] = 1;

    int cur = 1;
    for (int i = 0; i < n; i++) {
        cout << nxt[cur] << ' ';
        nxt[cur] = nxt[nxt[cur]];
        cur = nxt[cur];
    }
}
