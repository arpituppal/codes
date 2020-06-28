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

	LL k,i, ans = 0;
	cin>>k;
	vector<LL> kfcac, kminus1fac;


	if(k == 2) {
		cout<<"1"<<endl;
		return 0;
	}

	for(i = 2; i*i <= k; i++) {

		if(k % i == 0) {
			kfcac.PB(i);

			//if(k/i != i) kfcac.PB(k/i);
		}
	}

	//for(i = 0; i < kfcac.size(); i++) cout<< " FAC "<<kfcac[i]<<endl;

	for(i = 0 ; i < kfcac.size(); i++) {

		LL kcpy = k;
		while(kcpy % kfcac[i] == 0) kcpy /= kfcac[i];

		if(kcpy % kfcac[i] == 1)  ans++; 
			//cout<<" A " << kfcac[i]<<endl; }

	}


	k--;

	for(i = 2; i*i <= k; i++) {

		if(k % i == 0) {
			kminus1fac.PB(i);

			if(k/i != i) kminus1fac.PB(k/i);
		}
	}

	ans += kminus1fac.size() + 2;

	cout<<ans<<endl;

	return 0;
}