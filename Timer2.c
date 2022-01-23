int main(void)
{
   /*attiva oscillatore MISON 4MHZ*/
   RCC->CR|=RCC_CR_MSION;
   /*abilita oscillatore per timer2*/
   RCC->APB1ENR1|=RCC_APB1ENR1_TIM2EN;
   /*abilita oscillatore per gpioa*/
   RCC->AHB2ENR|=RCC_AHB2ENR_GPIOAEN;
   /*imposta overflow timer*/
   TIM2->ARR=0x7A11FF;
   /*attiva auto-preload reload e inizia conteggio*/
   TIM2->CR1|=TIM_CR1_ARPE|TIM_CR1_CEN;
   /*imposta pin 5 porta a come output*/
   GPIOA->MODER&=~GPIO_MODER_MODER5_1;


   while (1)
   {
    /*polling flag overflow timer*/
    if((TIM_SR_UIF&TIM2->SR)==1)
    {
    /*toggle pin 5 con xor bit*/
    GPIOA->ODR^=GPIO_ODR_OD5;
    /*azzera flag overflow*/
    TIM2->SR=0;
    }

   }

}
