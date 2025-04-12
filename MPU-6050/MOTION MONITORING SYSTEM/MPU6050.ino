// Include necessary libraries
#include <Wire.h>
#include <MPU6050.h>
#include <LiquidCrystal_I2C.h>

// Initialize MPU6050
MPU6050 mpu;

// Initialize LCD16x2 on I2C address 0x27 (common address)
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
    // Initialize serial communication for debugging
    Serial.begin(9600);

    // Initialize I2C communication
    Wire.begin();

    // Initialize MPU6050 
    mpu.initialize();
    
    if (!mpu.testConnection()) {
        Serial.println("Could not find a valid MPU6050 sensor, check wiring!");
        while (1);
    }

    // Initialize LCD 
    lcd.init();
    lcd.backlight();
    
    lcd.setCursor(0, 0);
    lcd.print("MPU6050 Sensor");
    
    // Clear LCD and display initial message 
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("MPU60 Data");
}

void loop() {
    int16_t ax, ay, az;
    int16_t gx, gy, gz;

    // Read raw data from MPU6050
    mpu.getAcceleration(&ax, &ay, &az);
    mpu.getRotation(&gx, &gy, &gz);
    
    // Convert raw data into g's & degrees per second  
    float ax_f = ax / 16384.00;
    float ay_f = ay / 16384.00;
    float az_f = az / 16384.00;
    
    float gx_f = gx / 131.00;  
    float gy_f = gy / 131.00;  
    float gz_f = gz / 131.00;

    float temperature = mpu.getTemperature() / 340.00 + 36.53; 

    // Display Accelerometer data on LCD
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Accel X: ");
    lcd.print(ax_f);
    lcd.setCursor(0, 1);
    lcd.print("Accel Y: ");
    lcd.print(ay_f);
    delay(2000); // Display for 2 seconds

    // Display Accelerometer Z and Gyroscope X on LCD
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Accel Z: ");
    lcd.print(az_f);
    lcd.setCursor(0, 1);
    lcd.print("Gyro X: ");
    lcd.print(gx_f);
    delay(2000); // Display for 2 seconds

    // Display Gyroscope Y and Z on LCD
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Gyro Y: ");
    lcd.print(gy_f);
    lcd.setCursor(0, 1);
    lcd.print("Gyro Z: ");
    lcd.print(gz_f);
    delay(2000); // Display for 2 seconds

    // Display Temperature
    lcd.clear();
    lcd.setCursor(0 ,0);  
    lcd.print("Temp: ");   
    lcd.print(temperature);   
    delay(2000);
}
