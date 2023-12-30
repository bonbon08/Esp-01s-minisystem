void setup()
{
  Serial.begin(9600);
}

void loop() {
  print("test");
}

void print(const char* text){
  Serial.println(text);
}

const char* input(const char* prompt) {
  print(prompt);
  static char inputText[50]; // Assuming a maximum length of 50 characters, adjust as needed
  while (true) {
    if (Serial.available() > 0) {
      char receivedChar = Serial.read();
      if (receivedChar == '\n') {
        // End of input, break out of the loop
        break;
      } else {
        // Add the character to the inputText
        strcat(inputText, &receivedChar);
      }
    }
  }
  return inputText;
}
