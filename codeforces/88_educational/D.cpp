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
#define MAX 100005

int arr[MAX];

int kadane(int n, int eleToDrop) {

	int flag = 0, i;

	for(i = 0 ; i < n; i++) {
		if(arr[i] == eleToDrop) {
			flag = 1;
			break;
		}
	}

	if(!flag) {
		return 0;
	}

	int maxsum = -1, currsum = 0, found = 0;

	for(i = 0 ; i < n; i++) {

		if(arr[i] > eleToDrop) {
			found = 0;
			currsum = 0;
			continue;
		}

		currsum += arr[i];

		if(currsum < 0) {
			found = 0;
			currsum = 0;
			continue;
		}

		if(arr[i] == eleToDrop) {
			found = 1;
		}

		if(found == 1 && currsum > maxsum) {
			maxsum = currsum;
		}
	}

	return maxsum - eleToDrop;
}

int main() {

	int n, i, ans = 0;
	cin>>n;
	
	for(i = 0; i < n; i++) {
		cin>>arr[i];
	}

	for(i = 0; i <= 30; i++) {
		ans = max(ans, kadane(n, i));
	} 

	cout<<ans<<endl;

	return 0;
}