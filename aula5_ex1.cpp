#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <string.h>
#define N 10001000
using namespace std;
 
bool check[N];
vector <long long> prime;
 
bool isPrime(long long p){
    if(p < 2 || p % 2 == 0) 
        return false;
 
    int len = sqrt(p * 1.0);
 
    for(int i = 3; i <= len; i += 2){
        if ( p % i == 0 ) 
            return false;
    }
 
    return true;
}
 
void sieve(){
    memset(check, true, sizeof(check));
 
    check [0] = false;
    check [1] = false;
 
    for(int i = 4; i < N; i += 2 ) 
        check[i] = false;
 
    for(int i = 3; i * i <= N; i += 2) {
        if(check[i] ) {
            for(int j = i * i; j < N; j += 2*i) 
                check[j] = false;
        }
    }
 
    prime.push_back (2);
 
    for(int i = 3; i < N; i += 2 ) {
        if(check[i] ) 
            prime.push_back (i);
    }
}
 
long long solve(long long n){
    int i = 0;
    int cnt = 0;
    long long tmp = n;
    long long resp = -1;
 
    while(prime[i] * prime[i] <= n ){
        if(n%prime[i] == 0){
            resp = prime[i];
            cnt++;
        }
        while(tmp % prime[i] == 0 ){
            tmp /= prime[i];
        }
        i++;
    }
 
    if(tmp > 1 ){
        resp = tmp;
        cnt++;
    }
    if(cnt <= 1)
        resp = -1;

    return resp;
}
 
int main(){
    sieve();
    long long n;
    long long resp;
 
    cin >> n;
    while(n != 0 ) {
        if(n < 0 )
            n *= -1;
 
        if((n < N && check[n]) || isPrime (n))
            printf ("-1\n");
        else{
            resp = solve(n);
            cout << resp << endl;
        }

        cin >> n;
    }

    return 0;
}