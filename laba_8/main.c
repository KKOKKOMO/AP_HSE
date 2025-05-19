#include "task_1.h"
#include "task_2.h"
#define TASK_1_RUN


int main(){
    #ifdef TASK_1_RUN
    task_1();
    #else
    task_2();
    #endif
    return 0;
}