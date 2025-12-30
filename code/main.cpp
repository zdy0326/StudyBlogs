#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9 + 7;

int prim(int n, vector<vector<pair<int, int>>>& adj) {
    vector<int> dist(n, inf);
    vector<bool> used(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    dist[0] = 0;
    pq.push({0, 0});
    
    int res = 0;

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (used[u]) continue;
        used[u] = true;
        res += d;

        for (auto [v, w] : adj[u]) {
            if (!used[v] && w < dist[v]) {
                dist[v] = w;
                pq.push({w, v});
            }
        }
    }

    for (bool b : used) {
        if (!b) return -1;
    }
    return res;
}

int main() {
    return 0;
}