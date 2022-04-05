// Robust Rotary encoder reading
//
// Copyright John Main - best-microcontroller-projects.com
//
#include <Keyboard.h>

// 2 6 - click
// 8 7 - non clicl
#define CLK 3
#define DATA 2
const int BUTTON = 9;
int BUTTONstate = 0;

int buttonState;             // the current reading from the input pin
int lastButtonState = LOW;   // the previous reading from the input pin

unsigned long lastDebounceTime = 0; // the last time the output pin was toggled
unsigned long debounceDelay = 50;   // the debounce time; increase if the output flickers

void setup()
{
   pinMode(CLK, INPUT);
   pinMode(CLK, INPUT_PULLUP);
   pinMode(DATA, INPUT);
   pinMode(DATA, INPUT_PULLUP);
   pinMode(BUTTON, INPUT_PULLUP);
   Serial.begin(115200);
   Serial.print("C Value");
   // initialize control over the keyboard:
   Keyboard.end();
   Keyboard.begin();
}

static uint8_t prevNextCode = 0;
static uint16_t store = 0;

void loop()
{
   static int8_t c, val;
   int reading = digitalRead(BUTTON);

   if (val = read_rotary())
   {
      c += val;

      Serial.println(c);

      // Left turn (Anti-Clock wise)
      if (val == 1)
      {
         // Send 2
         SendKeyWithF15(50);
      }

      // Right turn (click wise)
      if (val == -1)
      {
         // Send 1
         SendKeyWithF15(49);
      }
   };

   // Button Click
   // check to see if you just pressed the button
   // (i.e. the input went from LOW to HIGH), and you've waited long enough
   // since the last press to ignore any noise:

   // If the switch changed, due to noise or pressing:
   if (reading != lastButtonState)
   {
      // reset the debouncing timer
      lastDebounceTime = millis();
   }

   if ((millis() - lastDebounceTime) > debounceDelay)
   {
      // whatever the reading is at, it's been there for longer than the debounce
      // delay, so take it as the actual current state:

      // if the button state has changed:
      if (reading != buttonState)
      {
         buttonState = reading;

         // only toggle the LED if the new button state is HIGH
         if (buttonState == LOW)
         {
            // Run when pressed
            // Send 3
            SendKeyWithF15(51);
         }
      }
   }


   // save the reading. Next time through the loop, it'll be the lastButtonState:
   lastButtonState = reading;
}

// A vald CW or  CCW move returns 1, invalid returns 0.
int8_t read_rotary()
{
   static int8_t rot_enc_table[] = {0, 1, 1, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0};

   prevNextCode <<= 2;
   if (digitalRead(DATA))
      prevNextCode |= 0x02;
   if (digitalRead(CLK))
      prevNextCode |= 0x01;
   prevNextCode &= 0x0f;

   // If valid then store as 16 bit data.
   if (rot_enc_table[prevNextCode])
   {
      store <<= 4;
      store |= prevNextCode;
      // if (store==0xd42b) return 1;
      // if (store==0xe817) return -1;
      if ((store & 0xff) == 0x2b)
         return -1;
      if ((store & 0xff) == 0x17)
         return 1;
   }
   return 0;
}

int SendKeyWithF15(int x)
{
   Keyboard.press(KEY_F15);
   Keyboard.press(x);
   delay(9);
   Keyboard.releaseAll();
}
