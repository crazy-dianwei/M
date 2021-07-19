* 信号由用户、系统、进程发送给进程的信息，通知进程状态的改变或者系统异常

* 产生条件：
    - 特殊的终端字符
    - 系统异常
    - 系统状态变化
    - kill命令或者kill函数


* 一个进程给另外一个进程发送信号的API是kill函数

* 信号处理函数：
    - typedef void (*__sighandler_t) (int);
    - 头文件定义的处理函数：
        - #define SIG_DFL((__sighandler_t) 0)   信号默认处理方式：结束进程(Term)、忽略信号(Ign)、结束进程并生成coredump文件(Core)、暂停进程(Stop)、继续进程(Cont)
        - #define SIG_IGN((__sighandler_T) 1)   忽略信号

| 信号 | 起源 | 默认行为 | 含义 |
| :----: | :----: | :----: | :----: |
| SIGHUP | POSIX | Term | 控制终端挂起 |
| SIGINT | ansi | Term | Ctrl + C |


* 与网络编程关系紧密的几个信号
    - SIGHUP、SIGPIPE和SIGURG
* 中断系统调用
    - SIGSTOP、SIGTTIN

* 设置信号处理函数
    - __sighandler_t signal(int sig, __sighandler_t _handler);
    - 更健壮的系统调用
        - int sigaction(int sig, const struct sigaction* act, struct sigaction *oact);


* 利用管道传递信号给主循环，利用IO多路复用监听管道的读端文件描述符上的可读事件



