#include "mbed.h"

// Serial port homework - week 4

Serial async_port(p9,p10);

#if 1

DigitalOut red_led(p21);
DigitalOut green_led(p22);
DigitalOut strobe(p7);
DigitalIn switch_ip1(p5);
DigitalIn switch_ip2(p6);

char switch_word;
char recd_val;

#endif


Serial pc(USBTX, USBRX);

int main() {

	  async_port.baud(9600);
        
    while(1) {

			switch_word=0xa0;
			if (switch_ip1 == 1) 
				switch_word = switch_word|0x01;
			if (switch_ip2 == 1)
				switch_word = switch_word|0x02;

			strobe = 1;
			wait_us(10);
			strobe = 0;
			
			async_port.putc(switch_word);
			
			if (async_port.readable() == 1)
				recd_val = async_port.getc();

			wait(1);
			pc.printf("Status 0x%x, recv 0x%x\n", switch_word, recd_val);

			red_led = 0;
			green_led = 0;
			recd_val = recd_val & 0x03;

			if (switch_ip1 == 1)
					red_led = 1;
			if (switch_ip2 == 1)
					green_led = 1;

    }
}
