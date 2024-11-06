#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
int main(void){
    pid_t pid_test;
    int A=3,B=4;
    pid_test=fork();

    if(pid_test<0){
        printf("error in fork");
    }else if (pid_test==0){
        printf("I am child process,ID is %d\n",A);
    }
    else{
        printf("I am parent process,ID is %d\n",B);
        pause();
    }
    printf("End fork!");
}