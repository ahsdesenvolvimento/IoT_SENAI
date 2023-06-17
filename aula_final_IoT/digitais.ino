void digitais()
{
 if((digitalRead(13)==LOW)&&(FLAG1==LOW))
 {
   FLAG1=1;
   client.publish("Sensor_AHS",String("Ativado").c_str());
 }
 if((digitalRead(13)==HIGH)&&(FLAG1==HIGH))
 {
   FLAG1=0;
   client.publish("Sensor_AHS",String("Desativado").c_str());
 }
}
void Comando()
{
  //controle rele 19
  if (my_payload =="A")
  digitalWrite(19,HIGH);
  if (my_payload =="a")
  digitalWrite(19,LOW);

  //controle rele 18
  if (my_payload =="B")
  digitalWrite(18,HIGH);
  if (my_payload =="b")
  digitalWrite(18,LOW);

  //controle rele 17
  if (my_payload =="C")
  digitalWrite(17,HIGH);
  if (my_payload =="c")
  digitalWrite(17,LOW);

  //controle rele 16
  if (my_payload =="D")
  digitalWrite(16,HIGH);
  if (my_payload =="d")
  digitalWrite(16,LOW);
}
