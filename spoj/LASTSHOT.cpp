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


vector<int> vec[10010];
queue<int> q;
int visited[10010];

int bfs(int st) {

	int ans = 1;
		
	q.push(st);
	visited[st] = 1;
	
	while(!q.empty()) {
	
		int node = q.front();
		q.pop();
		
		for(int i = 0; i < vec[node].size(); i++) {
			
			if(!visited[vec[node][i]]) {
				ans++;
				q.push(vec[node][i]);
				visited[vec[node][i]] = 1;
			}
		}	
	}
	
	return ans;
}


int main() {
	
	int n, m, i, a, b, ans = 0;
	scanf("%d %d", &n, &m);
	
	while(m--) {
		
		scanf("%d %d", &a, &b);
		vec[a].PB(b);
	}
	
	for(i = 1; i <= n; i++) {
	
		int a = bfs(i);
		ans = MAX(ans, a);
		
		for(int j = 1; j <=n; j++) {
			visited[j] = 0;
		}
		
	}
	
	printf("%d\n", ans);
	return 0;
}