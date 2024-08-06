#include<ESP8266WiFi.h>
#include<FirebaseArduino.h>

  
#define WiFi_NAME "PEC_RD"
#define WiFi_PASSWORD "pecrd123"
#define FireBase_HOST "digital-horn-system-21069-default-rtdb.firebaseio.com"
#define FireBase_API "AIzaSyBWNjzjOqTxf1jq8O19fkRugjSJEiMXp0A"



void setup() {
  pinMode(D0, OUTPUT);
 
  Serial.begin(9600);
  
  
  WiFi.begin(WiFi_NAME,WiFi_PASSWORD);
  Serial.print("Connecting");
  
  while(WiFi.status()!= WL_CONNECTED)
  {
    Serial.print("Connecting");
    delay(500);
  }

  Serial.println();
  Serial.print("CONNECTED");
  Serial.println(WiFi_NAME);
  
  Firebase.begin(FireBase_HOST, FireBase_API);
  

}

void loop() {
  
  
  int i = Firebase.getString("VALUE").toInt();
  
  if(i==1)
  {
    Serial.print("LIGHRT Is ON");
    Serial.print(Firebase.getInt("VALUE"));
    digitalWrite(D0, HIGH);
    
  }
 else
 {
  Serial.print("LIGHT IS OFF");
  Serial.print(Firebase.getInt("VALUE"));
  digitalWrite(D0, LOW);
 }
}
