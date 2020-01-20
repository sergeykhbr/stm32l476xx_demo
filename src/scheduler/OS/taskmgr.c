
#include "preinclude.h"
#include "taskmgr.h"

static uint32_t freeSlot(void);
static void recountTasksTime(void);
static TIME_T nearestTaskTime(void);

static task_s tasks[MAX_TASKS];
static bool haveTaskToDo; //TODO search usage of this variable

// TODO Need to implement or do it weak
void tickHook(void)
{
}

static timerElapsedTime_t timerElapseSinceLastTimeFunction = NULL;

void osInit(uint32_t resolution, timerInit_t timerInitialization, timerElapsedTime_t timerElapsedTime)
{
	  uint32_t i;
	  for(i = 0; i < MAX_TASKS; ++i)
	  {
	    tasks[i].state = tskFree;
	  }

	timerInitialization(resolution, tickHook);
	timerElapseSinceLastTimeFunction = timerElapsedTime;
}

void osRun(void){
  uint32_t nextTaskTime;
  while(1){
    do{
      recountTasksTime();
      for(taskId_t i = 0; i < MAX_TASKS; ++i){
        ENTER_CRITICAL_SECTION();
        if(tasks[i].state == tskReady){
          task_t task = tasks[i].task;
          uint32_t param = tasks[i].param;
          tasks[i].state = tskFree;
          EXIT_CRITICAL_SECTION();
          task(param);
        }
        else{
          EXIT_CRITICAL_SECTION();
        }
      }
      nextTaskTime = nearestTaskTime();
    } while(nextTaskTime == 0);
    if(nextTaskTime > MINIMAL_SLEEP_TIME) // sleep
    {
    	//TODO add sleep mode
    }
  }
}


taskId_t osTaskAdd(task_t task, uint32_t param, TIME_T time){
  ENTER_CRITICAL_SECTION();
  uint32_t idx = freeSlot();
  if(idx < MAX_TASKS){
    recountTasksTime();
    tasks[idx].task = task;
    tasks[idx].param = param;
    tasks[idx].time = time;
    tasks[idx].state = time ? tskWait
                            : tskReady, haveTaskToDo = true;

  }
//  ASSERTEX(idx < MAX_TASKS,46);
  EXIT_CRITICAL_SECTION();
  return idx;
}

void osTaskAddSingle(task_t task, uint32_t param, TIME_T time){
  osTaskDelHandler(task);
  osTaskAdd(task, param, time);
}


uint32_t osTaskDelId(taskId_t id, task_t handler){
  ENTER_CRITICAL_SECTION();
  uint32_t result = 0;
  if(id < MAX_TASKS && tasks[id].task == handler){
    tasks[id].time = 0;
    tasks[id].task = 0;
    tasks[id].state = tskFree;
    tasks[id].param= 0xDE1D;
    result = 1;
  }
  EXIT_CRITICAL_SECTION();
  return result;
}


uint32_t osTaskDelHandler(task_t task){
  ENTER_CRITICAL_SECTION();
  uint32_t result = 0;
  for (int i = 0; i < MAX_TASKS; ++i){
    if(tasks[i].state != tskFree && tasks[i].task == task){
      tasks[i].state = tskFree;
      tasks[i].task = 0;
      tasks[i].time = 0;
      tasks[i].param= 0x0DE1;
      result++;
    }
  }
  EXIT_CRITICAL_SECTION();
  return result;
}


TIME_T osTaskTime(taskId_t id){
  recountTasksTime();
  return tasks[id].time;
}


void osTaskDelAll(void){
  for(uint32_t i = 0; i < MAX_TASKS; ++i){
    tasks[i].time = 0;
    tasks[i].state = tskFree;
  }
}


static inline uint32_t freeSlot(void){
  uint32_t slot = 0;
  for(slot = 0; slot < MAX_TASKS; ++slot){
    if(tasks[slot].state == tskFree){
      break;
    }
  }
  return slot;
}


static TIME_T nearestTaskTime(void){
  ENTER_CRITICAL_SECTION();
  TIME_T time = INVALID_TIME;
  for(taskId_t i = 0; i < MAX_TASKS; ++i){
    if(tasks[i].state == tskWait){
      time > tasks[i].time?
        time = tasks[i].time: 0;
    }
    else if(tasks[i].state == tskReady){
      time = 0;
      break;
    }
  }
  haveTaskToDo = time == 0;
  EXIT_CRITICAL_SECTION();
  return time;
}


static void recountTasksTime(void){
  ENTER_CRITICAL_SECTION();
  TIME_T value = timerElapseSinceLastTimeFunction();
  if(value){
    for(taskId_t i = 0; i < MAX_TASKS; ++i)
    {
      if(tasks[i].state == tskWait)
      {
        if(tasks[i].time > 0){
          if(tasks[i].time > value)
            tasks[i].time -= value;
          else
            tasks[i].time = 0;
        }

        if(tasks[i].time == 0 && tasks[i].task){
          haveTaskToDo = true;
          tasks[i].state = tskReady;
        }
      }
    }
  }
  EXIT_CRITICAL_SECTION();
}

