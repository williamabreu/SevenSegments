#include "SevenSegments.h"

#define D0 5
#define D1 4
#define D2 3
#define D3 2

#define U0 11
#define U1 10
#define U2 9
#define U3 8

SevenSegments disp(D0, D1, D2, D3, U0, U1, U2, U3);

void setup() {
    Serial.begin(9600);
}

void loop() {
    byte atual = Serial.read();
    int i = (int) atual;
    disp.print(i);
    delay(200);
}

