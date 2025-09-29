#include "decimal.h"
#include <gtest/gtest.h>

TEST(DecimalConstructorTest, StringConstructor) {
  Decimal d("123");
  Decimal expected("123");
  EXPECT_TRUE(equals(d, expected));
}

TEST(DecimalConstructorTest, EmptyConstructor) {
    Decimal d;
    EXPECT_EQ(d.get_size(), 0);
}

TEST(DecimalArithmeticTest, SubtractionNegativeResult) {
    Decimal d1("5");
    Decimal d2("10");
    Decimal res = sub(d1, d2);
    EXPECT_TRUE(equals(res, Decimal("0")));
}

TEST(DecimalArithmeticTest, SubtractionPositiveResult) {
    Decimal d1("10");
    Decimal d2("5");
    Decimal res = sub(d1, d2);
    EXPECT_TRUE(equals(res, Decimal("5")));
}

TEST(DecimalArithmeticTest, AdditionCheck) {
    Decimal d1("1000");
    Decimal d2("123");
    Decimal res = plus(d1, d2);
    EXPECT_TRUE(equals(res, Decimal("1123")));
}

TEST(DecimalComparisonTest, Comparisons) {
    Decimal zero("0");
    Decimal one("1");
    
    EXPECT_TRUE(equals(zero, zero));
    EXPECT_TRUE(less(zero, one));
    EXPECT_TRUE(greater(one, zero));
    EXPECT_FALSE(less(one, zero));
    EXPECT_FALSE(greater(zero, one));
}

TEST(DecimalCopyTest, CopyConstructor) {
    Decimal original("12345");
    Decimal copy(original);
    
    EXPECT_TRUE(equals(copy, original));
    EXPECT_TRUE(equals(original, Decimal("12345")));
}

TEST(DecimalInitializerListTest, InitializerListConstructor) {
    Decimal d{1, 2, 3, 4, 5};
    Decimal expected("12345");
    EXPECT_TRUE(equals(d, expected));
}

TEST(DecimalMoveTest, MoveConstructor) {
    Decimal original("12345");
    Decimal moved = static_cast<Decimal&&>(original);
    
    EXPECT_TRUE(equals(moved, Decimal("12345")));
    EXPECT_EQ(original.get_size(), 0);
}