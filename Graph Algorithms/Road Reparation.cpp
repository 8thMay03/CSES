/*
	Author: kamine
	Created: 2024-09-09 09:08:33
*/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 1;

int n, m, a[N], sz[N], par[N];
vector<tuple<int, int, int>> edges;

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

bool is_connected(int u, int v) {
	return find(u) == find(v);
}

void merge(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v) return;
	if (sz[u] < sz[v]) swap(u, v);
	par[v] = u;
	sz[u] += sz[v];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	init();
	for (int i = 1; i <= n; i++) {
		par[i] = i;
		sz[i] = 1;
	}
	while (m--) {
		int u, v, z;
		cin >> u >> v >> z;
		edges.push_back({u, v, z});
	}
	sort(edges.begin(), edges.end(), [&](tuple<int, int, int> a, tuple<int, int, int> b) {
		auto [x1, y1, z1] = a;
		auto [x2, y2, z2] = b;
		return z1 < z2;
	});
	long long ans = 0, cnt = 0;
	for (auto [u, v, cost] : edges) {
		if (!is_connected(u, v)) {
			ans += cost;
			cnt++;
			merge(u, v);
		}
	}
	if (cnt < n - 1) {
		cout << "IMPOSSIBLE";
	} else {
		cout << ans;
	}
	return 0;
}