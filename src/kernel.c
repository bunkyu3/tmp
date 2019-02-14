#include "irq.h"
#include "mini_uart.h"
#include "utils.h"
#include "peripherals/mini_uart.h"

void handle_mini_uart_irq(void){
	put32(AUX_MU_IIR_REG, MU_IIR_RX_CLR);
	uart_send('a');
}

void kernel_main(void)
{
	uart_init();
	irq_vector_init();
	enable_interrupt_controller();
	enable_irq();

	volatile long i;

	while (1){
		for(i=0; i<300000; i++)
			;
		uart_send('k');
	}	
}
