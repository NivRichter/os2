#include "kernel/types.h"
#include "user/user.h"
#include "kernel/fcntl.h"

struct sigaction {
void (*sa_handler)(int);
uint sigmask;
};

void t_handler(int a){
    fprintf(2, "handler !\n");
    return ;
}
int main(int argc, char** argv){
    fprintf(2, "Hello world!\n");
    fprintf(2, "size %d\n", sizeof(void *));

    struct sigaction* s = malloc(sizeof(struct sigaction));
    s->sa_handler = (void *)t_handler;
    s->sigmask = 0;
    sigaction(4,s,0);
    kill(getpid(),9);
    exit(0);



    //s->sigmask=4;
    char c = 'z';
    write(2,&c,1);
    //int f = getpid();
    int child = 0;
    if(fork()==0){
        kill(getpid(),16);

        fprintf(2, "Hello child!\n");
        exit(0);

    }
    fprintf(2,"child pid: %d",wait(&child));
    fprintf(2, "Hello father!\n");

    exit(0);
}