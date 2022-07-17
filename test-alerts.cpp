#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "typewise-alert.h"

BatteryCharacter batteryChar;
batteryChar.coolingType = PASSIVE_COOLING;
TEST_CASE("infers the breach according to limits") {
  REQUIRE(checkAndAlert(TO_CONTROLLER, 20, 30) == TOO_LOW);
}
