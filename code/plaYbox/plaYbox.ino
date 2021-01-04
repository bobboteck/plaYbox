/*
 * Name          : plaYbox.ino
 * @author       : Roberto D'Amico (@bobboteck)
 * Last modified : 2021.01.04
 * Revision      : 1.1.0
 *
 * Modification History:
 * Date         Version     Modified By		Description
 * 2021-01-04   1.1.0       Roberto D'Amico added a control to turn off the LEDs after 30 seconds of inactivity
 * 2020-12-22   1.0.0       Roberto D'Amico First play mode
 * 
 * LICENSE GNU Affero General Public License v3.0
 * 
 * This file is part of the plaYbox project (https://github.com/bobboteck/plaYbox).
 * Copyright (c) 2020 Roberto D'Amico (@bobboteck).
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#define LED_WHITE   11
#define LED_BLUE    10
#define LED_YELLOW  9
#define LED_RED     6
#define LED_GREEN   5

#define BUTTON_WHITE    2
#define BUTTON_BLUE     A0
#define BUTTON_YELLOW   A1
#define BUTTON_RED      A2
#define BUTTON_GREEN    A3

long randNumber;
unsigned long lastActionTime;
uint8_t leds[5] = { LED_WHITE, LED_BLUE, LED_YELLOW, LED_RED, LED_GREEN };
uint8_t buttons[5] = { BUTTON_WHITE, BUTTON_BLUE, BUTTON_YELLOW, BUTTON_RED, BUTTON_GREEN };

void setup()
{
    pinMode(LED_BUILTIN, OUTPUT);
    // Leds configuration
    pinMode(LED_WHITE, OUTPUT);
    pinMode(LED_BLUE, OUTPUT);
    pinMode(LED_YELLOW, OUTPUT);
    pinMode(LED_RED, OUTPUT);
    pinMode(LED_GREEN, OUTPUT);
    // Buttons configuration
    pinMode(BUTTON_WHITE, INPUT);
    pinMode(BUTTON_BLUE, INPUT);
    pinMode(BUTTON_YELLOW, INPUT);
    pinMode(BUTTON_RED, INPUT);
    pinMode(BUTTON_GREEN, INPUT);

    // Initialize the randomizer
    randomSeed(analogRead(5));
    // Generate the first random number and power on the relative led
    randNumber = random(50) % 5;
    digitalWrite(leds[randNumber], HIGH);
    // Set the last action time to manage the auto power off of leds
    lastActionTime = millis();
}

void loop()
{
    // Check if the button with led on is pressed
    if (digitalRead(buttons[randNumber]) == HIGH)
    {
        // Power off the led
        digitalWrite(leds[randNumber], LOW);
        // Generate a new random number from 0 to 4
        randNumber = random(50) % 5;
        // Power on the new led
        digitalWrite(leds[randNumber], HIGH);
        // Update the last action variable
        lastActionTime = millis();
    }

    // Check if no action for more than 30 seconds
    if(millis() - lastActionTime >= 30000)
    {
        // Power off the led currently on
        digitalWrite(leds[randNumber], LOW);
    }
}
