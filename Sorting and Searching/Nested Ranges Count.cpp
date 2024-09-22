/*
    Author: kamine
    Created: 2024-09-21 10:07:33
*/
#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()

using namespace std;

class SegmentTree {
public:
    vector<int> a;
    vector<vector<int>> sg;

    void build(int id, int l, int r) {
        if (l == r) {
            sg[id].push_back(a[l]);
            return;
        }
        int m = (l + r) >> 1; 
        build(id * 2 + 1, l, m);
        build(id * 2 + 2, m + 1, r);
        merge(all(sg[id * 2 + 1]), all(sg[id * 2 + 2]), back_inserter(sg[id]));
    }

    int get(int id, int l1, int r1, int l2, int r2, int k) {
        if (l1 > r2 || r1 < l2) return 0;
        if (l1 >= l2 && r1 <= r2) {
            return upper_bound(all(sg[id]), k) - sg[id].begin();
        }
        int m = (l1 + r1) >> 1; 
        return get(id * 2 + 1, l1, m, l2, r2, k) + get(id * 2 + 2, m + 1, r1, l2, r2, k);
    }

    SegmentTree(vector<int> v) {
        this->a = v;
        sg.resize(4 * a.size());
        build(0, 0, a.size() - 1); 
    }
};

class SegmentTree2 {
public:
    vector<int> a;
    vector<vector<int>> sg;

    void build(int id, int l, int r) {
        if (l == r) {
            sg[id].push_back(a[l]);
            return;
        }
        int m = (l + r) >> 1; 
        build(id * 2 + 1, l, m);
        build(id * 2 + 2, m + 1, r);
        merge(all(sg[id * 2 + 1]), all(sg[id * 2 + 2]), back_inserter(sg[id]));
    }

    int get(int id, int l1, int r1, int l2, int r2, int k) {
        if (l1 > r2 || r1 < l2) return 0;
        if (l1 >= l2 && r1 <= r2) {
            return sg[id].end() - lower_bound(all(sg[id]), k);
        }
        int m = (l1 + r1) >> 1; 
        return get(id * 2 + 1, l1, m, l2, r2, k) + get(id * 2 + 2, m + 1, r1, l2, r2, k);
    }

    SegmentTree2(vector<int> v) {
        this->a = v;
        sg.resize(4 * a.size());
        build(0, 0, a.size() - 1); 
    }
};

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
    sort(a.begin(), a.end(), [&] (range x, range y) {
        if (x.l == y.l) {
            return x.r > y.r;
        }
        return x.l < y.l;
    });
    vector<int> v;
    for (int i = 0; i < n; i++) {
        v.push_back(a[i].r);
    }
    SegmentTree tree(v);
    vector<int> contains(n, 0);
    for (int i = 0; i < n; i++) {
        contains[a[i].idx] = tree.get(0, 0, n - 1, i + 1, n - 1, v[i]);
    }
    SegmentTree2 tree2(v);
    vector<int> contained(n, 0);
    for (int i = 0; i < n; i++) {
        contained[a[i].idx] = tree2.get(0, 0, n - 1, 0, i - 1, v[i]);
    }
    for (int i : contains) {
        cout << i << ' ';
    }
    cout << endl;
    for (int i : contained) {
        cout << i << ' ';
    }
}