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
void sendToController(BreachType breachType) {
  const unsigned short header = 0xfeed;
  printMessage(std::to_string(header) + " : " +  std::to_string(breachType));
}
std::string preparestrtosendmail(std::string str)
{
  return "To:" + EMAILID + "\n Hi, the temperature is too "+ str +"\n";
}
void sendToEmail(BreachType breachType) {
     std::unordered_map<BreachType, std::string> umapbreachtype = { { NORMAL, "Normal" }, { TOO_LOW, "low" }, { TOO_HIGH,"high" } } ;
     printMessage(preparestrtosendmail(umapbreachtype[breachType]));
}