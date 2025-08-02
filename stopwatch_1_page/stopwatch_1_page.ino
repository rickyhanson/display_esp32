#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Serial.begin(115200);
  
  // Start I2C Communication SDA = 5 and SCL = 4 on Wemos Lolin32 ESP32 with built-in SSD1306 OLED
  Wire.begin(5, 4);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C, false, false)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  delay(2000); // Pause for 2 seconds
 
  // Clear the buffer.
  display.clearDisplay();

  //image_cat
  // Draw bitmap on the screen
  display.drawBitmap(0, 0, image_cat, 128, 64, 1);
  display.display();
  //end image_cat
}
 
void loop() {
  unsigned long currentMillis = millis();
  char timeString[9];  // format "MM:SS" + null terminator

  // Clear the display to make sure the new image is shown cleanly
  display.clearDisplay();
    
  // Draw the blank image or any other image
  display.setTextSize(1);
  display.setTextColor(WHITE);

  // Display static message
  display.setCursor(0, 0);
  display.print("Tap to login");
  // Set the cursor slightly to the left and in the middle vertically
  display.setCursor(44,46);
  display.println("Logged in for:");
  // Display for the stopwatch
  display.setCursor(58,55);

  int hours = (currentMillis/1000/60/60)%24;
  int minutes = (currentMillis/1000/60)%60;
  int seconds = (currentMillis/1000)%60;

  sprintf(timeString, "%02d:%02d:%02d", hours, minutes, seconds);

  display.println(timeString);
  display.display();
}