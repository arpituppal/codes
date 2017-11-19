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
#define N 500000

int dp[N][20], parent[N], visited[N], depth[N], color[N], maxht = 0;
vector<int> vec[N];
queue<int> q;

void bfs(int node) {

	visited[node] = 1;
	depth[node] = 0;
	q.push(node);

	while(!q.empty()) {

		int u = q.front();
		q.pop();

		maxht = MAX(maxht, depth[u]);

		for(int i = 0; i < vec[u].size(); i++){

			if(!visited[vec[u][i]]) {

				visited[vec[u][i]] = 1;
				depth[vec[u][i]] = depth[u] + 1;
				parent[vec[u][i]] = u;
				q.push(vec[u][i]);
			}
		}

	}
}


void preprocess(int n) {

	int i, j;

	for(i = 1; i <=n; i++) {
		for(j = 0; (1 << j) < n; j++) {
			dp[i][j] = -1;

		}
	}

	for(i = 1; i <=n; i++) {
		dp[i][0] = parent[i];
	}

	for(j = 1; (1 << j) <n; j++) {

		for(i = 1; i<=n; i++) {

			if(dp[i][j-1] != -1) {
				dp[i][j] = dp[dp[i][j-1]][j-1];
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

	//bring u to height of v
	int dist = depth[u] - depth[v];

	while(dist > 0) {
		int raiseBy = log(dist) / log(2);
		u = dp[u][raiseBy];
		dist -= (1<<raiseBy);
	}

	if(u == v) {
		return u;
	}

	for(j = log(maxht) / log(2) ; j >=0 ;j--) {

		if(dp[u][j] != -1 && dp[u][j] != dp[v][j]) {
			u = dp[u][j];
			v= dp[v][j];
		}
	}

	return parent[u];
}


int main() {

	int t;
	scanf("%d", &t);
	while(t--) {

		int n, q, r, u, v, i, j;
		scanf("%d %d %d", &n, &q, &r);

		for(i = 0; i < n; i++) {
			scanf("%d", &color[i]);
		}

		for(i = 0 ; i < n; i++) {
			scanf("%d %d", &u, &v);
			vec[u].PB(v);
			vec[v].PB(u);
		}

		
	}

}

