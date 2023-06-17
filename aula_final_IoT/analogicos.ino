void analogicos()
{
  //ultrassom

  distancia = ultrasonic.read();
  if(millis()>= T_distancia + 1000)
  {
    T_distancia = millis();
 
  client.publish("ultrassonicAHS",String(distancia).c_str());
  }

  //randomico

  valor= random(0,100);
  if(millis() >= T_valor +1000)
  {
    T_valor = millis();
    client.publish("Rand_AHS",String(valor).c_str());
  }

 //temperatura

  DHT.read(DHT11_PIN);
  if(millis() >= T_dht +1000)
  {
    T_dht = millis();
    client.publish("Temp_AHS",String(DHT.temperature).c_str());
  }
}