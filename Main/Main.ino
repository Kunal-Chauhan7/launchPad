static boolean IsLightOn = false;
void setup() {
  Serial.begin(9600);
  pinMode(7, INPUT);
  pinMode(6, INPUT);
  pinMode(5, INPUT);
  pinMode(4, INPUT);
  pinMode(3, INPUT);
  pinMode(8, OUTPUT);
}

void loop() {
  int light = digitalRead(7);
  int shutDown = digitalRead(6);
  int sendMessage = digitalRead(5);
  int LeetCodeDailyQuestion = digitalRead(4);
  int goIncoginto = digitalRead(3);
  if(light==0){
    IsLightOn = !IsLightOn;
  }
  if(IsLightOn){
    digitalWrite(8, HIGH);
  }
  else{
    digitalWrite(8, LOW);
  }

  if(shutDown==0){
    Serial.println("shutdown");
  }

  if(sendMessage==0){
    Serial.println("send");
  }

  if(LeetCodeDailyQuestion==0){
    Serial.println("leetcode");
  }

  if(goIncoginto==0){
    Serial.println("hide");
  }

  delay(250);
}
