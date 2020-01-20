#ifndef TASKMGR_H
#define TASKMGR_H

#include "preinclude.h"
#include "timers.h" // TODO remove

#ifndef MAX_TASKS
#define MAX_TASKS 20
#endif

#ifndef MINIMAL_SLEEP_TIME
#define MINIMAL_SLEEP_TIME 3
#endif

typedef void (*timerInit_t)(uint32_t resolution, timerHandler_t handler);
typedef TIME_T (*timerElapsedTime_t)(void);

typedef void (*task_t)(uint32_t);
typedef uint32_t taskId_t;

typedef enum {
  tskFree,
  tskReady,
  tskWait,
} taskStates_t;


typedef struct {
  TIME_T time;
  task_t task;
  uint32_t param;
  taskStates_t state;
  uint8_t priority; // TODO add priority to tasks.
}task_s;



typedef enum{
  INVALID_TIME = 0xFFFFFFFF,
  MAX_SLEEP_TIME_SEC = 15,
} var_consts;

void osInit(uint32_t resolution, timerInit_t timerInit, timerElapsedTime_t timerElapsedTime);
void osRun(void);

taskId_t osTaskAdd(task_t task, uint32_t param, TIME_T delay);
void osTaskAddSingle(task_t task, uint32_t param, TIME_T time);
uint32_t osTaskDelId(taskId_t id, task_t handler);
uint32_t osTaskDelHandler(task_t task);

TIME_T osTaskTime(taskId_t id);
void osTaskDelAll(void);


#endif
