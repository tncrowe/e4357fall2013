#include "mbed.h"
#include "Ethernet.h"

Ethernet eth;
char data[] = {0x89, 0x46};

DigitalOut myled(LED1);

int main() {
    while(1) {
        eth.write(data, 0x02);
        eth.send();
        
        
        myled = 1;
        wait(0.2);
        myled = 0;
        wait(0.2);
    }
}
