#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include <stack>
#include <cctype>
#include <utility>
#include <map>
#include <string>
#include <climits>
#include <set>
#include <sstream>
#include <utility>
#include <ctime>
#include <cassert>
#include <fstream>
using namespace std;
typedef long long LL;
#define MS(A) memset(A, 0, sizeof(A))
#define MSV(A,a) memset(A, a, sizeof(A))
#define MAX(a,b) ((a >= b) ? (a) : (b))
#define MIN(a,b) ((a >= b) ? (b) : (a))
#define ABS(a) (((a) > 0) ? (a) : (-a))
#define MP make_pair
#define PB push_back
#define getcx getchar_unlocked
#define INF (int(1e9))
#define INFL (LL(1e18))
#define EPS 1e-12
#define chkbit(s, b) (s & (1<<b))
#define setbit(s, b) (s |= (1<<b))
#define clrbit(s, b) (s &= ~(1<<b))
#define LIM 100000
#define MAXLOG 32

vector<int> vec[LIM];
queue<int> q;

int visited[LIM], parent[LIM], depth[LIM], p[LIM][MAXLOG], maxht = 0;

void bfs(int node) {

	visited[node] = 1;
	depth[node] = 0;
	q.push(node);

	while(!q.empty()) {

		int u = q.front();
		q.pop();

		maxht = MAX(maxht, depth[u]);

		for(int i = 0; i < vec[u].size(); i++) {

			if(!visited[vec[u][i]]) {
				parent[vec[u][i]] = u;
				depth[vec[u][i]] = depth[u] + 1;
				visited[vec[u][i]] = 1;
				q.push(vec[u][i]);
			}
		}
	}
}


void preprocess(int n) {

	int i, j;

	for(i = 1; i <= n; i++) {
		for(j = 0; (1 << j) < n; j++) {
			p[i][j] = -1;
		}
	}

	//first parent is the original parent for each node
	for(i = 1 ; i <= n; i++) {
		p[i][0] = parent[i];
	}

	for(j = 1; (1<<j) < n; j++) {
		for(i = 1; i<=n; i++) {

			//if node does not have 2^(j-1)th ancestor then 2^j ancestor also does not exist
			//else 2^jth ancestor = 2^(j-1)th ancestor of (2^(j-1)th ancestor of node i)

			if(p[i][j-1] != -1) {
				p[i][j] = p[p[i][j-1]][j-1];
			}
		}
	}
}

int lca(int u, int v) {

	int i, j;
	if(depth[u] < depth[v]) {
		int tmp = u;
		u = v;
		v = tmp;
	}

	//u is at a much greater depth, bring u to the level of v
	int dist = depth[u] - depth[v];
	while(dist > 0) {
		int raiseBy = log(dist) / log(2);
		u = p[u][raiseBy];
		dist -= (1<<raiseBy);
	}

	if(u == v) {
		return u;
	}

	for(j = (log(maxht) / log(2)) ; j >= 0; j--) {
		
		if(p[u][j] != -1 && p[u][j] != p[v][j]) {
			u = p[u][j];
			v= p[v][j];
		}
	}

	return parent[u];
}

int main() {

	int n, m, i, u, v;

	scanf("%d %d", &n, &m);

	for(i = 1; i<= n; i++) {
		parent[i] = i;
	}

	for(i = 0 ; i < m; i++) {

		scanf("%d %d", &u, &v);

		vec[u].PB(v);
		vec[v].PB(u);
	}

	bfs(1);


	preprocess(n);
	printf("TILL HERE\n");
	int t;
	scanf("%d", &t);

	while(t--) {
		scanf("%d %d", &u, &v);
		printf("%d\n", lca(u, v));
	}

	return 0;
}