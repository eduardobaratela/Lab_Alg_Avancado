#include <cstdio>

int main() {
	int T;
	scanf("%d", &T);

	for(int t = 0; t < T; t++){
		int N, P, W, G, MW, resp;
		int DP[31];
        for(int i = 0; i < 31; i++)
            DP[i] = 0;

		scanf("%d", &N);
		for(int i = 0; i < N; i++){
			scanf("%d %d", &P, &W);
			for(int j = 30; j >= W; j--)
				if(DP[j] < DP[j-W]+P)
					DP[j] = DP[j-W]+P;
		}

        resp = 0;
		scanf("%d", &G);
		for(int i = 0; i < G; i++){
			scanf("%d", &MW);
			resp += DP[MW];
		}
		printf("%d\n", resp);
	}

    return 0;
}