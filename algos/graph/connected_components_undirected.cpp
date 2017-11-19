
// HACKERRANL Graph algo - Roads and libraries


#include <iostream>
#include<bits/stdc++.h> 
#define MAX 100010
#define PB push_back
#define MIN(a, b) (a) < (b) ? (a) : (b)
#define LL long long int

using namespace std;

int visited[MAX] = {0};
vector<int> vec[MAX];

void dfs(int u, int *sz ) {

	//printf("Size %d \n", *sz);
	visited[u] = 1;
	(*sz)++;
	for(int i = 0; i < vec[u].size(); i++) {
		
		if(!visited[vec[u][i]]) {
			dfs(vec[u][i], sz);
		}

	}
}

int main() {
	
	int q;
	scanf("%d", &q);
	
	while(q--) {
		
		int n, m, clib, croad, i, j, u ,v;
		LL ans = 0;
		vector<int> connected;
		scanf("%d %d %d %d", &n, &m, &clib, &croad);
		
		while(m--) {
			
			scanf("%d %d", &u, &v);
			vec[u].PB(v);
			vec[v].PB(u);
		}
		
		
		for(i = 1; i <=n; i++) {
			
			if(!visited[i]) {
				int sz = 0;
				dfs(i, &sz);
				connected.PB(sz);
			}
		}
		
		for(i = 0 ; i < connected.size(); i++) {
			
			ans += MIN(connected[i] * clib, ((connected[i] - 1) * croad + clib));
			
		}
		printf("%lld\n", ans);
		
		for(i = 1; i <= n; i++) {
			vec[i].clear();
			visited[i] = 0;
		}
	}
	
	return 0;
}
