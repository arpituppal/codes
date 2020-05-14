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

vector<int> vec[110], vrev[110];
stack<int> stk;
int visited[110];
char s[110][110];


void dfs(int node) {

	int i;
	visited[node] = 1;

	for(i = 0 ; i < vec[node].size(); i++) {
		if(!visited[vec[node][i]]) {
			dfs(vec[node][i]);
		}
	}

	stk.push(node);
}


void dfsr(int node) {

	int i;

	visited[node] = 1;

	for(i = 0; i < vrev[node].size(); i++) {
		if(!visited[vrev[node][i]]) {
			dfsr(vrev[node][i]);
		}
	}
}

void construct_graph(int n) {

	int i, j;

	for(i = 0 ; i < n; i++) {

		for(j = 0 ; j < n; j++) {
			if(s[i][j] == 'Y') {
				vec[i].PB(j);
				vrev[j].PB(i);
			}
		}
	}
}


int main() {

	int t;
	scanf("%d", &t);
	while(t--) {

		int i, j, n, ans = 0;
		scanf("%d", &n);

		for(i = 0; i < n; i++) {
			scanf("%s", s[i]);
		}

		construct_graph(n);

		for(i = 0 ; i < n; i++) {
			if(!visited[i]) {
				dfs(i);
			}
		}

		memset(visited, 0, sizeof(visited));

		while(!stk.empty()) {

			int node = stk.top();
			stk.pop();

			if(!visited[node]) {
				ans++;
				dfsr(node);
			}
		}

		printf("%d\n", ans);

		for(i = 0 ; i < n ; i++) {
			visited[i] = 0;
			vec[i].clear();
			vrev[i].clear();
		}
	}

	return 0;
}