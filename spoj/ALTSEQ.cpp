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
#define mod 1000000007

long long int arr[5001];
int dp[5001];

int main() {
	
	int n, i, j, mx = -1;
	
	scanf("%d", &n);
	
	for(i = 0 ; i < n ; i++) {
		scanf("%lld", &arr[i]);
	}
	
	int curr;
	
	for( i = 0 ; i < n; i++) {
	
		for(j = 0; j<i; j++) {
			
			if((arr[i] > 0 && arr[j] <0 || arr[i]<0 && arr[j]>0) && ABS(arr[i]) > ABS(arr[j])) {
				dp[i] = MAX(dp[i], dp[j] + 1);
			}
		}
		
		if(dp[i] == 0) {
			dp[i]=1;
		}
	}
	
	for(i = 0 ; i <n; i++) {
		mx = MAX(dp[i], mx);
	}
	printf("%d\n", mx);
	return 0;
}
