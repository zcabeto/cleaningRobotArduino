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
    digitialWrite(8, HIGH);         // turns on 8 when code runs
    dial = analogRead(A1);
    direc = map(dial, 0, 1023, 0, 100);

    if (digitalRead(A2)==HIGH)      // forward movement
    {
        if (direc <= 15)        // turn left on spot
        {
            digitialWrite(1,HIGH);
            digitialWrite(2,LOW);
            digitialWrite(3,LOW);
            digitialWrite(4,HIGH);
        }
        else if (direc >= 75)   // turn right on spot
        {
            digitialWrite(1,LOW);
            digitialWrite(2,HIGH);
            digitialWrite(3,HIGH);
            digitialWrite(4,LOW);
        }
        else                    // straight forward
        {
            digitialWrite(1,HIGH);
            digitialWrite(2,HIGH);
            digitialWrite(3,LOW);
            digitialWrite(4,LOW);
        }
    }
    else if (digitalRead(A3)==HIGH)  // backward movement
    {
        digitialWrite(1,LOW);
        digitialWrite(2,LOW);
        digitialWrite(3,HIGH);
        digitialWrite(4,HIGH);
    }
    else                            // no movement
    {
        digitialWrite(1,LOW);
        digitialWrite(2,LOW);
        digitialWrite(3,LOW);
        digitialWrite(4,LOW);
    }

    
}