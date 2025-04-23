#include <bits/stdc++.h>
 
using namespace std;

// Xây dựng sum SegmentTree với sum(l, r) tương ứng với số phần từ còn lại trong đoạn l, r
// Để tìm ra số thứ x còn lại trong dãy, ta chỉ cần tìm vị trí đầu tiên index mà sum(0, index) = x
// Cách làm là sử dụng binary search trên đoạn [0, n - 1] với điều kiện sum(0, mid) >= x

class SegmentTree {
    int n;
    vector<int> st;
 
public:
    SegmentTree(int n) {
        this->n = n;
        st.resize(4 * n, 0);
        build(0, 0, n - 1);
    }
 
    void build(int id, int l, int r) {
        if (l == r) {
            st[id] = 1;
            return;
        }
        int m = (l + r) / 2;
        build(id * 2 + 1, l, m);
        build(id * 2 + 2, m + 1, r);
        st[id] = st[id * 2 + 1] + st[id * 2 + 2];
    }
 
    void update(int id, int l, int r, int pos, int x) {
        if (pos < l || pos > r) return;
        if (l == r) {
            st[id] = x;
            return;
        }
        int m = (l + r) / 2;
        update(id * 2 + 1, l, m, pos, x);
        update(id * 2 + 2, m + 1, r, pos, x);
        st[id] = st[id * 2 + 1] + st[id * 2 + 2];
    }
 
    int get(int id, int l, int r, int L, int R) {
        if (r < L || l > R) return 0;
        if (L <= l && r <= R) return st[id];
        int m = (l + r) / 2;
        return get(id * 2 + 1, l, m, L, R) + get(id * 2 + 2, m + 1, r, L, R);
    }
};
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    SegmentTree st(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        int low = 0, high = n - 1;
        int ans = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            int sum = st.get(0, 0, n - 1, 0, mid);
            if (sum >= x) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        st.update(0, 0, n - 1, ans, 0);
        cout << a[ans] << ' ';
    }
}