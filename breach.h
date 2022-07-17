#include "typewise-alert.h"

typedef enum {
  NORMAL,
  TOO_LOW,
  TOO_HIGH
} BreachType;

BreachType inferBreach(double value, double lowerLimit, double upperLimit);
BreachType classifyTemperatureBreach(CoolingType coolingType, double temperatureInC);
void sendToController(BreachType breachType);
void sendToEmail(BreachType breachType);
bool comparevalue(double value,double Limit);