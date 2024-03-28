// volatile byte Flag;

// //****************************************************************************
// void setup ()
// {
//   Serial.begin(19200);
//   Serial.println("Serial has started");

//   for (int x = 4; x <= 7; x++)   //switches wired from input to GND
//     pinMode(x, INPUT_PULLUP);

//   //D00 and D01 used for Serial communications
//   //PCMSK2 |= bit (PCINT16); // Pin D0
//   //PCMSK2 |= bit (PCINT17); // Pin D1
//   // PCMSK2 |= bit (PCINT18); // Pin D02
//   // PCMSK2 |= bit (PCINT19); // Pin D03
//   PCMSK2 |= bit (PCINT20); // Pin D04
//   PCMSK2 |= bit (PCINT21); // Pin D05
//   PCMSK2 |= bit (PCINT22); // Pin D06
//   PCMSK2 |= bit (PCINT23); // Pin D07
//   PCIFR  |= bit (PCIF2);   // clear any outstanding interrupts
//   PCICR  |= bit (PCIE2);   // enable pin change interrupts for D00 to D07

//   // PCMSK0 |= bit (PCINT0);  // Pin D08
//   // PCMSK0 |= bit (PCINT1);  // Pin D09
//   // PCMSK0 |= bit (PCINT2);  // Pin D10
//   // PCMSK0 |= bit (PCINT3);  // Pin D11
//   // PCMSK0 |= bit (PCINT4);  // Pin D12
//   // PCMSK0 |= bit (PCINT5);  // Pin D13
//   // PCIFR  |= bit (PCIF0);   // clear any outstanding interrupts
//   // PCICR  |= bit (PCIE0);   // enable pin change interrupts for D08 to D13
// }

// //****************************************************************************
// void loop ()
// {
//   //have we had an interrupt?
//   if (Flag == 1)
//   {
//     Flag = 0;

//     //check for the bit that caused the interrupt
//     byte interrupt = checkBit();

//     if (interrupt != 0)
//     {
//       Serial.print("Interrupt called = ");
//       Serial.println(interrupt);
//     }
//   }
  
//       delay(10000);
// }


// //****************************************************************************
// byte checkBit()
// {
//   //check PIND D02-D07
//   for (byte x = 4; x <= 7; x++)
//   {
//     //check for LOW pin
//     byte value = PIND;
//     if (bitRead(value, x) == 0)
//       return x;
//   }

//   // //check PINB D08-D13
//   // for (byte x = 0; x <= 5; x++)
//   // {
//   //   //check for LOW pin
//   //   byte value = PINB;
//   //   if (bitRead(value, x) == 0)
//   //   {
//   //     //offset by 8 bits
//   //     return x + 8;
//   //   }
//   // }
  
//   //must have gone HIGH
//   return 0;
// }

// //****************************************************************************
// ISR (PCINT2_vect) //D02-07
// {
//   //get out quick
//   Serial.println("asdas");
//   Flag = 1;
// }

// //****************************************************************************
// // ISR (PCINT0_vect) //D08-13
// // {
// //   //get out quick
// //   Flag = 1;
// // }