#include <LiquidCrystal.h>

// Setup the LiquidCrystal library with the pin numbers we have
// physically connected the module to.
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int lastUpdate = 0;
String s1 = "EMP", s2 = "EMP", s3 = "EMP";

// IR Sensors:
uint8_t IR1 = A3;
uint8_t IR2 = A0;
uint8_t IR3 = 10;

// Green LED's:
uint8_t G1 = A4;
uint8_t G2 = A1;
uint8_t G3 = 9;

// Red LED's:
uint8_t R1 = A5;
uint8_t R2 = A2;
uint8_t R3 = 8;

void setup() {
  // Setup the number of columns and rows that are available on the LCD.
  input(IR1); // IR Sensor
  output(G1); // Green LED
  output(R1); // Red LED
  input(IR2); // IR Sensor
  output(G2); // Green LED
  output(R2); // Red LED
  input(IR3); // IR Sensor
  output(G3); // Green LED
  output(R3); // Red LED
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("S1: EMP, s2: EMP");
  lcd.setCursor(0, 1);
  lcd.print("S3: EMP");
  digitalWrite(A4, HIGH);
  digitalWrite(A1, HIGH);
  digitalWrite(9, HIGH);
}

void loop() {
  // Get the time in milliseconds since the last reset.
  // int time = millis();

  // If 800 milliseconds have passed since we last updated
  // the text on the screen, print the next line of the
  // lyrics on the screen.
  // if ((time  - lastUpdate) >= 1000)
  // {
  //   // Move the cursor back to the first column of the first row.
  //   lcd.setCursor(0, 0);

  //   cnt1++;
  //   cnt2++;
  //   cnt3++;

  //   // increase the time in each parking by 1
  //   lcd.clear();
  //   lcd.print("S1: " + String(cnt1) + ", S2: " + String(cnt2));
  //   lcd.setCursor(0, 1);
  //   lcd.print("S3: " + String(cnt3));

  //   lastUpdate = time;
  // }

  if (isIR(IR1, LOW, s1, "FIL")) {
    setS1(G1, R1, LOW, HIGH, "FIL", s2, s3);
  } else if (isIR(IR1, HIGH, s1, "EMP")) {
    setS1(G1, R1, HIGH, LOW, "EMP", s2, s3);
  }

  if (isIR(IR2, LOW, s2, "FIL")) {
    setS1(G2, R2, LOW, HIGH, s1, "FIL", s3);
  } else if (isIR(IR2, HIGH, s2, "EMP")) {
    setS1(G2, R2, HIGH, LOW, s1, "EMP", s3);
  }

  if (isIR(IR3, LOW, s3, "FIL")) {
    setS1(G3, R3, LOW, HIGH, s1, s2, "FIL");
  } else if (isIR(IR3, HIGH, s3, "EMP")) {
    setS1(G3, R3, HIGH, LOW, s1, s2, "EMP");
  }

  delay(1);
}

void input(uint8_t pin) {
  pinMode(pin, INPUT);
}

void output(uint8_t pin) {
  pinMode(pin, OUTPUT);
}

void setS1(uint8_t pin1, uint8_t pin2, uint8_t mode1, uint8_t mode2, String newS1, String newS2, String newS3) {
  digitalWrite(pin1, mode1); // off the green LED
    digitalWrite(pin2, mode2); // on the red LED
    lcd.clear();
    lcd.setCursor(0, 0);
    s1 = newS1;
    s2 = newS2;
    s3 = newS3;
    lcd.print("S1: " + String(newS1) + ", S2: " + String(newS2));
    lcd.setCursor(0, 1);
    lcd.print("S3: " + String(newS3));
}

bool isIR(uint8_t pin, uint8_t mode, String s, String val) {
  return digitalRead(pin) == mode && s != val;
}