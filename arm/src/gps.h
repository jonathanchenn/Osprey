#ifndef GPS_H
#define GPS_H

#include <Adafruit-GPS-Library/Adafruit_GPS.h>
#include <wiring_private.h>
#include <Wire.h>

#include "sensor.h"

#define GPS_RX_PIN 11
#define GPS_TX_PIN 10
#define GPS_BAUD 9600
#define ISO_8601_LENGTH 32

#define KALMAN_PROCESS_NOISE 0.01
#define KALMAN_MEASUREMENT_NOISE 0.25
#define KALMAN_ERROR 1

using namespace std;

class GPS : public virtual Sensor {
  public:
    GPS();
    int init();

    float getLatitude();
    float getLongitude();
    float getSpeed();
    float getAltitude();
    int getQuality();
    char* getIso8601();

    static Uart GPSSerial;
    static Adafruit_GPS gps;

  protected:
    char iso8601[];

    kalman_t latitude;
    kalman_t longitude;
    kalman_t speed;
    kalman_t altitude;
};

#endif
