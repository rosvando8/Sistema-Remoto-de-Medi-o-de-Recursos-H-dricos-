
#include <VirtualWire.h>

const int led_pin = 11;
const int transmit_pin = 12;
const int receive_pin = 5; //2;
const int transmit_en_pin = 6; //3;

int contaPulso1; 
int contaPulso2; 
int contaPulso3; 


char leitura [5];



void setup()
{ 
  
  
  Serial.begin(9600); 
  pinMode(19, INPUT);
  pinMode(2 ,INPUT);
  pinMode(21, INPUT);
  
  digitalWrite(19, LOW);
  digitalWrite(2, LOW);
  digitalWrite(21, LOW);
  
  attachInterrupt(4, incpulso1, RISING); 
  attachInterrupt(0, incpulso2, RISING); 
  attachInterrupt(2, incpulso3, RISING);
 
  
  contaPulso1 = 0;
  contaPulso2 = 0;
  contaPulso3 = 0;
  
  // Initialise the IO and ISR
  vw_set_tx_pin(transmit_pin);
  vw_set_rx_pin(receive_pin);
  vw_set_ptt_pin(transmit_en_pin);
  vw_set_ptt_inverted(true); // Required for DR3100
  vw_setup(2000);   // Bits per sec

sei();  
} 
byte count = 1;

int contagem1=0 ;
int contagem2 =0;
int contagem3 =0;


void loop ()


{  char msg[5];

contagem1=contaPulso1;
contagem2=contaPulso2;
contagem3=contaPulso3;

  msg[0] = 'A';
  msg[1] = contagem1;
  msg[2] = contagem2;
  msg[3] = contagem3;
  msg[4] = 'A';
  
  //msg[5] = count;
  digitalWrite(led_pin, HIGH); // Flash a light to show transmitting
  vw_send((uint8_t *)msg, 5);
  vw_wait_tx(); // Wait until the whole message is gone
  digitalWrite(led_pin, LOW);
  delay(1000);
 
  Serial.println('a'); 
  Serial.println(contagem1);
   
  Serial.println(contagem2);
   
  Serial.println(contagem3);
  
  contaPulso1 =0;
  contaPulso2 =0;
  contaPulso3=0;
 
   delay(200);  //  leitura a cada meio segundo
  
}


void incpulso1 ()
{ 
  contaPulso1++; 
  //Serial.println("Pulso1);
} 


void incpulso2 ()
{ 
  contaPulso2++; 
  //Serial.println("Pulso2);
} 

void incpulso3 ()
{ 
  contaPulso3++; 
  //Serial.println("Pulso3);
} 


