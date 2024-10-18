#include "matrix5x5.hpp"
#include "matrix8x8.hpp"
#include "matrix8x8M.hpp"
#include "matrix13x9.hpp"
#include "matrix16x9.h"
#include "services.hpp"

volatile bool display = true;
Matrix16x9TaskHandler matrix16x9TaskHandler;

void setup()
{
  delay(5000);
  Wire.begin();
  Wire.setClock(400000UL);

  Serial.begin(115200);
  log_d("Starting setup...");

  wifiSetup();
  mDnsSetup();
  otaSetup();
  restSetup();

  Matrix5x5Setup();
  Matrix8x8Setup();
  Matrix8x8MSetup();
  Matrix13x9Setup();
  //Matrix16x9Setup();

  matrix16x9TaskHandler.createTask();

  log_d("Setup complete");
}

void loop()
{
  ArduinoOTA.handle();
  restServer.handleClient();
  checkWifiStatus();
  delay(10);
}
