# Smart_street_lighting_system
void setup()
{
  pinMode(A0,INPUT);//ldr0 to detect brightness
  pinMode(A1,INPUT);//ldr1 to detect faulty street 
  pinMode(3,INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}
void loop()
{
  
  int lightRead = analogRead(A0);
  Serial.println(lightRead);
  delay(100);
  if(lightRead > 900){
    Serial.println("It is dark outside");
    if (digitalRead(3) == 1)
    {
      Serial.println("Motion detected");
      int value=digitalRead(3);
      Serial.println(value);
      delay(100);
      digitalWrite(13,HIGH);
      Serial.println("LED on");
      delay(100);
      int lightRead1 = analogRead(A1); //reading the light luminosity after LED is in ON state
      Serial.println("Second ldr value:");
      Serial.println(lightRead1);
      delay(100);
      if(lightRead1 > 1020){
        Serial.println("The street light is faulty");
        //Geographical location is sent
        Serial.println("Geographical location is sent");
      }
      else {
        Serial.println("The street light is working fine");
      }
      delay(3000);
    }
    else 
    {
      Serial.println("Motion undetected");
      int value=digitalRead(3);
      delay(100);
      Serial.println(value);
      digitalWrite(13,LOW);
      Serial.println("LED off");
      delay(3000);
    }
    /*digitalWrite(13,HIGH);
    Serial.println("Fine");
    delay(1000);*/
  }
  else{
    digitalWrite(13,LOW);
    Serial.println("It is bright outside");
    delay(3000);
  }
    
}
