unsigned long pastOther;

void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(0));
  pastOther = millis();
}

int8_t tempInGet(){
  return 26;
}

int8_t tempOutGet(){
  return 13;
}

uint8_t velocityGet(){
  static uint8_t pastSpeed = 0;
  uint8_t res1 = min(random(max(0 - pastSpeed, -10), 11) + pastSpeed, 150);
  uint8_t res2 = min(random(max(0 - pastSpeed, -10), 11) + pastSpeed, 150);
  uint8_t res3 = min(random(max(0 - pastSpeed, -10), 11) + pastSpeed, 150);
  if(abs(60 - res1) < abs(60 - res2)){
    if(abs(60 - res1) < abs(60 - res3)) return pastSpeed = res1;
    else return pastSpeed = res3;
  } else if(abs(60 - res2) < abs(60 - res3)) return pastSpeed = res2;
  else return pastSpeed = res3;
}

void loop() {
  if((millis() - pastOther) > 3000 && (millis() - pastOther < 5000)){
    //Serial.println(pastOther);
    //Serial.println(millis());
  }
  if (millis() - pastOther >= 1000){
    //Serial.print("temp-in ");
    //Serial.println(tempInGet());
    //Serial.print("temp-out ");
    //Serial.println(tempOutGet());
    //Serial.print("velocity ");
    Serial.println(velocityGet());

    //Serial.print("time from prev. data:");
    //Serial.println(millis() - pastOther);
    pastOther = millis();
  }
}
