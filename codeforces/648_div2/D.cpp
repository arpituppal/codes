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
#define MP make_pair
#define PB push_back
#define getcx getchar_unlocked
#define INF (int(1e9))
#define INFL (LL(1e18))
#define EPS 1e-12
#define chkbit(s, b) (s & (1<<b))
#define setbit(s, b) (s |= (1<<b))
#define chk(a) cerr << endl << #a << " : " << a << endl
#define chk2(a,b) cerr << endl << #a << " : " << a << "\t" << #b << " : " << b << endl
#define chk3(a,b,c) cerr << endl << #a << " : " << a << "\t" << #b << " : " << b << "\t" << #c << " : " << c << endl
#define chk4(a,b,c,d) cerr << endl << #a << " : " << a << "\t" << #b << " : " << b << "\t" << #c << " : " << c << "\t" << #d << " : " << d << endl
#define rep(i, a, n) for(i=a;i<n;i++)
#define rev(i, a, n) for(i=a;i>=n;i--)
#define rep_itr(itr, c) for(itr = (c).begin(); itr != (c).end(); itr++)
#define MOD 1000000007
#define MAX 1000000

char s[51][51];
int visited[51][51], dp[51][51], n, m;

bool isValid(int x, int y) {
	return x >= 0 && x < n && y >=0 && y < m;
}

int dfs(int currx, int curry) {
	visited[currx][curry] = 1;

	if(currx == n-1 && curry == m-1) return 1;
	
	if(dp[currx][curry]) return dp[currx][curry];

	int nextx = currx;
	int nexty = curry-1;

	int flag = 0;

	if(isValid(nextx, nexty) && s[nextx][nexty] != '#' && !visited[nextx][nexty]) {
		flag |= dfs(nextx, nexty);
	}

	nextx = currx;
	nexty = curry+1;
	if(isValid(nextx, nexty) && s[nextx][nexty] != '#' && !visited[nextx][nexty]) {
		flag |= dfs(nextx, nexty);
	}

	nextx = currx-1;
	nexty = curry;
	if(isValid(nextx, nexty) && s[nextx][nexty] != '#' && !visited[nextx][nexty]) {
		flag |= dfs(nextx, nexty);
	}

	nextx = currx+1;
	nexty = curry;
	if(isValid(nextx, nexty) && s[nextx][nexty] != '#' && !visited[nextx][nexty]) {
		flag |= dfs(nextx, nexty);
	}



	dp[currx][curry] = flag;
	return dp[currx][curry];

}

int main() {

	int t;
	cin>>t;

	while(t--) {

		int i, j, flag = 0, gcnt = 0 ,ans =0;
		vector<pair<int, int> > bad;
		vector<pair<int, int> > good;
		
		scanf("%d %d", &n, &m);
		for(i = 0; i < n; i++) {
			for(j = 0 ; j < m; j++) {
				
				cin>>s[i][j];
				if(s[i][j] == 'B') {
					bad.PB(MP(i,j));
				}

				if(s[i][j] == 'G') {
					good.PB(MP(i,j));
					gcnt++;
				}
			}
		}

		for(i = 0 ; i < bad.size(); i++) {
			int x = bad[i].first;
			int y = bad[i].second;

			if(isValid(x, y-1)) {
				if(s[x][y-1] == 'G') {
					flag = 1;
					break;
				}

				s[x][y-1] = '#';
			}

			if(isValid(x, y+1)) {
				if(s[x][y+1] == 'G') {
					flag = 1;
					break;
				}

				s[x][y+1] = '#';
			}

			if(isValid(x-1, y)) {
				if(s[x-1][y] == 'G') {
					flag = 1;
					break;
				}
				s[x-1][y] = '#';
			}

			if(isValid(x+1, y)) {
				if(s[x+1][y] == 'G') {
					flag = 1;
					break;
				}
				s[x+1][y] = '#';
			}
		}
		if(flag) {
			cout<<"No"<<endl;
			continue;
		}

		for(i = 0 ; i < n ; i++) {
			for(j = 0; j < m; j++) dp[i][j] = 0;
		}

		for(int k = 0; k < good.size(); k++) {
			
			int x = good[k].first;
			int y = good[k].second;

			for(i = 0 ; i < n ; i++) {
				for(j = 0; j < m; j++) visited[i][j] = 0;
			}

			int r = dfs(x, y);
			if(r) {
				ans++;
			} 
		}

		if(gcnt == 0) {
				cout<<"Yes"<<endl;
			continue;
		}

		if(ans == gcnt) {
			cout<<"Yes"<<endl;
		} else {
			cout<<"No"<<endl;
		}
	}

	return 0;
}