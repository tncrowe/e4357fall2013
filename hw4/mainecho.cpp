#include "mbed.h"

Serial async_port(p9,p10);

#if 1

DigitalOut myled1(LED1);
DigitalOut myled2(LED2);
DigitalOut myled3(LED3);
DigitalOut myled4(LED4);
DigitalOut red_led(p21);
DigitalOut green_led(p22);
DigitalOut strobe(p7);
DigitalIn switch_ip1(p5);
DigitalIn switch_ip2(p6);

char switch_word;
char recd_val;

#endif


//Serial pc(USBTX, USBRX);

int main() {

	  async_port.baud(9600);
        
    while(1) {
#if 0
				pc.printf("Hello World\n");
        myled3 = 1;
        wait(0.2);
        myled3 = 0;
        wait(0.2);
        myled4 = 1;
        wait(0.2);
        myled4 = 0;
        wait(0.2);
				myled21 = 1;
				wait(0.2);
				myled21 = 0;
				wait(0.2);
				myled22 = 1;
				wait(0.2);
				myled22 = 0;
				wait(0.2);
#endif

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

			red_led = 0;
			green_led = 0;
			recd_val = recd_val & 0x03;

			if (switch_ip1 == 1)
					red_led = 1;
			if (switch_ip2 == 1)
					green_led = 1;

//if (recd_val == 3)
//					red_led = 1;
//					green_led = 1;


#if 0
			if (recd_val == 1)
					red_led = 1;
			if (recd_val == 2)
					green_led = 1;
			if (recd_val == 3)
					red_led = 1;
					green_led = 1;
#endif					
    }
}
