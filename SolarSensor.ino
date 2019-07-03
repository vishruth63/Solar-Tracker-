int base1=2;
int base2=3;
int top1=4;
int top2=5;

int ldr1=A0;
int ldr2=A1;

int reg_top=940;
int reg_side=300;
int max_top=700;
int max_side=150;

int sensor1;
int sensor2;

void setup() {
 
 Serial.begin(9600);

 pinMode(ldr1,INPUT);
 pinMode(ldr2,INPUT);
 pinMode(top1,OUTPUT);
 pinMode(top2,OUTPUT);
 pinMode(base1,OUTPUT);
 pinMode(base2,OUTPUT);

}

void loop() {
 
 sensor1= analogRead(ldr1);
 sensor2= analogRead(ldr2);

 if(sensor1>200 && sensor1<450)
 {
  digitalWrite(top1,LOW);
  digitalWrite(top2,LOW);
  digitalWrite(base1,LOW);
  digitalWrite(base2,LOW);
 }
   if(sensor1>reg_top && sensor2>reg_side)
 {
   digitalWrite(base2,HIGH);
   digitalWrite(base1,LOW);
   
   delay(200);

   digitalWrite(base1,LOW);
   digitalWrite(base2,LOW);
   delay(100);   
 }
 if(sensor2>max_side && sensor2<reg_side) 
 {
   if(sensor1<200)
  {
   while(sensor2>max_side)
   {
   digitalWrite(base1,LOW);
   digitalWrite(base2,HIGH);

   delay(200);

   digitalWrite(base1,LOW);
   digitalWrite(base2,LOW);
   delay(100);
   sensor2=analogRead(ldr2);
   }
  } 
   if(sensor1>450 && sensor1<800)
  {
   while(sensor2>max_side)
   {
   digitalWrite(base1,LOW);
   digitalWrite(base2,HIGH);

   delay(200);

   digitalWrite(base1,LOW);
   digitalWrite(base2,LOW);
   delay(100);
   sensor2=analogRead(ldr2);
   }
  } 
 }
  if(sensor2<max_side)
 {
  digitalWrite(base1,LOW);
  digitalWrite(base2,LOW);

  while(sensor1>450 || sensor1<200)  { 
   digitalWrite(top2,LOW);
   digitalWrite(top1,HIGH);
  
   delay(200);

   digitalWrite(top1,LOW);
   digitalWrite(top2,LOW);
   delay(100);
   
   sensor1=analogRead(ldr1);
  }
 }
 if(sensor1<800 && sensor1>450)
 {
  digitalWrite(top1,LOW);
  digitalWrite(top2,HIGH);
  
  delay(200);

  digitalWrite(top1,LOW);
  digitalWrite(top2,LOW);
  delay(100);  
 }
 if(sensor1<200 && sensor1>150)
 {
  digitalWrite(top1,LOW);
  digitalWrite(top2,HIGH);
  
  delay(200);

  digitalWrite(top1,LOW);
  digitalWrite(top2,LOW);
  delay(100);  
 }
  if(sensor1>200 && sensor1<450)
 {
  digitalWrite(top1,LOW);
  digitalWrite(top2,LOW);
  digitalWrite(base1,LOW);
  digitalWrite(base2,LOW);
 }

 Serial.print(sensor1);
 Serial.print("    ");
 Serial.println(sensor2); 
 delay(200);
} 
