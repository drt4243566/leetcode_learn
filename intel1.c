#include <stdio.h>
#include <string.h>

void removeStr(char* str){
    int n = strlen(str);
    int dic[1000] = {0};
    int cover = 0;
    for(int i=0;i<=n;i++){
        int cnt = dic[str[i]-'0'];
        if(cnt==0){
            dic[str[i]-'0']++;
        }else{
            cover++;
        }
        if(cover>0){
            str[i] = str[i+cover];
        }
    }
}

int main(){
    char s = "hello";
    removeStr(s);
    printf("%s/n",s);
    return 0;
}