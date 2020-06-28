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

	LL k, i, itr;
	cin>>k;

	queue<pair<LL, int> >  q;
	vector<LL> vec;

	for(i = 1; i < 10; i++) {
		q.push(MP(i,i));
		vec.PB(i);
	}

	itr = 9;

	while(!q.empty()) {

		LL num = q.front().first;
		LL lastdig = q.front().second;
		q.pop();

		if(itr >= 100000) break;

		for(i = 0; i <=9 ;i++) {
		//	cout<<"NUM " << num << " " <<i<< " " << itr<<endl;
			if(abs(lastdig - i) <= 1) {
				q.push(MP((num*10)+ i, i));
				vec.PB((num*10) + i);
				++itr;
			}
		}

	}

//	for(i = 0; i < 20; i++) cout<<vec[i] << endl;

	cout<<vec[k-1]<<endl;
	return 0;

}