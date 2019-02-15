#include "irq.h"
#include "mini_uart.h"
#include "utils.h"
#include "peripherals/mini_uart.h"

void handle_mini_uart_irq(void){
	char c = uart_recv();
	uart_send(c);
}

void kernel_main(void)
{
	uart_init();
	irq_vector_init();
	enable_interrupt_controller();
	enable_irq();

	volatile long i;

	while (1){
		for(i=0; i<3000000; i++)
			;
		uart_send('a');
	}	
}
