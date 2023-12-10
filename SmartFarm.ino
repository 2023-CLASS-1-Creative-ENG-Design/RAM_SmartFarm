#include <Adafruit_NeoPixel.h>
#include <DHT.h>
#include <DHT_U.h>
#include <Wire.h>
#include <LiquidCrystal.h>
#include <LiquidCrystal_I2C.h>

#define DHTPIN 7
#define DHTTYPE DHT11
#define LEDPIN 6
#define CDSPIN A0
#define NUMPIXELS 8

Adafruit_NeoPixel pixels(NUMPIXELS, LEDPIN, NEO_GRB + NEO_KHZ800);

DHT dht(DHTPIN, DHTTYPE);
// LCD 설정
LiquidCrystal lcd(11, 10, 5, 4, 3, 2);  // 일반 LCD 핀 설정
LiquidCrystal_I2C lcd_i2c(0x27, 16, 2);  // I2C LCD 설정, 주소는 0x27일 수 있습니다.

// 채광량, 습도, 온도, 토양습도를 저장
int Sunlight = 0;	
float Humidity = 0;
float Temperature = 0;
int SoilHumid = 0;

// 물높이 변수
int level = 0;

// 시간을 확인하기 위한 변수 (+1 -> 10s)
int ClockCounter = 351;

// 핀 설정
int Sensor_pin = A3;
int A1A = 9;
int A1B = 8;
int INA = 12;
int INB = 13;

int i;

// Default setup
void setup() {
	Serial.begin(9600);
	// INITIALIZE NeoPixel strip object (REQUIRED)
	pixels.begin();
  pinMode(A1A, OUTPUT);
  pinMode(A1B, OUTPUT);
  pinMode(INA, OUTPUT);
  pinMode(INB, OUTPUT);
  digitalWrite(INA,LOW);
  digitalWrite(INB,LOW);
	lcd.begin(16, 2);
	lcd_i2c.init();
	lcd_i2c.backlight();
	lcd_i2c.begin(16, 2);
	dht.begin();
}

void loop() {
	// 센서로부터 값을 읽어와 저장 및 출력
	Sunlight = analogRead(CDSPIN);
	Humidity = dht.readHumidity();
	Temperature = dht.readTemperature();
  level = analogRead(A1);

  // 시리얼 모니터 출력
	Serial.println("Humid: ");
	Serial.println(Humidity);
	Serial.println("Temperature: ");
	Serial.println(Temperature);
	Serial.println("Light: ");
	Serial.println(Sunlight);
  Serial.println("Level: ");
  Serial.println(level);
  Serial.println("Soil(hour): ");
	Serial.println(SoilHumid);

  // 첫 번째 LCD에 변수 1과 2 표시
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Humid: ");
  lcd.print(Humidity);
  lcd.setCursor(0, 1);
  lcd.print("Temp: ");
  lcd.print(Temperature);

  // 두 번째 LCD에 변수 3과 4 표시
  lcd_i2c.clear();
  lcd_i2c.setCursor(0, 0);
  lcd_i2c.print("Light: ");
  lcd_i2c.print(Sunlight);
	lcd_i2c.setCursor(0, 1);
  lcd_i2c.print("Soil(hour): ");
  lcd_i2c.print(SoilHumid);

  // 습도가 높으면 선풍기 작동
	if (Humidity >= 80 || Temperature >= 30)
  {
		digitalWrite(INA,HIGH);
    digitalWrite(INB,LOW); 
    delay(3000);
    digitalWrite(INA,LOW);
    digitalWrite(INB,LOW);
    delay(3000);
    ClockCounter += 6;
	}
  if (level < 500)
  {
    lcd_i2c.setCursor(15, 0);
    lcd_i2c.print("W");
  }
  // 1시간 간격으로 측정
	if (ClockCounter >= 360)
  {
    // max 1023(dry) ~ min 200(wet)
    SoilHumid = analogRead(Sensor_pin);
    // 워터펌프를 3초 동안 작동시켜 물 공급
    if (SoilHumid > 650)
    {
      Serial.println("\nwater\n");
      digitalWrite(A1A, HIGH);
      digitalWrite(A1B, LOW);
      delay(6000);
      digitalWrite(A1A, LOW);
      digitalWrite(A1B, LOW);
    }
    // 변수 초기화
    ClockCounter = 0;
	}

	// 조도량에 따라 LED를 작동할 개수를 결정
	// ex, 850일 때는 0번과 1번 LED 동작
  pixels.clear();
  i = 0;
	if (Sunlight < 960 && Sunlight >= 840)
  {
    pixels.setPixelColor(i, pixels.Color(255, 0, 255));
  }
  else if (Sunlight < 840 && Sunlight >= 720)
  {
    for (i; i < 2; i++)
    {
      pixels.setPixelColor(i, pixels.Color(255, 0, 255));
    }
  }
  else if (Sunlight < 720 && Sunlight >= 600)
  {
    for (i; i < 3; i++)
    {
      pixels.setPixelColor(i, pixels.Color(255, 0, 255));
    }
  }
  else if (Sunlight < 600 && Sunlight >= 480)
  {
    for (i; i < 4; i++)
    {
      pixels.setPixelColor(i, pixels.Color(255, 0, 255));
    }
  }
  else if (Sunlight < 480 && Sunlight >= 360)
  {
    for (i; i < 5; i++)
    {
      pixels.setPixelColor(i, pixels.Color(255, 0, 255));
    }
  }
  else if (Sunlight < 360 && Sunlight >= 240)
  {
    for (i; i < 6; i++)
    {
      pixels.setPixelColor(i, pixels.Color(255, 0, 255));
    }
  }
  else if (Sunlight < 240 && Sunlight >= 120)
  {
    for (i; i < 7; i++)
    {
      pixels.setPixelColor(i, pixels.Color(255, 0, 255));
    }
  }
  else if (Sunlight < 120)
  {
    for (i; i < 8; i++)
    {
      pixels.setPixelColor(i, pixels.Color(255, 0, 255));
    }
  }
  pixels.show();
  delay(3000);
	ClockCounter += 3;
}