const int led = 13;
const int buzzer = 12;
const int ldr = A0;
int counter = 0;


void setup() {
  Serial.begin(9600);

  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(ldr, OUTPUT);
}

//void loop() {
//  int ldrStatus = analogRead(ldr);
//
//  if(ldrStatus >= 3) {
//
//    tone(buzzer, 400);
//    digitalWrite(led, HIGH);
//    delay(100);
//
//    noTone(buzzer);
//    digitalWrite(led, LOW);
//    delay(200);
//
//
//    Serial.println(ldrStatus);
//  }
//  else {
//    noTone(buzzer);
//    digitalWrite(led, LOW);
//
//    Serial.println(ldrStatus);
//  }
//}


// Buzzer play star wars theme

const int c = 261;
const int d = 294;
const int e = 329;
const int f = 349;
const int g = 391;
const int gS = 415;
const int a = 440;
const int aS = 455;
const int b = 466;
const int cH = 523;
const int cSH = 554;
const int dH = 587;
const int dSH = 622;
const int eH = 659;
const int fH = 698;
const int fSH = 740;
const int gH = 784;
const int gSH = 830;
const int aH = 880;


void loop(){
  int ldrStatus = analogRead(ldr);
  if(ldrStatus >= 3) {

    //Play first section
    firstSection();

    //Play second section
    secondSection();

    //Variant 1
    beep(f, 250);
    beep(gS, 500);
    beep(f, 350);
    beep(a, 125);
    beep(cH, 500);
    beep(a, 375);
    beep(cH, 125);
    beep(eH, 650);

    delay(500);

    //Repeat second section
    secondSection();

    //Variant 2
    beep(f, 250);
    beep(gS, 500);
    beep(f, 375);
    beep(cH, 125);
    beep(a, 500);
    beep(f, 375);
    beep(cH, 125);
    beep(a, 650);

    delay(650);
  } else {
    noTone(buzzer);
    digitalWrite(led, LOW);

    Serial.println(ldrStatus);
  }
}


void beep(int note, int duration){
  //Play tone on buzzerPin
  tone(buzzer, note, duration);

  //Play different LED depending on value of 'counter'
  if(counter % 2 == 0)
  {
    digitalWrite(led, HIGH);
    delay(duration);
    digitalWrite(led, LOW);
  }
  {
    digitalWrite(led, HIGH);
    delay(duration);
    digitalWrite(led, LOW);
  }

  //Stop tone on buzzerPin
  noTone(buzzer);

  delay(50);

  //Increment counter
  counter++;
}

void firstSection()
{
  beep(a, 500);
  beep(a, 500);
  beep(a, 500);
  beep(f, 350);
  beep(cH, 150);
  beep(a, 500);
  beep(f, 350);
  beep(cH, 150);
  beep(a, 650);

  delay(500);

  beep(eH, 500);
  beep(eH, 500);
  beep(eH, 500);
  beep(fH, 350);
  beep(cH, 150);
  beep(gS, 500);
  beep(f, 350);
  beep(cH, 150);
  beep(a, 650);

  delay(500);
}

void secondSection(){
  beep(aH, 500);
  beep(a, 300);
  beep(a, 150);
  beep(aH, 500);
  beep(gSH, 325);
  beep(gH, 175);
  beep(fSH, 125);
  beep(fH, 125);
  beep(fSH, 250);

  delay(325);

  beep(aS, 250);
  beep(dSH, 500);
  beep(dH, 325);
  beep(cSH, 175);
  beep(cH, 125);
  beep(b, 125);
  beep(cH, 250);

  delay(350);
}
