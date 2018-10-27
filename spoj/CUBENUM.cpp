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

int ans[N], hashi[N];
vector<int> cubes;

void precompute() {

	
	int i, j = 0, curr = 0, cnt = 0, num;

	for(i = 0; i < N; i++) {
		ans[i] = INF;
	}
	
	for(i = 1; i*i*i<= N; i++) {
		hashi[j++] = i*i*i;
	}
	
	ans[0] = 0;
	ans[1] = 1;
	
	for(i = 1; i < N; i++) {
		
		for(int k = 0; k < j; k++) {
			
			if(hashi[k] > i) break;
			
			if(ans[i-hashi[k]] != INF && (1 + ans[i-hashi[k]]) < ans[i]) {
				ans[i] = 1 + ans[i-hashi[k]];
			}
		}
	}
}

int main() {

	int t = 0;
	int n;

	precompute();

	while(scanf("%d", &n) != EOF) {
		t++;
		printf("Case #%d: %d\n",t, ans[n]);
	}
}