#include "DataProcessor.h"

float DataProcessor::sumWindSpeed = 0;
int DataProcessor::countWindSpeed = 0;
float DataProcessor::sumTemperature = 0;
int DataProcessor::countTemperature = 0;

void DataProcessor::calculateWindSpeedCallback(WindTempSolar data) {
    sumWindSpeed += data.getWindSpeed();
    countWindSpeed++;
}

void DataProcessor::calculateTemperatureCallback(WindTempSolar data) {
    sumTemperature += data.getTemperature();
    countTemperature++;
}
