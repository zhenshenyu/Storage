#include <iostream>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <cstring>
#include <thread>
using namespace std;
void thread_task(int);

const int BUF_SIZE=500;
const char EXIT_CODE[20]="quit";

int main() {
    int c_fd;
    ssize_t len;
    sockaddr_in s_in;
    char inputBuff[BUF_SIZE];
    memset(&s_in,0,sizeof(s_in));
    s_in.sin_family=AF_INET;
    s_in.sin_addr.s_addr=inet_addr("127.0.0.1");
    s_in.sin_port=htons(8889);

    if((c_fd=socket(PF_INET,SOCK_STREAM,0))<0){
        perror("socket error");
        return 1;
    }
    if((connect(c_fd,(sockaddr *)&s_in,sizeof(s_in)))<0){
        perror("connect error");
        return 1;
    }
    cout<<c_fd<<endl;
    cout<<"connected to server"<<endl;
    bzero(inputBuff,BUF_SIZE);
    len=recv(c_fd,inputBuff,BUF_SIZE,0);
    if(len>0){
        inputBuff[len]='\0';
        cout<<inputBuff;
    };
    timeval tv;
    thread t(thread_task,c_fd);
    t.detach();
    while(1){
                bzero(inputBuff, BUF_SIZE);
                cin.getline(inputBuff, BUF_SIZE);
                if (strncmp(inputBuff, EXIT_CODE, 10) == 0) {
                    break;
                }
                send(c_fd,inputBuff,BUF_SIZE,0);
            }
    close(c_fd);
    return 0;
}

void thread_task(int c_fd){
    char buf[BUF_SIZE];
    ssize_t length;
    while(1){
        bzero(buf,BUF_SIZE);
        length=recv(c_fd,buf,BUF_SIZE,0);
        if(length>0){
            buf[length]='\0';
            cout<<"server:\t"<<buf<<endl;
        } else if(length==-1){
            return;
        }
    }
}