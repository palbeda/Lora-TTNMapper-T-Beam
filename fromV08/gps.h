#ifndef __GPS_H__
#define __GPS_H__

#include <TinyGPS++.h>
#include <HardwareSerial.h>

#define GPS_TX 34
#define GPS_RX 12

class gps
{
    public:
        void init();
        bool checkGpsFix();
        void buildPacket(uint8_t txBuffer[9]);
        void gdisplay(uint16_t txBuffer2[5]);
        void getLatLon(double* lat, double* lon, double *alt, double *kmph, int *sats);
        void encode();
        TinyGPSPlus tGps;

    private:
        uint32_t LatitudeBinary, LongitudeBinary;
        uint16_t altitudeGps;
        uint8_t hdopGps;
        char t[32]; // used to sprintf for Serial output
};

#endif
