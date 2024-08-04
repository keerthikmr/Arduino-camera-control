const int trigger1 = 2; // Trigger pin of 1st Sensor
const int echo1 = 3;    // Echo pin of 1st Sensor
const int led = 13;     // Pin for LED
long time_taken;        
int dist;               

// Function to setup all pin modes
void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(trigger1, OUTPUT);
  pinMode(echo1, INPUT);
}

// Function to calculate distance
void calculate_distance(int trigger, int echo) {
  
  digitalWrite(trigger, LOW);         // For clean pulse

  delayMicroseconds(2);         
  
  digitalWrite(trigger, HIGH);        // Ultrasonic pulse
  
  delayMicroseconds(10);              // For clean reach

  digitalWrite(trigger, LOW);         // Stop pulse

  time_taken = pulseIn(echo, HIGH);   // Time to hit target and reach back

  dist = time_taken * 0.034 / 2;      // Spped of sound / 2. d = t * s

  if (dist > 60) {
    dist = 60;                        // Setting upper limit
  }
}

void loop() { //infinite loop

  calculate_distance(trigger1, echo1);

  if ((dist < 40 && dist > 5)) {

    if (dist >= 15 && dist <= 40) {

      SerialF_CPU
      delay(1000);
      calculate_distance(trigger1, echo1);

      while (dist < 15) {
        Serial.println("Zoom in");
        delay(300);
        calculate_distance(trigger1, echo1);
      }

      while (dist > 20 && dist < 60) {
        Serial.println("Zoom out");
        delay(300);
        calculate_distance(trigger1, echo1);
      }
      
    } else if (dist < 15) {
      Serial.println("Capture");
      digitalWrite(13, HIGH);
      delay(2000);
      digitalWrite(13, LOW);
    }
  }
  delay(200);
}
