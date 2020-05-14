#include<bits/stdc++.h>
#define LL long long int
using namespace std;
 
int bit[1000000];
 
void update(LL idx, LL val, LL n) {
    
    while(idx <= n) {
        bit[idx] += val;
        idx += (idx & -idx);
    }
}
 
LL query(LL idx, LL n) {
    
    LL sum = 0;
    while(idx > 0) {
        sum += bit[idx];
        idx -= (idx & -idx);
    }
    
    return sum;
}
 
int isRound(LL n) {
    
    if(n < 0) {
        return 0;
    }
    
    int lastDig = n%10;
    LL revnum = 0;
    
    while(n > 0) {
        revnum = revnum*10 + (n%10);
        n /= 10;
    }
    
    int firstDig = revnum%10;
    
    return firstDig == lastDig;
}
 
int main() {
    
    LL n,q, arr[1000000],i,k,l,r,op, hashi[1000000];
    cin>>n>>q;
   
    for(i = 1; i <= n; i++) {
        cin>>arr[i];
        
        //int rnd = isRound(arr[i]);
    
        if(isRound(arr[i])) {
            hashi[i] = 1;
            update(i, 1, n);
        }
    }
    
    while(q--) {
        
        cin>>op>>l>>r;
        if(op == 1) {
            printf("%lld\n", (query(r, n) - query(l-1, n)));
        } else {
            
            int rnd = isRound(r);
            
            if(rnd == 0 && hashi[l] == 1) {
                hashi[l] = 0;
                update(l, -1, n);
            }
            
            if(rnd == 1 && hashi[l] == 0) {
                hashi[l] = 1;
                update(l, 1, n);
            }
        }
    }
    
    return 0;
}