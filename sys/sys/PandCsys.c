#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>
#include <semaphore.h>

#define BUFFER_SIZE 10

int buffer[BUFFER_SIZE];
int count = 0;
int in = 0;
int out = 0;

pthread_mutex_t mutex;
sem_t FULL, EMPTY;

void *producer(void *arg) {
    int item = rand() % 100;

    sem_wait(&EMPTY);
    pthread_mutex_lock(&mutex);

    buffer[in] = item;
    in = (in + 1) % BUFFER_SIZE;

    pthread_mutex_unlock(&mutex);
    sem_post(&FULL);

    count++;
    printf("고객번호[%d]님이 주문제작한 기타가 [제작 완료]되었습니다.\n", item);
    free(arg);
    pthread_exit(NULL);
}

void *consumer(void *arg) {
    sem_wait(&FULL);
    pthread_mutex_lock(&mutex);

    int item = buffer[out];
    out = (out + 1) % BUFFER_SIZE;

    pthread_mutex_unlock(&mutex);
    sem_post(&EMPTY);

    count--;
    printf("고객번호[%d]님이 주문제작한 기타가 [배송 완료] 되었습니다.\n", item);
    free(arg);
    pthread_exit(NULL);
}


int main(int argc, const char *argv[]) {
    int pid, cid;
    pthread_t pro[7];
    pthread_t con[7];

    sem_init(&FULL, 0, 0);
    sem_init(&EMPTY, 0, BUFFER_SIZE);
    pthread_mutex_init(&mutex, NULL);

    for (int i = 0; i < 7; i++) {
        int *producer_id = malloc(sizeof(int));
        *producer_id = i;

        int *consumer_id = malloc(sizeof(int));
        *consumer_id = i;

        pid = pthread_create(&pro[i], NULL, producer, producer_id);
        if (pid < 0) {
            fprintf(stderr, "Error creating producer thread\n");
            return 1;
        }

        cid = pthread_create(&con[i], NULL, consumer, consumer_id);
        if (cid < 0) {
            fprintf(stderr, "Error creating consumer thread\n");
            return 1;
        }
    }

    for (int i = 0; i < 7; i++) {
        pthread_join(pro[i], NULL);
        pthread_join(con[i], NULL);
    }

    sem_destroy(&FULL);
    sem_destroy(&EMPTY);
    pthread_mutex_destroy(&mutex);

    return 0;
}
