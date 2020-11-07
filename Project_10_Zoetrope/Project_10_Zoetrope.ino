const int controlPin1 = 2;
const int controlPin2 = 3;
const int enablePin = 9;
const int directionSwitchPin = 4;
const int onOfSwitchStateSwitchPin = 5;
const int potPin = A0;
int onOfSwitchState = 0;
int previousOnOfSwitchState = 0;
int directionSwitchState = 0;
int previousDirectionSwitchState = 0;
int motorEnabled = 0;
int motorSpeed = 0;
int motorDirection = 1;
void setup(){
 pinMode(directionSwitchPin, INPUT);
 pinMode(onOfSwitchStateSwitchPin, INPUT);
 pinMode(controlPin1, OUTPUT);
 pinMode(controlPin2, OUTPUT);
 pinMode(enablePin, OUTPUT);
 digitalWrite(enablePin, LOW);
}
void loop(){
 onOfSwitchState =
 digitalRead(onOfSwitchStateSwitchPin);
 delay(1);
 directionSwitchState =
 digitalRead(directionSwitchPin);
 motorSpeed = analogRead(potPin)/4;
if(onOfSwitchState != previousOnOfSwitchState){
 if(onOfSwitchState == HIGH){
 motorEnabled = !motorEnabled;
 }
 }
 if (directionSwitchState !=
 previousDirectionSwitchState) {
 if (directionSwitchState == HIGH) {
 motorDirection = !motorDirection;
 }
 }
 if (motorDirection == 1) {
 digitalWrite(controlPin1, HIGH);
 digitalWrite(controlPin2, LOW);
 }
 else {
 digitalWrite(controlPin1, LOW);
 digitalWrite(controlPin2, HIGH);
 }
 if (motorEnabled == 1) {
 analogWrite(enablePin, motorSpeed);
 }
 else {
 analogWrite(enablePin, 0);
 }
 previousDirectionSwitchState =
 directionSwitchState;
 previousOnOfSwitchState = onOfSwitchState;
}
