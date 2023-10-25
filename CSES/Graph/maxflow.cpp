#include <bits/stdc++.h>

using namespace std;


long long max_flow(vector<vector<long long>> g, int n, int source, int sink) {

	long long flow = 0;

	vector<int> parent(n, -1);


	// Find a way from the source to sink on a path with non-negative capacities

	auto reachable = [&]() -> bool {

		queue<int> q;

		q.push(source);

		while (!q.empty()) {

			int node = q.front();

			q.pop();

			for (int son = 0; son < n; son++) {

				long long w = g[node][son];

				if (w <= 0 || parent[son] != -1) continue;

				parent[son] = node;

				q.push(son);

			}

		}

		return parent[sink] != -1;

	};


	// While there is a way from source to sink with non-negative capacities

	while (reachable()) {

		int node = sink;


		// The minimum capacity on the path from source to sink

		long long curr_flow = LLONG_MAX;

		while (node != source) {

			curr_flow = min(curr_flow, g[parent[node]][node]);

			node = parent[node];

		}

		node = sink;

		while (node != source) {

			// Subtract the capacity from capacity edges

			g[parent[node]][node] -= curr_flow;

			// Add the current flow to flow backedges

			g[node][parent[node]] += curr_flow;

			node = parent[node];

		}

		flow += curr_flow;

		fill(parent.begin(), parent.end(), -1);

	}


	return flow;

}


int main() {

	int n, m;

	cin >> n >> m;


	vector<vector<long long>> capacity(n, vector<long long>(n, 0));

	for (int i = 0; i < m; i++) {

		int x, y, c;

		cin >> x >> y >> c;

		capacity[--x][--y] += c;

	}


	cout << max_flow(capacity, n, 0, n - 1) << endl;

}