/*
 * UltraSonic.c
 *
 *  Created on: Nov 15, 2023
 *      Author: omar
 */
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "UltraSonic.h"


// Function to initialize the HC-SR04 ultrasonic sensor
void initUltrasonicSensor() {
    // Configure trigger pin as output
    DDRD |= (1 << TRIG_PIN);
    // Configure echo pin as input
    DDRD &= ~(1 << ECHO_PIN);

    // Enable external interrupts for echo pin
    GICR |= (1 << INT1);
    // Trigger INT1 on rising edge
    MCUCR |= (1 << ISC11);
    MCUCR &= ~(1 << ISC10);

    // Enable global interrupts
    sei();
}

// Function to generate a pulse on the trigger pin of the ultrasonic sensor
void ultrasonicTrigger(void) {
    PORTD |= (1 << TRIG_PIN);
    _delay_us(10);
    PORTD &= ~(1 << TRIG_PIN);
}

// Function to measure the pulse duration on the echo pin of the ultrasonic sensor
int ultrasonicMeasure() {
    // Use Timer1 to measure pulse duration
    TCNT1 = 0; // Reset the counter
    TCCR1A |= (1 << CS10); // Start Timer1 without prescaling

    // Wait for the rising edge on the echo pin
    loop_until_bit_is_set(PIND, ECHO_PIN);

    // Record the start time
    uint16_t startTime = TCNT1;

    // Wait for the falling edge on the echo pin
    loop_until_bit_is_clear(PIND, ECHO_PIN);

    // Record the end time
    uint16_t endTime = TCNT1;

    // Stop Timer1
    TCCR1A = 0;

    // Calculate the pulse duration in microseconds
    int pulseWidth = (endTime - startTime)* 0.0343 * 0.5;

    return pulseWidth;
}

