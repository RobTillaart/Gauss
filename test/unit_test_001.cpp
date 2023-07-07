//
//    FILE: unit_test_001.cpp
//  AUTHOR: Rob Tillaart
//    DATE: 2023-07-07
// PURPOSE: unit tests for the Gauss library
//          https://github.com/RobTillaart/Gauss
//          https://github.com/Arduino-CI/arduino_ci/blob/master/REFERENCE.md
//

// supported assertions
// ----------------------------
// assertEqual(expected, actual)
// assertNotEqual(expected, actual)
// assertLess(expected, actual)
// assertMore(expected, actual)
// assertLessOrEqual(expected, actual)
// assertMoreOrEqual(expected, actual)
// assertTrue(actual)
// assertFalse(actual)
// assertNull(actual)


#include <ArduinoUnitTests.h>

#include "Arduino.h"
#include "Gauss.h"


unittest_setup()
{
    fprintf(stderr, "GAUSS_LIB_VERSION: %s\n", (char *) GAUSS_LIB_VERSION);
}


unittest_teardown()
{
}


unittest(test_constructor)
{
  Gauss G;

  G.begin(0, 1);

  assertEqualFloat(0.5, G.P_smaller(0), 0.001);
}


unittest(test_P_smaller)
{
  Gauss G;

  G.begin(0, 1);

  assertEqualFloat(0.0013, G.P_smaller(-3.0), 0.001);
  assertEqualFloat(0.0228, G.P_smaller(-2.0), 0.001);
  assertEqualFloat(0.1587, G.P_smaller(-1.0), 0.001);
  assertEqualFloat(0.5000, G.P_smaller(0.0), 0.001);
  assertEqualFloat(0.8413, G.P_smaller(1.0), 0.001);
  assertEqualFloat(0.9772, G.P_smaller(2.0), 0.001);
  assertEqualFloat(0.9987, G.P_smaller(3.0), 0.001);
}


unittest(test_P_larger)
{
  Gauss G;

  G.begin(0, 1);

  assertEqualFloat(0.9987, G.P_larger(-3.0), 0.001);
  assertEqualFloat(0.9772, G.P_larger(-2.0), 0.001);
  assertEqualFloat(0.8413, G.P_larger(-1.0), 0.001);
  assertEqualFloat(0.5000, G.P_larger(0.0), 0.001);
  assertEqualFloat(0.1587, G.P_larger(1.0), 0.001);
  assertEqualFloat(0.0228, G.P_larger(2.0), 0.001);
  assertEqualFloat(0.0013, G.P_larger(3.0), 0.001);
}


unittest(test_P_between)
{
  Gauss G;

  G.begin(0, 1);

  assertEqualFloat(0.4987, G.P_between(-3.0, 0.0), 0.001);
  assertEqualFloat(0.4772, G.P_between(-2.0, 0.0), 0.001);
  assertEqualFloat(0.3413, G.P_between(-1.0, 0.0), 0.001);
  assertEqualFloat(0.0000, G.P_between(0.0, 0.0), 0.001);
  assertEqualFloat(0.3413, G.P_between(0.0, 1.0), 0.001);
  assertEqualFloat(0.4772, G.P_between(0.0, 2.0), 0.001);
  assertEqualFloat(0.4987, G.P_between(0.0, 3.0), 0.001);
}


unittest(test_P_equal)
{
  Gauss G;

  G.begin(0, 1);

  assertEqualFloat(0.000000, G.P_equal(-3.0), 0.001);
  assertEqualFloat(0.000000, G.P_equal(-2.0), 0.001);
  assertEqualFloat(0.000000, G.P_equal(-1.0), 0.001);
  assertEqualFloat(0.398942, G.P_equal(0.0), 0.001);
  assertEqualFloat(0.000000, G.P_equal(1.0), 0.001);
  assertEqualFloat(0.000000, G.P_equal(2.0), 0.001);
  assertEqualFloat(0.000000, G.P_equal(3.0), 0.001);
}


unittest_main()


//  -- END OF FILE --
