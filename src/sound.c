#include <stm32l4xx.h>
#include <sound.h>

#define WAVEFORM_NUM_STEPS (6)
#define AUDIOLEVELS_COUNT (8)
#define SOUND_CONTROL_TIMER_FREQ (1000)

//MC9S08DZ128 frequency to convert
//periods
#define ORIGINAL_FREQUENCY_MHZ (20)

static uint16_t toneburst;
static uint8_t audiolevel;
static uint32_t audiohar1;
static uint32_t audiohar2;
static uint32_t audiohar3;
static uint32_t audiohar4;
static uint8_t audiophase;
static sound_state_t currentState;

static const wavestep_t waveformSteps[WAVEFORM_NUM_STEPS] = {
    {2, &audiohar4},
    {3, &audiohar3},
    {5, &audiohar2},
    {7, &audiohar3},
    {8, &audiohar4},
    {11, &audiohar1}
};

static const uint8_t audioleveltab[AUDIOLEVELS_COUNT] = {
    4, 6, 10, 15, 25, 40, 64, 127
};

static void soundInitTimers() {
    RCC->APB1ENR1 |= RCC_APB1ENR1_TIM3EN | RCC_APB1ENR1_TIM6EN;

    TIM3->CCMR2 = 0x6 << TIM_CCMR2_OC4M_Pos;    //PWM Mode 1
    TIM3->CR1 = 0x1 << TIM_CR1_CMS_Pos;
    TIM3->SR = 0;
    TIM3->CCER = TIM_CCER_CC4E;                 //Enable Channel1 output
    TIM3->PSC = 0;
    TIM3->ARR = 0;
    TIM3->BDTR |= TIM_BDTR_MOE;

    TIM6->ARR = SystemCoreClock / SOUND_CONTROL_TIMER_FREQ;

    NVIC_EnableIRQ(TIM3_IRQn);
    NVIC_EnableIRQ(TIM6_DAC_IRQn);
}

static void soundSetTimerPeriod(uint32_t period) {
    TIM3->ARR = period;
}

static void soundSetTimerDuty(uint32_t duty) {
    TIM3->CCR4 = duty;
}

//Convert HCS08 TPM intervals (duty cycle and period) to
//STM32 TIM3 intervals
static uint32_t intervalConvert(uint32_t interval) {
    uint32_t sysClkMhz = SystemCoreClock / 1000000;

    return interval * sysClkMhz / ORIGINAL_FREQUENCY_MHZ;
}

static void soundStart() {
    toneburst = 0;
    TIM6->CR1 |= TIM_CR1_CEN;
    TIM6->DIER |= TIM_DIER_UIE;
}

static void soundStop() {
    TIM3->CR1 &= ~TIM_CR1_CEN;
    TIM3->DIER &= ~TIM_DIER_UIE;
    TIM6->CR1 &= ~TIM_CR1_CEN;
    TIM6->DIER &= ~TIM_DIER_UIE;
    currentState = sound_silence;
}

static void soundPlayNote(uint32_t period, uint32_t level) {
    soundSetTimerPeriod(intervalConvert(period));

    if (level < AUDIOLEVELS_COUNT) {
        audiohar1 = intervalConvert(audioleveltab[level] *
                                    (period / 512 + 5));
        audiohar2 = audiohar1 / 8;
        audiohar3 = audiohar2 / 8;
        audiohar4 = audiohar3 / 8;
    }
    audiophase = 12;
    TIM3->CR1 |= TIM_CR1_CEN;
    TIM3->DIER |= TIM_DIER_UIE;
}

static void soundStopNote() {
    TIM3->CR1 &= ~TIM_CR1_CEN;
    TIM3->DIER &= ~TIM_DIER_UIE;
}

void initSound() {
    toneburst = 0;
    audiolevel = 3;
    currentState = sound_silence;
    soundInitTimers();
}

void soundSetLevel(uint8_t level) {
    if (level < 8) {
        audiolevel = level;
    }
}

uint8_t soundGetLevel() {
    return audiolevel;
}

void soundBeep() {
    if (currentState == sound_silence) {
        currentState = sound_beep;
        soundStart();
    }
}

void soundKeyBeep() {
    if (currentState == sound_silence) {
        currentState = sound_keybeep;
        soundStart();
    }
}

void soundAlarm() {
    if (currentState == sound_silence) {
        currentState = sound_alarm;
        soundStart();
    }
}

void soundHiAlarm() {
    if (currentState != sound_hialarm) {
        currentState = sound_hialarm;
        soundStart();
    }
}

void soundStopAlarm() {
    switch (currentState) {
    case sound_alarm:
    case sound_hialarm:
        soundStop();
        break;
    default:
        break;
    }
}

static void beepControlHandler() {
    switch (toneburst) {
    case 1:
        soundPlayNote(2485, audiolevel - 4);
        break;
    case 16:
        soundPlayNote(2485, audiolevel - 3);
        break;
    case 31:
        soundPlayNote(2485, audiolevel - 1);
        break;
    case 231:
        soundPlayNote(2485, audiolevel - 3);
        break;
    case 246:
        soundStopNote();
        break;
    case 401:
        soundPlayNote(3131, audiolevel - 4);
        break;
    case 416:
        soundPlayNote(3131, audiolevel - 3);
        break;
    case 431:
        soundPlayNote(3131, audiolevel - 1);
        break;
    case 631:
        soundPlayNote(3131, audiolevel - 3);
        break;
    case 646:
        soundStopNote();
        break;
    case 800:
        soundStop();
        break;
    }
}

void keybeepControlHandler() {
    switch (toneburst) {
    case 1:
        soundPlayNote(2485, audiolevel - 3);
        break;
    case 11:
        soundPlayNote(2485, audiolevel - 1);
        break;
    case 131:
        soundPlayNote(2485, audiolevel - 3);
        break;
    case 141:
        soundStopNote();
        break;
    case 161:
        soundStop();
        break;
    }
}

void hialarmControlHandler() {
    uint16_t toneburst_local;

    if (toneburst < 2000) {
        toneburst_local = toneburst;
    } else {
        toneburst_local = toneburst - 2000;
    }

    switch (toneburst_local) {
    case    1:
        soundPlayNote(1566, audiolevel - 4);
        break;
    case    10:
        soundPlayNote(1566, audiolevel - 3);
        break;
    case    20:
        soundPlayNote(1566, audiolevel - 1);
        break;
    case    181:
        soundPlayNote(1566, audiolevel - 3);
        break;
    case    191:
        soundStopNote();
        break;
    case    251:
        soundPlayNote(2790, audiolevel - 4);
        break;
    case    261:
        soundPlayNote(2790, audiolevel - 3);
        break;
    case    271:
        soundPlayNote(2790, audiolevel - 1);
        break;
    case    431:
        soundPlayNote(2790, audiolevel - 3);
        break;
    case    441:
        soundStopNote();
        break;
    case    501:
        soundPlayNote(2214, audiolevel - 4);
        break;
    case    511:
        soundPlayNote(2214, audiolevel - 3);
        break;
    case    521:
        soundPlayNote(2214, audiolevel - 1);
        break;
    case    681:
        soundPlayNote(2214, audiolevel - 3);
        break;
    case    691:
        soundStopNote();
        break;
    case    1001:
        soundPlayNote(1566, audiolevel - 4);
        break;
    case    1011:
        soundPlayNote(1566, audiolevel - 3);
        break;
    case    1021:
        soundPlayNote(1566, audiolevel - 1);
        break;
    case    1181:
        soundPlayNote(1566, audiolevel - 3);
        break;
    case    1191:
        soundStopNote();
        break;
    case    1250:
        soundPlayNote(2790, audiolevel - 4);
        break;
    case    1260:
        soundPlayNote(2790, audiolevel - 3);
        break;
    case    1270:
        soundPlayNote(2790, audiolevel - 1);
        break;
    case    1431:
        soundPlayNote(2790, audiolevel - 3);
        break;
    case    1441:
        soundStopNote();
        break;
    }
}

//Sound playback control
//Called by TIM6 interrupt handler
void soundControlHandler() {
    switch (currentState) {
    case sound_beep:
        beepControlHandler();
        break;
    case sound_keybeep:
        keybeepControlHandler();
        break;
    case sound_hialarm:
        hialarmControlHandler();
        break;
    default:
        soundStop();
    }

    toneburst++;

    if (toneburst > 10000) {
        toneburst = 0;
    }
}

//Waveform control
//Called by TIM3 interrupt handler
void soundWaveformHandler() {
    uint32_t nextDutyCycle = 0;

    if (audiophase > 0) {
        audiophase--;
    } else {
        audiophase = 12;
    }

    for (int i = 0; i < WAVEFORM_NUM_STEPS; i++) {
        if (audiophase == waveformSteps[i].phase) {
            nextDutyCycle = *waveformSteps[i].duty;
        }
    }
    soundSetTimerDuty(nextDutyCycle);
}
