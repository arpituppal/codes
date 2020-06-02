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

int main() {

	priority_queue<int, vector<int> > pqA;
	priority_queue<int, vector<int> > pqB;
	
	LL n, i, sumA = 0, sumB = 0, num;
	cin>>n;

	for(i = 0 ; i < n; i++) {
		cin>>num;
		pqA.push(num);
	}

	for(i = 0 ; i < n; i++) {
		cin>>num;
		pqB.push(num);
	}

	int chance = 0;

	while(!pqA.empty() || !pqB.empty()) {
		
		if(chance == 0) {

			if(!pqA.empty() && (pqB.empty() || pqA.top() > pqB.top())) {
				sumA += pqA.top();
				pqA.pop();
			} else {
				pqB.pop();
			}
		} else {
			if(!pqB.empty() && (pqA.empty() || pqB.top() > pqA.top())) {
				sumB += pqB.top();
				pqB.pop();
			} else {
				pqA.pop();
			}
		}

		chance = chance == 0 ? 1 : 0;
	}

	cout<<(sumA - sumB) <<endl;
	return 0;
}