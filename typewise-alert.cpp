#include "typewise-alert.h"
#include <stdio.h>
#include "breach.h"
void printMessage(std::string printstr)
{
  std::cout<<printstr<<std::endl;
}
bool comparevalue(double value,double Limit)
{
  return (value < Limit) ? true:false;
}
BreachType checkAndAlert(AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC) {

  BreachType breachType = classifyTemperatureBreach(batteryChar.coolingType, temperatureInC);

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
std::string preparestrtosendmail(std::string str)
{
  return "To:" + EMAILID + "\n Hi, the temperature is too "+ str +"\n";
}
void sendToEmail(BreachType breachType) {
     std::unordered_map<BreachType, std::string> umapbreachtype = { { NORMAL, "Normal" }, { TOO_LOW, "low" }, { TOO_HIGH,"high" } } ;
     printMessage(preparestrtosendmail(umapbreachtype[breachType]));
}
