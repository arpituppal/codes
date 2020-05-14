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

vector<int> vec[100000];

int getcode(char* s) {

	int i, l = strlen(s);
	int ans = 0;

	for( i = 0 ; i < l ; i++) {
		ans += (int)s[i];
	}

	return ans;
}


int dfs(map<int, int> &latestcode, int code, map<int, int> newmapping, int visited[1000000]) {

	if(newmapping.find(code) == newmapping.end()) {
		return code;
	}

	if(visited[code]) {
		return latestcode[code];
	}

	int i, ans;
	visited[code] = 1;

	ans = dfs(latestcode, newmapping[code], newmapping, visited);

	latestcode[code] = ans;
	return ans;
}

int main() {

	int t;
	scanf("%d", &t);
	while(t--) {

		int visited[1000000] = {0};
		map<int, string> codemap;

		map<int , int> latestcode;
		map<long long int, int> peslassign;
		map<int, int> newmapping;

		vector<int> changedcodes;

		int p, i, z;
		long long int pesl;
		char mro[6], oldmro[6], newmro[6];

		scanf("%d", &p);
		for( i = 0 ; i < p ; i++) {
			
			scanf("%lld", &pesl);
			scanf("%s", mro);

			int code = getcode(mro);
	
			peslassign[pesl] = code;
			latestcode[code] = code;
			
			string s = mro;
			codemap[code] = s;
		}
				
		scanf("%d", &z);
		for(i = 0 ; i < z; i++) {
			
			scanf("%s", oldmro);
			scanf("%s", newmro);
			
			int oldcode = getcode(oldmro);
			int newcode = getcode(newmro);

			newmapping[oldcode] = newcode;
			changedcodes.PB(oldcode);
			vec[oldcode].PB(newcode);
		}

		int st;
		for(i = 0 ; i < changedcodes.size(); i++) {
			
			if(!visited[changedcodes[i]]) {
				dfs(latestcode, changedcodes[i], newmapping, visited);
			}
		}

		scanf("%d", &p);
		while(p--) {
			long long int qpesl;
			scanf("%lld", &qpesl);

			cout<<qpesl<< " " << codemap[latestcode[peslassign[qpesl]]] << endl;
			//printf("%lld %s\n", qpesl, ]);
		}
			cout<<endl;
	}

	return 0;

}