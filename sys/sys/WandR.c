#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define ARRAY_SIZE 10

int sharedArray[ARRAY_SIZE];
int writeIndex = 0;
int readIndex = 0;
int LottoCode[10] = {13,65,42,12,8,23,27,89,15,31};

pthread_mutex_t mutex;

void *writer(void *arg) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        // 쓰기 작업
        sharedArray[writeIndex] = LottoCode[i];
        printf("TV : %2d번째 숫자는 %2d\n",writeIndex + 1, LottoCode[i]);
        writeIndex = (writeIndex + 1) % ARRAY_SIZE;
    }
    pthread_exit(NULL);
}

void *reader(void *arg) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        int value = sharedArray[readIndex];
        printf("사람 : %2d번째 숫자는 %2d\n",readIndex + 1, value);
        sleep(1);
        readIndex = (readIndex + 1) % ARRAY_SIZE;
    }
    pthread_exit(NULL);
}

int main(int argc, const char *argv[]) {
    pthread_t writerThread, readerThread;


    // 쓰기 스레드 생성
    pthread_create(&writerThread, NULL, writer, NULL);
    // 읽기 스레드 생성
    pthread_create(&readerThread, NULL, reader, NULL);

    // 스레드 종료 대기
    pthread_join(writerThread, NULL);
    pthread_join(readerThread, NULL);


    return 0;
}
