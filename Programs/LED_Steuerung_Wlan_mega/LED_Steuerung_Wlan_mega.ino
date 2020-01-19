#include "LED.h"
#include "ESP8266.h"

const char *SSID     = "WG";
const char *PASSWORD = "1234Hannover5678";

byte usedLED[] = {22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40};

const int serverPort = 666;


SoftwareSerial mySerial(11, 10); //SoftwareSerial pins for MEGA/Uno. For other boards see: https://www.arduino.cc/en/Reference/SoftwareSerial

ESP8266 wifi(mySerial); 

LED _leds;

void setup(void) {
  Serial.begin(9600);
  // Set WiFi to station mode and disconnect from an AP if it was previously connected
  //WiFi.hostname(hostName);
  
  //Serial.print("Connection");
  _leds.setLEDArray(usedLED, sizeof(usedLED)/sizeof(byte));
  delay(50);
  
  Serial.println("Begin");

  if (!wifi.init(SSID, PASSWORD))
  {
    Serial.println("Wifi Init failed. Check configuration.");
    while (true) ; // loop eternally
  }

  //_leds.setLEDArray(usedLED, sizeof(usedLED)/sizeof(byte));

  // default setting if WiFi is not working
  // Random mode
  //_leds.setMode(1);
  
  
  // Blink mode
  //_leds.setMode(2);
  
  // Set the time
  //_leds.setTimer1(100);

}

void loop(void){
  // Listen for incoming client requests.
    Serial.println("Sending Request to www.google.com");
    wifi.httpGet();

    delay(4000);/*
  if(WiFiON)
  {
     WiFiON =false;
    //client = server.available();
    Serial.println("Server start" + wifi.startTCPServer());
/*
    if(WiFi.status() == WL_CONNECTED) {
      digitalWrite(led_Test, HIGH);
    } else {
      digitalWrite(led_Test, LOW);
    }

      _leds.doIt();
  }
  else 
  {
    /*
    if (client.connected())
    {
      Serial.println("Client connected");
      
      //digitalWrite(led_Connected, HIGH);
      readRequest(&client);
  
    }
    if (!client.connected()){
      Serial.println("Client disonnected");
      //digitalWrite(led_Connected, LOW);
    }
    
    _leds.doIt();
  }

  // Close the connection.
  //client.stop();
*/
  
}

/*
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
*/
