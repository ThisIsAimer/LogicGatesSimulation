// C++ code
//

const int ANALOG_INPUT = A0;


const int BUTTON1 = 13;
const int BUTTON2 = 12;

const int LED_OUTPUT = 4;


void setup()
{
  pinMode(ANALOG_INPUT, INPUT);
  pinMode(BUTTON1, INPUT);
  pinMode(BUTTON2, INPUT);
  
  pinMode(LED_OUTPUT, OUTPUT);
}

void loop()
{

    // values will be divided into 5 parts of 51. 51*4 = 255
    int analogueValue = (analogRead(ANALOG_INPUT)/4);

    // actual inputs of buttons pressed
    int firstButton = !digitalRead(BUTTON1); 
    int secondButton = !digitalRead(BUTTON2);

    // AND function
    if(analogueValue >= 0 && analogueValue <= 50){

    if (firstButton && secondButton) {
        digitalWrite(LED_OUTPUT, HIGH);
    }

    else{
        digitalWrite(LED_OUTPUT, LOW);
    }
    }

    // NAND function
    if(analogueValue >= 51 && analogueValue <= 101){ 

    if (firstButton && secondButton) {
        digitalWrite(LED_OUTPUT, LOW);
    }

    else{
        digitalWrite(LED_OUTPUT, HIGH); 
    }
    }

    // OR function
    if(analogueValue >= 102 && analogueValue <= 152){

    if (firstButton && secondButton) {
        digitalWrite(LED_OUTPUT, HIGH);
    }

    else if (!firstButton && secondButton) {
        digitalWrite(LED_OUTPUT, HIGH);
    }

    else if (firstButton && !secondButton) {
        digitalWrite(LED_OUTPUT, HIGH);
    }

    else{
        digitalWrite(LED_OUTPUT, LOW); 
    }
    }

    // NOR function
    if(analogueValue >= 153 && analogueValue <= 203){

    if (!firstButton && secondButton) {
        digitalWrite(LED_OUTPUT, LOW);
    }

    else if (firstButton && !secondButton) {
        digitalWrite(LED_OUTPUT, LOW);
    }

    else{
        digitalWrite(LED_OUTPUT, HIGH); 
    }
    }

    // XNOR function
    if(analogueValue >= 204 && analogueValue <= 254){

    if (!firstButton && secondButton) {
        digitalWrite(LED_OUTPUT, HIGH);
    }

    else if (firstButton && !secondButton) {
        digitalWrite(LED_OUTPUT, HIGH);
    }

    else{
        digitalWrite(LED_OUTPUT, LOW); 
    }
    }


  }