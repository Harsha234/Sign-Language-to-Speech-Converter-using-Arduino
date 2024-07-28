#include <SoftwareSerial.h>
SoftwareSerial mySerial(1, 0); // RX, TX

  const int flex1 = A0;
  const int flex2 = A1;
  const int flex3 = A2;
  const int xpin = A3;                  // x-axis of the accelerometer
  const int ypin = A4;                  // y-axis
  const int zpin = A5;                  // z-axis (only on 3-axis models)


void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
 mySerial.begin(9600);
 delay(15000);
}

void loop() {
  // put your main code here, to run repeatedly:
  int x = analogRead(xpin);
  delay(50);

  int y = analogRead(ypin);
  delay(50);

  int z = analogRead(zpin);
  delay(50);
  int thumb;
  int pointer;
  int middle;
  int nomx;
  int nomy;
  int nomz;
  
  thumb = analogRead(flex1);
  pointer = analogRead(flex2);
  middle = analogRead(flex3);
  nomx = x-265;
  nomy = y-253;
  nomz = z-323;

 
  Serial.print(thumb);
   Serial.print("\t");
  Serial.print(pointer);
   Serial.print("\t");
  Serial.print(middle);
   Serial.print("\t");
  Serial.print(nomx);
  Serial.print("\t");
  Serial.print(nomy);
  Serial.print("\t");
  Serial.print(nomz);
  Serial.print("\n");
  Serial.println("");
  delay(500);


   //group1
  if ((thumb > 960)  && (thumb < 985) && (pointer > 970) && (pointer < 1023) && (nomy > 430) && (nomy < 480))  {
    Serial.print("LOOK FORWARD");
    delay(2000);
    }
    else if ((thumb > 960)  && (thumb < 985) && (pointer >970 ) && (pointer < 1023) && (nomy > 480) && (nomy < 550))  {
    Serial.print("LOOK DOWN");
     delay(2000);
    }
    else if ((thumb > 985)  && (thumb < 1023) && (pointer > 970) && (pointer < 1023)&& (nomy > 430) && (nomy < 500))  {
    Serial.print("LOOK UP");
     delay(2000);
    }

  //group2
   else if ((thumb > 975)  && (thumb < 995) &&(pointer > 990) && (pointer < 1023) && (nomx > 450) && (nomx < 550))  {
    Serial.print("OKAY");
     delay(2000);
  }
  else if ((thumb > 1000)  && (thumb <1023 ) && (pointer > 1000) && (pointer < 1023) && (nomx > 550) && (nomy < 650))  {
    Serial.print("HOLD");
     delay(2000);
    }
    else if ((thumb > 1000)  && (thumb < 1023) &&(pointer > 980) && (pointer < 990) && (nomy > 0) && (nomy < 600))  {
   Serial.print("PRONTO");
    delay(2000);
  }

   //group3
    else if ((thumb > 980)  && (thumb < 1000) && (pointer > 1000) && (pointer < 1023) && (nomz >360) && (nomz < 400))  {
   Serial.print("CALL ME");
    delay(2000);
    }
    else if ((thumb > 990)  && (thumb < 1023) && (middle >980 ) && (pointer < 1000) && (nomy >400) && (nomy < 500))  {
   Serial.print("THUMBS DOWN");
    delay(2000);
    }
    else if ((thumb > 1000)  && (thumb < 1023) && (pointer > 1010) && (pointer < 1023) && (nomx >500) && (nomy < 600))  {
   Serial.print("u r beatiful");
    delay(2000);
    }
    else if ((thumb > 1000)  && (thumb < 1023) && (pointer > 1000) && (pointer < 1023) && (nomy > 460) && (nomy < 500))  {
    Serial.print("GIVE ME");
     delay(2000);
    }
    else if ((thumb > 0)  && (thumb < 1023) && (pointer > 0) && (pointer < 990) && (nomy > 90) && (nomy < 600))  {
    Serial.print("GIVE ME SOME");
     delay(2000);
    }     
  else{
    Serial.print("NO SIGN");
  }
  }
