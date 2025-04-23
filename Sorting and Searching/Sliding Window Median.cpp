#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<int> a;
multiset<int> lower_half, upper_half;

void balance() {
    while (lower_half.size() > upper_half.size() + 1) {
        upper_half.insert(*lower_half.rbegin());
        lower_half.erase(prev(lower_half.end()));
    }
    while (lower_half.size() < upper_half.size()) {
        lower_half.insert(*upper_half.begin());
        upper_half.erase(upper_half.begin());
    }
}

void insert(int x) {
    if (lower_half.empty() || x <= *lower_half.rbegin()) {
        lower_half.insert(x);
    } else {
        upper_half.insert(x);
    }
    balance();
}

void erase(int x) {
    if (lower_half.find(x) != lower_half.end()) {
        lower_half.erase(lower_half.find(x));
    } else {
        upper_half.erase(upper_half.find(x));
    }
    balance();
}

int main() {
    cin >> n >> k;
    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < k; i++) insert(a[i]);
    cout << *lower_half.rbegin() << " ";
    for (int i = k; i < n; i++) {
        insert(a[i]);
        erase(a[i - k]);
        cout << *lower_half.rbegin() << " ";
    }
    return 0;
}
