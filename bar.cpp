#include "catch.hpp"
double SUMM ( double A, double B )
  {
  return A+B;
  };
TEST_CASE ("TEST Func", "[SUMM]")
  {
  REQUIRE (SUMM (1,2) == 3);
  REQUIRE (SUMM (1.5, 1.5) == 3);
  }
