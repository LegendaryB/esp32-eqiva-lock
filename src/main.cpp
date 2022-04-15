#include <Arduino.h>
#include <NimBLEDevice.h>

#include <conf.h>
#include <beacon_locator.h>

void setup() {
  Serial.begin(115200);

  NimBLEDevice::init("esp32-eqiva-lock");

  BeaconLocator *bf = new BeaconLocator();
  bf->isBeaconPresent();

  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
}