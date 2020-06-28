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

int main() {

	int t;
	cin>>t;
	while(t--) {

		int n, arr[501], b[501], i;
		map<pair<int,int>, int> mpa;
		map<pair<int, int>, int> mpb;
		map<pair<int, int>, int> ::iterator it;

		cin>>n;

		for(i = 0 ; i < n ; i++) cin>>arr[i];
		for(i = 0 ; i < n ; i++) cin>>b[i];

		for(i = 0 ; i < n/2; i++) {
			mpa[MP(min(arr[i], arr[n-i-1]), max(arr[i], arr[n-i-1]))]++;
			mpb[MP(min(b[i], b[n-i-1]), max(b[i], b[n-i-1]))]++;
		}

		if(n % 2 == 1 && arr[n/2] != b[n/2]) {
			cout<<"No"<<endl;
			continue;
		}
		
		int flag = 0;

		for(it = mpa.begin(); it != mpa.end(); it++) {
			if(mpb[it->first] != it->second) {
				flag = 1;
				break;
			}
		}

		if(flag) cout<<"No"<<endl;
		else cout<<"Yes"<<endl;

	}

	return 0;
}