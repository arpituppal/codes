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
#define MAX 200005

vector<pair<int, int> > factorise(int n) {
	int num = n;
	vector<pair<int, int> > v;
	for(int j=2;j*j<=n;j++) {
		int cnt = 0;
		while(num%j==0) {
			cnt++;
			num/=j;
		}
		v.PB(MP(j, cnt));
	}
	if(num > 1) v.PB(MP(num, 1));
	return v;
}

int main() {

	int n,i, arr[MAX], cnt[MAX], primepower[MAX][2], j;
	LL ans = 1;

	cin>>n;
	
	for(i = 0 ; i < n; i++) {
		cin>>arr[i];
	}

	for(i = 0 ; i < MAX; i++) {
		cnt[i] = 0;
		primepower[i][0] = 50;
		primepower[i][1] = 50;
	}

	for(i = 0 ; i < n; i++) {
		vector<pair<int, int> > vec = factorise(arr[i]);

		for(j = 0 ; j < vec.size(); j++) {
			int pnum = vec[j].first;
			int pwr = vec[j].second;

			if(pwr <= primepower[pnum][0]) {
				primepower[pnum][1] = primepower[pnum][0];
				primepower[pnum][0] = pwr;
			} else if(pwr <= primepower[pnum][1]) {
				primepower[pnum][1] = pwr;
			}

			cnt[pnum]++;
		}
	}

	for(i = 2; i < MAX; i++) {

		if(cnt[i] < n - 1) continue;

		int pwr = -1;

		if(primepower[i][0] != 50 && primepower[i][1] == 50) pwr = primepower[i][0];
		else pwr = primepower[i][1];

		if(pwr != -1) {
			//cout<<" i " << i << "pwr " <<pwr<< " prime power " << primepower[i][0] << " " << primepower[i][1]<<endl;
			ans = ans * pow(i, pwr);
		}
	}

	cout<<ans<<endl;
	return 0;
}


 