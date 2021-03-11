#include <iostream>
#include <sys/types.h>
#include <unistd.h>
//using namespace std;
int main(void){
    pid_t pid;
    signal(1,SIG_IGN);
    printf("before fork pid:%d\n",getpid());
    int abc=10;
    
}