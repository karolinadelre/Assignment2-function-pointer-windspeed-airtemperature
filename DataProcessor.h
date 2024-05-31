#ifndef DATAPROCESSOR_H
#define DATAPROCESSOR_H

#include "WindTempSolar.h"

class DataProcessor {
private:
    static float sumWindSpeed;
    static int countWindSpeed;
    static float sumTemperature;
    static int countTemperature;

public:
    static void calculateWindSpeedCallback(WindTempSolar data);
    static void calculateTemperatureCallback(WindTempSolar data);
};

#endif // DATAPROCESSOR_H
