#include <stdio.h>
#define N 10000
int main(){

    int i, num, goal, t = 1;
    int a[N];
    scanf("%d %d",&num, &goal);
    for(i = 1;i<num;i++){
        scanf("%d", a+i);
    }
    while(t!=goal and t!=num){
        t = t + a[t];
    }
    if(t == goal)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
    
}