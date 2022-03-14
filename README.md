# arduino-macro-keyboard

This is for the macro keyboard

## continuitytester
It will turn off built in LED if Line 2 is connected to ground.
It also putout to the Serial for debugging

* Ref: https://roboticsbackend.com/arduino-input_pullup-pinmode/

## rotaryencodertest
Testing rotary encoder. Testing rotary encoder
Used Examples > Encoder > TwoKnobs as base.

It mostly works but sometimes it stutters and often times single click is multiple (4) input

the code
![image](https://user-images.githubusercontent.com/30095306/158216055-3c5f0004-0edb-4ba4-ad64-206b1eacb1a7.png)

using basic:
init
![image](https://user-images.githubusercontent.com/30095306/158216400-b5b39f25-59cf-438b-a1dd-695fad90fbc6.png)

cw turn (move to 4)
![image](https://user-images.githubusercontent.com/30095306/158216559-a31c6054-f692-4b58-b6cb-2d35b9faf554.png)

another turn - showing stutter (going back and forth)
![image](https://user-images.githubusercontent.com/30095306/158216693-44e6e918-d1f1-4547-a303-3420cad0515e.png)


Check the code from other people
```
        void encoderA(){
    long newPos = RotaryEncoderA.read()/4; //When the encoder lands on a valley, this is an increment of 4.
    
    if (newPos != positionEncoderA && newPos > positionEncoderA) {
        positionEncoderA = newPos;
        //Serial.println(positionEncoderA);
        Keyboard.press(KEY_LEFT_ARROW);
        Keyboard.release(KEY_LEFT_ARROW);                      }

    if (newPos != positionEncoderA && newPos < positionEncoderA) {
        positionEncoderA = newPos;
        //Serial.println(positionEncoderA);
        Keyboard.press(KEY_RIGHT_ARROW);
        Keyboard.release(KEY_RIGHT_ARROW);                      }
    }
```
Code Link: http://www.retrobuiltgames.com/the-build-page/macro-keyboard-v2-0/

looks like just devide by 4 before it register it as a input.


* Ref: https://lastminuteengineers.com/rotary-encoder-arduino-tutorial/

## Ref
* Macro keyboard using pro micro: https://www.youtube.com/watch?v=IDlcxLQ1SbY

