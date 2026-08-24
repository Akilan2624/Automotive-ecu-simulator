#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define BUTTON_1 18
#define BUTTON_2 19


#define BUZZER 23

bool engineRunning = false;
bool warningActive = false;

void setup() {
  pinMode(BUTTON_1, INPUT_PULLUP);
  pinMode(BUTTON_2, INPUT_PULLUP);
  pinMode(BUZZER, OUTPUT);

  digitalWrite(BUZZER, LOW);

  Wire.begin();

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    while (true);
  }

  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(1);

  display.setCursor(10, 10);
  display.println("AUTOMOTIVE ECU");
  display.setCursor(25, 30);
  display.println("SIMULATOR");

  display.display();
  delay(2000);

  updateDisplay();
}

void loop() {

  
  if (digitalRead(BUTTON_1) == LOW) {
    delay(50);

    if (digitalRead(BUTTON_1) == LOW) {
      engineRunning = !engineRunning;

      if (!engineRunning) {
        warningActive = false;
        digitalWrite(BUZZER, LOW);
      }

      updateDisplay();

      while (digitalRead(BUTTON_1) == LOW);
    }
  }


  if (digitalRead(BUTTON_2) == LOW) {
    delay(50);

    if (digitalRead(BUTTON_2) == LOW) {

      if (engineRunning) {
        warningActive = !warningActive;

        if (warningActive) {
          digitalWrite(BUZZER, HIGH);
        } else {
          digitalWrite(BUZZER, LOW);
        }

        updateDisplay();
      }

      while (digitalRead(BUTTON_2) == LOW);
    }
  }
}

void updateDisplay() {

  display.clearDisplay();

  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("ECU STATUS");
  display.println("----------------");

  display.setCursor(0, 20);

  if (engineRunning) {
    display.println("ENGINE: RUNNING");
  } else {
    display.println("ENGINE: OFF");
  }

  display.setCursor(0, 35);

  if (warningActive) {
    display.println("WARNING: ACTIVE");
  } else {
    display.println("WARNING: NORMAL");
  }

  display.setCursor(0, 52);

  if (warningActive) {
    display.println("BUZZER: ON");
  } else {
    display.println("BUZZER: OFF");
  }

  display.display();
}
