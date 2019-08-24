#include<stdio.h>
#include<unistd.h>
#include <sys/wait.h>


int main() {
    pid_t pid;
    pid = fork();
    if (pid < 0) {
        fprintf(stderr, "fork failed\n");
        return 1;
    } else if (pid == 0) {
        execlp("/bin/ls", "ls", NULL);
    } else {
        wait(NULL);
        printf("child complete\n");
    }
    return 0;
}