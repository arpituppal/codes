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


vector<int> vec[100005];
int numdesc[100005], numcandy[100005], visited[100005];


int dfs(int node) {



}

int pre(int node) {

	printf("NODE %d\n",node);
	int i, val;

	// if(vec[node].size() == 0) {
	// 	numdesc[node] = 0;
	// 	numcandy[node] = 1;
	// }

	// if(visited[node]) {
	// 	return 0;
	// }

	visited[node] = 1;

	for(i = 0 ; i < vec[node].size(); i++) {
		
		val = 0;


		if(!visited[vec[node][i]]) {
			 val = 1 + pre(vec[node][i]);
		}
	}

	printf("node rec = %d val = %d\n", node, val);
		
	numdesc[node] += val;
	numcandy[node] = numdesc[node] + 1;
	//printf("NODE %d \n", );
	return numdesc[node];
}


int main() {

	int t;
	scanf("%d", &t);

	while(t--) {

		int n, i, u, v;

		scanf("%d", &n);

		for(i = 0; i < n-1; i++) {
			scanf("%d %d", &u, &v);
			vec[u].PB(v);
			vec[v].PB(u);
		}

		pre(1);

		for(i = 1 ;i <= n; i++) {
			printf("i = %d desc = %d \n", i, numdesc[i]);
		}

	}

	return 0;
}