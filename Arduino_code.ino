#include <Wire.h>
// #include <LiquidCrystal_I2C.h>
#include <math.h>
long x ;                              
long y;
long h = 1500;
// LiquidCrystal_I2C lcd(0x27, 16, 2);
// void setup()
// {
//   lcd.begin();


// 	lcd.backlight();
// 	lcd.clear();
//   Serial.begin(9600);                
// }
// void loop()
// {
//   x = analogRead(A0);
//   Serial.print("Joy Value in X is "); 
//   Serial.print(x);
//    y = analogRead(A1);
//   Serial.print(" \t Joy Value in y is");
//   Serial.println(y); 
//   float angle, value;
//   float g = abs(((y-512)*(y-512)) + ((x-512)*(x-512)));
//   value = sqrt(g);
//   value = value/h;
//   angle = acos(value);
//   float val = 90-((angle*180)/3.14);
//   Serial.println(val);
//   lcd.clear();
//   lcd.setCursor(0, 0);
//   lcd.print("Deflection is:");
//   lcd.setCursor(0, 1);
//   lcd.print(val-0.61);
//   lcd.print(" degree");
//   // Serial.print(val);
//   // lcd.print("°");
//   delay(100);
//   }


#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Serial.begin(9600);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  delay(2000);
  display.clearDisplay();
  // Display static text
  // display.println("Hello, world!");
  // display.display(); 
}

void loop() {
  display.setTextSize(3);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  x = analogRead(A0);
  Serial.print("Joy Value in X is "); 
  Serial.print(x);
   y = analogRead(A1);
  Serial.print(" \t Joy Value in y is");
  Serial.println(y); 
  float angle, value;
  float g = abs(((y-512)*(y-512)) + ((x-512)*(x-512)));
  value = sqrt(g);
  value = value/h;
  angle = acos(value);
  float val = 90-((angle*180)/3.14);
  Serial.println(val - 0.81);
  display.setTextSize(2);
  display.println("Wind Speed");
  display.println();
  // display.print("");
  display.setTextSize(3);
  display.print((val - 0.81)/2.8);
  display.setTextSize(2);
  display.print("m/s");
  display.display();
  display.clearDisplay();
  delay(200);
}