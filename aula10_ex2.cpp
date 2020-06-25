#include <cstdio>
#include <algorithm>
#define N 100010
using namespace std;

int s[N],dp[N];
int ans;

int main(){
	int t,n;

	scanf("%d",&t);
	for(int k = 0; k<t; k++){
		scanf("%d",&n);
		for(int i=0; i<n; i++){
            scanf("%d",&s[i+1]);
            dp[i+1]=1;
        }

		ans=1;
		for(int i=1; i<=n; i++){
			for(int j=i; j<=n; j+=i){
				if(s[i]<s[j])
                    dp[j]=max(dp[j],dp[i]+1);
                ans=max(ans,dp[j]);
            }
        }            

		printf("%d\n",ans);
	}

	return 0;
}