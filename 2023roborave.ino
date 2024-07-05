int Dl = 0, Dm = 0, Dr = 0, Ul = 0, Um = 0, Ur = 0;
int Speed = 80;
int left = 0, ml = 0, mr = 0, right = 0, aa = 0, bb = 0;
int a = 0;
void setup() {
  Serial.begin(9600);
  for (int i = 2; i < 10; i++) {
    pinMode(i, OUTPUT);
  }
  for (int k = 22; k < 30; k++) {
    pinMode(k, OUTPUT);
  }
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);
  pinMode(A12, INPUT);
  pinMode(A13, INPUT);
  pinMode(A14, INPUT);
  pinMode(A15, INPUT);
  pinMode(10, INPUT);
}
void loop() {
  left = analogRead(15);
  ml = analogRead(14);
  mr = analogRead(13);
  right = analogRead(12);
  Dl = analogRead(A3);
  Dm = analogRead(A4);
  Dr = analogRead(A5);
  Ul = analogRead(A0);
  Um = analogRead(A1);
  Ur = analogRead(A2);
  /*
    while (1) {
      Dm = analogRead(4);
      Um = analogRead(1);
      Serial.print("DM: ");
      Serial.print(Dm);
      Serial.print("   ");
      Serial.print("UM: ");
      Serial.println(Um);
      delay(10);
    }

  */
  while (digitalRead(10) == 0) { }
  delay(500);
  while (1) {
    forward();
    delay(500);
    while (ml < 950 && mr < 950) {
      ml = analogRead(14);
      mr = analogRead(13);
      forward();
    }
    forward_stop();
    delay(100);
    fan();
    break;
  }
  back();
  delay(400);
  back_stop();
  while (right < 950) {
    right = analogRead(12);
    rightright();
  }
  rightright_stop();
  delay(100);
  leftleft();
  delay(300);
  leftleft_stop();
  //part2...................................................................................
  while (1) {
    left = analogRead(15);
    ml = analogRead(14);
    mr = analogRead(13);
    right = analogRead(12);
    Dl = analogRead(A3);
    Dm = analogRead(A4);
    Dr = analogRead(A5);
    Ul = analogRead(A0);
    Um = analogRead(A1);
    Ur = analogRead(A2);
    while (Dl > 950 && Dm > 950 && Dr > 950 && Ul > 950 && Um > 950 && Ur > 950) {
      left = analogRead(15);
      ml = analogRead(14);
      mr = analogRead(13);
      right = analogRead(12);
      Dl = analogRead(A3);
      Dm = analogRead(A4);
      Dr = analogRead(A5);
      Ul = analogRead(A0);
      Um = analogRead(A1);
      Ur = analogRead(A2);
      if (left > 950) {
        back();
        delay(800);
        back_stop();
        aa = 0;

        while (right < 950 &&  aa < 90  ) {
          right = analogRead(12);
          turn_left();
          delay(10);
          aa += 1;
        }
        turn_left_stop();
        aa = 0;
      }
      else {
        if (right < 950) {
          forward();
        }
        else if (right > 950) {
          turn_left();
          delay(100);//...............................
          turn_left_stop();
          delay(50);
          aa = 0;

          while (left < 950 &&  aa < 90  ) {
            left = analogRead(15);
            leftleft();
            delay(10);
            aa += 1;
          }
          aa = 0;
          leftleft_stop();
          delay(100);
        }
      }
    }
    delay(50);
    forward_stop();
    delay(100);
    forward();
    delay(200);
    forward_stop();
    delay(100);//..................................
    left = analogRead(15);
    ml = analogRead(14);
    mr = analogRead(13);
    right = analogRead(12);
    Dl = analogRead(A3);
    Dm = analogRead(A4);
    Dr = analogRead(A5);
    Ul = analogRead(A0);
    Um = analogRead(A1);
    Ur = analogRead(A2);
    delay(10);



    if (Dl < 950 || Ul < 950) {
      bb = 0;
      while (bb < 4 && Dl > 950 && Ul > 950) {
        Dl = analogRead(A3);
        Ul = analogRead(A0);
        bb += 1;
        forward_stop();
        delay(50);
      }
      bb = 0;
      delay(100);
      Dm = analogRead(4);
      Um = analogRead(1);

      while (Dm > 700 && Um > 700) {
        Dm = analogRead(4);
        Um = analogRead(1);
        turn_left();
        delay(10);
      }
      turn_left_stop();
      delay(300);
      while (ml < 950 && mr < 950) {
        ml = analogRead(14);
        mr = analogRead(13);
        forward();
        delay(10);
      }
      forward_stop();
      delay(100);
      fan();
      delay(100);
      back();
      delay(1000);
      back_stop();
      delay(100);
      turn_right();
      delay(750);
      turn_right_stop();
      delay(100);
    }
    else if (Dr < 950 || Ur < 950) {
      bb = 0;
      while (bb < 4 && Dl > 950 && Ul > 950) {
        Dl = analogRead(A3);
        Ul = analogRead(A0);
        bb += 1;
        forward_stop();
        delay(50);
      }
      bb = 0;
      delay(10);
      Dm = analogRead(4);
      Um = analogRead(1);
      while (Dm > 950 && Um > 950) {
        Dm = analogRead(4);
        Um = analogRead(1);
        turn_right();
        delay(10);
      }
      turn_left_stop();
      delay(300);
      while (ml < 950 && mr < 950) {
        ml = analogRead(14);
        mr = analogRead(13);
        forward();
        delay(10);
      }
      forward_stop();
      delay(100);
      fan();
      delay(100);
      back();
      delay(1000);
      back_stop();
      delay(100);
      turn_left();
      delay(750);
      turn_left_stop();
      delay(100);
    }
    else {
      bb = 0;
      while (bb < 4 && Dl > 950 && Ul > 950) {
        Dl = analogRead(A3);
        Ul = analogRead(A0);
        Um = analogRead(A4);
        Um = analogRead(A1);
        bb += 1;
        forward_stop();
        delay(50);
      }
      bb = 0;
      delay(50);
      while (ml < 950 && mr < 950) {
        ml = analogRead(14);
        mr = analogRead(13);
        forward();
        delay(10);
      }
      forward_stop();
      delay(100);
      fan();
      delay(100);
      back();
      delay(1000);
      back_stop();
      delay(100);
      turn_right();
      delay(1000);
      turn_right_stop();
      delay(100);
    }
  } //..................................................................
}
//子程式..............................................................................................
void forward() {
  analogWrite(2, Speed);
  analogWrite(3, 0);
  analogWrite(4, 0);
  analogWrite(5, Speed);
  analogWrite(8, Speed);
  analogWrite(9, 0);
  analogWrite(6, 0);
  analogWrite(7, Speed);
}
void back() {
  analogWrite(2, 0);
  analogWrite(3, Speed);
  analogWrite(4, Speed);
  analogWrite(5, 0);
  analogWrite(8, 0);
  analogWrite(9, Speed);
  analogWrite(6, Speed);
  analogWrite(7, 0);
}
void forward_stop() {
  analogWrite(2, 0);
  analogWrite(3, Speed);
  analogWrite(4, Speed);
  analogWrite(5, 0);
  analogWrite(8, 0);
  analogWrite(9, Speed);
  analogWrite(6, Speed);
  analogWrite(7, 0);
  delay(50);
  for (int i = 2; i < 10; i++) {
    analogWrite(i, 0);
  }
}
void back_stop() {
  analogWrite(2, Speed);
  analogWrite(3, 0);
  analogWrite(4, 0);
  analogWrite(5, Speed);
  analogWrite(8, Speed);
  analogWrite(9, 0);
  analogWrite(6, 0);
  analogWrite(7, Speed);
  delay(50);
  for (int i = 2; i < 10; i++) {
    analogWrite(i, 0);
  }
}
void turn_left() {
  analogWrite(2, Speed);
  analogWrite(3, 0);
  analogWrite(4, 0);
  analogWrite(5, Speed);
  analogWrite(8, 0);
  analogWrite(9, Speed);
  analogWrite(6, Speed);
  analogWrite(7, 0);
}
void turn_left_stop() {
  analogWrite(2, 0);
  analogWrite(3, Speed);
  analogWrite(4, Speed);
  analogWrite(5, 0);
  analogWrite(8, Speed);
  analogWrite(9, 0);
  analogWrite(6, 0);
  analogWrite(7, Speed);
  delay(50);
  for (int i = 2; i < 10; i++) {
    analogWrite(i, 0);
  }
}
void turn_right() {
  analogWrite(2, 0);
  analogWrite(3, Speed);
  analogWrite(4, Speed);
  analogWrite(5, 0);
  analogWrite(8, Speed);
  analogWrite(9, 0);
  analogWrite(6, 0);
  analogWrite(7, Speed);
}
void turn_right_stop() {
  analogWrite(2, Speed);
  analogWrite(3, 0);
  analogWrite(4, 0);
  analogWrite(5, Speed);
  analogWrite(8, 0);
  analogWrite(9, Speed);
  analogWrite(6, Speed);
  analogWrite(7, 0);
  delay(50);
  for (int i = 2; i < 10; i++) {
    analogWrite(i, 0);
  }
}
void leftleft() {
  analogWrite(2, Speed - 2);
  analogWrite(3, 0);
  analogWrite(4, Speed);
  analogWrite(5, 0);
  analogWrite(8, 0);
  analogWrite(9, Speed);
  analogWrite(6, 0);
  analogWrite(7, Speed);
}
void leftleft_stop() {
  analogWrite(2, 0);
  analogWrite(3, Speed);
  analogWrite(4, 0);
  analogWrite(5, Speed);
  analogWrite(8, Speed);
  analogWrite(9, 0);
  analogWrite(6, Speed);
  analogWrite(7, 0);
  delay(50);
  for (int i = 2; i < 10; i++) {
    analogWrite(i, 0);
  }
}
void rightright() {
  analogWrite(2, 0);
  analogWrite(3, Speed - 2);
  analogWrite(4, 0);
  analogWrite(5, Speed);
  analogWrite(8, Speed);
  analogWrite(9, 0);
  analogWrite(6, Speed);
  analogWrite(7, 0);
}
void rightright_stop() {
  analogWrite(2, Speed);
  analogWrite(3, 0);
  analogWrite(4, Speed);
  analogWrite(5, 0);
  analogWrite(8, 0);
  analogWrite(9, Speed);
  analogWrite(6, 0);
  analogWrite(7, Speed);
  delay(50);
  for (int i = 2; i < 10; i++) {
    analogWrite(i, 0);
  }
}
void fan() {
  digitalWrite(22, 1);
  digitalWrite(23, 0);
  digitalWrite(24, 0);
  digitalWrite(25, 1);
  digitalWrite(26, 1);
  digitalWrite(27, 0);
  digitalWrite(28, 1);
  digitalWrite(29, 0);
  delay(2000);
  digitalWrite(22, 0);
  digitalWrite(23, 0);
  digitalWrite(24, 0);
  digitalWrite(25, 0);
  digitalWrite(26, 0);
  digitalWrite(27, 0);
  digitalWrite(28, 0);
  digitalWrite(29, 0);
}
