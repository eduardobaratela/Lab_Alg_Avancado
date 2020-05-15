#include <cstdio>
#include <algorithm>
using namespace std;

int n, k;
int km[605], pos[605];

bool check(int x){
    int y = x;
    int sleep = 0;
    for(int i=0; i<n+1; i++){
        int dif = pos[i+1] - pos[i];
        if(y >= dif) 
            y -= dif;
        else{
            sleep++;
            y = x-dif;              
        }    
        if(sleep>k || y<0)
            return false;
    }     
    return true;
}

int main(){
    while (scanf("%d %d", &n, &k) == 2){
        for(int i=1; i<n+2; i++)
            scanf("%d", &km[i]);
          
        pos[0] = 0;
        for(int i=1; i<n+2; i++)
            pos[i] = km[i] + pos[i-1];       
          
        int left = pos[0];
        int right = pos[n+1];
        int dist = 1000000;
          
        while(left <= right){
            int mid = ((long long)left+right)/2;
            if(check(mid)){
                dist = min(dist, mid);
                right = mid-1;
            }
            else 
                left = mid+1;
        }   
        printf("%d\n", dist);
    }

    return 0;
}