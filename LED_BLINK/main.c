#include "stm32f10x.h"  

void INIT_GPIOC13() {
    RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;

    GPIOC->CRH &= ~(GPIO_CRH_CNF13 | GPIO_CRH_MODE13);
    GPIOC->CRH |= GPIO_CRH_MODE13_0;
}

void delay(int ms) {
    for (volatile int i = 0; i < ms*1000; i++);
}

int main() {
    INIT_GPIOC13();

    while (1) {
        delay(1000);
        GPIOC->BSRR = GPIO_BSRR_BS13;
        delay(1000);
        GPIOC->BRR = GPIO_BRR_BR13;
    }
}
