#include <iostream>
#include <cstdio>
#include <cmath>
#define N 65001
using namespace std;

int pt = 0;
bool check[N];

void sieve(){
    memset(check, true, sizeof(check));
 
    check [0] = false;
    check [1] = false;
 
    for(int i = 4; i < N; i += 2 ) 
        check[i] = false;
 
    for(int i = 3; i * i <= N; i += 2){
        if(check[i]){
            for(int j = i * i; j < N; j += 2*i) 
                check[j] = false;
        }
    }

    
}

long long fermat(long long b,long long p,long long mod){
    if(p == 0)
        return 1;
    else if(p % 2 == 0){
        long long ans = fermat(b,p/2,mod);
        return ((ans%mod)*(ans%mod))%mod;
    }
    else{
        return ((b%mod)*((fermat(b,p-1,mod))%mod))%mod;
    }
}

bool carmichael(long long n){
    if(check[n])
        return false;
    else{
        for(int i=2;i<=n-1;i++){
            if(fermat(i,n,n) != i)
                return false;
        }
    }

    return true;
}

int main(){
    long long n;

    sieve();

    while(scanf("%lld", &n) == 1){
        if(n == 0)
            break;
        if(carmichael(n))
            printf("The number %lld is a Carmichael number.\n",n);
        else printf("%lld is normal.\n",n);
    }

    return 0;
}