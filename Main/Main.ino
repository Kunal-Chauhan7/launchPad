static boolean IsLightOn = false;
void setup() {
  Serial.begin(9600);
  pinMode(7, INPUT);
  pinMode(8, OUTPUT);
}

void loop() {
  int light = digitalRead(7);
  if(light==0){
    IsLightOn = !IsLightOn;
  }
  if(IsLightOn){
    digitalWrite(8, HIGH);
  }
  else{
    digitalWrite(8, LOW);
  }
  delay(250);
}
