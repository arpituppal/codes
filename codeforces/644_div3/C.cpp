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


int main() {

	int t;
	cin>>t;
	while(t--) {

		int n, i, arr[100], cnteven = 0, cntodd = 0, flag = 0;
		vector<int> even;
		vector<int> odd;

		cin>>n;

		for(i = 0 ; i < n ; i++) {
			cin>>arr[i];

			if(arr[i] % 2 == 0) {
				cnteven++;
				even.PB(arr[i]);
			} else {
				cntodd++;
				odd.PB(arr[i]);
			}
		}

		if(cnteven % 2 == 0 && cntodd % 2 == 0) {
			printf("YES\n");
			continue;
		}

		//sort(arr, arr+n);

		for(i = 0 ; i < even.size(); i++) {

			for(int j = 0 ; j < odd.size(); j++) {

				if(ABS((even[i]- odd[j])) == 1) {
					flag = 1;
					break;
				}
			}
		}

		if(flag) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}


		// for(i = 1; i < n; i++) {

		// 	if(arr[i] % 2 != arr[i-1] % 2 && arr[i] - arr[i-1] != 1) {
		// 		flag = 1;
		// 		break;
		// 	}
		// }
		// if(!flag) {
		// 	printf("YES\n");
		// } else {
		// 	printf("NO\n");
		// }
	}

	return 0;
}