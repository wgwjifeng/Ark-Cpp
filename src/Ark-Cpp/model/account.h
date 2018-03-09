

#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "address.h"
#include "balance.h"
#include "publickey.h"
#include "signature.h"

#include <cstring>
#include <cstdio>

/********************************************************************************
*
* account: 
*    {  
*      "success":true,
*      "account":{  
*         "address":  Address,
*         "unconfirmedBalance": Balance,
*         "balance":  Balance,
*         "publicKey":  Publickey,
*         "unconfirmedSignature": int,
*         "secondSignature":  int,
*         "secondPublicKey":  Publickey,
*         "multisignatures":  [ Signature ],
*         "u_multisignatures":  [ Signature ]
*      }
*    }
*
********************************************************************************/

namespace ARK
{

/*  ================================================  */
/*  ============  */
/*  ARK::Account  */
struct Account
{
public:
    Address address_;
    Balance unconfirmedBalance_;
    Balance balance_;
    Publickey publicKey_;
    int unconfirmedSignature_;
    int secondSignature_;
    Publickey secondPublicKey_;
    Signature multisignatures_;
    Signature u_multisignatures_;
    
    Account(
        const char* const a, 
        const char* const ub,
        const char* const b,
        const char* const pk,
        int us,
        int ss,
        const char* const spk,
        const char* const ms,
        const char* const ums
    ) : 
		address_(a), 
		unconfirmedBalance_(ub), 
		balance_(b), 
		publicKey_(pk), 
		unconfirmedSignature_(us), 
		secondSignature_(ss), 
		secondPublicKey_(spk), 
		multisignatures_(ms), 
		u_multisignatures_(ums)
    { }

	const Address& address() const noexcept { return address_; }
	const Balance& unconfirmed_balance() const noexcept { return unconfirmedBalance_; }
	const Balance& balance() const noexcept { return balance_; }
	const Publickey& public_key() const noexcept { return publicKey_; }
	int unconfirmed_signature() const noexcept { return unconfirmedSignature_; }
	int second_signature() const noexcept { return secondSignature_; }
	const Publickey& second_public_key() const noexcept { return secondPublicKey_; }
	const Signature& multi_signatures() const noexcept { return multisignatures_; }
	const Signature& u_multi_signatures() const noexcept { return u_multisignatures_; }
	

    void description(char* const buf, size_t len);
};
/*  ============  */
/*  ================================================  */

};

#endif