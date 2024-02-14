#pin declarations
int taster = 2;
int lampe_rot = 3;
int lampe_gelb = 4;
int lampe_gruen = 5;
int rgb_rot = 6;
int rgb_blau = 8;
int rgb_gruen = 7;
int piezo = 9;
int temp = 12;
int ldr = A7;
int sensor_wert = 0;
int potentiometer = A6;
SSD1306AsciiWire oled;
DHT dht(DHTPIN, DHTTYPE);

#include "SSD1306Ascii.h"
#include "SSD1306AsciiWire.h"
#include <Wire.h>
#define I2C_ADDRESS 0x3C
#include <DHT.h>
#define DHTPIN 12
#define DHTTYPE DHT11

#include <Adafruit_NeoPixel.h>
#ifdef _AVR_
#include <avr/power.h>
#endif
#define PIN 11
#define NUMPIXELS 40
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
#define NOTE_B0 31
#define NOTE_C1 33
#define NOTE_CS1 35
#define NOTE_D1 37
#define NOTE_DS1 39
#define NOTE_E1 41
#define NOTE_F1 44
#define NOTE_FS1 46
#define NOTE_G1 49
#define NOTE_GS1 52
#define NOTE_A1 55
#define NOTE_AS1 58
#define NOTE_B1 62
#define NOTE_C2 65
#define NOTE_CS2 69
#define NOTE_D2 73
#define NOTE_DS2 78
#define NOTE_E2 82
#define NOTE_F2 87
#define NOTE_FS2 93
#define NOTE_G2 98
#define NOTE_GS2 104
#define NOTE_A2 110
#define NOTE_AS2 117
#define NOTE_B2 123
#define NOTE_C3 131
#define NOTE_CS3 139
#define NOTE_D3 147
#define NOTE_DS3 156
#define NOTE_E3 165
#define NOTE_F3 175
#define NOTE_FS3 185
#define NOTE_G3 196
#define NOTE_GS3 208
#define NOTE_A3 220
#define NOTE_AS3 233
#define NOTE_B3 247
#define NOTE_C4 262
#define NOTE_CS4 277
#define NOTE_D4 294
#define NOTE_DS4 311
#define NOTE_E4 330
#define NOTE_F4 349
#define NOTE_FS4 370
#define NOTE_G4 392
#define NOTE_GS4 415
#define NOTE_A4 440
#define NOTE_AS4 466
#define NOTE_B4 494
#define NOTE_C5 523
#define NOTE_CS5 554
#define NOTE_D5 587
#define NOTE_DS5 622
#define NOTE_E5 659
#define NOTE_F5 698
#define NOTE_FS5 740
#define NOTE_G5 784
#define NOTE_GS5 831
#define NOTE_A5 880
#define NOTE_AS5 932
#define NOTE_B5 988
#define NOTE_C6 1047
#define NOTE_CS6 1109
#define NOTE_D6 1175
#define NOTE_DS6 1245
#define NOTE_E6 1319
#define NOTE_F6 1397
#define NOTE_FS6 1480
#define NOTE_G6 1568
#define NOTE_GS6 1661
#define NOTE_A6 1760
#define NOTE_AS6 1865
#define NOTE_B6 1976
#define NOTE_C7 2093
#define NOTE_CS7 2217
#define NOTE_D7 2349
#define NOTE_DS7 2489
#define NOTE_E7 2637
#define NOTE_F7 2794
#define NOTE_FS7 2960
#define NOTE_G7 3136
#define NOTE_GS7 3322
#define NOTE_A7 3520
#define NOTE_AS7 3729
#define NOTE_B7 3951
#define NOTE_C8 4186
#define NOTE_CS8 4435
#define NOTE_D8 4699
#define NOTE_DS8 4978
#define REST 0

int tempo = 88;
int buzzer = 11;
int melody[] = {
    NOTE_AS4, -2, NOTE_F4, 8, NOTE_F4, 8, NOTE_AS4, 8, // 1
    NOTE_GS4, 16, NOTE_FS4, 16, NOTE_GS4, -2,
    NOTE_AS4, -2, NOTE_FS4, 8, NOTE_FS4, 8, NOTE_AS4, 8,
    NOTE_A4, 16, NOTE_G4, 16, NOTE_A4, -2,
    REST, 1,

    NOTE_AS4, 4, NOTE_F4, -4, NOTE_AS4, 8, NOTE_AS4, 16, NOTE_C5, 16, NOTE_D5, 16, NOTE_DS5, 16, // 7
    NOTE_F5, 2, NOTE_F5, 8, NOTE_F5, 8, NOTE_F5, 8, NOTE_FS5, 16, NOTE_GS5, 16,
    NOTE_AS5, -2, NOTE_AS5, 8, NOTE_AS5, 8, NOTE_GS5, 8, NOTE_FS5, 16,
    NOTE_GS5, -8, NOTE_FS5, 16, NOTE_F5, 2, NOTE_F5, 4,

    NOTE_DS5, -8, NOTE_F5, 16, NOTE_FS5, 2, NOTE_F5, 8, NOTE_DS5, 8, // 11
    NOTE_CS5, -8, NOTE_DS5, 16, NOTE_F5, 2, NOTE_DS5, 8, NOTE_CS5, 8,
    NOTE_C5, -8, NOTE_D5, 16, NOTE_E5, 2, NOTE_G5, 8,
    NOTE_F5, 16, NOTE_F4, 16, NOTE_F4, 16, NOTE_F4, 16, NOTE_F4, 16, NOTE_F4, 16, NOTE_F4, 16, NOTE_F4, 16, NOTE_F4, 8, NOTE_F4, 16, NOTE_F4, 8,

    NOTE_AS4, 4, NOTE_F4, -4, NOTE_AS4, 8, NOTE_AS4, 16, NOTE_C5, 16, NOTE_D5, 16, NOTE_DS5, 16, // 15
    NOTE_F5, 2, NOTE_F5, 8, NOTE_F5, 8, NOTE_F5, 8, NOTE_FS5, 16, NOTE_GS5, 16,
    NOTE_AS5, -2, NOTE_CS6, 4,
    NOTE_C6, 4, NOTE_A5, 2, NOTE_F5, 4,
    NOTE_FS5, -2, NOTE_AS5, 4,
    NOTE_A5, 4, NOTE_F5, 2, NOTE_F5, 4,

    NOTE_FS5, -2, NOTE_AS5, 4,
    NOTE_A5, 4, NOTE_F5, 2, NOTE_D5, 4,
    NOTE_DS5, -2, NOTE_FS5, 4,
    NOTE_F5, 4, NOTE_CS5, 2, NOTE_AS4, 4,
    NOTE_C5, -8, NOTE_D5, 16, NOTE_E5, 2, NOTE_G5, 8,
    NOTE_F5, 16, NOTE_F4, 16, NOTE_F4, 16, NOTE_F4, 16, NOTE_F4, 16, NOTE_F4, 16, NOTE_F4, 16, NOTE_F4, 16, NOTE_F4, 8, NOTE_F4, 16, NOTE_F4, 8

};
int notes = sizeof(melody) / sizeof(melody[0]) / 2;

// this calculates the duration of a whole note in ms (60s/tempo)*4 beats
int wholenote = (60000 * 4) / tempo;

int divider = 0, noteDuration = 0;

void setup()
{
  pinMode(2, INPUT_PULLUP);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  pinMode(12, INPUT_PULLUP);
  Wire.begin();
  oled.begin(&Adafruit128x64, 0x3C);
  Serial.begin(9600);
  pixels.begin();
}

void loop()
{
  oled.setFont(System5x7);
  oled.clear();
  aussschaltenLampen();
  /*
  pin #2 is a button, the following meaning "if button is pressed"
  */
  if (digitalRead(2) == LOW)
  {
    testDrehteil();    // test the potentiometer
    testGluehbirne();  // test the lights
    testRGB();         // test the LED lights
    testOLEDDisplay(); // test OLED
    testLDR();         // test photosensor
    testTemperatur();  // test temperature sensor
    testRGBStreifen(); // test the rgb-strip
    theEnd();          // play music
  }
}

void testDrehteil()
{
  /*
  this function tests the output of the potentiometer, the value it is set tho corresponds with the frequency of the sound playing
  */
  oled.println("Drehteil Langsam drehen");
  while (true)
  {
    int status = analogRead(A6);
    tone(piezo, status, 100);
    if (status == 1023)
    {
      oled.println("Maximum erreicht!");
      delay(3000);
      break;
    }
  }
}

void testGluehbirne()
{
  /*
  tests all lights seperately
  */
 
  oled.clear();
  // Rote Lampe
  digitalWrite(lampe_rot, 1);
  tone(piezo, 300);
  oled.println("Rote Lampe");
  delay(1500);
  digitalWrite(lampe_rot, 0);
  noTone(piezo);
  oled.clear();
  delay(500);

  // Gelbe Lampe
  digitalWrite(lampe_gelb, 1);
  tone(piezo, 300);
  oled.println("Gelbe Lampe");
  delay(1500);
  digitalWrite(lampe_gelb, 0);
  noTone(piezo);
  oled.clear();
  delay(500);

  // Gruene Lampe
  digitalWrite(lampe_gruen, 1);
  tone(piezo, 300);
  oled.println("Gruene Lampe");
  delay(1500);
  digitalWrite(lampe_gruen, 0);
  noTone(piezo);
  oled.clear();
  delay(500);
}

void testRGB()
{
  /*
  tests all colors of the LED and then white
   */
  // Rote LED von RGB
  digitalWrite(rgb_rot, 0);
  tone(piezo, 300);
  oled.println("Rote LED von RGB");
  delay(1500);
  digitalWrite(rgb_rot, 1);
  noTone(piezo);
  oled.clear();
  delay(500);

  // Gelbe LED von RGB
  digitalWrite(rgb_blau, 0);
  tone(piezo, 300);
  oled.println("Blaue LED von RGB");
  delay(1500);
  digitalWrite(rgb_blau, 1);
  noTone(piezo);
  oled.clear();
  delay(500);

  // Grüne LED von RGB
  digitalWrite(rgb_gruen, 0);
  tone(piezo, 300);
  oled.println("Gruene LED von RGB");
  delay(1500);
  digitalWrite(rgb_gruen, 1);
  noTone(piezo);
  oled.clear();
  delay(500);

  // Weiße Farbe (Intensität Testen)
  digitalWrite(rgb_gruen, 0);
  digitalWrite(rgb_rot, 0);
  digitalWrite(rgb_blau, 0);
  tone(piezo, 300);
  oled.println("LED White");
  delay(1500);
  digitalWrite(rgb_gruen, 1);
  digitalWrite(rgb_rot, 1);
  digitalWrite(rgb_blau, 1);
  noTone(piezo);
  oled.clear();
  delay(500);
}

void testOLEDDisplay()
{
  /*
  basically tests the oled display
  kinda useless? because previous functions already used the oled
  which means that when you couldnt see something earlier you wont see something now
  */
  oled.println("OLED Screen Test");
  delay(1000);
  oled.clear();

  tone(piezo, 300);
  oled.println("bad things was written here");
  delay(10000);
  sensor_wert = analogRead(ldr);
  Serial.print("Sensortwert = ");
  Serial.println(sensor_wert);
  noTone(piezo);
  oled.clear();
  delay(500);
}

void testLDR()
{
  /*
  i dont know if this ever worked? because im not sure under which conditions the ldr sends a true / false
  */
  oled.println("Bitte Lichtsensor freilassen");
  delay(2000);
  oled.clear();
  if (sensor_wert < 1000)
  {
    digitalWrite(lampe_rot, HIGH);
    digitalWrite(lampe_gelb, HIGH);
    digitalWrite(lampe_gruen, HIGH);
    oled.println("Es ist Hell -> Klappt");
    oled.println("glauben wir");
    delay(1500);
  }
  else
  {
    oled.println("Es ist Dunkel!");
    oled.println("LDR vllt kaputt?");
    delay(1500);
  }
  digitalWrite(lampe_rot, LOW);
  digitalWrite(lampe_gelb, LOW);
  digitalWrite(lampe_gruen, LOW);
}

void testTemperatur()
{
  /*
  this sometimes worked and sometimes did not so im not sure whether there is an error here or something else
  maybe we just had a lot of broken boards
  */
  oled.clear();
  delay(1500);
  oled.println("Temperatur messen:");
  tone(piezo, 300);
  delay(1500);
  oled.println("Temperatur:");
  float aktuelleTemperatur = dht.readTemperature();
  oled.print(aktuelleTemperatur);
  noTone(piezo);
  delay(2500);
  oled.clear();
  delay(1500);
}

void testRGBStreifen()
{
  /*
  goes through many colors
  */
  int intervall = 40;
  oled.println("RGB Streifen Test");
  tone(piezo, 300);
  delay(1500);
  noTone(piezo);
  for (int i = 1; i < 256; i = i + intervall)
  {
    for (int j = 1; j < 256; j = j + intervall)
    {
      for (int k = 1; k < 256; k = k + intervall)
      {
        oled.println("Rot: ");
        oled.println(i);
        oled.println("Gruen: ");
        oled.println(j);
        oled.println("Blau: ");
        oled.println(k);
        pixels.setPixelColor(1, pixels.Color(i, j, k));
        pixels.show();
        delay(1);
        pixels.setPixelColor(2, pixels.Color(i, j, k));
        pixels.show();
        delay(1);
        pixels.setPixelColor(3, pixels.Color(i, j, k));
        pixels.show();
        delay(1);
        pixels.setPixelColor(4, pixels.Color(i, j, k));
        pixels.show();
        delay(1);
        pixels.setPixelColor(5, pixels.Color(i, j, k));
        pixels.show();
        delay(1);
        pixels.setPixelColor(6, pixels.Color(i, j, k));
        pixels.show();
        delay(1);
        pixels.setPixelColor(7, pixels.Color(i, j, k));
        pixels.show();
        delay(1);
        pixels.setPixelColor(8, pixels.Color(i, j, k));
        pixels.show();
        delay(1);
        oled.clear();
      }
    }
  }
  aussschaltenLampen();
  oled.clear();
  tone(piezo, 300);
  delay(500);
  noTone(piezo);
  oled.clear();
}

void theEnd()
{
  oled.println("Test Erfolgreich!");
  musikSpielen();
}

void musikSpielen()
{
  /*
  not by me (yungztr)
  credits in readme.md
  */
  for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2)
  {

    // calculates the duration of each note
    divider = melody[thisNote + 1];
    if (divider > 0)
    {
      // regular note, just proceed
      noteDuration = (wholenote) / divider;
    }
    else if (divider < 0)
    {
      // dotted notes are represented with negative durations!!
      noteDuration = (wholenote) / abs(divider);
      noteDuration *= 1.5; // increases the duration in half for dotted notes
    }

    // we only play the note for 90% of the duration, leaving 10% as a pause
    tone(piezo, melody[thisNote], noteDuration * 0.9);

    // Wait for the specief duration before playing the next note.
    delay(noteDuration);

    // stop the waveform generation before the next note.
    noTone(piezo);
  }
}

void aussschaltenLampen()
{
  pixels.setPixelColor(1, pixels.Color(0, 0, 0));
  pixels.show();
  pixels.setPixelColor(2, pixels.Color(0, 0, 0));
  pixels.show();
  pixels.setPixelColor(3, pixels.Color(0, 0, 0));
  pixels.show();
  pixels.setPixelColor(4, pixels.Color(0, 0, 0));
  pixels.show();
  pixels.setPixelColor(5, pixels.Color(0, 0, 0));
  pixels.show();
  pixels.setPixelColor(6, pixels.Color(0, 0, 0));
  pixels.show();
  pixels.setPixelColor(7, pixels.Color(0, 0, 0));
  pixels.show();
  pixels.setPixelColor(8, pixels.Color(0, 0, 0));
  pixels.show();

  digitalWrite(rgb_rot, 1);
  digitalWrite(rgb_blau, 1);
  digitalWrite(rgb_gruen, 1);
  digitalWrite(lampe_gruen, 0);
  digitalWrite(lampe_gelb, 0);
  digitalWrite(lampe_rot, 0);
}