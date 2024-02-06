unsigned long pastOther;

void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(0));
  pastOther = millis();
}

void inMessageProc(){
  String s = Serial.readString();
  if(s.indexOf(' ') == -1) return;
  String action = s.substring(0, s.indexOf(' '));
  //if (action == "")
}

int validationCode(String s){
  int res = 0;
  for(int i = 0 ; i < s.length() - 1 ; ++i){
    res += s[i];
  }
  return res;
}

int randomValue(int edge, int average){
  return random(-edge, edge) + average;
}

float randomValue(float edge, float average){
  return random(-edge*100, edge*100) / 100.0 + average;
}

void messageSender(String id, String value){
  String res = id + ' ' + value;
  Serial.println(res);
  delay(10);
  /*Serial.println(validationCode(res));*/
}

String parktronikData(){
  String str = "";
    for (int j = 0; j<8; j++)
    {
      int p = random(1,10);
      str += p;
    }
  return str;
}

void loop() {
  if (Serial.available() > 0){
    inMessageProc();
  }
  if (millis() - pastOther >= 1000){
    for (int i = 0 ; i < 10 ; ++i){
      messageSender(String(i), String(randomValue(100.0f, 50.0f)));
      delay(2); // костыль, чтобы было отдельным сообщением 
    }
    //messageSender(String(10), parktronikData());
    pastOther = millis();
  }
}
