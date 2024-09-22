/*
    Author: kamine
    Created: 2024-09-21 10:07:33
*/
#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

struct range {
    int l, r, idx;
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<range> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].l >> a[i].r;
        a[i].idx = i;
    }  
    // Sắp xếp lại mảng theo l tăng dần.
    sort(a.begin(), a.end(), [&] (range x, range y) {
        if (x.l == y.l) {
            return x.r > y.r;
        }
        return x.l < y.l;
    });
    // Muốn kiểm tra xem đoạn hiện tại có bao gồm đoạn khác không thì li <= lj && ri >= rj. Do mảng đã sắp xếp theo l tăng dần nên ta chỉ xét r.
    // Chỉ cần duy trì giá trị minR là r nhỏ nhất của các đoạn từ dưới lên. Nếu ri >= minR suy ra chắc chắn ở phía sau i có 1 đoạn thuộc đoạn i hiện tại.
    int minR = INT_MAX;
    vector<int> contains(n, 0);
    for (int i = n - 1; i >= 0; i--) {
        contains[a[i].idx] = (a[i].r >= minR);
        minR = min(minR, a[i].r);
    }
    for (int i : contains) {
        cout << i << ' ';
    }
    cout << endl;
    // Tương tự bên trên
    int maxR = 0;
    vector<int> contained(n, 0);
    for (int i = 0; i < n; i++) {
        contained[a[i].idx] = (a[i].r <= maxR);
        maxR = max(maxR, a[i].r);
    }
    for (int i : contained) {
        cout << i << ' ';
    }
}