#include <ark.h>


/********************************************************************************
*
* Voter: 
*   {
*     "username": String,       //  "sleepdeficit",
*     "address":  Address,      //  "DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA",
*     "publicKey":  Publickey,  //  "0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456",
*     "balance":  Balance       //  "8419145341862"
*   }
*
********************************************************************************/
void constructVoter()
{
  ARK::Voter voter(
    "sleepdeficit",
    "DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA",
    "0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456",
    "8419145341862"
  );
  Serial.println("Offline Instantiated Voter Description\n"); 
  Serial.println(voter); 
};

void setup() {
  Serial.begin(115200);
  constructVoter();
}

void loop() {}
