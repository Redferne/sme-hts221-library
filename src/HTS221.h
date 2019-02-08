/*
 * HTS221.h
 *
 * Created: 02/01/2015 20:50:30
 *  Author: smkk
 */


#ifndef HTS221_H_
#define HTS221_H_

#include <Arduino.h>

#define AVERAGE_DEFAULT    0x1B // 16T & 32H samples
#define AVERAGE_32_64      0x24 // 32T & 64H samples
#define AVERAGE_64_128     0x2D // 64T & 128H samples
#define AVERAGE_128_256    0x36 // 128T & 256H samples
#define AVERAGE_256_512    0x3F // 256T & 512H samples

class HTS221
{
public:
    HTS221(void);
    bool begin(void);
    bool activate(void);
    bool samples(uint8_t);
    bool deactivate(void);

    bool bduActivate(void);
    bool bduDeactivate(void);

    const float readHumidity(void);
    const float readTemperature(void);
private:
    bool storeCalibration(void);
    unsigned char _h0_rH, _h1_rH;
    unsigned int  _T0_degC, _T1_degC;
    unsigned int  _H0_T0, _H1_T0;
    unsigned int  _T0_OUT, _T1_OUT;
    float _temperature;
    float _humidity;
    uint8_t _address;

    byte readRegister(uint8_t slaveAddress, uint8_t regToRead);
    bool writeRegister(uint8_t slaveAddress, uint8_t regToWrite, uint8_t dataToWrite);
};

#endif /* HTS221_H_ */
