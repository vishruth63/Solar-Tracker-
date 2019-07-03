int ledRed = 2;
int potPin = A0;
int readValue ; 
int ledGreen = A1;
int ledBlue = A4 ;
String choice ;



void setup() {
  // put your setup code here, to run once:
  Serial.begin (9600) ;
  pinMode ( ledRed , OUTPUT ) ;
  pinMode ( potPin , INPUT ) ;
  pinMode ( ledBlue , OUTPUT ) ;
  pinMode ( ledGreen , OUTPUT ) ;
}

void loop() {
  //put your main code here, to run repeatedly:
  /*
  Serial.println ("Enter Your color choice" ) ;
  while (Serial.available () == 0) {}
  choice = Serial.readString () ;
  if ( choice == "red" ) 
  {
    analogWrite (ledRed, 133) ;
    analogWrite (ledGreen, 0) ;
    analogWrite (ledBlue, 0) ;  
  }  
  
  if ( choice == "blue" ) 
  {
    analogWrite (ledRed, 0) ;
    analogWrite (ledGreen, 0) ;
    analogWrite (ledBlue, 133) ;  
  }  
  
  if ( choice == "green" ) 
  {
    analogWrite (ledRed, 0) ;
    analogWrite (ledGreen, 133) ;
    analogWrite (ledBlue, 0) ;  
  }  
  */
 
  readValue = analogRead ( potPin ) ;
  readValue = (255./1023.)*(float)(readValue) ;
  Serial.println ( readValue ) ; 
  analogWrite ( ledRed, readValue ) ;
  analogWrite ( ledBlue, readValue ) ;
  analogWrite ( ledGreen, readValue ) ;
  delay (250); 
}
