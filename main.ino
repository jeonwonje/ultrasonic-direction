#include <NewPing.h>

#define TRIGPIN_A 8
#define ECHOPIN_A 9

#define TRIGPIN_B 10
#define ECHOPIN_B 11

#define MAX_DISTANCE 50

NewPing sonar[2] = {
  NewPing(TRIGPIN_A, ECHOPIN_A, MAX_DISTANCE), // trigger, echo, max distance.
  NewPing(TRIGPIN_B, ECHOPIN_B, MAX_DISTANCE)
};


void setup() {
  Serial.begin(115200);
}

void loop() {

  Serial.print("Sensor ping AB: ");
  //float pingSensorA = sonar[0].ping_median(6);
  float pingSensorA = sonar[0].ping() - 20;
  Serial.print(pingSensorA);
  Serial.println("us");
  delay(1000);

  Serial.print("Sensor ping BA: ");
  //float pingSensorB = sonar[1].ping_median(6);
  float pingSensorB = sonar[1].ping();
  Serial.print(pingSensorB);
  Serial.println("us");
  delay(1000);
  
  Serial.println(calcError(pingSensorA, pingSensorB));
  
  if (pingSensorA > pingSensorB) {
    Serial.println("Air is moving from Right to Left"); // If A to B is longer, air is travelling from B to A
  } else if (pingSensorA < pingSensorB) {
    Serial.println("Air is moving from Left to Right"); // If B to A is longer, air is travelling from A to B
  } else {
    Serial.println("Air is stagnant");
  }
  Serial.println("_____________________");
}

float calcError(float a, float b) {
  float percentageError = 100 * (abs(a - b) / a);
  return percentageError;
}
