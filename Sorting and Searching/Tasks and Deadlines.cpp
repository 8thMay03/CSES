/*
    Author: kamine
    Created: 2024-09-03 16:35:13
*/
#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<ll, ll>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    // Sort by the time it takes to finish the task
    sort(a.begin(), a.end());
    ll ans = 0, cur = 0;
    for (int i = 0; i < n; i++) {
        cur += a[i].first;
        ans += a[i].second - cur;
    }
    cout << ans << endl;
}