     #include<stdio.h>
    typedef unsigned long long bignum;
    int color(int year, bignum pos){
    if(year==0 && pos==0){
    return 1;
    }
    if(pos < 1ULL<<(year-1)){
    return !color(year-1, pos);
    }
    else return color(year-1, pos-(1ULL<<(year-1)));
    }
    int main(){
    bignum year, pos;
    scanf("%llu %llu", &year, &pos);
    if(color(year, pos))
    printf("red\n");
    else printf("blue\n");
    return 0;
    }