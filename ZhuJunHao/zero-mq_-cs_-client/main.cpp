
#include <zmq.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include<zmq.hpp>
#include<iostream>

//C++ version
using namespace zmq;
using namespace std;
int main(){
    //初始化一个ZMQ环境上下文
    context_t context(1);
    //订阅发布模式的发布方
    socket_t socket(context,ZMQ_PUB);
    //绑定一个socket，接收发来的链接请求
    socket.bind("tcp://*:5555");
        char message[6][100] ={
            "We drive Benz,Rolls-Royce",
            "You drive mazda",
            "Of course there's a traffic jam",
            "you drive mazda",
            "You are not qualified to attend this meeting",
            "Go back and wait for the news"
    };
    for(int i=0;i < 6;i++){
        //循环发送数据
        message_t msg(strlen(message[i]));
        memcpy(msg.data(),&message[i],strlen(message[i]));
        cout<<"size="<<msg.size()<<endl;
        sleep(1);
        socket.send(msg);
    }
    socket.close();
    return 0;
}
