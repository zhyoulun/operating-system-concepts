#include <zconf.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int sum;

void *runner(void *params);

int main(int argc, char *argv[]) {
    pthread_t tid;
    pthread_attr_t attr;
    if (argc != 2) {
        fprintf(stderr, "usage: cmd <integer value>\n");
        return 1;
    }
    if (atoi(argv[1]) < 0) {
        fprintf(stderr, "%d must be >=0\n", atoi(argv[1]));
        return 1;
    }

    pthread_attr_init(&attr);
    pthread_create(&tid, &attr, runner, argv[1]);
    pthread_join(tid, NULL);
    printf("sum=%d\n", sum);
    return 0;
}

void *runner(void *params) {
    int i, upper = atoi(params);
    sum = 0;
    for (i = 0; i <= upper; i++) {
        sum += i;
    }
    pthread_exit(0);
}
