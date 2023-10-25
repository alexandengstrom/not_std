#include "../../include/data_structures/bitset.hpp"
#include "test_framework.hpp"

void register_bitset_tests()
{
    REGISTER_TEST(bitset_tests, []()
                  {
        not_std::bitset<128> bs;
        bs.set(3).set(5).set(127);
        unit_test(bs[3] == true, "set_and_access: bitset should have set 3rd position to true");
        unit_test(bs[5] == true, "set_and_access: bitset should have set 5th position to true");
        unit_test(bs[127] == true, "set_and_access: bitset should have set 127th position to true");
        unit_test(bs[2] == false, "set_and_access: bitset should not have set 2nd position to true"); });

    REGISTER_TEST(bitset_tests, []()
                  {
        not_std::bitset<64> bs;
        bs.set();
        unit_test(bs.count() == 64, "set_all: all bits should be set to true after set()");
        bs.reset();
        unit_test(bs.count() == 0, "reset_all: all bits should be set to false after reset()"); });

    REGISTER_TEST(bitset_tests, []()
                  {
        not_std::bitset<128> bs;
        bs.set(3).set(7).set(63);
        bs.flip();
        unit_test(bs[3] == false, "flip_all: 3rd position should be false after flip");
        unit_test(bs[7] == false, "flip_all: 7th position should be false after flip");
        unit_test(bs[63] == false, "flip_all: 63rd position should be false after flip");
        unit_test(bs[5] == true, "flip_all: 5th position should be true after flip (since it was not set earlier)"); });

    REGISTER_TEST(bitset_tests, []()
                  {
        not_std::bitset<1000> bs;
        bs.set(3).set(7).set(999);
        bs.flip(7);
        unit_test(bs[3] == true, "flip_position: 3rd position should remain true");
        unit_test(bs[7] == false, "flip_position: 7th position should be flipped to false");
        unit_test(bs[999] == true, "flip_position: 999th position should remain true"); });

    REGISTER_TEST(bitset_tests, []()
                  {
        not_std::bitset<1> bs;
        bs.set();
        unit_test(bs[0] == true, "smallest_bitset: single bit should be true after set()");
        bs.reset();
        unit_test(bs[0] == false, "smallest_bitset: single bit should be false after reset()"); });

    REGISTER_TEST(bitset_tests, []()
                  {
        not_std::bitset<65> bs;
        bs.set(64);
        unit_test(bs[64] == true, "over_one_block: 65th position should be true after set");
        unit_test(bs.count() == 1, "over_one_block: only one bit should be set");
        bs.reset(64);
        unit_test(bs[64] == false, "over_one_block: 65th position should be false after reset()"); });

    REGISTER_TEST(bitset_tests, []()
                  {
        not_std::bitset<256> bs;
        bs.set();
        unit_test(bs[255] == true, "last_position: last position should be true after set all");
        bs.flip(255);
        unit_test(bs[255] == false, "last_position: last position should be false after flip");
        unit_test(bs.count() == 255, "last_position: 255 bits should remain set"); });

    REGISTER_TEST(bitset_tests, []()
                  {
        not_std::bitset<1000> bs;
        for(u_int i = 0; i < 1000; i+=2)
            bs.set(i);
        unit_test(bs.count() == 500, "alternate_bits_set: 500 bits should be set when setting alternate bits"); });

    REGISTER_TEST(bitset_tests, []()
                  {
        not_std::bitset<1000> bs;
        bs.set();
        for(u_int i = 0; i < 1000; i+=3) {
            bs.reset(i);
        }

        unit_test(bs.count() == 666, "alternate_bits_reset: 334 bits should be reset when resetting every third bit"); });

    REGISTER_TEST(bitset_tests, []()
                  {
        not_std::bitset<128> bs;
        bs.set(0).set(63).set(64).set(127);
        unit_test(bs.count() == 4, "border_bits_set: bitset should have 4 bits set");
        bs.flip();
        unit_test(bs.count() == 124, "border_bits_flip: bitset should have 124 bits set after flipping"); });

    REGISTER_TEST(bitset_tests, []()
                  {
        not_std::bitset<128> bs;
        bs.set(); 
        unit_test(bs.all() == true, "all_set: all() should return true when all bits are set");

        bs.reset(3); 
        unit_test(bs.all() == false, "all_not_set: all() should return false when a bit is reset"); });

    REGISTER_TEST(bitset_tests, []()
                  {
        not_std::bitset<128> bs;
        bs.reset(); 
        unit_test(bs.any() == false, "none_set: any() should return false when no bits are set");

        bs.set(3); 
        unit_test(bs.any() == true, "some_set: any() should return true when at least one bit is set"); });

    REGISTER_TEST(bitset_tests, []()
                  {
        not_std::bitset<128> bs;
        bs.reset();
        unit_test(bs.none() == true, "none_set: none() should return true when no bits are set");

        bs.set(3); 
        unit_test(bs.none() == false, "some_set: none() should return false when at least one bit is set"); });

    REGISTER_TEST(bitset_tests, []()
                  {
        not_std::bitset<128> bs1; 
        not_std::bitset<128> bs2;
        not_std::bitset<128> result;

        bs1.set(3).set(5).set(127);
        bs2.set(5).set(127).set(64);

        result = bs1 & bs2;
        unit_test(result[3] == false, "bitwise_and: 3rd position should be false after &");
        unit_test(result[5] == true, "bitwise_and: 5th position should be true after &");
        unit_test(result[64] == false, "bitwise_and: 64th position should be false after &");
        unit_test(result[127] == true, "bitwise_and: 127th position should be true after &");

        result = bs1 | bs2;
        unit_test(result[3] == true, "bitwise_or: 3rd position should be true after |");
        unit_test(result[5] == true, "bitwise_or: 5th position should be true after |");
        unit_test(result[64] == true, "bitwise_or: 64th position should be true after |");
        unit_test(result[127] == true, "bitwise_or: 127th position should be true after |");

        result = bs1 ^ bs2;
        unit_test(result[3] == true, "bitwise_xor: 3rd position should be true after ^");
        unit_test(result[5] == false, "bitwise_xor: 5th position should be false after ^");
        unit_test(result[64] == true, "bitwise_xor: 64th position should be true after ^");
        unit_test(result[127] == false, "bitwise_xor: 127th position should be false after ^");

        bs1 &= bs2;
        unit_test(bs1[5] == true, "bitwise_and_assign: 5th position should be true after &=");
        unit_test(bs1[3] == false, "bitwise_and_assign: 3rd position should be false after &=");
        
        bs1.set(3).set(5).set(127);
        bs1 |= bs2;
        unit_test(bs1[64] == true, "bitwise_or_assign: 64th position should be true after |=");
        unit_test(bs1[3] == true, "bitwise_or_assign: 3rd position should be true after |=");
        
        bs1.set(3).set(5).set(127);
        bs1 ^= bs2;
        unit_test(bs1[5] == false, "bitwise_xor_assign: 5th position should be false after ^=");
        unit_test(bs1[3] == true, "bitwise_xor_assign: 3rd position should be true after ^=");

        result = ~bs1;
        unit_test(result[3] == false, "bitwise_not: 3rd position should be false after ~");
        unit_test(result[5] == true, "bitwise_not: 5th position should be true after ~"); });
}
