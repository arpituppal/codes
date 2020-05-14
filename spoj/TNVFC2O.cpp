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

std::map<long long int, int> hashMap;

int main() {

	int n, k;
	int ans;
	
	scanf("%d %d", &n, &k);
		
	while(n--) {
	
		int id;
		scanf("%d", &id);
		hashMap[id] = hashMap[id] + 1;
	}
	
	map<long long int, int>::iterator it;
	
	for(it = hashMap.begin(); it!= hashMap.end(); it++) {
		
		if(it->second % k !=0) {
			ans = it->first;
			break;
		}
	}
	
	printf("%d\n", ans);
	return 0;
}
