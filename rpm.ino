int timeold=millis();
int rotating_time;
int rpmcount=1;
void setup()
{
  Serial.begin(9600);
  attachInterrupt(0, rpm_counter, RISING); // Interrupt triggers on rising edge; 
                    //when the sensor turns off(the magnet leaves).
  
  
}
 
void loop()
{
  int rpm;
  if (rpmcount == 1) 
    timeold=millis();
  else if (rpmcount > 20) 
  { 
    rotating_time = millis() - timeold;
    //checks RPM every 20 counts (Khalil please change it if it is too fast or too slow)
    //decrease for faster update
    rpm = 60000/rotating_time*(rpmcount-1);//1 min = 60000ms
    rpmcount = 0;
    Serial.println(rpm, DEC);
  }
}
 
void rpm_counter(int rpmcount)
{
  rpmcount++;
}
