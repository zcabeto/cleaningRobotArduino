#define echoPinL 2
#define trigPinL 3

#define echoPinR 4
#define trigPinR 5

long durationL;     // duration of the sound wave
long durationR;
long dL;            // distance measurements deduced
long dR;

long x;             // x,y of triangulation
long y;

void setup()
{
    pinMode(echoPinL, INPUT);
    pinMode(trigPinL, OUTPUT);
    pinMode(echoPinR, INPUT);
    pinMode(trigPinR, OUTPUT);

    Serial.begin(9600);
    Serial.println("US triangulation: ")
}

void loop()
{
    digitalWrite(trigPinL, LOW);
    digitalWrite(trigPinR, LOW);
    delayMicroseconds(2);

    digitalWrite(trigPinL, HIGH);
    digitalWrite(trigPinR, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPinL, LOW);
    digitalWrite(trigPinR, LOW);

    durationL = pulseIn(echoPinL, HIGH);
    dL = durationL * 0.034 / 2;
    durationR = pulseIn(echoPinR, HIGH);
    dR = durationR * 0.034 / 2;

    x = ((dL**2) - (dR**2)) / 44;
    y = ((dL**2) - 121 + 0.5*((dR**2) - (dL**2)) - (x**2)) ** 0.5;

    // then use x,y to coordinate how harsh a turn might need to be made
}