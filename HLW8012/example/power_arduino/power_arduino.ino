#include "power.h"
ESP8266PowerClass power_dev;
unsigned long previousMillis = 0;
const long interval = 2000;
void setup() {
    Serial.begin(74880);
    Serial1.begin(115200);
    pinMode(D6,OUTPUT);
    digitalWrite(D6,HIGH);
	
	
	powerMeter.setPowerParam(12.65801022, 0.0);
    powerMeter.setVoltageParam(0.45039823, 0.0);
    powerMeter.setCurrentParam(19.52, -85.9);

    power_dev.enableMeasurePower();
    power_dev.selectMeasureCurrentOrValtage(CURRENT);
    power_dev.startMeasure(); // mills
     
    double power current frequency voltage; 
}

void loop() {
    unsigned long currentMillis = millis();
    if(currentMillis - previousMillis >= interval) {
        previousMillis = currentMillis;   

        power = powerMeter.getPower();
        current = powerMeter.getCurrent();
        voltage = powerMeter.getVoltage();

        cfrequency = powerMeter.getCurrFrequency();
        
        Serial1.println(power);
        Serial1.println(current);
        Serial1.println(voltage);

        Serial1.println(cfrequency);
    }
   // yield();
}

