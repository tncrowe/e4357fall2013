#include "mbed.h"

DigitalOut myled(LED1);
Ethernet eth;
Serial pc(USBTX, USBRX);

char buf[0xff];

int main() {
    pc.printf("Ethernet data read and display\n\r");
    while(1) {
    
        int size = eth.receive();
        if (size > 0) {
            eth.read(buf, size);
            pc.printf("size = %d; data = ", size );
            for (int i = 0; i < size; i++) {
                pc.printf("%02X ", buf[i]);
            }
            
            pc.printf("\n\r");
        
        }
        myled = 1;
        wait(0.2);
        myled = 0;
        wait(0.2);
        
    }
}
