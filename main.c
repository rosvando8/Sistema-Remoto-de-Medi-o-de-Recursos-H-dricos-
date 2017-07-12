//#include<SoftwareSerial.h>

//SoftwareSerial bt(0,1);  // rx tx

float litros1; 
float litros2; 
float litros3;
int contaPulso1; 
int contaPulso2; 
int contaPulso3; 
int x;
int y;
int z;


char leitura [5];



void setup()
{ 
  Serial1.begin(9600);
  Serial.begin(9600); 
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(21, INPUT);
  attachInterrupt(0, incpulso1, RISING); 
  attachInterrupt(1, incpulso2, RISING); 
  attachInterrupt(2, incpulso3, RISING);
  contaPulso1 = 0;
  contaPulso2 = 0;
  contaPulso3 = 0;
  // protocolo de  envio 


  sei();  
} 


void loop ()
{  
  litros1 = contaPulso1*0.002;
  litros2 = contaPulso2*0.002;
  litros3 = contaPulso3*0.002;

  // CONVERTER PARA ASCII
  leitura[2]= contaPulso1;
  leitura[3]=contaPulso2;
  leitura[4]=contaPulso3;


  // Escrita na tela
  Serial.println('a'); 
  Serial.println(contaPulso1);
  //Serial.print(" Litros"); 
  //Serial.print("     "); 
 // Serial.print("Sensor 2"); 
  Serial.println(contaPulso2);
  //Serial.print(" Litros");
 // Serial.print("     "); 
 // Serial.print("Sensor 3"); 
  Serial.println(contaPulso3);
 // Serial.println(" Litros");



  if(leitura[2] >= 483 || leitura[3] >= 483 || leitura[4] >= 483)
  {
    //  manda para o outro arduino via Serial canal 1
    noInterrupts();
    if( leitura[2] >= 483)
    {
      x = 1;
      leitura[2] = 0;
      contaPulso1 = 0 ;
    }
    else{
      x = 0;
    }
    if( leitura[3] >= 483)
    {
      y = 1;
      leitura[3] = 0;
      contaPulso1 = 0 ;  
  }
    else
    {
      y=0;
    }

    if( leitura[4] >= 483)
    {
      z = 1;
      leitura[4] = 0;
      contaPulso1 = 0 ;
    }
    else
    {
      z=0; 
    }
    Serial1.write ('a');
    Serial1.write (contaPulso1);
    Serial1.write (contaPulso2);
    Serial1.write (contaPulso3);
    Serial1.write ('b');
    //interrupts();
  }
  delay(500);  //  leitura a cada meio segundo 
}


void incpulso1 ()
{ 
  contaPulso1++; 
} 


void incpulso2 ()
{ 
  contaPulso2++; 
} 

void incpulso3 ()
{ 
  contaPulso3++; 
} 


