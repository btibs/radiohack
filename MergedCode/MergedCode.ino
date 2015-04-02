/*
 http://arduino.cc/en/Tutorial/Tone
 note that the tone function does not allow volume control
 solution being to write our own with analog out
*/
//#include "pitches.h"
/*************************************************
 * Public Constants
 *************************************************/

#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978


#define E_07 3
#define X_148 4
#define D_259 5
#define MSP_36 6
#define PERIOD_X 7
#define POWER_X 8

#define SIG_NUM 5
#define SIG_LENGTH 30
#define HISTORY_LENGTH 2


/******************************************************
* radio variables
*******************************************************/
int nSongs = 7;

// notes
const int melodies[][78] PROGMEM = {
  // default
  { //NOTE_C4, NOTE_G3,NOTE_G3, NOTE_A3, NOTE_G3,0, NOTE_B3, NOTE_C4
  NOTE_C4, NOTE_C4,NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4
  },
  // Happy Birthday
  { NOTE_C4,NOTE_C4,NOTE_D4,NOTE_C4,NOTE_F4,NOTE_E4, NOTE_C4,NOTE_C4,NOTE_D4,NOTE_C4,NOTE_G4,NOTE_F4, NOTE_C4,NOTE_C4,NOTE_C5,NOTE_A4,NOTE_F4,NOTE_E4,NOTE_D4, NOTE_AS4,NOTE_AS4,NOTE_A4,NOTE_F4,NOTE_G4,NOTE_F4   
  },
  // Gangnam Style
  { NOTE_A4,NOTE_A4,NOTE_C5,0,NOTE_A4,0,NOTE_E5,NOTE_E5,NOTE_E5,0,NOTE_D5,0, NOTE_D5,NOTE_D5,NOTE_E5,0,0,NOTE_E5,NOTE_E5,NOTE_E5,NOTE_E5,0,0, NOTE_E5,NOTE_E5,NOTE_E5,NOTE_E5,NOTE_E5,NOTE_E5,NOTE_E5,NOTE_E5,NOTE_E5,NOTE_E5,NOTE_E5,NOTE_E5,NOTE_E5,NOTE_E5,NOTE_E5,NOTE_E5,NOTE_E5, NOTE_E5,NOTE_E5,NOTE_E5,NOTE_E5,NOTE_E5,NOTE_E5,NOTE_E5,NOTE_E5,NOTE_E5,NOTE_E5,NOTE_E5,NOTE_E5,NOTE_E5,NOTE_E5,NOTE_E5,0,0, NOTE_A4,NOTE_A4,NOTE_C5,NOTE_C5,NOTE_A4,0,0
  },
  // Star Wars Imperial March
  {  NOTE_A4, 0,  NOTE_A4, 0,  NOTE_A4, 0,  NOTE_F4, 0, NOTE_C5, 0,  NOTE_A4, 0,  NOTE_F4, 0, NOTE_C5, 0, NOTE_A4, 0,  NOTE_E5, 0,  NOTE_E5, 0,  NOTE_E5, 0,  NOTE_F5, 0, NOTE_C5, 0,  NOTE_G5, 0,  NOTE_F5, 0,  NOTE_C5, 0, NOTE_A4, 0},
  // Star Wars theme
  {  NOTE_F4,  NOTE_F4, NOTE_F4,  NOTE_AS4,   NOTE_F5,  NOTE_DS5,  NOTE_D5,  NOTE_C5, NOTE_AS5, NOTE_F5, NOTE_DS5,  NOTE_D5,  NOTE_C5, NOTE_AS5, NOTE_F5, NOTE_DS5, NOTE_D5, NOTE_DS5,   NOTE_C5},
  // Mario
  { NOTE_E7, NOTE_E7, 0, NOTE_E7, 0, NOTE_C7, NOTE_E7, 0, NOTE_G7, 0, 0,  0, NOTE_G6, 0, 0, 0, NOTE_C7, 0, 0, NOTE_G6, 0, 0, NOTE_E6, 0, 0, NOTE_A6, 0, NOTE_B6, 0, NOTE_AS6, NOTE_A6, 0, NOTE_G6, NOTE_E7, NOTE_G7, NOTE_A7, 0, NOTE_F7, NOTE_G7, 0, NOTE_E7, 0, NOTE_C7, NOTE_D7, NOTE_B6, 0, 0, NOTE_C7, 0, 0, NOTE_G6, 0, 0, NOTE_E6, 0, 0, NOTE_A6, 0, NOTE_B6, 0, NOTE_AS6, NOTE_A6, 0, NOTE_G6, NOTE_E7, NOTE_G7, NOTE_A7, 0, NOTE_F7, NOTE_G7, 0, NOTE_E7, 0, NOTE_C7, NOTE_D7, NOTE_B6, 0, 0
  },
  // Mario Underworld Melody
  { NOTE_C4, NOTE_C5, NOTE_A3, NOTE_A4, NOTE_AS3, NOTE_AS4, 0, 0, NOTE_C4, NOTE_C5, NOTE_A3, NOTE_A4, NOTE_AS3, NOTE_AS4, 0, 0, NOTE_F3, NOTE_F4, NOTE_D3, NOTE_D4, NOTE_DS3, NOTE_DS4, 0, 0, NOTE_F3, NOTE_F4, NOTE_D3, NOTE_D4, NOTE_DS3, NOTE_DS4, 0, 0, NOTE_DS4, NOTE_CS4, NOTE_D4, NOTE_CS4, NOTE_DS4, NOTE_DS4, NOTE_GS3, NOTE_G3, NOTE_CS4, NOTE_C4, NOTE_FS4, NOTE_F4, NOTE_E3, NOTE_AS4, NOTE_A4, NOTE_GS4, NOTE_DS4, NOTE_B3, NOTE_AS3, NOTE_A3, NOTE_GS3, 0, 0, 0
  },
};

// durations
const int noteDurations[][78]PROGMEM = {
  {4,4,4,4,4,4,4,4 },
  {
    6,12,4,4,4,2,
    6,12,4,4,4,2,
    6,12,4,4,4,4,2,
    6,12,4,4,4,2,     
  },
  {
    8,8,4,8,8,4,8,8,4,8,8,4, // 12
    8,8,4,8,4,8,8,8,4,8,4, // 11
    8,8,8,8,8,8,8,8,8,8,8,4,4,4,4,16,16, // 17
    16,16,16,16,16,16,16,16,16,16,16,16,16,16,1,1,4, // 17
    8,8,8,8,4,1,4 // 7
  },
  {  50, 20, 50, 20, 50, 20, 40, 5, 20, 5,  60, 10, 40, 5, 20, 5, 60, 80, 50, 20, 50, 20, 50, 20, 40, 5, 20, 5,  60, 10, 40, 5,  20, 5, 60, 40},
  {  21,  21, 21,  128,  128,   21,  21,  21, 128, 64,  21,  21,  21, 128, 64,  21, 21,  21, 128 },
  {
    12, 12, 12, 12,
    12, 12, 12, 12,
    12, 12, 12, 12,
    12, 12, 12, 12,
  
    12, 12, 12, 12,
    12, 12, 12, 12,
    12, 12, 12, 12,
    12, 12, 12, 12,
  
    9, 9, 9,
    12, 12, 12, 12,
    12, 12, 12, 12,
    12, 12, 12, 12,
  
    12, 12, 12, 12,
    12, 12, 12, 12,
    12, 12, 12, 12,
    12, 12, 12, 12,
  
    9, 9, 9,
    12, 12, 12, 12,
    12, 12, 12, 12,
    12, 12, 12, 12,
  },
  {
    12, 12, 12, 12,
    12, 12, 6,
    3,
    12, 12, 12, 12,
    12, 12, 6,
    3,
    12, 12, 12, 12,
    12, 12, 6,
    3,
    12, 12, 12, 12,
    12, 12, 6,
    6, 18, 18, 18,
    6, 6,
    6, 6,
    6, 6,
    18, 18, 18, 18, 18, 18,
    10, 10, 10,
    10, 10, 10,
    3, 3, 3
  },
};

// total notes
int total[] = {
  8,
  25,
  64,
  36,
  19,
  78,
  56,
};

int speakerPin = 9; // for digital or analog out
int ledPins[] = {4,5,6,7};
int nLeds = sizeof(ledPins) / sizeof(int);

// inputs from radio potentiometers
int freqPin = A0;
int freqMax = 296;
int freqMin = 110;

int volPin = A1;
int volMax = 310;
int volMin = 101;


/******************************************************
* calculator variables
*******************************************************/

int signals[SIG_NUM][SIG_LENGTH];
int highCount[SIG_NUM];
int pointer = 0;
char prepKey[] = {'n', 'n', 'n'};
char currentKey = 'n';
int currentInt = -1;
int preInt = -1;
int postInt = -1;
char calOperator = 'n';

void setup() {
  Serial.begin(9600);
  Serial.println("Serial Start");
  
  //radio code start
  pinMode(freqPin, INPUT);
  pinMode(volPin, INPUT);
  pinMode(speakerPin, OUTPUT);
  pinMode(13, OUTPUT); // on board LED indicator
  //radio code end
  
  // calculator code start
  resetSignals();
  // calculator code end
}

long prevCalcLoopTime = -1;
long prevRadioLoopTime = -1;
int song = 5;
int thisNote = 0;
boolean radioStop = false;
void loop() {
  // radio code start
  int freqVal = analogRead(freqPin);
  int volVal = analogRead(volPin);
  //Serial.print(freqVal);
  //Serial.print(" ");
  // 1 second / note type
  //int timeChange = map(volVal, volMin, volMax, -5, 5); // higher = faster
  //int timeChange = 0;
  int timeChange = map(freqVal, freqMin, freqMax, -5, 5);
  
  int noteDuration = 1000/(pgm_read_word(&(noteDurations[song][thisNote])) + timeChange);
  //Serial.println(noteDuration);
  
  int freqChange = map(freqVal, freqMin, freqMax, -50, 50);
  //int freqChange = 0;
  //Serial.println(freqChange);
  buzz(speakerPin, pgm_read_word(&(melodies[song][thisNote])) + freqChange, noteDuration);
  
  
  // to distinguish the notes, set a minimum time between them.
  // the note's duration + 30% seems to work well:
  int pauseBetweenNotes = noteDuration * 1.30;
  delay(pauseBetweenNotes);

  // stop the tone playing
  buzz(speakerPin, 0, noteDuration);
  
  
  thisNote++;
  if(thisNote >= total[song]-1) {
    thisNote = 0;
  }  
  // radio code end
  if(Serial.available() > 0){
    song = (int)(Serial.read()-'0');
    Serial.print(song);
    Serial.println(",,");
  }
}

void resetSignals(){
  for(int i=0; i<SIG_NUM; i++){
    for(int j=0; j<SIG_LENGTH; j++){
      signals[i][j] = -1;
    }
  }
}


void showButtonEvent(int index){
  highCount[index] = 0;
  for(int j=0; j<SIG_LENGTH; j++){
    if(signals[index][j] > 256) highCount[index]++;      
  }
  
  float ratio = (float)highCount[index] / (float)SIG_LENGTH;
  //Serial.print(ratio);
  
  if (index == E_07){
    if (ratio > 0.15 && ratio < 0.35) {
      currentKey = '7';
      currentInt = 7;
    }
    else if (ratio > 0.4 && ratio < 0.6) {
      currentKey = '=';
      currentInt = -1;
    }
    //else if (ratio > 0.4 && ratio < 0.6) currentKey = '0';
  } 
  
  else if ( index == X_148){
    if (ratio > 0.15 && ratio < 0.35) {
      currentKey = '8';
      currentInt = 8;
    }
    else if (ratio > 0.4 && ratio < 0.6) {
      currentKey = '1';
      currentInt = 1;
    }
    else if (ratio > 0.65 && ratio < 0.85) {
      currentKey = '4';
      currentInt = 4;
    }
  } 
  
  else if ( index == D_259){
    if (ratio > 0.15 && ratio < 0.35) {
      currentKey = '9';
      currentInt = 9;
    }
    else if (ratio > 0.4 && ratio < 0.6) {
      currentKey = '2'; // divide
      currentInt = 2;
    }
    else if (ratio > 0.65 && ratio < 0.85) {
      currentKey = '5';
      currentInt = 5;
    }
  } 
  
  else if ( index == MSP_36){
    float powerFreq = (float)highCount[POWER_X] / (float)SIG_LENGTH;
    if (ratio > 0.15 && ratio < 0.35) {
      currentKey = '-';
      currentInt = -1;
    }
    else if (ratio > 0.4 && ratio < 0.6) {
      currentKey = '3'; // x
      currentInt = 3;
    }
    else if (ratio > 0.65 && ratio < 0.85) {
      currentKey = '6'; // +
      currentInt = 6;
    }
  } 
  
  else if ( index == PERIOD_X){
   // if (ratio > 0.5) currentKey = '.';
  } 
}

boolean printButton = true;
int songNumber = 0;
void matchButtons(char currentKey){
  boolean match = true;
  for(int i=0; i < HISTORY_LENGTH; i++){
    //Serial.print(prepKey[i]);
    
    if (currentKey != prepKey[i]){
      match = false;
    }
  }
  //Serial.print('-');
  //Serial.println(currentKey);
  
  if (match){
    if(currentKey != 'n'){
      if (printButton) {
        Serial.println(currentKey);
        if (currentInt != -1){
          songNumber = songNumber*10 + currentInt;
          Serial.println(songNumber);
        }
        
        if(currentKey == '='){
          //select a song
          if (songNumber < 6) song = songNumber;
          songNumber = 0;
        }
        
        /*
        if (preInt == -1){
          if (currentInt != -1) preInt = currentInt;
        }else if (calOperator == 'n') {
          if (currentInt == 6) calOperator = '+';
          else if (currentInt == 3) calOperator = 'x';
          else if (currentInt == 2) calOperator = 'd';
          else if (currentKey == '-') calOperator = '-';
        }else if (postInt == -1){
          if (currentInt != -1) postInt = currentInt;
        }else{
          if(currentKey == '='){
            float signal = -1;
            if (calOperator == '+') signal = preInt + postInt;
            else if (calOperator == '-') signal = preInt - postInt;
            else if (calOperator == 'x') signal = preInt * postInt;
            else if (calOperator == 'd') signal = (float)preInt / (float)postInt;
            if (signal < 0) signal = 0;
            
            //send signal
            Serial.println(signal);
            preInt = -1;
            postInt = -1;
            calOperator = 'n';
          }
        }
        
        Serial.print(preInt);
        Serial.print(',');
        Serial.print(calOperator);
        Serial.print(',');
        Serial.println(postInt);
        */
      }
      
      for(int i = 0; i<HISTORY_LENGTH; i++){
        prepKey[i] = 'n';    
      }
      printButton = false;
    }else{
      printButton = true;
    }
  }else {
    for(int i = 0; i<HISTORY_LENGTH-1; i++){
      prepKey[i] = prepKey[i+1];    
    }
    prepKey[HISTORY_LENGTH-1] = currentKey;
  }
}

void dataUpdate(){
  for(int i=0; i<SIG_NUM; i++){
    signals[i][pointer] = analogRead(i);
    highCount[i] = 0;
  }
}

// using this instead of tone
void buzz(int targetPin, long frequency, long length) {
  digitalWrite(13, HIGH);
  long delayValue = 1000000 / frequency / 2; // calculate the delay value between transitions
  // 1 second's worth of microseconds, divided by the frequency, then split in half since
  // there are two phases to each cycle
  long numCycles = frequency * length / 1000; // calculate the number of cycles for proper timing
  // multiply frequency, which is really cycles per second, by the number of seconds to
  // get the total number of cycles to produce
  for (long i = 0; i < numCycles; i++) {
    digitalWrite(targetPin, HIGH);
    delayMicroseconds(delayValue);
    digitalWrite(targetPin, LOW);
    delayMicroseconds(delayValue);
  }
  digitalWrite(13, LOW);
}

 
