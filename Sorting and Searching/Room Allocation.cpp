/*
    Author: kamine
    Created: 2024-09-22 21:56:17
*/
#include <bits/stdc++.h>

using namespace std;

struct Customer {
    int s, e, idx;
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<Customer> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].s >> a[i].e;
        a[i].idx = i;
    }
    // Sắp xếp theo thời gian mà khách đến
    sort(a.begin(), a.end(), [&](Customer x, Customer y) {
        return x.s < y.s;
    });
    // Tạo một hàng đợi ưu tiên để lưu thời gian kết thúc và phòng
    // Nếu thời điểm đến của khách hiện tại mà lớn hơn thời gian kết thúc nhỏ nhất của khách trước đó thì phải tạo thêm phòng mới
    // Ngược lại thì sử dụng phòng cũ chính là phòng có thời gian kết thúc nhỏ nhất đó
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    vector<int> ans(n);
    int room_idx = 1;
    for (int i = 0; i < n; i++) {
        if (q.empty()) {
            ans[a[i].idx] = room_idx++;
            q.push({a[i].e, room_idx - 1});
        } else {
            auto [end_time, room] = q.top();
            if (end_time < a[i].s) {
                q.pop();
                q.push({a[i].e, room});
                ans[a[i].idx] = room;
            } else {
                ans[a[i].idx] = room_idx++;
                q.push({a[i].e, room_idx - 1});
            }
        }
    }
    cout << room_idx - 1 << "\n";
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
}