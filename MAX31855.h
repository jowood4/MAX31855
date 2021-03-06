#ifndef MAX31855_H
#define MAX31855_H

#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

#define SPI_transfer 1

#if defined(SPI_transfer)
#include "SPI.h"
#endif

class MAX31855
{
public:
	MAX31855(void);
	#if defined(SPI_transfer)
	void setup(uint8_t latch);
	#else
	void setup(uint8_t data, uint8_t clock, uint8_t latch);
	#endif
	uint8_t spi_shift(void);
	void read_temp(void);

        double thermocouple_temp;
        uint8_t fault;
        double chip_temp;
        uint8_t scv_fault;
        uint8_t scg_fault;
        uint8_t oc_fault;
private:
	uint8_t _data;
	uint8_t _clock;
	uint8_t _latch;
};
#endif
