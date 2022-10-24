#define echoPin 2
#define trigPin 3

long duration;      // duration of the sound wave
int distance;       // distance measurement deduced

void setup()
{
    pinMode(echoPin, INPUT);
    pinMode(trigPin, OUTPUT);

    Serial.begin(9600);
    Serial.println("US sensor test: ")
}

void loop()
{
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);

    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    duration = pulseIn(echoPin, HIGH);
    distance = duration * 0.034 / 2;

    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.print("cm\n");
}