//
//    FILE: Gauss_test_dump.ino
//  AUTHOR: Rob Tillaart
// PURPOSE: demo


#include "Gauss.h"

Gauss G;

uint32_t start;
uint32_t stop;


void setup(void)
{
  Serial.begin(115200);
  Serial.println(__FILE__);
  Serial.print("GAUSS_LIB_VERSION: ");
  Serial.println(GAUSS_LIB_VERSION);

  //  test_1();
  //  test_2();
  //  test_3();
  //  get_bell_curve();
  test_4();

  Serial.println("\ndone...");
}


void loop(void)
{
}


void test_1()
{
  G.begin(0, 1);

  for (float f = -5.0; f <= 5.0; f += 0.025)
  {
    Serial.println(100 * G.P_smaller(f));
  }
  Serial.println();
}


void test_2()
{
  G.begin(100, 25);

  for (float f = 0; f <= 200; f += 1)
  {
    Serial.println(100 * G.P_smaller(f));
  }
  Serial.println();
}


void test_3()
{
  G.begin(0, 1);

  for (float f = -5.0; f <= 5.0; f += 0.025)
  {
    Serial.println(100 * G.P_larger(f));
  }
  Serial.println();
}


void get_bell_curve()
{
  G.begin(0, 1);

  for (float f = -5.0; f <= 5.0; f += 0.05)
  {
    float a = G.P_smaller(f - 0.025);
    float b = G.P_smaller(f + 0.025);
    Serial.println(1000 * (b - a), 6);
  }
  Serial.println();
}


void test_4()
{
  G.begin(0, 1);

  for (float f = -5.0; f <= 5.0; f += 0.01)
  {
    Serial.println(100.0 * G.calc(f));
    //    float a = G.P_smaller(f - 0.025);
    //    float b = G.P_smaller(f + 0.025);
    //    Serial.println(100 * (b - a), 6);
  }
  Serial.println();
}

// -- END OF FILE --
