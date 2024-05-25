#include <stdio.h>

int m,n;

int main(){
    scanf("%d%d",&m,&n);
    int a[7][7];
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    }
    int ans[7][7];
    for (int i=0;i<n;i++){
        int head=m%n;
        int cnt=0;
        // 1 2 3 4 5 6 7 8
        // 7 8 1 2 3 4 5 6

        for (int j=head;j<n;j++)
            ans[i][j]=a[i][cnt++];

        for (int j=0;j<head;j++)
            ans[i][j]=a[i][cnt++];
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++)
            printf("%d ",ans[i][j]);
        printf("\n");
    }

    return 0;
}