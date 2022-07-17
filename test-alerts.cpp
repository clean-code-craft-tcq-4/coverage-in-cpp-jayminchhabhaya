#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "typewise-alert.h"

TEST_CASE("infers the breach according to limits") {
  BatteryCharacter batteryChar;
  batteryChar.coolingType = PASSIVE_COOLING;
  REQUIRE(checkAndAlert(TO_CONTROLLER, batteryChar, 30) == NORMAL);
  REQUIRE(checkAndAlert(TO_EMAIL, batteryChar, -1) == TOO_LOW);
  REQUIRE(checkAndAlert(TO_EMAIL, batteryChar, 40) == TOO_HIGH);

  batteryChar.coolingType = HI_ACTIVE_COOLING;
  REQUIRE(checkAndAlert(TO_CONTROLLER, batteryChar, 30) == NORMAL);
  REQUIRE(checkAndAlert(TO_EMAIL, batteryChar, -1) == TOO_LOW);
  REQUIRE(checkAndAlert(TO_EMAIL, batteryChar, 50) == TOO_HIGH);

  batteryChar.coolingType = MED_ACTIVE_COOLING;
  REQUIRE(checkAndAlert(TO_CONTROLLER, batteryChar, 30) == NORMAL);
  REQUIRE(checkAndAlert(TO_EMAIL, batteryChar, -1) == TOO_LOW);
  REQUIRE(checkAndAlert(TO_EMAIL, batteryChar, 45) == TOO_HIGH);

  
}
