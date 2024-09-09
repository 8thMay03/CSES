/*
	Author: kamine
	Created: 2024-09-08 20:42:27
*/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 1;

int n, m;
int a[N], sz[N], par[N];

void init() {
	for (int i = 1; i <= n; i++) {
		par[i] = i;
		sz[i] = 1;
	}
}

int find(int u) {
	while (u != par[u]) {
		u = par[u];
	}
	return u;
}

bool merge(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v) return false;
	if (sz[u] < sz[v]) swap(u, v);
	par[v] = u;
	sz[u] += sz[v];
	return true;
} 

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	init();
	int cnt = n, mx = 1;
	while (m--) {
		int u, v;
		cin >> u >> v;
		u = find(u);
		v = find(v);
		bool flag = merge(u, v);
		if (flag) {
			cnt--;
			mx = max({mx, sz[u], sz[v]});
		}
		cout << cnt << ' ' << mx << endl;
	}
}