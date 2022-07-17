#include "typewise-alert.h"
#include <stdio.h>

void printMessage(std::string printstr)
{
  std::cout<<printstr<<std::endl;
}
bool comparevalue(double value,double Limit)
{
  return (value < Limit) ? true:false;
}
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

BreachType checkAndAlert(
    AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC) {

  BreachType breachType = classifyTemperatureBreach(
    batteryChar.coolingType, temperatureInC
  );

  switch(alertTarget) {
    case TO_CONTROLLER:
      sendToController(breachType);
      break;
    case TO_EMAIL:
      sendToEmail(breachType);
      break;
  }
  return breachType;
}
void sendToController(BreachType breachType) {
  const unsigned short header = 0xfeed;
  printMessage(std::to_string(header) + " : " +  std::to_string(breachType));
}
void sendToEmail(BreachType breachType) {
  switch(breachType) {
    case TOO_LOW:
      printMessage("To:" + EMAILID + "\n Hi, the temperature is too low\n");
      break;
    case TOO_HIGH:
      printMessage("To:" + EMAILID + "\n Hi, the temperature is too high\n");
      break;
    case NORMAL:
      break;
  }
}
