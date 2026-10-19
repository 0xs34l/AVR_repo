
#include <avr/io.h>
#include <util/delay.h>

#define F_CPU 16000000UL

int main(void)
{
    DDRB |= (1 << DDB5);  // Set PB5 as output

    while (1)
    {
        PORTB |= (1 << PB5);   // LED ON
        _delay_ms(1000);

        PORTB &= ~(1 << PB5);  // LED OFF
        _delay_ms(1000);
    }

    return 0;
}
