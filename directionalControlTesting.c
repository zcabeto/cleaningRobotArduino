// this program is a generalised version of the 4 wheel control
// it uses 4 lights to signify different servo motor controls to test before running in reality


int direc;              // denotes forward or backward
float dial;             // read if directional dial inputs request to turn

void setup()
{
    pinMode(1,OUTPUT);  // Right Wheels' forward movement
    pinMode(2,OUTPUT);  // Left Wheels' forward movement
    pinMode(3,OUTPUT);  // Right Wheels' backward movement
    pinMode(4,OUTPUT);  // Left Wheels' backward movement
    pinMode(8,OUTPUT);  // check code running light

    pinMode(A1,INPUT);  // directional dial
    pinMode(A2,INPUT);  // forward movement button
    pinMode(A3,INPUT);  // backward movement button
}

void loop()
{
    digitalWrite(8, HIGH);         // turns on 8 when code runs
    dial = analogRead(A1);
    direc = map(dial, 0, 1023, 0, 100);

    if (digitalRead(A2)==HIGH)      // forward movement
    {
        if (direc <= 15)        // turn left on spot
        {
            digitalWrite(1,HIGH);
            digitalWrite(2,LOW);
            digitalWrite(3,LOW);
            digitalWrite(4,HIGH);
        }
        else if (direc >= 75)   // turn right on spot
        {
            digitalWrite(1,LOW);
            digitalWrite(2,HIGH);
            digitalWrite(3,HIGH);
            digitalWrite(4,LOW);
        }
        else                    // straight forward
        {
            digitalWrite(1,HIGH);
            digitalWrite(2,HIGH);
            digitalWrite(3,LOW);
            digitalWrite(4,LOW);
        }
    }
    else if (digitalRead(A3)==HIGH)  // backward movement
    {
        digitalWrite(1,LOW);
        digitalWrite(2,LOW);
        digitalWrite(3,HIGH);
        digitalWrite(4,HIGH);
    }
    else                            // no movement
    {
        digitalWrite(1,LOW);
        digitalWrite(2,LOW);
        digitalWrite(3,LOW);
        digitalWrite(4,LOW);
    }

    
}