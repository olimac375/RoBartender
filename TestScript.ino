//         =====       PERASTALTIC PREPROCESSOR MACROS       ======

#define peraPinOnePlus 22
#define peraPinOneMinus 24

#define peraPinTwoPlus 26
#define peraPinTwoMinus 28

#define peraPinThreePlus 30
#define peraPinThreeMinus 31

#define peraPinFourPlus 32
#define peraPinFourMinus 33

#define peraPinFivePlus 34
#define peraPinFiveMinus 35

#define peraPinSixPlus 36
#define peraPinSixMinus 37

#define peraPinSevenPlus 38
#define peraPinSevenMinus 39

#define peraPinEightPlus 40
#define peraPinEightMinus 41

#define peraPinNinePlus 42
#define peraPinNineMinus 43

#define peraPinTenPlus 44
#define peraPinTenMinus 45

    int perastalticPins[20] = 
        {
            peraPinOnePlus, peraPinOneMinus, peraPinTwoPlus, peraPinTwoMinus, peraPinThreePlus, \
            peraPinThreeMinus, peraPinFourPlus, peraPinFourMinus, peraPinFivePlus, peraPinFiveMinus, \
            peraPinSixPlus, peraPinSixMinus, peraPinSevenPlus, peraPinSevenMinus, peraPinEightPlus, \
            peraPinEightMinus, peraPinNinePlus, peraPinNineMinus, peraPinTenPlus, peraPinTenMinus
        };
        


//        =====           STEPPER PREPROCESSOR MACROS         ======


#define shakerLoadPinStep 6
#define shakerLoadPinDir 47 
#define shakerLoadPinEnable 7

#define icePinStep 4
#define icePinDir 49
#define icePinEnable 5

#define shakerRotPinStep 2
#define shakerRotPinDir 48
#define shakerRotPinEnable 3


  int stepperPins[9] =
        {
          shakerLoadPinStep, shakerLoadPinDir, shakerLoadPinEnable, icePinStep, icePinDir, \
          icePinEnable, shakerRotPinStep, shakerRotPinDir, shakerRotPinEnable
        };


//        =====          LATCH PREPROCESSOR MACROS            ======

#define shakerLatchPin 50
#define lidLatchPin 51

    int latchPins[2] = 
        {
          shakerLatchPin, lidLatchPin
        };

void stepperMotor(int pin, int steps, int period);


void setup() {

    

    for(volatile int i = 0; i < sizeof(perastalticPins); i++){
      pinMode( perastalticPins[i], OUTPUT);
      digitalWrite(perastalticPins[i], LOW);
    }

    for(volatile int i = 0; i < sizeof(stepperPins); i++){
      pinMode( stepperPins[i], OUTPUT);
      digitalWrite(stepperPins[i], LOW);
    }

    for(volatile int i = 0; i < sizeof(latchPins); i++){
      pinMode( latchPins[i], OUTPUT);
      digitalWrite(latchPins[i], LOW);
    }

    
}

void loop() {
  
 ///Perastaltic1
 digitalWrite(peraPinOnePlus, HIGH);
 delay(1000);
 digitalWrite(peraPinOnePlus, LOW);
 

 digitalWrite(peraPinTwoPlus, HIGH);
 delay(1000);
 digitalWrite(peraPinTwoPlus, LOW);

 digitalWrite(peraPinThreePlus, HIGH);
 delay(1000);
 digitalWrite(peraPinThreePlus, LOW);
 /*
 
 digitalWrite(peraPinFourPlus, HIGH);
 delay(1000);
 digitalWrite(peraPinFourPlus, LOW);

digitalWrite(peraPinFivePlus, HIGH);
 delay(1000);
 digitalWrite(peraPinFivePlus, LOW);

 digitalWrite(peraPinSixPlus, HIGH);
 delay(1000);
 digitalWrite(peraPinSixPlus, LOW);

 digitalWrite(peraPinSevenPlus, HIGH);
 delay(1000);
 digitalWrite(peraPinSevenPlus, LOW);

 digitalWrite(peraPinEightPlus, HIGH);
 delay(1000);
 digitalWrite(peraPinEightPlus, LOW);

 digitalWrite(peraPinNinePlus, HIGH);
 delay(1000);
 digitalWrite(peraPinNinePlus, LOW);
 
 digitalWrite(peraPinTenPlus, HIGH);
 delay(1000);
 digitalWrite(peraPinTenPlus, LOW);
 */
 





 ///Shaker Step 

stepperMotor(shakerLoadPinStep, 200, 10);
delay(1000);
 



//// Ice Step

stepperMotor(icePinStep, 200, 10);
delay(1000);


stepperMotor(shakerRotPinStep, 200, 10);
delay(1000);

digitalWrite(shakerLatchPin, HIGH);
delay(150);
digitalWrite(shakerLatchPin, LOW);

delay(1000);

digitalWrite(lidLatchPin, HIGH);
delay(150);
digitalWrite(lidLatchPin, LOW);

delay (1000);



}

void stepperMotor(int pin, int steps, int period) {
  int halfStep = period/2;
  for(int i = 0; i < steps; i++){
    digitalWrite(pin, HIGH);
    delay(halfStep);
    digitalWrite(pin, LOW);
    delay(halfStep);
  }
}
