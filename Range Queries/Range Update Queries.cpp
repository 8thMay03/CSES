#include <bits/stdc++.h>

using namespace std;

/*
    Ý tưởng: tạo mảng diff[i] = a[i] - a[i - 1]
    Dễ thấy diff[1] + diff[2] + ... + diff[i] = a[i] (Truy vấn loai 2)
    Nỗi khi ta tăng đoạn (l, r) mỗi giá trị a[i] thêm u đơn vị thì diff[l] tăng u và dif[r + 1] giảm u, từ đó thực hiện update segment tree
*/

const int N = 2e5 + 1;

long long a[N], diff[N], sg[4 * N];

void build(int id, int l, int r) {
    if (l == r) {
        sg[id] = diff[l];
        return;
    }
    int m = l + r >> 1;
    build(id << 1, l, m);
    build(id << 1 | 1, m + 1, r);
    sg[id] = sg[id << 1] + sg[id << 1 | 1];
}

void update(int id, int l, int r, int pos, long long val) {
    if (pos < l || pos > r) return;
    if (l == r) {
        sg[id] = diff[pos];
        return;
    }
    int m = l + r >> 1;
    update(id << 1, l, m, pos, val);
    update(id << 1 | 1, m + 1, r, pos, val);
    sg[id] = sg[id << 1] + sg[id << 1 | 1];
}

long long get(int id, int l1, int r1, int l2, int r2) {
    if (r1 < l2 || l1 > r2) return 0;
    if (l1 >= l2 && r1 <= r2) return sg[id];
    int m = l1 + r1 >> 1;
    long long left = get(id << 1, l1, m, l2, r2);
    long long right = get(id << 1 | 1, m + 1, r1, l2, r2);
    return left + right;
}

int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        diff[i] = a[i] - a[i - 1];
    }
    build(1, 1, n);
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            long long l, r, u;
            cin >> l >> r >> u;
            diff[l] += u;
            diff[r + 1] -= u;
            update(1, 1, n, l, diff[l]);
            update(1, 1, n, r + 1, diff[r]);
        } else {
            int pos;
            cin >> pos;
            cout << get(1, 1, n, 1, pos) << endl;
        }
    }
}