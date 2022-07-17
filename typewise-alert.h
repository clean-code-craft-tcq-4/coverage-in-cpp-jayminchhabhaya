#pragma once
#include<string>
#include <iostream>
#include <unordered_map>
#include "breach.h"
const std::string EMAILID = "a.b@c.com";

typedef enum {
  PASSIVE_COOLING,
  HI_ACTIVE_COOLING,
  MED_ACTIVE_COOLING
} CoolingType;

typedef enum {
  TO_CONTROLLER,
  TO_EMAIL
} AlertTarget;

typedef struct {
  CoolingType coolingType;
  char brand[48];
} BatteryCharacter;

BreachType checkAndAlert(AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC);
void printMessage(std::string printstr);
std::string preparestrtosendmail(std::string str);
void sendToControllerOREmail(AlertTarget alertTarget,BreachType breachType);

