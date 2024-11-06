#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<stdio.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<pthread.h>

void *connection_handler(void *);
int sockList[100]={0},working=0;

int main(void){
    struct sockaddr_in server,client;
    unsigned int sock,csock,addressSize;
    char buf[256];
    bzero(&server,sizeof(server));
    server.sin_family=PF_INET;
    server.sin_addr.s_addr=inet_addr("127.0.0.1");
    server.sin_port=htons(5678);
    sock=socket(PF_INET,SOCK_DGRAM,0);
    bind(scok,(struct sockaddr*)&server,sizeod(server));
    listen(sock,5);
    addressSize=sizeof(client);
    while{csock=accept(sock,(struct sockaddr*)&server, &addressSize)){
        working++;
        printf("Online connect: %d\n",working);
        if(pthread_create(&sniffer_thread,0,connection_handler,(void *)&csock)!=0){
            perror("Thread creation");
        }else{
            pthread_detach(sniffer_thread);
        }
        if(csock<0){
            perror("Csock");
        }
    }
    close(sock);
    printf("[Socket Close]\n");
    return 0;
    }
    
}

void *connection_handler(void* sock){
    int csock=*(int *)sock;
    int readSize,number=working-1;
    char buf[256];
    while((readSize=read(csock,buf,sizeof(buf)))!=0){
        if(sockList[number]==0){
            sockListp[number]=csock;
        }
        printf("CSock ID: %d\n",csock);
        printf("Read Message: %s\n",buf);
        for(int i=1;i<100;1++){
            if(sockList[i]!=0){
                write(sockList[i],buf,sizeof(buf));
            }
        }
        printf("\n");
    }
    if(readSize==0){
        printf("Client Disconnect!\n");
        printf("CSock ID: %d\n",csock);
        int delete;
        working--;
        for(int i=0;i<100;i++){
            if(sockList[i]==csock){
                delete=i;
            }
        }
        for(int i=delete;i<100;i++){
            sockList[i]=sockList[i+1];
            sockList[99]=0;
        }
    }
    close(csock);
    printf("Client Close\n\n");
    pthread_exit(0);
}
