struct DEV_AC : Service::Fan
{
  int powerSwitchPin;
  int powerCheckPin;
  SpanCharacteristic *power;

  DEV_AC(int powerSwitchPin) : Service::Fan()
  {

    power = new Characteristic::Active();
    this->powerSwitchPin = powerSwitchPin;
    pinMode(powerSwitchPin, OUTPUT);
  }

  boolean update()
  {
    if (power->updated())
    {
      digitalWrite(powerSwitchPin, HIGH);
      delay(50);
      digitalWrite(powerSwitchPin, LOW);
    }
    return (true);
  }

  void loop()
  {
    if (digitalRead(powerCheckPin) == HIGH)
    {
      power->setValue(1);
    }
    else
    {
      power->setValue(0);
    }
  }
};
