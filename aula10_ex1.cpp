#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

struct Status{
	int v;
    int score;
};

char dna1[50005], dna2[50005];
int v1[50005], v2[50005];
int len1, len2, ans, ptr1, ptr2, cnt;
int cost[4][4] = { { 0, 5, 5, 5 }, 
                   { 5, 0, 4, 5 },
                   { 5, 4, 0, 5 },
                   { 5, 5, 5, 0 } };
Status f1[50005], f2[50005];

int convert(char c){
	if(c == 'A')	return 0;
	if(c == 'G')	return 1;
	if(c == 'C')	return 2;
	if(c == 'T')	return 3;

	return -1;
}

int main(){
	while(cin >> dna1 >> dna2){
		//printf("enbtrou\n");
		len1 = strlen(dna1);
        len2 = strlen(dna2);
		for(int i = 0; i < len1; i++)
			v1[i] = convert(dna1[i]);
		for(int i = 0; i < len2; i++)
			v2[i] = convert(dna2[i]);

		ans = (len1 + len2) / 10 * 3;
		f1[0].v = -1;
        f1[0].score = 0;
        cnt = 1;

		for(int i = -1; i < len1 - 1; i++){
			ptr1 = ptr2 = 0;
			while (ptr1 < cnt){
				int pos = f1[ptr1].v;
                int score = f1[ptr1].score;

				if((ptr1 + 1 == cnt || score < f1[ptr1 + 1].score + 3 * (f1[ptr1 + 1].v - pos)) &&
					(ptr2 == 0 || score < f2[ptr2 - 1].score + 3 * (pos - f2[ptr2 - 1].v + 1)) &&
					(score + 3 * abs((int)(len1 - i) - (int)(len2 - pos)) <= ans)){
					if(pos + 1 < len2 && v1[i + 1] == v2[pos + 1]){
						f2[ptr2].v = pos + 1;
                        f2[ptr2++].score = score;
                    }
					else{
						if(ptr2 == 0 || f2[ptr2 - 1].v != pos){
							f2[ptr2].v = pos;
                            f2[ptr2++].score = score + 3;
                        }
						else
							f2[ptr2 - 1].score = min(f2[ptr2 - 1].score, score + 3);
						if(pos < len2 - 1){
							f2[ptr2].v = pos + 1;
							f2[ptr2++].score = score + cost[v1[i + 1]][v2[pos + 1]];
							if (ptr1 + 1 == cnt || f1[ptr1 + 1].v != pos + 1){
								f1[ptr1].v = pos + 1;
                                f1[ptr1--].score = score + 3;
                            }
							else
								f1[ptr1 + 1].score = min(f1[ptr1 + 1].score, score + 3);
						}
					}
				}
				ptr1++;
			}
			cnt = ptr2;
			memcpy(f1, f2, cnt * sizeof * f1);
		}
		ans = f2[ptr2 - 1].score + 3 * (len2 - 1 - f2[ptr2 - 1].v);
		printf("%d\n", ans);
	}

	return 0;
}