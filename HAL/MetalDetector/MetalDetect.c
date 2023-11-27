#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "MetalDetect.h"

// Function to initialize the metal detector sensor
void initMetalDetector(void) {
    // Configure metal detector pin as input
    DDRA &= ~(1 << METAL_PIN);
}
