#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<pthread.h>
#include<limits.h>
#include<math.h>
#include<sched.h>

void *countA() {
    struct sched_param *param;

    struct timespec *start;
    struct timespec *end;

    int val = pthread_setschedparam(thread_self(), SCHED_OTHER, &param);
    
    int timeEnd;
    int timeStart;
    if (val == 0) {
        int count;
        int max = pow(2, 32);
        timeStart = clock_gettime(CLOCK_REALTIME, &start);
        for (int i = 1; i <= max; i++) {
            count++;
        }
        timeEnd = clock_gettime(CLOCK_REALTIME, &end);
    } else {
        printf("Error!!");
    }

    int timeDiff = timeEnd - timeStart;
    printf(&timeDiff);
}

void *countB() {
    struct sched_param *param;

    struct timespec *start;
    struct timespec *end;

    int val = pthread_setschedparam(thread_self(), SCHED_RR, &param);

    int timeEnd;
    int timeStart;
    if (val == 0) {
        int count;
        int max = pow(2, 32);
        timeStart = clock_gettime(CLOCK_REALTIME, &start);
        for (int i = 1; i < max; i++) {
            count++;
        }
        timeEnd = clock_gettime(CLOCK_REALTIME, &end);
    } else {
        printf("Error!!");
    }

    int timeDiff = timeEnd - timeStart;
    printf(&timeDiff);
}

void *countC() {
    struct sched_param *param;

    struct timespec *start;
    struct timespec *end;

    int val = pthread_setschedparam(thread_self(), SCHED_FIFO, &param);

    int timeEnd;
    int timeStart;
    if (val == 0) {
        int count;
        int max = pow(2, 32);
        timeStart = clock_gettime(CLOCK_REALTIME, &start);
        for (int i = 1; i < max; i++) {
            count++;
        }
        timeEnd = clock_gettime(CLOCK_REALTIME, &end);
    } else {
        printf("Error!!");
    }

    int timeDiff = timeEnd - timeStart;
    printf(&timeDiff);
}

int main() {
    pthread_t id1;
    pthread_t id2;
    pthread_t id3;
    int result1;
    int result2;
    int result3;

    result1 = pthread_create(&id1, NULL, countA, NULL);
    result2 = pthread_create(&id2, NULL, countB, NULL);
    result3 = pthread_create(&id3, NULL, countC, NULL);

    pthread_join(id1, NULL);
    pthread_join(id2, NULL);
    pthread_join(id3, NULL);
}
