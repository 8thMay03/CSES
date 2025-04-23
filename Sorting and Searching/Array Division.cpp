#include <bits/stdc++.h>

#define int long long

using namespace std;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    int sum = 0, mx = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mx = max(mx, (int)a[i]);
        sum += a[i];
    }
    // Kiểm tra xem với giá trị mid để cho tổng các đoạn con không vượt quá mid thì số đoạn cần sử dụng là có vượt quá k hay không
    auto check = [&](int mid) {
        int cnt = 1, sum = 0;
        for (int i : a) {
            if (sum + i > mid) {
                cnt++;
                sum = i;
                if (cnt > k) return false;  
            } else {
                sum += i;
            }
        }
        return true;
    };
    // Giá trị mà ta cần tìm nằm trong khoảng mx và sum
    int low = mx, high = sum, ans = high;
    while (low <= high) {  
        int mid = (low + high) / 2;
        if (check(mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    cout << ans;
}
