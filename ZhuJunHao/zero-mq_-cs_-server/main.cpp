
#include <zmq.h>
#include <stdio.h>
#include <string.h>
#include<zmq.hpp>
#include<iostream>


//C++ version
using namespace zmq;
using namespace std;
int main(){
    //初始化一个ZMQ环境上下文
    context_t context(1);
    //采用订阅发布模式，一端负责发数据，一端收数据
    //这里负责收数据
    socket_t socket(context,ZMQ_SUB);
    //由一个socket创建一个对外连接
    socket.connect("tcp://localhost:5555");
    //必须加下面的函数才能让订阅发布模式收到数据
    socket.setsockopt(ZMQ_SUBSCRIBE,"",0);
    while(true){
        message_t msg;
        //接收数据
        socket.recv(&msg);
        std::cout<<"size="<<msg.size()<<std::endl;
        char buf[100];
        buf[msg.size()]='\0';
        memcpy(buf,msg.data(),msg.size());
        std::cout<<buf<<std::endl;
    }
    socket.disconnect("tcp://localhost:5555");
    socket.close();
    return 0;
}