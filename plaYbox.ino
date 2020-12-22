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

void setup()
{
    pinMode(LED_BUILTIN, OUTPUT);
    //Leds configuration
    pinMode(LED_WHITE, OUTPUT);
    pinMode(LED_BLUE, OUTPUT);
    pinMode(LED_YELLOW, OUTPUT);
    pinMode(LED_RED, OUTPUT);
    pinMode(LED_GREEN, OUTPUT);

    fadeInOut();
}

void loop()
{
  if (digitalRead(BUTTON_WHITE) == HIGH)
  {
    digitalWrite(LED_WHITE, HIGH);
  }
  else
  {
    digitalWrite(LED_WHITE, LOW);
  }

  if (digitalRead(BUTTON_BLUE) == HIGH)
  {
    digitalWrite(LED_BLUE, HIGH);
  }
  else
  {
    digitalWrite(LED_BLUE, LOW);
  }

  if (digitalRead(BUTTON_YELLOW) == HIGH)
  {
    digitalWrite(LED_YELLOW, HIGH);
  }
  else
  {
    digitalWrite(LED_YELLOW, LOW);
  }

  if (digitalRead(BUTTON_RED) == HIGH)
  {
    digitalWrite(LED_RED, HIGH);
  }
  else
  {
    digitalWrite(LED_RED, LOW);
  }

  if (digitalRead(BUTTON_GREEN) == HIGH)
  {
    digitalWrite(LED_GREEN, HIGH);
  }
  else
  {
    digitalWrite(LED_GREEN, LOW);
  }
}

void fadeInOut()
{
    digitalWrite(LED_WHITE, LOW);
    digitalWrite(LED_BLUE, LOW);
    digitalWrite(LED_YELLOW, LOW);
    digitalWrite(LED_RED, LOW);
    digitalWrite(LED_GREEN, LOW);

    for(int i=0;i<256;i++)
    {
        analogWrite(LED_WHITE, i);
        analogWrite(LED_BLUE, i);
        analogWrite(LED_YELLOW, i);
        analogWrite(LED_RED, i);
        analogWrite(LED_GREEN, i);

        delay(30);
    }

    delay(500);
    
    digitalWrite(LED_WHITE, LOW);
    digitalWrite(LED_BLUE, LOW);
    digitalWrite(LED_YELLOW, LOW);
    digitalWrite(LED_RED, LOW);
    digitalWrite(LED_GREEN, LOW);

    delay(500);
    
    digitalWrite(LED_WHITE, HIGH);
    digitalWrite(LED_BLUE, HIGH);
    digitalWrite(LED_YELLOW, HIGH);
    digitalWrite(LED_RED, HIGH);
    digitalWrite(LED_GREEN, HIGH);

    delay(500);

    digitalWrite(LED_WHITE, LOW);
    digitalWrite(LED_BLUE, LOW);
    digitalWrite(LED_YELLOW, LOW);
    digitalWrite(LED_RED, LOW);
    digitalWrite(LED_GREEN, LOW);

    delay(500);
    
    digitalWrite(LED_WHITE, HIGH);
    digitalWrite(LED_BLUE, HIGH);
    digitalWrite(LED_YELLOW, HIGH);
    digitalWrite(LED_RED, HIGH);
    digitalWrite(LED_GREEN, HIGH);

    delay(500);

    for(int i=255;i>-1;i--)
    {
        analogWrite(LED_WHITE, i);
        analogWrite(LED_BLUE, i);
        analogWrite(LED_YELLOW, i);
        analogWrite(LED_RED, i);
        analogWrite(LED_GREEN, i);

        delay(30);
    }

    digitalWrite(LED_WHITE, LOW);
    digitalWrite(LED_BLUE, LOW);
    digitalWrite(LED_YELLOW, LOW);
    digitalWrite(LED_RED, LOW);
    digitalWrite(LED_GREEN, LOW);
}
