#include "breach.h"
BreachType inferBreach(double value, double lowerLimit, double upperLimit) {
  if(comparevalue(value,lowerLimit)) {
    return TOO_LOW;
  }
  if(!comparevalue(value,upperLimit)) {
    return TOO_HIGH;
  }
  return NORMAL;
}
BreachType classifyTemperatureBreach(CoolingType coolingType, double temperatureInC) {
  int lowerLimit = 0;
  int upperLimit = 0;
   std::unordered_map<CoolingType, int, std::hash<int>> umapcoolingtype = { { PASSIVE_COOLING, 35 }, { HI_ACTIVE_COOLING, 45 }, { MED_ACTIVE_COOLING,40 } } ;
   if (umapcoolingtype.find(coolingType) != umapcoolingtype.end()){
    upperLimit = umapcoolingtype[coolingType];
   }
  return inferBreach(temperatureInC, lowerLimit, upperLimit);
}