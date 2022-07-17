#pragma once
#include<string>
#include <iostream>
#include <unordered_map>
const std::string EMAILID = "a.b@c.com";

typedef enum {
  PASSIVE_COOLING,
  HI_ACTIVE_COOLING,
  MED_ACTIVE_COOLING
} CoolingType;
 std::unordered_map< CoolingType, int, std::hash<int> > umap = { { PASSIVE_COOLING, 35 }, { HI_ACTIVE_COOLING, 45 }, { MED_ACTIVE_COOLING,40 } } ;
typedef enum {
  NORMAL,
  TOO_LOW,
  TOO_HIGH
} BreachType;

BreachType inferBreach(double value, double lowerLimit, double upperLimit);
BreachType classifyTemperatureBreach(CoolingType coolingType, double temperatureInC);

typedef enum {
  TO_CONTROLLER,
  TO_EMAIL
} AlertTarget;

typedef struct {
  CoolingType coolingType;
  char brand[48];
} BatteryCharacter;

BreachType checkAndAlert(AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC);
void sendToController(BreachType breachType);
void sendToEmail(BreachType breachType);
void printMessage(std::string printstr);
bool comparevalue(double value,double Limit);
