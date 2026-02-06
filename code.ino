int player1LED = 12;
int greenLED = 11;
int yellowLED = 10;
int redLED = 9;
int player2LED = 8;

int buzzer = 7;

int button1 = 13;
int button2 = 6;

bool buttonPressed = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(player1LED, OUTPUT);
  pinMode(player2LED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);

  pinMode(buzzer, OUTPUT);

  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);

  randomSeed(analogRead(A0));
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(greenLED, HIGH);
  digitalWrite(buzzer, HIGH);
  delay(100);
  digitalWrite(buzzer, LOW);
  delay(900);
  digitalWrite(greenLED, LOW);

  digitalWrite(yellowLED, HIGH);
  digitalWrite(buzzer, HIGH);
  delay(100);
  digitalWrite(buzzer, LOW);
  delay(900);
  digitalWrite(yellowLED, LOW);

  digitalWrite(redLED, HIGH);
  digitalWrite(buzzer, HIGH);
  delay(100);
  digitalWrite(buzzer, LOW);
  delay(random(900,4901));
  digitalWrite(redLED, LOW);

  while (buttonPressed == 0) {
    digitalWrite(player1LED, HIGH);
    digitalWrite(player2LED, HIGH);
    if (digitalRead(button1) == 0) {
      buttonPressed = 1;
      digitalWrite(player2LED, LOW);
    } else if (digitalRead(button2) == 0) {
      buttonPressed = 1;
      digitalWrite(player1LED, LOW);
    }
  }
    digitalWrite(buzzer, HIGH);
  delay(500);
  digitalWrite(buzzer, LOW);
  delay(1500);
  digitalWrite(player1LED, LOW);
  digitalWrite(player2LED, LOW);
  buttonPressed = 0;
}
