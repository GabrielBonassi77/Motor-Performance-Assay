const int ledPin1 = 9;  // LED pin 1
const int ledPin2 = 12; // LED pin 2
const int loopCount = 400; // Number of times to loop
bool loopActive = false;   // Flag to control the looping

void setup() {
  pinMode(ledPin1, OUTPUT); // Set pin 9 as an output for the LED
  pinMode(ledPin2, OUTPUT); // Set pin 12 as an output for the LED
  digitalWrite(ledPin1, LOW); // Initialize the LED to be OFF
  digitalWrite(ledPin2, HIGH);  // Initialize the LED to be OFF
  Serial.begin(9600); // Initialize serial communication at 9600 baud rate
}

void loop() {
  if (Serial.available() > 0) { // Check if data is available to read
    char receivedChar = Serial.read(); // Read the incoming byte

    // Echo the received character for debugging
    Serial.print("Received: ");
    Serial.println(receivedChar);

    // Start the loop if '1' is received
    if (receivedChar == '1') {
      loopActive = true;
    }
  }

  if (loopActive) {
    for (int i = 0; i < loopCount; i++) {
      digitalWrite(ledPin1, HIGH);  // Turn the LED ON
      digitalWrite(ledPin2, LOW); // Turn the LED ON
      delay(2000);                 // Keep the LED ON for 2 seconds
      digitalWrite(ledPin1, LOW); // Then turn the LED OFF
      digitalWrite(ledPin2, HIGH);  // Then turn the LED OFF
      delay(1000);                 // Wait for 1 second
    }
    loopActive = false; // Stop the loop after 400 iterations
  }
}
