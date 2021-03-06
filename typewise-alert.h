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

typedef enum {
  NORMAL,
  TOO_LOW,
  TOO_HIGH
} BreachType;

typedef enum {
  TO_CONTROLLER,
  TO_EMAIL
} AlertTarget;

typedef struct {
  CoolingType coolingType;
  char brand[48];
} BatteryCharacter;

void checkAndAlert(AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC);
void sendToController(BreachType breachType);
void sendToEmail(BreachType breachType);
void printMessage(std::string printstr);
bool comparevalue(double value,double Limit);
std::string preparestrtosendmail(std::string str);
void sendToControllerOREmail(AlertTarget alertTarget,BreachType breachType);

