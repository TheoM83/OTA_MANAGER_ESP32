#include <WiFi.h>
#include <Update.h>
#include <string.h>
#include <iostream>
 
const char* ssid = "";
const char* password =  "";

const uint16_t port = 8090;
const char * host = "192.168.1.27";

//DEVICE INFORMATIONS
const char* ID = "UID123";
const char* Name = "device-TEST";
const char* Version = "1";

void setup()
{
  //Connect to the Wifi
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(500);
    Serial.println("///Connecting to the Wifi///");
  }
  Serial.print("  --> Connected as : ");
  Serial.println(WiFi.localIP());

  //Connect to the Server
  WiFiClient client;
    
    if (!client.connect(host, port)) 
    {
      Serial.println("Connection to host failed");
      delay(1000);
    }
    else
    {
        Serial.println("Connected to server successful!");
        Serial.println("Sending information");
        client.write(ID);
        delay(200);
        client.write(Name);
        delay(200);
        client.write(Version);
        delay(200);
        Serial.println("Checking Firmware");
        
        String stringFileSize = client.readStringUntil('\n');
        Serial.println(stringFileSize);
        int fileSize = atoi(stringFileSize.c_str());
        bool start = Update.begin(fileSize);

        if (start) {
        Serial.println("Downloading and applying OTA update...");
        size_t written = Update.writeStream(client);
  
        if (written == fileSize) {
          Serial.println("Written : " + String(written) + " successfully");
        } else {
          Serial.println("Written only : " + String(written) + "/" + String(fileSize) + ". Retry?" );
        }
        if (Update.end()) {
          Serial.println("Update finished!");
          if (Update.isFinished()) {
            Serial.println("Rebooting.");
            ESP.restart();
          } else {
            Serial.println("Error...");
          }
        } else {
          Serial.println("Error Occurred...");
        }
      } else {
        Serial.println("Not enough memory");
        client.flush();
      }
    }
}
 
void loop()
{

}
