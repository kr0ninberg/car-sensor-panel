unsigned long pastOther;

void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(0));
  pastOther = millis();
}

float temperatureGet(){
  static float pastTemperature = 26;
  float res1 = max(min(random(-100, 100) / 100.0 + pastTemperature, 50), -50);
  float res2 = max(min(random(-100, 100) / 100.0 + pastTemperature, 50), -50);
  float res3 = max(min(random(-100, 100) / 100.0 + pastTemperature, 50), -50);
  if(abs(26 - res1) < abs(26 - res2)){
    if(abs(26 - res1) < abs(26 - res3)) return pastTemperature = res1;
    else return pastTemperature = res3;
  } else if(abs(26 - res2) < abs(26 - res3)) return pastTemperature = res2;
  else return pastTemperature = res3;
}

void loop() {
  if((millis() - pastOther) > 3000 && (millis() - pastOther < 5000)){
    //Serial.println(pastOther);
    //Serial.println(millis());
  }
  if (millis() - pastOther >= 1000){
    Serial.println(temperatureGet());

    //Serial.print("time from prev. data:");
    //Serial.println(millis() - pastOther);
    pastOther = millis();
  }
}
