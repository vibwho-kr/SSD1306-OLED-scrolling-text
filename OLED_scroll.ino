#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>


#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32

#define OLED_RESET     -1
#define SCREEN_ADDRESS 0x3C 

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

char message[]="Beneath the frost-locked earth, a silent ember slept. Winter held the soil in an iron grip, a suffocating shroud of white and grey. For months, the seed knew only the heavy, numbing weight of the dark.";
int x, minX;

bool scroll = true;

void setup() {
  Serial.begin(9600);

  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
  Serial.println(F("SSD1306 allocation failed"));
  for(;;);
  }
  display.clearDisplay();

  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setTextWrap(false);

  minX = -18 * strlen(message);  // 12 = 6 pixels/character * text size 2
}


void loop() {
  x = display.width();
  while(scroll==true) {
  display.clearDisplay();
  display.setTextSize(3);
  display.setCursor(x,4);
  display.print(message);
  display.display();
  x=x-1; //change -1 to be more positive to increase scroll speed
  if(x < minX) {scroll = false;}//replace scroll=false with x=display.width() to make the scrolling loop
  }
  delay(100);
}




