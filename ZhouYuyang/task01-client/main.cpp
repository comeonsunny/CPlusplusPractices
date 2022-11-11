#include <zmq.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

// client
int main() {
    // zmq_ctx_new创建上下文环境
    void *context = zmq_ctx_new();
    // ZMQ_PUB套接字用来使发布者分发数据
    void *push = zmq_socket(context, ZMQ_PUB);
    // 将push连接到"tcp://*:5555"
    zmq_bind(push, "tcp://*:5555");
    //发送文本
    char message[6][100] ={
            "",
            "You were with me one minute before 3 p.m. on April 16, 1960.",
            "Because of you, I will remember this minute.",
            "From now on, we are friends for one minute.",
            "This is a fact. You can't change it, because it's gone.",
            "I'll come back tomorrow."
    };

    for(int i=0;i<6;i++){
        zmq_msg_t msg;
        // zmq_msg_init()函数会将msg参数引用的ZMQ消息对象进行初始化，使其成为一个空消息。
        zmq_msg_init(&msg);
        // 拷贝message[i]数据进入msg中
        memcpy (&msg, message[i], strlen(message[i]));
        // 根据message[i]创建消息，并将该消息添加到消息队列push
        zmq_send (push, message[i], strlen(message[i]),0);
        printf ("正在发送%d...%s\n",i,message[i]);

        sleep(1);
        // 销毁msg
        zmq_close (&msg);
    }
    return 0;
}