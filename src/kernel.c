#include "irq.h"
#include "mini_uart.h"


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
