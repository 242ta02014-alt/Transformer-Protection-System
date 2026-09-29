// Transformer Protection System
// Arduino C++ Code

int temperaturePin = A0;
int currentPin = A1;
int voltagePin = A2;

int relayPin = 8;
int buzzerPin = 9;

float temperature;
float current;
float voltage;

void setup() {
  Serial.begin(9600);

  pinMode(relayPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  // Transformer initially ON
  digitalWrite(relayPin, HIGH);
  digitalWrite(buzzerPin, LOW);

  Serial.println("Transformer Protection System");
}

void loop() {

  // Read sensors
  int tempValue = analogRead(temperaturePin);
  int currentValue = analogRead(currentPin);
  int voltageValue = analogRead(voltagePin);

  // Simple conversion for demonstration
  temperature = (tempValue * 5.0 / 1023.0) * 100;
  current = (currentValue * 5.0 / 1023.0) * 10;
  voltage = (voltageValue * 5.0 / 1023.0) * 100;

  Serial.println("----------------------");
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" C");

  Serial.print("Current: ");
  Serial.print(current);
  Serial.println(" A");

  Serial.print("Voltage: ");
  Serial.print(voltage);
  Serial.println(" V");

  // Protection conditions
  if (temperature > 70 || current > 5 || voltage > 250 || voltage < 180) {

    // Transformer OFF
    digitalWrite(relayPin, LOW);
    digitalWrite(buzzerPin, HIGH);

    Serial.println("WARNING!");
    Serial.println("Transformer Protection Activated");
    Serial.println("Transformer OFF");
  }

  else {

    // Transformer ON
    digitalWrite(relayPin, HIGH);
    digitalWrite(buzzerPin, LOW);

    Serial.println("Transformer Status: NORMAL");
  }

  delay(1000);
}
