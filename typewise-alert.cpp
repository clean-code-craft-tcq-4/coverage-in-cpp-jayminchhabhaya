#include "typewise-alert.h"
#include <stdio.h>

void printMessage(std::string printstr){
  std::cout<<printstr<<std::endl;
}
void sendToControllerOREmail(AlertTarget alertTarget,BreachType breachType)
{
switch(alertTarget) {
    case TO_CONTROLLER:
      sendToController(breachType);
      break;
    case TO_EMAIL:
      sendToEmail(breachType);
      break;
  }
}
BreachType checkAndAlert(AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC) {

  BreachType breachType = classifyTemperatureBreach(batteryChar.coolingType, temperatureInC);
  sendToControllerOREmail(alertTarget,breachType); 
  return breachType;
}

