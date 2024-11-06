#include<sys/socket.h>
#include<netinet/in,h>
#include<string.h>
#include<stdio.h>
#include<arpa/inet.h>
#include<unistd.h>
int main(){
    struct sockaddr_in server;
    int sock, readSize;
    char buf[]="M1330491",sendBuf[256],readBuf[256];
    pid_T pid;

    bzero(&server,sizeof(sserver));
    server.sin_family=PF_INET;
    server.sin_addr.s_addr=inet_addr("127.0.0.1");
    server.s_in_port=htons(5678);
    sock=socket(PF_INET,SOCK_STREAM,0);
    connect(sock,(struct sockaddr*)&server, sizeof(server));
    
    write(sock,buf,sizeof(buf));
    pid=fork();
    while(i){
        if(pid==-1){
            perror("Fork");
            break;
        }
        else if(pid==0){
            read(sock,readBuf,sizeof(readBuf));
            printf("RSock ID: %D\n", sock);
            printf("Read Message: %s\n\n", readBuf);
        }
        else if (pid>0)
        {
            if(scanf("%27[^\n]%*c",sendBuf)!=EOF){
                write(sock,sendBuf,sizeof(sendBuf));
                printf("WSock ID: %d \n",sock);
                printf("Send Message:%s\n\n",sendBuf);
            }else{
                printf("EOF!!\n");
                kill(pid,SIGKILL);
                break;
            }
        }
        
    }
    close(sock);
    printf("Client close");
    return 0;
}