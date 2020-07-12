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

	int t;
	cin>>t;
	while(t--) {

		int n, i, arr[1001], lt[10001], rt[1001], j, k;

		cin>>n;
		
		for(i = 0 ; i < n; i++) {
			cin>>arr[i];
		}

		int mini = arr[0];
		int miniidx = 0;

		for(i = 1; i < n; i++) {

			if(mini < arr[i]) {
				lt[i] = miniidx;
			} else lt[i] = -1;

			if(arr[i] < mini) {
				mini = arr[i];
				miniidx = i;
			}
		}

		mini = arr[n-1];
		miniidx = n-1;

		for(i = n-2; i >= 0; i--) {

			if(mini < arr[i]) {
				rt[i] = miniidx;
			} else rt[i] = -1;

			if(arr[i] < mini) {
				mini = arr[i];
				miniidx = i;
			}
		}

		int flag = 0;

		for(i = 1; i < n-1; i++) {

			if(lt[i] != -1 && rt[i] != -1) {
				flag = 1;
				cout<<"YES"<<endl;
				cout<<lt[i]+1 << " " << i +1<< " " << rt[i]+1<<endl;
				break;
			}

		}

		if(!flag) cout<<"NO"<<endl;
	}

	return 0;
}