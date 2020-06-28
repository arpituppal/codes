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

int main() {

	LL n, k, t, a, b, ans = 0, i ;
	
	vector<LL> bothlikes;
	vector<LL> alikes;
	vector<LL> blikes;


	cin>>n>>k;

	for(i = 0; i < n; i++) {
		cin>>t>>a>>b;
		
		if(a == 0 && b == 0) continue;

		if(a == 1 && b == 1) bothlikes.PB(t);
		else if (a == 1) alikes.PB(t);
		else blikes.PB(t);

	}

	
	sort(alikes.begin(), alikes.end());
	sort(blikes.begin(), blikes.end());

	i = 0;
	while(i < alikes.size() && i < blikes.size()) {
		bothlikes.PB(alikes[i] + blikes[i]);
		i++;
	}

	sort(bothlikes.begin(), bothlikes.end());

	if(bothlikes.size() < k ) {
		cout<<-1<<endl;
	}else {
		for(i = 0 ; i < k; i++) {
			ans += bothlikes[i];
		}

		cout<<ans<<endl;
	}

	return 0;
}