#include <cstdio>
#include <cstring>
using namespace std;

long long a[202], DP[202][12][22];

void solve(int N, int M, int D){
	memset(DP, 0, sizeof(DP));
	long long sum;

	DP[0][0][0] = 1;
	for(int i = 1; i <= N; i++){
		for(int j = 0; j <= M; j++){
			for(int k = 0; k < D; k++){
				sum = (k+a[i]) % D;
                if(sum < 0)
                    sum += D;
				DP[i][j][k] += DP[i-1][j][k];
                if(j) DP[i][j][k] += DP[i-1][j-1][sum];
			}
		}
	}
	printf("%lld\n", DP[N][M][0]);
}

int main(){
	int N, Q, D, M;
	int set = 1;
    
	while(scanf("%d %d", &N, &Q) == 2){
		if(N == 0 && Q == 0)
            break;

		for(int i = 1; i <= N; i++)
			scanf("%lld", &a[i]);

		printf("SET %d:\n", set);
		for(int i = 1; i <= Q; i++){
			scanf("%d %d", &D, &M);
			printf("QUERY %d: ", i);
			solve(N, M, D);
		}
        set++;
	}

    return 0;
}