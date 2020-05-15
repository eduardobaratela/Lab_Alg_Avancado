#include <cstdio>
#include <cmath>
using namespace std;

int main(){
    int p,q,r,s,t,u;
    double low,high,mid,f;
    
    while(scanf("%d %d %d %d %d %d",&p,&q,&r,&s,&t,&u)==6){        
        low=0.0; high=1.0;
        
        for(int i=0; i<50; i++){
            mid=(low+high)/2;
            
            f=p*exp(-mid)+q*sin(mid)+r*cos(mid)+s*tan(mid)+t*mid*mid+u;
            
            if(f < 1e-13 && f > -1e-13){
                printf("%.4f\n", low);
                break;
            }
            
            if(f>0) low=mid;
            else high=mid;
        }
        
        if(f > 1e-13 || f < -1e-13)
        printf("No solution\n");
    }
    
    return 0;
}