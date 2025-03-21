int check = 0;
int arm = 0;
int startstop = 0;

void setup() {
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);

  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);

  Serial.begin(9600);
}

void loop() {
  arm = digitalRead(5);
  startstop = digitalRead(4);
  if(startstop == 1 && check == 1){
    digitalWrite(3, HIGH);
    digitalWrite(2, HIGH);
    check = 0;
    delay(1000);
  }
  if(arm == 1 && check == 0){
    digitalWrite(3, LOW);
  }
  if(arm == 0 && check == 0){
    digitalWrite(3, HIGH);
  }
  if(arm == 1 && startstop == 1 && check == 0){
    while(startstop == 1){
      startstop = digitalRead(4);
      digitalWrite(2, LOW);
      delay(1000);
    }
    check = 1;
    digitalWrite(2, HIGH);
  }
}
