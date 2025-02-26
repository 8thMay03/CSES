/*
    Author: kamine
    Created: 2025-02-07 20:49:56
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int& x : a) {
        cin >> x;
    }
    unordered_map<int, int> cnt;
    long long ans = 0;
    int left = 0;
    for (int right = 0; right < n; right++) {
        cnt[a[right]]++;
        while (cnt.size() > k) {
            cnt[a[left]]--;
            if (cnt[a[left]] == 0) {
                cnt.erase(a[left]);
            }
            left++;
        }
        ans += right - left + 1;
    }
    cout << ans << '\n';
}