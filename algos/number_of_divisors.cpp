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
#define LIM 20000001

int numdiv[LIM], prime[LIM];

void sieve() {

	int i, j;
	
	numdiv[1] = 1;

	//store largest prime divisor for each number
	for(i = 2; i * i < LIM; i++) {
		
		if(prime[i] == 0) {
			prime[i] = i;
			for(j = 2*i; j < LIM; j += i) {
				prime[j] = i;
			}
		}
	}
	
	for(; i < LIM; i++ ){
		if(prime[i] == 0) {
			prime[i] = i;
		}
	}
	
	numdiv[0] = 0;
	numdiv[1] = 1;

	//prime divisor method to calculate number of divisors(including 1 and itself) for a number
	for(i = 2; i <LIM; i++) {
		
		int cnt = 0;
		j = i;
		while(j % prime[i] == 0) {
			cnt++;
			j /= prime[i];
		}
		numdiv[i] = numdiv[j] * (cnt + 1);
	}
}

int main() {

	sieve();
	return 0;
}

