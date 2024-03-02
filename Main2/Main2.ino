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
  char light = '0' + digitalRead(7);
  char shutDown = '0' + digitalRead(6);
  char sendMessage = '0' + digitalRead(5);
  char LeetCodeDailyQuestion = '0' + digitalRead(4);
  char goIncognito = '0' + digitalRead(3);
  String s = String(light) + String(shutDown) + String(sendMessage) + String(LeetCodeDailyQuestion) + String(goIncognito);
  Serial.println(s);

  if(s=="01111"){
    IsLightOn = !IsLightOn;
    if(IsLightOn){
      digitalWrite(8, HIGH);
    }
    else{
      digitalWrite(8, LOW);
    }
  }
  else if(s=="10111"){
    Serial.println("shutdown");
  }

  else if(s=="11011"){
    Serial.println("send");
  }

  else if(s=="11101"){
    Serial.println("leetcode");
  }

  else if(s=="11110"){
    Serial.println("hide");
  }

  else if(s=="00111"){
    Serial.println("openRecentTab");
  }

  else if(s=="10011"){
    Serial.println("lockScreen");
  }

  delay(2000);
}
