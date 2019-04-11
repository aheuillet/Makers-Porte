//#include "AS5048A.h"


//AS5048A angleSensor(10);
#define PIN 10

int pwm = 0;
int pwm_ = 1;
unsigned int cpt = 0;
int dv = 0;
unsigned int cpt_moy = 0;

void setup()
{
	Serial.begin(19200);
	//angleSensor.init();
  pinMode(PIN, INPUT);
}

void loop()
{
  pwm = digitalRead(PIN);
  if ((pwm != pwm_)){
    if(pwm == 1){
      cpt = 0;
      dv = 0;
    }else{
      if (dv == 0){
        if (cpt_moy == 10){
          Serial.print("cpt : ");
          Serial.println(cpt);
          cpt_moy = 0;
        }else{
          cpt_moy++;
        }
      }
      dv = 1;
      cpt++;
    }
  }
  pwm_ = pwm;
  cpt++;
	/*word val = angleSensor.getRawRotation();
	Serial.print("Got rotation of: 0x");
	Serial.println(val, HEX);*/
	/*Serial.print("State: ");
	angleSensor.printState();
	Serial.print("Errors: ");
	Serial.println(angleSensor.getErrors());*/
}
