#include <iostream>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <cstring>
using namespace std;

const int PORT=8889;
const int BACKLOG=5;
const int CONN_MAX=8;
const int BUF_SIZE=500;
const char EXIT_CODE[10]="quit";  //退出码

int main()
{
    sockaddr_in s_in;//server address structure
    int s_fd;//服务器端套接字
    int c_fds[CONN_MAX];//客户端套接字
    int c_location;
    for(int i=0;i<CONN_MAX;i++){
        c_fds[i]=0;
    }
    char inputMess[BUF_SIZE];
    char buf[BUF_SIZE];//content buff area
    string tem;
    memset(&s_in,0,sizeof(s_in));

    s_in.sin_family = AF_INET;//IPV4 communication domain  
    s_in.sin_addr.s_addr = INADDR_ANY;//accept any address  
    s_in.sin_port = htons(PORT);//listen port

    if((s_fd=socket(AF_INET,SOCK_STREAM,0))<0){
        perror("socket error");
        return 1;
    }//socket(int domain, int type, int protocol)
    if(bind(s_fd,(struct sockaddr *)&s_in,sizeof(s_in))<0){
        perror("bind error");
        return 1;
    }
    if(listen(s_fd,BACKLOG)<0){
        perror("listen error");
        return 1;
    }//

    fd_set server_fd_set;
    int max_fd;
    timeval tv;  //超时时间设置

    while(1){
        tv.tv_sec=20;
        tv.tv_usec=0;
        max_fd=-1;
        FD_ZERO(&server_fd_set);
        FD_SET(STDIN_FILENO,&server_fd_set);
        if(max_fd<STDIN_FILENO){
            max_fd=STDIN_FILENO;
        }
        FD_SET(s_fd,&server_fd_set);
        if(max_fd<s_fd){
            max_fd=s_fd;
        }

        //客户端连接
        for(int i=0;i<CONN_MAX;i++){
            if(c_fds[i]!=0) {
                FD_SET(c_fds[i], &server_fd_set);
                if(max_fd<c_fds[i]){
                    max_fd=c_fds[i];
                }
            }
        }
        //select第一个参数必须设为max_fd+1
        int ret=select(max_fd+1,&server_fd_set, nullptr, nullptr,&tv);
        if(ret<0){
            perror("select error");
            continue;
        } else if(ret==0){
            //select超时
            continue;
        } else{
            if(FD_ISSET(STDIN_FILENO,&server_fd_set)){
                bzero(inputMess,BUF_SIZE);
                cin.getline(inputMess,BUF_SIZE);
                if(strncmp(inputMess,EXIT_CODE,20)==0){
                    close(s_fd);
                    return 0;
                }
                for(int i=0;i<CONN_MAX;i++){
                    if(c_fds[i]!=0){
                        send(c_fds[i],inputMess,BUF_SIZE,0);
                    }
                }
            }

            //如果有新的client请求连接，尝试完成连接
            if(FD_ISSET(s_fd,&server_fd_set)){
                sockaddr_in c_in;
                socklen_t len;
                int c_fd=accept(s_fd,(sockaddr *)&c_in,&len);
                cout<<"新连接请求,ip地址: "<<inet_ntoa(c_in.sin_addr)<<endl;
                if(c_fd>0){
                    c_location=-1;
                    for(int i=0;i<CONN_MAX;i++) {
                        if (c_fds[i] == 0) {
                            c_location = i;
                            c_fds[i] = c_fd;
                            break;
                        }
                    }
                    if(c_location>=0){
                        cout<<c_location<<"号新客户端加入成功\n";
                        bzero(inputMess,BUF_SIZE);
                        strcpy(inputMess,"欢迎！！\n");
                        send(c_fd,inputMess,BUF_SIZE,0);
                    } else{
                        cout<<"新客户加入失败，客户端连接数达到最大\n";
                        bzero(inputMess,BUF_SIZE);
                        strcpy(inputMess,"连接失败，客户端连数量已达到最大\n");
                        send(c_fd,inputMess,BUF_SIZE,0);
                    }
                }
            }

            //遍历所有连接，处理收到的字符串
            for(int i=0;i<CONN_MAX;i++){
                if(c_fds[i]!=0){
                    if(FD_ISSET(c_fds[i],&server_fd_set))
                    {
                        bzero(buf,BUF_SIZE);
                        long rev_num=recv(c_fds[i],buf,BUF_SIZE,0);
                        if(rev_num>0){
                            if(rev_num>BUF_SIZE){
                                rev_num=BUF_SIZE;
                                buf[rev_num]='\0';

                            }
                            cout<<i<<":\t"<<buf<<endl;
                        } else if(rev_num<0){
                            printf("从%d获取信息失败\n",i);
                        } else{
                            FD_CLR(c_fds[i],&server_fd_set);
                            c_fds[i]=0;
                            cout<<i<<"号客户端退出了\n";
                        }
                    }
                }
            }
        }
    }
    return 0;
}