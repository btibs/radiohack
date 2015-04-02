import processing.serial.*;

Serial calculatorPort;        // The serial port
Serial radioPort;        // The serial port

void setup(){
  size(800, 500);
  frame.setResizable(true);

  println(Serial.list());
  calculatorPort = new Serial(this, Serial.list()[9], 115200);
  calculatorPort.bufferUntil('\n');
  
  radioPort = new Serial(this, Serial.list()[8], 9600);
  radioPort.bufferUntil('\n');
  background(20);
}

void draw(){
}

void serialEvent (Serial myPort) {
  String inString = myPort.readStringUntil('\n');
  
  if (inString != null) {
    println(inString);
    String[] words = split(inString, ',');
    println(words.length);
    if (words.length == 1){
      radioPort.write(inString.charAt(0));
    }
  }
}


