#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> pli;
 
const int maxn = 100005;
vector<pair<int,ll>> adj[maxn];
ll dist[maxn][2]; // dist[i][0]: chưa dùng giảm giá, dist[i][1]: đã dùng
int n, m;
 
void dijkstra() {
    // Khởi tạo khoảng cách ban đầu là vô cùng
    for(int i = 1; i <= n; i++) {
        dist[i][0] = dist[i][1] = LLONG_MAX;
    }
    dist[1][0] = 0;
    
    priority_queue<pair<ll,pair<int,int>>, 
                  vector<pair<ll,pair<int,int>>>,
                  greater<pair<ll,pair<int,int>>>> pq;
    
    pq.push({0, {1, 0}}); // {khoảng cách, {đỉnh hiện tại, trạng thái giảm giá}}
    
    while(!pq.empty()) {
        ll d = pq.top().first;
        int u = pq.top().second.first;
        int used = pq.top().second.second;
        pq.pop();
        
        if(d > dist[u][used]) continue;
        
        for(auto edge : adj[u]) {
            int v = edge.first;
            ll w = edge.second;
            
            // TH1: Không dùng giảm giá ở cạnh này
            if(dist[u][used] + w < dist[v][used]) {
                dist[v][used] = dist[u][used] + w;
                pq.push({dist[v][used], {v, used}});
            }
            
            // TH2: Dùng giảm giá ở cạnh này (nếu chưa dùng)
            if(!used && dist[u][0] + w/2 < dist[v][1]) {
                dist[v][1] = dist[u][0] + w/2;
                pq.push({dist[v][1], {v, 1}});
            }
        }
    }
}
 
int main() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    
    dijkstra();
    cout << dist[n][1]; // In ra kết quả nhỏ nhất khi đã dùng giảm giá
    return 0;
}