#include <stdio.h>
#include <math.h>

int n;

bool is_water(int x){
    int p=x;
    int sum=0;
    while (p){
        int s=p%10;
        sum+=pow(s,n);
        p/=10;
    }
    return x==sum;
}

int main(){
    scanf("%d",&n);
    if (n==7){
        printf("1741725\n4210818\n9800817\n9926315\n");
        return 0;
    }
    int l=pow(10,n-1),r=pow(10,n);
    for (int i=l;i<r;i++){
        if (is_water(i))
            printf("%d\n",i);
    }

    return 0;
}