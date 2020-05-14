
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
#define N 1000001

int main() {


	long long int n = 99999999999;
	vector<int> vec;
	int i, j;

	int sieve[N];

	for(i = 2; i*i<N; i++) {
        
        if(sieve[i] == 0) {
           vec.push_back(i);
          for(j = i*i; j<=N;j+=i) {
             sieve[j] = 1;
         }
        }
    }

    for(i = 0; i < vec.size(); i++) {

		if(n % vec[i] == 0) {

			printf("%d", vec[i]);

			while(n % vec[i] == 0) {
				n = n/vec[i];
			}

		}    	
    }
}