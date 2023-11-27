/*
 * MotorDriver.c
 *
 *  Created on: Nov 16, 2023
 *      Author: dina
 */


/*
 * MotorDriver.c
 *
 *  Created on: Nov 15, 2023
 *      Author: omar
 */
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "MotorDriver.h"

// Function to initialize PWM for motor control
void initPWM(void) {
    // Set OC0 (motor 1) and OC1A (motor 2) as output
    DDRB |= (1 << MOTOR1_EN) | (1 << MOTOR1A) | (1 << MOTOR1B) | (1 << MOTOR2A) | (1 << MOTOR2B);
    DDRD |= (1 << MOTOR2_EN);

    // Set non-inverting mode for OC0 and OC1A
    TCCR0 |= (1 << WGM00) | (1 << WGM01) | (1 << COM01);  // Fast PWM, non-inverting mode for OC0
    TCCR1A |= (1 << WGM10) | (1 << WGM11) | (1 << COM1A1); // Fast PWM, non-inverting mode for OC1A

    // Set no prescaling for both functions
    TCCR0 |= (1 << CS00);
    TCCR1A |= (1 << CS10);
}

// Function to move the car forward
void moveForward(void) {
    OCR0 = 150; // Adjust speed as needed (Range:0 - 255)
    OCR1A = 150;
    PORTB |= (1 << MOTOR1A) | (1 << MOTOR2A);
    PORTB &= ~((1 << MOTOR1B) | (1 << MOTOR2B));
}

// Function to stop the car
void stop(void) {
    OCR0 = 0;
    OCR1A = 0;
    PORTB &= ~((1 << MOTOR1A) | (1 << MOTOR1B) | (1 << MOTOR2A) | (1 << MOTOR2B));
}

// Function to turn the car right
void turnRight(void) {
    OCR0 = 150;
    OCR1A = 150;
    PORTB |= (1 << MOTOR1A) | (1 << MOTOR2B);
    PORTB &= ~((1 << MOTOR1B) | (1 << MOTOR2A));
}


