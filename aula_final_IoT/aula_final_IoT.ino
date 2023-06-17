#include <WiFi.h>
#include <PubSubClient.h>
#include <Ultrasonic.h>

//leitor de temperatura
#include <DFRobot_DHT11.h>
DFRobot_DHT11 DHT;
#define DHT11_PIN 23

Ultrasonic ultrasonic(32, 35);
const char* ssid = "Sala_C37";
const char* password = "Treinamento_IoT";
const char* mqtt_server = "xxx.xxx.x.xxx";

//variaveis para o ESP receber do NOD RED:
String my_payload;
String my_topic;

//variaveis para o NOD RED receber do ESP32 analogicos:
int valor;
int T_valor;
int distancia;
int T_distancia;
int Potenc;
int T_Potenc;
int T_dht;
//variaveis para o NOD RED receber do ESP32 digitais:
bool FLAG1;

WiFiClient Cliente_AHS;
PubSubClient client(Cliente_AHS);

void setup_wifi() {

  delay(10);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.print(WiFi.localIP());
}


void callback(char* topic, byte* payload, unsigned int length)
 {
   String conc_payload;
  for (int i = 0; i < length; i++)
   {
    conc_payload += ((char)payload[i]);
  }
    my_payload = conc_payload;
    my_topic = topic;
}
void reconnect()
 {
 
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
   
    if (client.connect("Cliente_AHS"))
    {
        Serial.println("connected");
        client.subscribe("LUZ_AHS");
    } else {
      Serial.print("failed");
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}

void setup() {
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
  pinMode(2,OUTPUT);  
  pinMode(19,OUTPUT);
  pinMode(18,OUTPUT);
  pinMode(17,OUTPUT);
  pinMode(16,OUTPUT);
}

void LED_Conexao()
{
  if (WiFi.status() == WL_CONNECTED)
  digitalWrite(2,HIGH);
  else
  digitalWrite(2,LOW);
}
void loop()
  {
    reconnect();
    client.loop();
    LED_Conexao();
    analogicos();
    digitais();
    Comando();
  }
  