#define delay50 100

int myled[] = {4, 5, 9, 10};
int num_of_leds;

void setup() {
  num_of_leds = sizeof(myled) / sizeof(int);
  for (int i = 0; i < num_of_leds; i++) {
    pinMode(myled[i], OUTPUT);
  }
}

void loop() {
  delay(1000);
  ledonn();
  delay(2000);
  ledoff();
  delay(2000);
  for (int i = 0; i < 5; i++) {pattern1();}
  for (int i = 0; i < 5; i++) {pattern2();}
  for (int i = 0; i < 5; i++) {pattern3();}
  for (int i = 0; i < 5; i++) {pattern4();}
  for (int i = 0; i < 25; i++){pattern5();}
  for (int i = 0; i < 5; i++) {pattern6();}
  for (int i = 0; i < 15; i++){pattern7();}
  for (int i = 0; i < 15; i++){pattern8();}
  for (int i = 0; i < 5; i++) {pattern9();}
  for (int i = 0; i < 50; i++){pattern11();}
  for (int i = 0; i < 50; i++){pattern12();}
  ledoff();
  delay(5000);
}

//TURN ON ALL LEDs
void ledonn() {
  for (int i = 0; i < num_of_leds; i++) {
    digitalWrite(myled[i], LOW);
  }
}

//TURN OFF ALL LEDs
void ledoff() {
  for (int i = 0; i < num_of_leds; i++) {
    digitalWrite(myled[i], HIGH);
  }
}

//LEFT TO RIGHT
void pattern1() {
  for (int i = 0; i < num_of_leds; i++) {
    digitalWrite(myled[i], LOW);
    delay(delay50);
    digitalWrite(myled[i], HIGH);
  }
}

//RIGHT TO LEFT
void pattern2() {
  for (int i = num_of_leds; i > 0; i--) {
    digitalWrite(myled[i - 1], LOW);
    delay(delay50);
    digitalWrite(myled[i - 1], HIGH);
  }
}

//LEFT TO RIGHT FILL
void pattern3() {
  for (int i = 0; i < num_of_leds; i++) {
    digitalWrite(myled[i], LOW);
    delay(delay50);
  }
  for (int i = num_of_leds; i > 0; i--) {
    digitalWrite(myled[i - 1], HIGH);
    delay(delay50);
  }
}

//RIGHT TO LEFT FILL
void pattern4() {
  ledonn();
  delay(delay50);
  for (int i = 0; i < num_of_leds; i++) {
    digitalWrite(myled[i], HIGH);
    delay(delay50);
  }
  for (int i = num_of_leds; i > 0; i--) {
    digitalWrite(myled[i - 1], LOW);
    delay(delay50);
  }
  ledoff();
}

//ALTERNATE LEDs
void pattern5() {
  for (int i = 0; i < num_of_leds; i = i + 2) {
    digitalWrite(myled[i], LOW);
    digitalWrite(myled[i + 1], HIGH);
  }
  delay(delay50);
  for (int i = 0; i < num_of_leds; i = i + 2) {
    digitalWrite(myled[i], HIGH);
    digitalWrite(myled[i + 1], LOW);
  }
  delay(delay50);
}

//OSCILLATING LEDs
void pattern6() {   //osc
  for (int i = 0; i < num_of_leds; i++) {
    digitalWrite(myled[i], LOW);
    delay(delay50);
    digitalWrite(myled[i], HIGH);
  }
  delay(delay50);
  for (int i = num_of_leds; i > 0; i--) {
    digitalWrite(myled[i - 1], LOW);
    delay(delay50);
    digitalWrite(myled[i - 1], HIGH);
  }
}

//INSIDE
void pattern7() {
  for (int i = 0; i < num_of_leds / 2; i++) {
    digitalWrite(myled[i], LOW);
    digitalWrite(myled[num_of_leds - 1 - i], LOW);
    delay(delay50);
    digitalWrite(myled[i], HIGH);
    digitalWrite(myled[num_of_leds - 1 - i], HIGH);
  }
}

//OUTSIDE
void pattern8() 
{
  for (int i = (num_of_leds / 2) - 1; i >= 0 ; i--)
  {
    digitalWrite(myled[i], LOW);
    digitalWrite(myled[num_of_leds - 1 - i], LOW);
    delay(delay50);
    digitalWrite(myled[i], HIGH);
    digitalWrite(myled[num_of_leds - 1 - i],HIGH);
  }
}

//LEFT TO RIGHT 3 LEDs
void pattern9() {
  for (int i = 0; i < num_of_leds + 3; i++) {
    if (i <= num_of_leds) {
      digitalWrite(myled[i], LOW);
    }
    if (i > 2) {
      digitalWrite(myled[i - 3], HIGH);
    }
    delay(delay50);
  }
}

//RANDOM EFFECT 1
void pattern11() {
  int randomnum = random(0, num_of_leds + 1);
  digitalWrite(myled[randomnum], LOW);
  delay(delay50);
  digitalWrite(myled[randomnum], HIGH);
  delay(delay50);
}

//RANDOM EFFECT 2
void pattern12() {
  int randomonn = random(0, num_of_leds + 1);
  int randomoff = random(0, num_of_leds + 1);
  digitalWrite(myled[randomonn], LOW);
  digitalWrite(myled[randomoff], HIGH);
  delay(delay50);
}
