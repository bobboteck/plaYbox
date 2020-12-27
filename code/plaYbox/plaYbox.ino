/*
 * Name          : plaYbox.ino
 * @author       : Roberto D'Amico (@bobboteck)
 * Last modified : 27.12.2020
 * Revision      : 1.0.0
 *
 * Modification History:
 * Date         Version     Modified By		Description
 * 2020-12-22	1.0.0		Roberto D'Amico	
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
uint8_t leds[5] = { LED_WHITE, LED_BLUE, LED_YELLOW, LED_RED, LED_GREEN };
uint8_t buttons[5] = { BUTTON_WHITE, BUTTON_BLUE, BUTTON_YELLOW, BUTTON_RED, BUTTON_GREEN };

void setup()
{
    pinMode(LED_BUILTIN, OUTPUT);
    //Leds configuration
    pinMode(LED_WHITE, OUTPUT);
    pinMode(LED_BLUE, OUTPUT);
    pinMode(LED_YELLOW, OUTPUT);
    pinMode(LED_RED, OUTPUT);
    pinMode(LED_GREEN, OUTPUT);
    //Buttons configuration
    pinMode(BUTTON_WHITE, INPUT);
    pinMode(BUTTON_BLUE, INPUT);
    pinMode(BUTTON_YELLOW, INPUT);
    pinMode(BUTTON_RED, INPUT);
    pinMode(BUTTON_GREEN, INPUT);

    randomSeed(analogRead(5));

    randNumber = random(50) % 5;
    digitalWrite(leds[randNumber], HIGH);
}

void loop()
{
    /*randNumber = random(50) % 5;

    digitalWrite(leds[randNumber], HIGH);
    delay(300);
    digitalWrite(leds[randNumber], LOW);
    delay(300);*/

    if (digitalRead(buttons[randNumber]) == HIGH)
    {
        digitalWrite(leds[randNumber], LOW);

        randNumber = random(50) % 5;

        digitalWrite(leds[randNumber], HIGH);
    }
}
