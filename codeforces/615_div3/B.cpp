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

int main() {

	int t;
	cin>>t;

	while(t--) {

		int n, i, x, y, j;
		string s = "";
		bool possible = true;
		vector<pair<int,int> > vec;

		cin>>n;
		for(i = 1; i <= n; i++) {
			cin>>x>>y;
			vec.PB(MP(x,y));
		}

		sort(vec.begin(), vec.end());

		for(i = 1; i <=vec[0].first; i++) {
			s += 'R';
		}

		for(i = 1; i <=vec[0].second; i++) {
			s += 'U';
		}

		for(i = 1; i < n; i++) {
			
			if(vec[i].second < vec[i-1].second) {
				possible = false;
				break;
			}

			for(j = 1; j <= (vec[i].first - vec[i-1].first); j++) {
				s += 'R';
			}

			for(j = 1; j <= (vec[i].second - vec[i-1].second); j++) {
				s += 'U';
			}
		}

		if(possible) {
			printf("YES\n");
			cout<<s<<endl;
		} else {
			printf("NO\n");
		}
	}

	return 0;
}

