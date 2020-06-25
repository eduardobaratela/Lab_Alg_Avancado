#include <iostream>  
#include <cstdio>  
#include <cmath>  
#include <cstring>  
using namespace std; 

const int N=2e6+5;  
long long cnt[N],sum[N];  
  
int main(){  
    int n, x, y, a;  

    scanf("%d %d %d", &n, &x, &y);  
    memset(cnt,0,sizeof(cnt));  
    memset(sum,0,sizeof(sum));  

    for(int i=1;i<=n;i++){  
        scanf("%d",&a);  
        cnt[a]++;
        sum[a]+=a;  
    }  

    for(int i=1; i<=N; i++){  
        cnt[i]+=cnt[i-1];  
        sum[i]+=sum[i-1];  
    }

    long long ans= (long long)n*x;
    int div = x / y;
    for(int i=2; i<=1e6; i++){  
        long long tmp = 0;  
        for(int j=i; j<=N && tmp<ans; j+=i){
            if(j-div > j-i+1)
                tmp += (cnt[j-div-1] - cnt[j-i])*x;  
            int f = max(j-i+1,j-div);  
            tmp+=((cnt[j]-cnt[f-1])*j-(sum[j]-sum[f-1]))*y;  
        }  
        ans=min(ans,tmp);  
    }  
    printf("%lld\n",ans);  

    return 0;  
}  