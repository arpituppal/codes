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

LL rt[4010][3];

int main() {

	char s[4010];
	LL n,i, ans = 0, j;

	cin>>n;
	scanf("%s", s);

	for(i = n-2; i>=0; i--) {

		if(s[i+1] == 'R') {
			rt[i][0] = rt[i+1][0] + 1;
			rt[i][1] = rt[i+1][1];
			rt[i][2] = rt[i+1][2];

		} else if(s[i+1] == 'G') { 
			rt[i][1] = rt[i+1][1] + 1;
			rt[i][0] = rt[i+1][0];
			rt[i][2] = rt[i+1][2];
		} else {
			rt[i][2] = rt[i+1][2] + 1;
			rt[i][0] = rt[i+1][0];
			rt[i][1] = rt[i+1][1];
		}
	}

	for(i = 0 ; i <= n-3; i++) {
		for(j = i+1; j <=n-2 ; j++) {

			if(s[i] == s[j]) {
				continue;
			}

			if((s[i] == 'R' && s[j] == 'G') || (s[i] == 'G' && s[j] == 'R')) {
				ans += rt[j][2] - (j+j-i >=n ? 0 : s[j+j-i] == 'B' ? 1 : 0) ;
			} else if ((s[i] == 'R' && s[j] == 'B') || (s[i] == 'B' && s[j] == 'R')) {
				ans += rt[j][1] - (j+j-i >=n ? 0 : s[j + j - i] == 'G' ? 1 : 0);
			} else if ((s[i] == 'G' && s[j] == 'B') || (s[i] == 'B' && s[j] == 'G')) {
				ans += rt[j][0] - (j+j-i >=n ? 0 : s[j + j -i] == 'R' ? 1 :0);
			}
		}
	}
	
	cout<<ans<<endl;
	return 0;
}