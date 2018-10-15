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

int freq[1000010];
set<int> st;

int main() {
	
	int m, i, k, val;
	long long int ans = 0;
	
	scanf("%d", &m);
	while(m--) {
		
		scanf("%d ", &k);
		while(k--) {
			scanf("%d", &val);
			freq[val]++;
			st.insert(val);
		}
		
		ans += (*--st.end()) - (*st.begin());

		freq[*st.begin()] --;
		freq[*--st.end()]--;
		
		if(freq[*st.begin()] == 0)
			st.erase(st.begin());
			
		if(freq[*--st.end()] == 0)
			st.erase(--st.end());
	}
	
	printf("%lld\n", ans);
	
	
	return 0;
}
