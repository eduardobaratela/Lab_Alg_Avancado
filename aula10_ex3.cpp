#include <cstdio>
#include <algorithm>
#define N 1000010
using namespace std;

char s[N];
int sum[N],dp[N];

int main(){
	int t,n,k,ans;

	scanf("%d", &t);

	for(int j=0; j<t; j++){
		scanf("%d %d %s",&n, &k, s);
		for(int i=0; i<n; i++){
            sum[i+1] = sum[i] + s[i]-'0';
		    dp[i+1] = sum[i] + (s[i]=='0');
        }
		for(int i=k; i<n; i++)
			dp[i+1]=min(dp[i+1],dp[i-k+1]+sum[i]-sum[i-k+1]+(s[i]=='0'));

		ans=sum[n];
		for(int i=1; i<=n; i++)
			ans=min(ans, dp[i]+sum[n]-sum[i]);

		printf("%d\n", ans);
	}

	return 0;
}