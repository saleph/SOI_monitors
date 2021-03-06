#ifndef MYQUEUE_H
#define MYQUEUE_H

#include <stdio.h>
#include <unistd.h>
#include "sem.h"

#define MYQUEUE_MAX_SIZE 4
#define MYQUEUE_MIN_SIZE 3
#define MYQUEUE_SIZE     0

#define LOG 1


typedef struct Data {
    int val;
} Data;

class MyQueue
{
    struct Data queue[MYQUEUE_MAX_SIZE];
    int size;
    Sem semBhaveRead, semAandC, semAChaveRead, semFull, semEmpty, mutex, printfMutex, semBExclusion, semACExclusion, semWaitingForEmpty, semReadyToPop;
    int aReads, bReads, cReads;
    Sem semReadStats;
public:
    MyQueue();
    ~MyQueue();

    Data readAsA();
    Data readAsB();
    Data readAsC();
    void write(const Data &data);

    void printReadStats();
private:
    Data takeFirst();
    Data pop();
    void push(const Data &data);
    Data readAsAorC();
};

#endif // MYQUEUE_H
