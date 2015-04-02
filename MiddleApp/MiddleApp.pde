import processing.serial.*;

Serial calculatorPort;        // The serial port
Serial radioPort;        // The serial port

void setup(){
  size(800, 500);
  frame.setResizable(true);

  println(Serial.list());
  calculatorPort = new Serial(this, Serial.list()[7], 115200);
  calculatorPort.bufferUntil('\n');
  background(20);
}

void draw(){
}

void serialEvent (Serial myPort) {
  String inString = calculatorPort.readStringUntil('\n');
  
  if (inString != null) {
  }
}


