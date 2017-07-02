/* Sweep
  by BARRAGAN <http://barraganstudio.com>
  This example code is in the public domain.

  modified 8 Nov 2013
  by Scott Fitzgerald
  http://www.arduino.cc/en/Tutorial/Sweep
*/

//********************************************************************
//*超音波センサを使って距離を表示するプログラム
//********************************************************************
//********************************************************************
//*超音波センサを使って距離を表示するプログラム
//********************************************************************

#include <Servo.h>

#define echoPin 2 // Echo Pin
#define trigPin 3 // Trigger Pin

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

double Duration = 0; //受信した間隔
double Distance = 0; //距離

void setup() {
  Serial.begin( 9600 );
  pinMode( echoPin, INPUT );
  pinMode( trigPin, OUTPUT );
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() 
  {
      /* 超音波 */
      digitalWrite(trigPin, LOW);
      delayMicroseconds(2);
      digitalWrite( trigPin, HIGH ); //超音波を出力
      delayMicroseconds( 10 ); //
      digitalWrite( trigPin, LOW );
      Duration = pulseIn( echoPin, HIGH ); //センサからの入力
      if (Duration > 0) 
      {
        Duration = Duration / 2; //往復距離を半分にする
        Distance = Duration * 340 * 100 / 1000000; // 音速を340m/sに設定
        Serial.print("Distance:");
        Serial.print(Distance);
        Serial.println(" cm");
      }
            delay(100);
        if( Distance < 10.0 )
        {
          if( pos > 90.0 )
          {
            pos = pos + 10;
            myservo.write(pos);              // tell servo to go to position in variable 'pos'
            delay(100);                       // waits 15ms for the servo to reach the position
          }
          else
          {
            pos = pos - 10;
            myservo.write(pos);              // tell servo to go to position in variable 'pos'
            delay(100);                       // waits 15ms for the servo to reach the position
          }
//    myservo.write(pos-10);              // tell servo to go to position in variable 'pos'
//    delay(1000);                       // waits 15ms for the servo to reach the position

        }
  }


