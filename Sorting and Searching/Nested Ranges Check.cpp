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

    // Sau khi đã sắp xếp mảng, ta tìm xem mỗi phần tử trong mảng có phần tử nhỏ hơn kế tiếp hay không, nếu có thì phần từ đó sẽ chứa 1 đoạn nào đó.
    vector<int> contains(n, 0);
    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && a[st.top()].r >= a[i].r) {
            contains[a[st.top()].idx] = 1;
            st.pop();
        }
        st.push(i);
    }
    for (int i : contains) {
        cout << i << ' ';
    }
    cout << endl;
    // Tương tự như trên
    st = stack<int> {};
    vector<int> contained(n, 0);
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && a[st.top()].r <= a[i].r) {
            contained[a[st.top()].idx] = 1;
            st.pop();
        }
        st.push(i);
    }
    for (int i : contained) {
        cout << i << ' ';
    }
}