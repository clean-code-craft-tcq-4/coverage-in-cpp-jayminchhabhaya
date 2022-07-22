#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "typewise-alert.h"
#include "breach.h"

TEST_CASE("infers the breach according to limits") {
  
  REQUIRE(inferBreach(20, 25, 30) == TOO_LOW);
  REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING,30) == NORMAL);
}
