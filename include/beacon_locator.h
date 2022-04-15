#include <NimBLEScan.h>

class BeaconLocator
{
    NimBLEAddress *pBLEBeaconAddr;
    NimBLEScan *pBLEScan;

    NimBLEAdvertisedDevice* getBeacon(NimBLEScanResults results);

public:
    BeaconLocator();
    bool isBeaconPresent();
};