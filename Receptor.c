#include <VirtualWire.h>


//    RECEIVER!!!!!!!!!!!!!!!!!!!!!!!!!!!!!   //    RECEIVER!!!!!!!!!!!!!!!!!!!!!!!!!!!!!11    //    RECEIVER!!!!!!!!!!!!!!!!!!!!!!!!!!!!!11     //    RECEIVER!!!!!!!!!!!!!!!!!!!!!!!!!!!!!11

const int led_pin = 13;
const int transmit_pin = 12;
const int receive_pin = 11;
const int transmit_en_pin = 3;

void setup()
{
  delay(1000);
  Serial.begin(9600);	// Debugging only
  //Serial.println("setup");

  // Initialise the IO and ISR
  vw_set_tx_pin(transmit_pin);
  vw_set_rx_pin(receive_pin);
  vw_set_ptt_pin(transmit_en_pin);
  vw_set_ptt_inverted(true); // Required for DR3100
  vw_setup(2000);	 // Bits per sec

  vw_rx_start();       // Start the receiver PLL running

  pinMode(led_pin, OUTPUT);
}

uint8_t contagem1;
uint8_t contagem2;
uint8_t contagem3;
//
//uint8_t buf[VW_MAX_MESSAGE_LEN];
//uint8_t buflen = VW_MAX_MESSAGE_LEN;


uint8_t buf[5];
uint8_t buflen = 5;

void loop()
{
  if (vw_get_message(buf, &buflen)) // Non-blocking
  {
    //int i;

    digitalWrite(led_pin, HIGH); // Flash a light to show received good message
    // Message with a good checksum received, dump it.
    //Serial.print("Got: ");

    if (buf[0] == 'A'){   
      contagem1 = buf[1];
      contagem2 = buf[2];
      contagem3 = buf[3];
    }
    Serial.println(buf[0]);
    Serial.println(contagem1);  
    Serial.println(contagem2);
    Serial.println(contagem3);

    digitalWrite(led_pin, LOW);

  }
    delay(1000);  


}


