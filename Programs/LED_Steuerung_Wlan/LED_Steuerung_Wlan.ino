#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <SPI.h>

#include "LED.h"



const char* ssid = "WG";
const char* password = "1234Hannover5678";
const char * hostName = "Node_Test";
const int state = WL_IDLE_STATUS;

byte usedLED[] = {D5, D6};
boolean ledONOFF[] = {false, false};

LED _leds(usedLED, ledONOFF, sizeof(usedLED)/sizeof(byte));

const int serverPort = 666;

boolean WiFiON = true;

const int led_Connected = D2;
const int led_Test = D1;

WiFiServer server(serverPort);
WiFiClient client;

void setup() {
  Serial.begin(115200);
  // Set WiFi to station mode and disconnect from an AP if it was previously connected
  WiFi.hostname(hostName);
  
  WiFi.begin(ssid, password);

  Serial.print("Connection");
  
  WiFi.mode(WIFI_STA);
  
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println();

  Serial.print("Connected, IP address: ");
  Serial.println(WiFi.localIP());
  
  delay(2000);
  Serial.println("WiFi Setup done");

  // setup Server 
  server.begin();
 // server.setNoDelay(true);
  Serial.println("Server started");

 
  pinMode(led_Test, OUTPUT);
  pinMode(led_Connected, OUTPUT);
//  pinMode(led_Interrupt, OUTPUT);


  
  digitalWrite(led_Test, LOW);
//  digitalWrite(led_Interrupt, LOW);

//  Interrupt is work in procness
/*
  if (client.connected())
  {
    attachInterrupt(client.read(), getMassage(), RISING);
  }
*/

}

void loop(){
  // Listen for incoming client requests.
  
    if(WiFi.status() == WL_CONNECTED) {
      digitalWrite(led_Test, HIGH);
    } else {
      digitalWrite(led_Test, LOW);
    }

  if(WiFiON && !client.connected())
  {
    client = server.available();

    if(WiFi.status() == WL_CONNECTED) {
      digitalWrite(led_Test, HIGH);
    } else {
      digitalWrite(led_Test, LOW);
    }
      _leds.doIt();
  }
  else 
  {
    if (client.connected())
    {
      Serial.println("Client connected");
      
      digitalWrite(led_Connected, HIGH);
      readRequest(&client);
  
    }
    if (!client.connected()){
      Serial.println("Client disonnected");
      digitalWrite(led_Connected, LOW);
    }
    _leds.doIt();
  }

  // Close the connection.
  //client.stop();

  //Serial.println("Client disonnected");
  delay(20);
  
}

// Test Funktion for the Interrupt
void getMessage() {
  //digitalWrite(led_Interrupt, !digitalRead(led_Interrupt));
}

// Read the request line,
void readRequest(WiFiClient* client){
  String request = "";


  // Loop while the client is connected.
  //while (client->connected())
  //{
    // Read available bytes.
    while (client->available())
    {
      // Read a byte.
      char c = client->read();

      // Print the value (for debugging).
      Serial.write(c);

      // Exit loop if end of line.
      if ('\n' == c)
      {
        break;
      }

      // Add byte to request line.
      request += c;
    }
  //}
  // return request;
  // went forward to the execution
   executeRequest(client, &request);
}

void executeRequest(WiFiClient* client, String* request){
  char command = readCommand(request);
  int n = readParam(request);

  switch(command)
  {
    case 'O':
      pinMode(n, OUTPUT);
      sendResponse(client, "O" + String(n) + " received");    
      break;
      
    case 'I':
      pinMode(n, INPUT);
      sendResponse(client, "I" + String(n) + " received");
      break;
    case 'L':
      _leds.setLEDOff(n);      
      sendResponse(client, "Command: L" + String(n) + "received" );
      break;
    case 'H':
      _leds.setLEDOn(n);      
      sendResponse(client, "Command: H" + String(n) + "received" );
      break;
    case 'M':
      _leds.setMode(n);
      sendResponse(client, "Command: M" + String(n) + "received" );
      break;
    case 'T':
      _leds.setTimer1(n);
      sendResponse(client, "Command: T" + String(n) + "received" );
      break;
      
    default:
      break;
  }
}

// Read the command from the request string.
char readCommand(String* request){
  String commandString = request->substring(0, 1);
  return commandString.charAt(0);
}

// Read the parameter from the request string.
int readParam(String* request){
  // This handles a hex digit 0 to F (0 to 15).
  char buffer[2];
  buffer[0] = request->charAt(1);
  buffer[1] = 0;
  return (int) strtol(buffer, NULL, 16);
}

void sendResponse(WiFiClient* client, String response){
  // Send response to client.
  client->println(response);

  // Debug print.
  Serial.println("sendResponse:");
  Serial.println(response);
}

void printServerStatus(){
  Serial.print("Server address:");
  Serial.println(WiFi.localIP());
}

