const int DispenserPWM=2; //Dispenser
const int Dispenser1=3;   //Dispenser
const int Dispenser2=4;   //Dispenser
const int BlenderPWM=5; //Blender
const int Blender1=6;  //Blender
const int Blender2=7;  //Blender
const int Gear1=8;  //Gear
const int Gear4=9;  //Gear
const int GearPWM=10;  //Gear
const int panStep = 11;
const int panDir = 12;
const int camStep = 44;
const int camDir = 45;



//If you want to run something once, make a function and put it in setup

void gearOpen()
{

  digitalWrite(Blender1,HIGH);    
  digitalWrite(Blender2,LOW);
  
  analogWrite(BlenderPWM, 200);      //Rotates gear at max speed for about 
  delay(300);
  
  digitalWrite(Blender1, LOW);
  digitalWrite(Blender2, LOW);
  
}

void gearClose()
{

  digitalWrite(Blender1,LOW);    //1 HIGH 2 LOW Opens from CLOSE
  digitalWrite(Blender2,HIGH);
  
  analogWrite(BlenderPWM, 200);      //change to 30 for dispenser
  delay(300);
  
  digitalWrite(Blender1, LOW);
  digitalWrite(Blender2, LOW);
  
}

void blender()
{
  digitalWrite(Gear1,HIGH);
  digitalWrite(Gear4,LOW);
  analogWrite(GearPWM, 200);    //Rotates Egg Beater at full speed
  Serial.println("Blender Started!");

  delay(15000);

  gearOpen();                 //Opens Gear after 15 seconds to let the beaten eggs flow
  Serial.println("Gear Opened!");

  delay(5000);                //continue beating for another 5 seconds before stopping the beating. 

  digitalWrite(Gear1, LOW);
  digitalWrite(Gear4, LOW);

  delay(1000);          

  gearClose();              //close the gear after. 
}

void dispense()
{ 
  digitalWrite(Blender1,HIGH);      //function to spin the ingredient dispenser 
  digitalWrite(Blender2,LOW);
  analogWrite(BlenderPWM, 200);
  Serial.println("Dispenser Started!");
  delay(2000);

  digitalWrite(Blender1, LOW);
  digitalWrite(Blender2, LOW);  
}

void tilt() {
  Serial.println("Tilting and Cooking");  
  digitalWrite(panDir, LOW);      //Make the pan tilt as the ingredients are being dispensed to make the 

  for (int x = 0; x < 20; x++)
  {
    digitalWrite(panStep, HIGH);
    delayMicroseconds(3000);
    digitalWrite(panStep, LOW);
    delayMicroseconds(3000);
  }
  delay(400);

  digitalWrite(panDir, HIGH);
  for (int x = 0; x < 80; x++)
  {
    digitalWrite(panStep, HIGH);
    delayMicroseconds(3000);
    digitalWrite(panStep, LOW);
    delayMicroseconds(3000);
  }
  delay(400);

  digitalWrite(panDir, LOW);    //Mechanism

  for (int x = 0; x < 20; x++)
  {
    digitalWrite(panStep, HIGH);
    delayMicroseconds(3000);
    digitalWrite(panStep, LOW);
    delayMicroseconds(3000);
  }

}

void pour() {
  Serial.println("Pouring");
  digitalWrite(panDir, LOW);            //Turn the pan halfway to dispense the omelette
  for (int x = 0; x < 120; x++)
  {
    digitalWrite(panStep, HIGH);
    delayMicroseconds(3000);
    digitalWrite(panStep, LOW);
    delayMicroseconds(3000);
  }
  delay(2000);

}

void camShaft() {
  digitalWrite(camDir, LOW);

 for(int x = 0; x < 30; x++)       //turn the cam to open the flow of the oil
   {
     digitalWrite(camStep, HIGH);
     delayMicroseconds(1000);
     digitalWrite(camStep, LOW);
     delayMicroseconds(1000);
   }
   delay(1000);

   for(int x = 0; x < 100; x++)   //turn the cam to stop flow of oil and to open the flow of the eggs
   {
     digitalWrite(camStep, HIGH);
     delayMicroseconds(1000);
     digitalWrite(camStep, LOW);
     delayMicroseconds(1000);
   }
   delay(4000);

   for(int x = 0; x < 70; x++)    //stop flow of the eggs
   {
     digitalWrite(camStep, HIGH);
     delayMicroseconds(1000);
     digitalWrite(camStep, LOW);
     delayMicroseconds(1000);
   }
   
    
}

void setup() {
  // put your setup code here, to run once:
  pinMode(BlenderPWM, OUTPUT);
  pinMode(GearPWM, OUTPUT);
  pinMode(Blender1, OUTPUT);
  pinMode(Blender2, OUTPUT);
  pinMode(Gear1, OUTPUT);
  pinMode(Gear4, OUTPUT);


  Serial.begin(9600);
  Serial.println("Beginning");
  
  blender();
  delay(4000);
  camShaft();
  dispense();
  tilt();
  delay(100*1000);
  pour();
}




void loop() {
 }
