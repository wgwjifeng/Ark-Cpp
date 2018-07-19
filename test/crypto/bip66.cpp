#include "gtest/gtest.h"

#include "crypto/ark_crypto.h"
#include "crypto/util.h"

TEST(crypto_bip66, toDER) {
	auto r = ParseHex("33A69CD2065432A30F3D1CE4EB0D59B8AB58C74F27C41A7FDB5696AD4E6108C9"); // dec: 23362334225185207751494092901091441011938859014081160902781146257181456271561
	auto s = ParseHex("6F807982866F785D3F6418D24163DDAE117B7DB4D5FDF0071DE069FA54342262"); // dec: 50433721247292933944369538617440297985091596895097604618403996029256432099938
	std::vector<uint8_t> signature;
	ARK::Crypto::toDER(ARK::Crypto::convert_to_der_buffer(r), ARK::Crypto::convert_to_der_buffer(s), signature);
	ASSERT_STRCASEEQ(
		"3044022033a69cd2065432a30f3d1ce4eb0d59b8ab58c74f27c41a7fdb5696ad4e6108c902206f807982866f785d3f6418d24163ddae117b7db4d5fdf0071de069fa54342262",
		HexStr(signature).c_str()
	);

	r = ParseHex("54C4A33C6423D689378F160A7FF8B61330444ABB58FB470F96EA16D99D4A2FED"); // dec: 38341707918488238920692284707283974715538935465589664377561695343399725051885
	s = ParseHex("07082304410EFA6B2943111B6A4E0AAA7B7DB55A07E9861D1FB3CB1F421044A5"); // dec: 3180566392414476763164587487324397066658063772201694230600609996154610926757
	ARK::Crypto::toDER(ARK::Crypto::convert_to_der_buffer(r), ARK::Crypto::convert_to_der_buffer(s), signature);
	ASSERT_STRCASEEQ(
		"3044022054c4a33c6423d689378f160a7ff8b61330444abb58fb470f96ea16d99d4a2fed022007082304410efa6b2943111b6a4e0aaa7b7db55a07e9861d1fb3cb1f421044a5",
		HexStr(signature).c_str()
	);

	r = ParseHex("FF466A9F1B7B273E2F4C3FFE032EB2E814121ED18EF84665D0F515360DAB3DD0"); // dec: 115464191557905790016094131873849783294273568009648050793030031933291767741904
	s = ParseHex("6FC95F5132E5ECFDC8E5E6E616CC77151455D46ED48F5589B7DB7771A332B283"); // dec: 50562520307781850052192542766631199590053690478900449960232079510155113443971
	ARK::Crypto::toDER(ARK::Crypto::convert_to_der_buffer(r), ARK::Crypto::convert_to_der_buffer(s), signature);
	ASSERT_STRCASEEQ(
		"3045022100ff466a9f1b7b273e2f4c3ffe032eb2e814121ed18ef84665d0f515360dab3dd002206fc95f5132e5ecfdc8e5e6e616cc77151455d46ed48f5589b7db7771a332b283",
		HexStr(signature).c_str()
	);

	r = ParseHex("C0DAFEC8251F1D5010289D210232220B03202CBA34EC11FEC58B3E93A85B91D3"); // dec: 87230998027579607140680851455601772643840468630989315269459846730712163783123
	s = ParseHex("75AFDC06B7D6322A590955BF264E7AAA155847F614D80078A90292FE205064D3"); // dec: 53231320085894623106179381504478252331065330583563809963303318469380290929875
	ARK::Crypto::toDER(ARK::Crypto::convert_to_der_buffer(r), ARK::Crypto::convert_to_der_buffer(s), signature);
	ASSERT_STRCASEEQ(
		"3045022100c0dafec8251f1d5010289d210232220b03202cba34ec11fec58b3e93a85b91d3022075afdc06b7d6322a590955bf264e7aaa155847f614d80078a90292fe205064d3",
		HexStr(signature).c_str()
	);

	r = ParseHex("7186363571D65E084E7F02B0B77C3EC44FB1B257DEE26274C38C928986FEA45D"); // dec: 51348483531757779992459563033975330355971795607481991320287437101831125115997
	s = ParseHex("0DE0B38E06807E46BDA1F1E293F4F6323E854C86D58ABDD00C46C16441085DF6"); // dec: 6277080015686056199074771961940657638578000617958603212944619747099038735862
	ARK::Crypto::toDER(ARK::Crypto::convert_to_der_buffer(r), ARK::Crypto::convert_to_der_buffer(s), signature);
	ASSERT_STRCASEEQ(
		"304402207186363571d65e084e7f02b0b77c3ec44fb1b257dee26274c38c928986fea45d02200de0b38e06807e46bda1f1e293f4f6323e854c86d58abdd00c46c16441085df6",
		HexStr(signature).c_str()
	);

	r = ParseHex("FBFE5076A15860BA8ED00E75E9BD22E05D230F02A936B653EB55B61C99DDA487"); // dec: 113979859486826658566290715281614250298918272782414232881639314569529560769671
	s = ParseHex("0E68880EBB0050FE4312B1B1EB0899E1B82DA89BAA5B895F612619EDF34CBD37"); // dec: 6517071009538626957379450615706485096874328019806177698938278220732027419959
	ARK::Crypto::toDER(ARK::Crypto::convert_to_der_buffer(r), ARK::Crypto::convert_to_der_buffer(s), signature);
	ASSERT_STRCASEEQ(
		"3045022100fbfe5076a15860ba8ed00e75e9bd22e05d230f02a936b653eb55b61c99dda48702200e68880ebb0050fe4312b1b1eb0899e1b82da89baa5b895f612619edf34cbd37",
		HexStr(signature).c_str()
	);

	r = ParseHex("CDE1302D83F8DD835D89AEF803C74A119F561FBAEF3EB9129E45F30DE86ABBF9"); // dec: 93122007060065279508564838030979550535085999589142852106617159184757394422777
	s = ParseHex("06CE643F5049EE1F27890467B77A6A8E11EC4661CC38CD8BADF90115FBD03CEF"); // dec: 3078539468410661027472930027406594684630312677495124015420811882501887769839
	ARK::Crypto::toDER(ARK::Crypto::convert_to_der_buffer(r), ARK::Crypto::convert_to_der_buffer(s), signature);
	ASSERT_STRCASEEQ(
		"3045022100cde1302d83f8dd835d89aef803c74a119f561fbaef3eb9129e45f30de86abbf9022006ce643f5049ee1f27890467b77a6a8e11ec4661cc38cd8badf90115fbd03cef",
		HexStr(signature).c_str()
	);
}