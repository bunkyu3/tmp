#include "irq.h"
#include "mini_uart.h"

void handle_mini_uart_irq(void){
	uart_send('a');
}

void kernel_main(void)
{
	uart_init();
	irq_vector_init();
	enable_interrupt_controller();
	enable_irq();

	while (1){
		;
	}	
}
