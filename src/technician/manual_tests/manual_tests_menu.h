#ifndef MANUAL_TESTS_MENU_H_
#define MANUAL_TESTS_MENU_H_

typedef enum {
    ManualTestDoor,
    ManualTestKeyboard,
    ManualTestTetris,
    ManualTestDisplay,
    ManualTestMotor,
    ManualTestSound,
    ManualTestAlarm,
    ManualTestLast
} ManualTest_t;

typedef void (*manualTestHandler)(void);

void showManualTestsScreen(void);

#endif /* MANUAL_TESTS_MENU_H_ */
