#include "gtest/gtest.h"

#include "api/api.h"

namespace
{
	const Publickey darkPubkey("0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456");
}

TEST(api, test_signature_fees)
{
	ARK::API::Manager _arkManager(ARK::Constants::Networks::Model::Devnet);
	const auto signatures_fee = _arkManager.signaturesFee();
	ASSERT_STREQ("5.00000000", signatures_fee.ark());
	ASSERT_STREQ("500000000", signatures_fee.arktoshi());

	/*  ==================================  */
}

	/*  ==================================  */
	/*  ==================================  */
	/*  Only on Mainnet?  */
	//  String multisignaturesAccounts = _arkManager.multisignaturesAccounts(darkHash);
	//    Serial.println("multisignaturesAccounts: ");
	//    Serial.println(multisignaturesAccounts);
	//    Serial.println("\n=====\n");
	/*  ==================================  */
	/*  ==================================  */

