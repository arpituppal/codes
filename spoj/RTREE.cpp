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
#define MOD 1000000007
#define N 100010
 
vector<int> vec[100010];
int ht[100010], ans[100010], visited[100010], parent[100010];

int calculateHeight(int s) {
	int i, mxval = -1;
	visited[s] = 1;
	
	// if(vec[s].size() == 1) {
	// 	ht[s] = 0;
	// 	return 0;
	// }
	
	
	for(i = 0; i < vec[s].size(); i++) {
		if(!visited[vec[s][i]]) {
			parent[vec[s][i]] = s;
			mxval = max(mxval, calculateHeight(vec[s][i]));
		}
	}
	
	//cout<<"max for node=> " << s <<" "<<mxval+1<<endl;
	ht[s] = mxval+1;
	return mxval+1;
}

void dfs(int s) {
	
	//case 1: does not involve
	//case 2: involves v
	int i;
	
	visited[s] = 1;
	
	// if(vec[s].size() == 1) {
	// 	ans[s] = 0;
	// 	return;
	// 	///return ans[s];
	// }
	
	for(i = 0 ; i < vec[s].size() ; i++) {
		if(!visited[vec[s][i]]) {
			dfs(vec[s][i]);
		}
	}
	
	vector<int> childsz;
	int includev = 0;
	int excludev = 0;

	for(i = 0; i < vec[s].size(); i++) {
		excludev = max(excludev, ans[vec[s][i]]);
		
		if(vec[s][i] != parent[s]) {
			childsz.PB(ht[vec[s][i]]);
		}
	}
	
	
	if(childsz.size() == 1) {
		includev = childsz[0] + 1;
	} else if(childsz.size() > 1) {
		sort(childsz.begin(), childsz.end());
		includev = childsz[childsz.size() -1] + childsz[childsz.size() -2] + 2;
	}
	
	//printf("for i = %d exl %d incl %d\n", s, excludev, includev);
	
	ans[s] = max(excludev, includev);
}

int main() {
	
	int n, i, s, u, v, q, m;
	scanf("%d", &n);
	for(i = 0 ; i < n-1; i++) {
		scanf("%d %d", &u, &v);
		vec[u].PB(v);
		vec[v].PB(u);
	}
	
	scanf("%d", &s);
	calculateHeight(s);

	// for(i = 1; i <= n; i++) {
	// 	printf(" i %d h %d\n", i, ht[i]);
	// }
	
	// printf("\n");
	
	scanf("%d", &q);
	
	for(i = 1; i <= n; i++) {
		visited[i] = 0;
	}
	
	dfs(s);
	
	// for(i = 1 ; i <=n; i++) {
	// 	printf(" ANS i %d %d\n ", i, ans[i]);
	// } 
	
	while(q--) {
		scanf("%d", &m);
		printf("%d\n", ans[m]);
	}
	
	
	return 0;
}