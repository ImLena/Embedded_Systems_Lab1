#include "hal.h"

void notN() {
    unsigned int leds_num[] = {GPIO_PIN_3, GPIO_PIN_4, GPIO_PIN_5, GPIO_PIN_6};
    unsigned int sw_num[] = {GPIO_PIN_4, GPIO_PIN_8, GPIO_PIN_10, GPIO_PIN_12};

    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_RESET);
    for (int i = 0; i < 4; i++) {
        GPIO_PinState state = HAL_GPIO_ReadPin(GPIOE, sw_num[i]);
        HAL_GPIO_WritePin(GPIOD, leds_num[i], state);
    }
}

void greenLignt() {
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_RESET);
}

int checkState(int flag) {
    if (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_15) == GPIO_PIN_RESET) flag *= -1;
    if (flag != 1) {
        while (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_15) == GPIO_PIN_SET) {
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_SET);
        }
    }
    return flag;
}

int umain() {
    int delay = 500;
    int flag = -1;
    while (true) {
        flag = checkState(flag);
        if (HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_4) == 0 && HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_8) == 1 &&
            HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_10) == 0 && HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_12) == 0) {
            greenLignt();
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_3, GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_4, GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_5, GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_11, GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_SET);
            HAL_Delay(delay);

            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_3, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_4, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_5, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_11, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_RESET);

        } else notN();
        flag = checkState(flag);
        if (HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_4) == 0 && HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_8) == 1 &&
            HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_10) == 0 && HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_12) == 0) {
            greenLignt();
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_4, GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_5, GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_6, GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_9, GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_11, GPIO_PIN_SET);
            HAL_Delay(delay);
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_4, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_5, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_6, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_9, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_11, GPIO_PIN_RESET);
        } else notN();
        flag = checkState(flag);
        if (HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_4) == 0 && HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_8) == 1 &&
            HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_10) == 0 && HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_12) == 0) {
            greenLignt();
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_5, GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_6, GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_8, GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_9, GPIO_PIN_SET);
            HAL_Delay(delay);
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_5, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_6, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_8, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_9, GPIO_PIN_RESET);
        } else notN();
        flag = checkState(flag);
        if (HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_4) == 0 && HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_8) == 1 &&
            HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_10) == 0 && HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_12) == 0) {
            greenLignt();
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_6, GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_8, GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_9, GPIO_PIN_SET);
            HAL_Delay(delay);
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_6, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_8, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_9, GPIO_PIN_RESET);
        } else notN();
        flag = checkState(flag);
        if (HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_4) == 0 && HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_8) == 1 &&
            HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_10) == 0 && HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_12) == 0) {
            greenLignt();
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_5, GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_6, GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_8, GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_9, GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_11, GPIO_PIN_SET);
            HAL_Delay(delay);
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_5, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_6, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_8, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_9, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_11, GPIO_PIN_RESET);
        } else notN();
        flag = checkState(flag);
        if (HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_4) == 0 && HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_8) == 1 &&
            HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_10) == 0 && HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_12) == 0) {
            greenLignt();
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_4, GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_5, GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_9, GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_11, GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_SET);
            HAL_Delay(delay);
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_4, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_5, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_9, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_11, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_RESET);
        } else notN();
        flag = checkState(flag);
        if (HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_4) == 0 && HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_8) == 1 &&
            HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_10) == 0 && HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_12) == 0) {
            greenLignt();
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_4, GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_5, GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_8, GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_9, GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_11, GPIO_PIN_SET);
            HAL_Delay(delay);
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_4, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_5, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_8, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_9, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_11, GPIO_PIN_RESET);
        } else notN();
        flag = checkState(flag);
        if (HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_4) == 0 && HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_8) == 1 &&
            HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_10) == 0 && HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_12) == 0) {
            greenLignt();
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_4, GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_5, GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_6, GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_8, GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_9, GPIO_PIN_SET);
            HAL_Delay(delay);
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_4, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_5, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_6, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_8, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_9, GPIO_PIN_RESET);
        } else notN();
        flag = checkState(flag);
        if (HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_4) == 0 && HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_8) == 1 &&
            HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_10) == 0 && HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_12) == 0) {
            greenLignt();
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_5, GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_6, GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_8, GPIO_PIN_SET);
            HAL_Delay(delay);
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_5, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_6, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_8, GPIO_PIN_RESET);
        } else notN();
        flag = checkState(flag);
        if (HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_4) == 0 && HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_8) == 1 &&
            HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_10) == 0 && HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_12) == 0) {
            greenLignt();
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_4, GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_5, GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_6, GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_8, GPIO_PIN_SET);
            HAL_Delay(delay);
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_4, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_5, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_6, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_8, GPIO_PIN_RESET);
        } else notN();
        flag = checkState(flag);
        if (HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_4) == 0 && HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_8) == 1 &&
            HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_10) == 0 && HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_12) == 0) {
            greenLignt();
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_8, GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_9, GPIO_PIN_SET);
            HAL_Delay(delay);
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_8, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_9, GPIO_PIN_RESET);
        } else notN();
        flag = checkState(flag);
        if (HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_4) == 0 && HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_8) == 1 &&
            HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_10) == 0 && HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_12) == 0) {
            greenLignt();
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_9, GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_11, GPIO_PIN_SET);
            HAL_Delay(delay);
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_9, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_11, GPIO_PIN_RESET);
        } else notN();

    }
    return 0;
}
