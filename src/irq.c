#include "utils.h"
#include "timer.h"
#include "mini_uart.h"
#include "entry.h"
#include "peripherals/irq.h"

void enable_interrupt_controller()
{
	put32(ENABLE_IRQS_1, SYSTEM_TIMER_IRQ_1); // Timer
	put32(ENABLE_IRQS_1, MINI_UART_IRQ); // mini-uart
}

void show_invalid_entry_message(int type, unsigned long esr, unsigned long address)
{
	uart_send('I');
}

void handle_irq(void)
{
	unsigned int irq = get32(IRQ_PENDING_1);
	switch (irq) {
		case (SYSTEM_TIMER_IRQ_1):
			handle_timer_irq();
			break;
		case (MINI_UART_IRQ):
			handle_mini_uart_irq();
			break;
		default:
			uart_send('D');
	}
}
