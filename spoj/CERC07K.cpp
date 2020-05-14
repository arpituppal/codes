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


char s[110][110];
int n,m, steps = 0, efound = 0;


int isKey(char ch) {
	return ch == 'r' || ch == 'b' || ch == 'y' || ch == 'g';
}

int isDoor(char ch) {
	return ch == 'R' || ch == 'B' || ch == 'Y' || ch == 'G';
}

int getKey(char ch) {

	if(ch == 'B' || ch == 'b') {
		return 0;
	}

	if(ch == 'Y' || ch == 'y') {
		return 1;
	}

	if(ch == 'R' || ch == 'r') {
		return 2;
	}

	if(ch == 'G' || ch == 'g') {
		return 3;
	}

	return 0;
}  

int isPosWithinBound(int x, int y) {
	return x >=0 && x < n && y>=0 && y<m;
}

void bfs(int stx, int sty) {

	queue<pair<vector<int>, pair<int,pair<int ,int> > > > q;
	vector<int> keys;
	steps = INF;
	efound = 0;

	q.push(MP(keys, MP(0,MP(stx, sty))));

	while(!q.empty()) {
		vector<int> currKeys = q.front().first;
		int currsteps = q.front().second.first;
		int currx = q.front().second.second.first;
		int curry = q.front().second.second.second;
		q.pop();

		printf("currx %d curry %d \n", currx, curry);
		//up
		int nextx = currx-1;
		int nexty = curry;

		if(s[currx][curry] == 'X') {
			steps = currsteps < steps ? currsteps : steps;
			efound = 1;
			return;
		}

		if(isPosWithinBound(currx-1, curry)) {

			if(isKey(s[nextx][nexty])) {
				currKeys[getKey(s[nextx-1][nexty])] = 1;
				q.push(MP(currKeys,MP(currsteps+1, MP(nextx, nexty))));
			}

			if(isDoor(s[nextx][nexty]) && keys[getKey(s[nextx][nexty])] == 1) {
				q.push(MP(currKeys,MP(currsteps+1, MP(nextx, nexty))));
			}

			if(s[nextx][nexty] == '*' || s[nextx][nexty] == '.') {
				q.push(MP(currKeys, MP(currsteps+1, MP(nextx, nexty))));
			}
		}
		//down

 		nextx = currx + 1;
		nexty = curry;

		if(isPosWithinBound(nextx, nexty)) {

			if(isKey(s[nextx][nexty])) {
				currKeys[getKey(s[nextx-1][nexty])] = 1;
				q.push(MP(currKeys,MP(currsteps+1, MP(nextx, nexty))));
			}

			if(isDoor(s[nextx][nexty]) && keys[getKey(s[nextx][nexty])] == 1) {
				q.push(MP(currKeys,MP(currsteps+1, MP(nextx, nexty))));
			}

			if(s[nextx][nexty] == '*' || s[nextx][nexty] == '.') {
				q.push(MP(currKeys, MP(currsteps+1, MP(nextx, nexty))));
			}
		}

		nextx = currx + 1;
		nexty = curry;

		if(isPosWithinBound(nextx, nexty)) {

			if(isKey(s[nextx][nexty])) {
				currKeys[getKey(s[nextx-1][nexty])] = 1;
				q.push(MP(currKeys,MP(currsteps+1, MP(nextx, nexty))));
			}

			if(isDoor(s[nextx][nexty]) && keys[getKey(s[nextx][nexty])] == 1) {
				q.push(MP(currKeys,MP(currsteps+1, MP(nextx, nexty))));
			}

			if(s[nextx][nexty] == '*' || s[nextx][nexty] == '.') {
				q.push(MP(currKeys, MP(currsteps+1, MP(nextx, nexty))));
			}
		}
		//left

		nextx = currx ;
		nexty = curry - 1;

		if(isPosWithinBound(nextx, nexty)) {

			if(isKey(s[nextx][nexty])) {
				currKeys[getKey(s[nextx-1][nexty])] = 1;
				q.push(MP(currKeys,MP(currsteps+1, MP(nextx, nexty))));
			}

			if(isDoor(s[nextx][nexty]) && keys[getKey(s[nextx][nexty])] == 1) {
				q.push(MP(currKeys,MP(currsteps+1, MP(nextx, nexty))));
			}

			if(s[nextx][nexty] == '*' || s[nextx][nexty] == '.') {
				q.push(MP(currKeys, MP(currsteps+1, MP(nextx, nexty))));
			}
		}

		//right
		nextx = currx;
		nexty = curry + 1;

		if(isPosWithinBound(nextx, nexty)) {

			if(isKey(s[nextx][nexty])) {
				currKeys[getKey(s[nextx-1][nexty])] = 1;
				q.push(MP(currKeys,MP(currsteps+1, MP(nextx, nexty))));
			}

			if(isDoor(s[nextx][nexty]) && keys[getKey(s[nextx][nexty])] == 1) {
				q.push(MP(currKeys,MP(currsteps+1, MP(nextx, nexty))));
			}

			if(s[nextx][nexty] == '*' || s[nextx][nexty] == '.') {
				q.push(MP(currKeys, MP(currsteps+1, MP(nextx, nexty))));
			}
		}
	}	
}


int main() {

	while(1) {

		int i, j, stx = 0, sty = 0;

		scanf("%d %d", &n,&m);

		if(n == 0 && m == 0) {
			break;
		}

		for(i = 0 ; i < n; i++) {
			scanf("%s",s[i]);

			for(j = 0; j < m; j++) {
				if(s[i][j] == '*') {
					stx = i;
					sty = j;
				}
			}
		}


		bfs(stx, sty);

		if(efound == 0) {
			printf("The poor student is trapped!\n");
		} else {
			printf("Escape possible in %d steps.\n", steps);
		}

	}

	return 0;
}