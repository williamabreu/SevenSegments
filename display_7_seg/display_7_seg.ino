#include "sevenSegmentsWilliam.h"

int i = 0;

void loop() {
    displayOut(i);
    i = (i + 1) % 100;
    delay(200);
}
