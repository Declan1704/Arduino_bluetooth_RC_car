int in1=A5;                     //in_1 L298N full bridge
int in2=A4;                     //in_2 L298N full bridge
int in3=A3;                     //in_3 L298N full bridge
int in4=A2;                     //in_4 L298N full bridge                      //in_8 L298N full bridge
int spdpin1=6;                  //in_1 L298N full bridge                 
int Speed=115;                  //pulse with moudulation ENA_2 and ENB_2 L298N full bridge
int key;                        //Key for the switch case

void setup(){
  
  pinMode(spdpin1,OUTPUT);

  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT); 
  Serial.begin(9600); 
}

void Stp(){
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
  digitalWrite(in5,LOW);
  digitalWrite(in6,LOW);
  digitalWrite(in7,LOW);
  digitalWrite(in8,LOW);
  analogWrite(spdpin1,Speed);
  Serial.println("Stop");
}

void forward(){
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);  
  analogWrite(spdpin1,Speed);
}

void back(){
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  analogWrite(spdpin1,Speed);
}

void left(){
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  analogWrite(spdpin1,Speed);
}

void right(){
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  analogWrite(spdpin1,Speed);
}

void loop(){
  if (Serial.available() > 0){  
    key=Serial.read();
    Stp();
    switch(key){
      case 'F':
        forward();
        Serial.println("Foreward");
        break;
      case 'B':
        back();
        Serial.println("Backward");
        break;
      case 'L':
        left();
        Serial.println("Left");
        break;
      case 'R':
        right();
        Serial.println("Right");
        break;
      case '0':
        Speed = 115;
        Serial.println("speed = 115");
        break;
      case '1':
        Speed = 130;
        Serial.println("speed = 130");
        break;
      case '2':
        Speed = 143;
        Serial.println("speed = 143");
        break;
      case '3':
        Speed = 157;
        Serial.println("speed = 157");
        break;
      case '4':
        Speed = 170;
        Serial.println("speed = 170");
        break;
      case '5':
        Speed = 185;
        Serial.println("speed = 185");
        break;
      case '6':
        Speed = 200;
        Serial.println("speed = 200");
        break;
      case '7':
        Speed = 213;
        Serial.println("speed = 213");
        break;
      case '8':
        Speed = 227;
        Serial.println("speed = 227");
        break;
      case '9':
        Speed = 240;
        Serial.println("speed = 240");
        break;
      case 'q':
        Speed = 255;
        Serial.println("speed = 255”);
        break;
        }
}
}