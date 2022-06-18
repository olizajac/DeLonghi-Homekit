#include "HomeSpan.h"
#include "DEV_AC.h"

void setup()
{

  Serial.begin(115200);

  homeSpan.setStatusPin(5);
  homeSpan.setPairingCode(69696969);
  homeSpan.enableOTA();

  homeSpan.begin(Category::AirConditioners, "Air Conditioner");

  new SpanAccessory();

  new Service::AccessoryInformation();
  new Characteristic::Identify();

  new DEV_AC(6);
}
void loop()
{
  homeSpan.poll();
}
