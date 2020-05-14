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
#define LL long long int
#define MAX 300005
#define MIN(a, b) (a) < (b) ? (a) : (b)

using namespace std;

LL presum[MAX], suffdiffsum[MAX], arr[MAX];
int main() {

	int n, i;
	scanf("%d", &n);
	
	LL ans;
	
	for(i = 0 ; i < n; i++) {
		scanf("%lld", &arr[i]);
	}
	
	sort(arr, arr+n);
	
	/*stores the sum till ith tree provided all i-1 trees are cut */
	
	for(i = 1; i<n; i++) {
		presum[i] = presum[i-1] + arr[i-1];
	}
	
	/*stores the sum till ith tree provided all i+1 trees are made of height = height of ith tree*/
	
	for(i = n-2; i>=0 ; i--) {
		suffdiffsum[i] = suffdiffsum[i+1] + (n-i-1) * (arr[i+1] - arr[i]); 
		
	}
	
	// printf("pre \n");
	// for(i = 0; i < n; i++) {
	// 	printf("%lld ", presum[i]);
	// }
	// printf("\ndiff\n");
	// for(i = 0; i < n; i++) {
	// 	printf("%lld ", suffdiffsum[i]);
	// }
	
	ans = presum[0] + suffdiffsum[0];
	
	for(i = 1; i< n ; i++) {
		ans = MIN(ans, (presum[i] + suffdiffsum[i]));
	}
	
	printf("%lld\n", ans);
	return 0;
}
