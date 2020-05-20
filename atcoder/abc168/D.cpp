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
int visited[100005], ans[100005];
queue<int> q;
vector<int> ter;

void bfs(int st) {

	q.push(st);
	visited[st] = 1;

	while(!q.empty()) {

		int curr = q.front();
		q.pop();

		for(int i = 0 ; i < vec[curr].size(); i++) {

			if(vec[curr][i] == 1) {
				ter.PB(curr);
				ans[curr] = 1;
			}

			if(!visited[vec[curr][i]]) {
				visited[vec[curr][i]] = 1;
				q.push(vec[curr][i]);
			}
		}

	}
}

int main() {

	int n,m,i,a,b;
	cin>>n>>m;

	for(i = 0 ; i < m; i++) {
		cin>>a>>b;
		vec[a].PB(b);
		vec[b].PB(a);
	}

	bfs(2);

	for(int i = 0 ; i < ter.size(); i++) {

		int curr = ter[i];

		for(int j = 0 ; j < vec[curr].size(); j++) {

			if(vec[curr][j] != 1 && ans[vec[curr][j]] == 0) {
				ans[vec[curr][j]] = curr;
				ter.PB(vec[curr][j]);
			}
		}
	}

	int flag = 0;



	for(int i = 2; i <=n; i++) {

		//printf("%d  ", ans[i]);
		if(ans[i] == 0) {
			flag = 1;
			break;
		}
	}

	if(flag == 1) {

		printf("No\n");
	} else {
		printf("Yes\n");

		for(i = 2; i <= n; i++) {
			printf("%d\n", ans[i]);
		}
	}
	return 0;
}