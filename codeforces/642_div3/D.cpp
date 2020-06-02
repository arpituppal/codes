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

struct compare {

	bool operator()(const pair<int, pair<int, int> > &l, const pair<int, pair<int, int> > &r) {

		if(l.first < r.first) {
			return true;
		}

		if(l.first == r.first) {

			if(l.second.first > r.second.first) {
				return true;
			}
		}

		return false;
	}
};

int main() {


	int t;
	cin>>t;
	while(t--) {

		int n, it = 1, i;
		priority_queue<pair<int,pair<int, int> >,vector<pair<int,pair<int, int> > >, compare> PQ; 
		
		cin>>n;

		int arr[n+1];

		PQ.push(MP(n, MP(1, n)));

		while(!PQ.empty()) {

			int sz = PQ.top().first;
			int st = PQ.top().second.first;
			int end = PQ.top().second.second;
			PQ.pop();

			int mid, newsz;

			if((end - st + 1) % 2) {
				mid = (end+st)/2;
				
			}  else {
				mid = (end+st-1)/2;
			}


			arr[mid] = it;
			it++;

			if(sz == 1) {
				continue;
			}

			if(sz % 2) {
			   PQ.push(MP((sz-1)/2, MP(st, mid-1)));
			   PQ.push(MP((sz-1)/2, MP(mid+1, end)));
			} else {

				if(sz > 2) {
					PQ.push(MP(sz/2 -1, MP(st, mid-1)));
				}

				PQ.push(MP(sz/2, MP(mid+1, end)));
			}
		}

		for(i = 1 ; i <= n;i++) {
			cout<<arr[i]<< " ";
		}

		cout<<endl;
	}

	return 0;
}