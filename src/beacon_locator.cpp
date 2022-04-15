#include <beacon_locator.h>
#include <conf.h>
#include <Arduino.h>
#include <NimBLEDevice.h>
#include <string>

BeaconLocator::BeaconLocator() {
    pBLEBeaconAddr = new NimBLEAddress(BEACON_BLE_ADDR);
    pBLEScan = NimBLEDevice::getScan();
}

NimBLEAdvertisedDevice* BeaconLocator::getBeacon(NimBLEScanResults results) {
    NimBLEAdvertisedDevice* device;

    for (int i = 0; i < results.getCount(); i++) {
        NimBLEAdvertisedDevice bleDevice = results.getDevice(i);

        if (bleDevice.getAddress() == *pBLEBeaconAddr) 
        {
            Serial.println("");
            Serial.println("Found Mi band beacon!");
            Serial.println(bleDevice.getRSSI());

            break;
        }
    }

    return device;
}

bool BeaconLocator::isBeaconPresent() {
    pBLEScan->setActiveScan(true);
    pBLEScan->start(5);

    NimBLEScanResults results = pBLEScan->getResults();

    NimBLEAdvertisedDevice device;

    for (int i = 0; i < results.getCount(); i++) {
        NimBLEAdvertisedDevice bleDevice = results.getDevice(i);

        if (bleDevice.getAddress() == *pBLEBeaconAddr) 
        {
            Serial.println("");
            Serial.println("Found Mi band beacon!");
            Serial.println(bleDevice.getRSSI());

            break;
        }
    }

    return false;
}