#include <zmq.h>
#include <stdio.h>
#include <string.h>
#include<iostream>

// server
int main() {
    // 初始化一个ZMQ环境上下文
    void *context = zmq_ctx_new();
    // ZMQ_SUB类型的套接字用来订阅发布者分发下来的数据。
    void *responder = zmq_socket(context,ZMQ_SUB);

    // ZMQ_SUBSCRIBE属性将会在ZMQ_SUB类型的socekt上创建一个新的消息过滤标志
    // 一个option_value的长度是0的过滤属性会订阅所有的广播消息
    zmq_setsockopt(responder,ZMQ_SUBSCRIBE,"",0);
    // 将responder连接到5555端口
    zmq_connect(responder,"tcp://localhost:5555");

    // 等待客户端请求
    while(1){
        zmq_msg_t request;
        // 将msg参数引用的ZMQ消息对象进行初始化，使其成为一个空消息
        zmq_msg_init (&request);
        // 从responder中读取消息帧，并存储在request消息结构中。
        zmq_msg_recv (&request, responder, 0);
        char buf[100];
        int size = zmq_msg_size(&request);
        buf[size]='\0';
        // 将request中的内容复制到buf
        memcpy (buf, zmq_msg_data(&request), size);
        // 输出buf中的内容
        printf("%s\n",buf);
        // 释放request
        zmq_msg_close (&request);
    }
    // 销毁responder
    zmq_close (responder);
    // 终结上下文context
    zmq_term (context);
    return 0;
}
