//
//    FILE: Gauss_test_bell_curve.ino
//  AUTHOR: Rob Tillaart
// PURPOSE: demo


#include "Gauss.h"

Gauss G;


void setup(void)
{
  Serial.begin(115200);
  Serial.println(__FILE__);
  Serial.print("GAUSS_LIB_VERSION: ");
  Serial.println(GAUSS_LIB_VERSION);
  Serial.println();

  get_bell_curve();
  approximate();

  Serial.println("\ndone...");
}


void loop(void)
{
}


void approximate()
{
  G.begin(0, 1);

  for (float f = -5.0; f <= 5.0; f += 0.01)
  {
    float a = G.P_smaller(f - 0.01);
    float b = G.P_smaller(f + 0.01);
    Serial.println(100.0 * (b - a), 6);
  }
  Serial.println();
}


void get_bell_curve()
{
  G.begin(0, 1);

  for (float f = -5.0; f <= 5.0; f += 0.01)
  {
    Serial.println(100.0 * G.P_equal(f), 6);
  }
  Serial.println();
}


// -- END OF FILE --
