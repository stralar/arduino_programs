#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <SPI.h>
//#include <WiFi.h>


char ssid[] = "WG";
char password[] = "1234Hannover5678";
int state = WL_IDLE_STATUS;


int serverPort = 666;

WiFiServer server(serverPort);

void setup() {
  Serial.begin(115200);
  // Set WiFi to station mode and disconnect from an AP if it was previously connected
  WiFi.hostname("Node_Test");
  
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
  
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);

  digitalWrite(5, HIGH);

  //delay(400);

  //digitalWrite(16, LOW);
  
}

void loop()
{
  // Listen for incoming client requests.
  WiFiClient client = server.available();
  if (!client)
  {
    return;
  }

  Serial.println("Client connected");
  while(client.connected())
  {
    digitalWrite(4, HIGH);
    String request = readRequest(&client);
    executeRequest(&client, &request);
  }
  digitalWrite(4, LOW);

  // Close the connection.
  //client.stop();

  Serial.println("Client disonnected");
}

// Read the request line,
String readRequest(WiFiClient* client)
{
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
        return request;
      }

      // Add byte to request line.
      request += c;
    }
  //}
  return request;
}

void executeRequest(WiFiClient* client, String* request)
{
  char command = readCommand(request);
  int n = readParam(request);
  if ('O' == command)
  {
    pinMode(n, OUTPUT);
    sendResponse(client, "O" + String(n) + " received");
  }
  else if ('I' == command)
  {
    pinMode(n, INPUT);
    sendResponse(client, "I" + String(n) + " received");

  }
  else if ('L' == command)
  {
    digitalWrite(n, LOW);
    sendResponse(client, "L" + String(n) + " received");

  }
  else if ('H' == command)
  {
    digitalWrite(n, HIGH);
    sendResponse(client, "H" + String(n) + " received");

  }
  else if ('R' == command)
  {
    sendResponse(client, String(digitalRead(n)));
  }
  else if ('A' == command)
  {
    sendResponse(client, String(analogRead(n)));
  }
}

// Read the command from the request string.
char readCommand(String* request)
{
  String commandString = request->substring(0, 1);
  return commandString.charAt(0);
}

// Read the parameter from the request string.
int readParam(String* request)
{
  // This handles a hex digit 0 to F (0 to 15).
  char buffer[2];
  buffer[0] = request->charAt(1);
  buffer[1] = 0;
  return (int) strtol(buffer, NULL, 16);
}

void sendResponse(WiFiClient* client, String response)
{
  // Send response to client.
  client->println(response);

  // Debug print.
  Serial.println("sendResponse:");
  Serial.println(response);
}

void printServerStatus()
{
  Serial.print("Server address:");
  Serial.println(WiFi.localIP());
}
