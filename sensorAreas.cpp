#define echoPinL 2
#define trigPinL 3

#define echoPinR 4
#define trigPinR 5

long durationL;     // duration of the sound wave
long durationR;
long dL;            // distance measurements deduced
long dR;

void setup()
{
    pinMode(echoPinL, INPUT);
    pinMode(trigPinL, OUTPUT);
    pinMode(echoPinR, INPUT);
    pinMode(trigPinR, OUTPUT);

    Serial.begin(9600);
    Serial.println("US area watching: ")
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

    ratio = dL/dR;
    if (dL <= 120 or dR <= 120)
    {
        if (0.8 < ratio < 1.2)
        {
            // go straight on
        }
        else if (ratio > 1.2)
        {
            // turn slight right (repeated until can go straight on)
        }
        else 
        {
            // turn slight left (repeated until can go straight on)
        }
    }
}