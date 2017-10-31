#include "PFAString.hpp"
#include "gtest/gtest.h"
#include <sstream>
#include <string>

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

TEST(Constructors, DefaultCtor) {
  PFAString myVector;
  EXPECT_EQ(myVector.get_capacity(), 0);
  EXPECT_EQ(myVector.get_size(), 0);
}
TEST(Constructors, CapacityCtor) {
  PFAString myVector(10);
  EXPECT_EQ(myVector.get_capacity(), 10);
  EXPECT_EQ(myVector.get_size(), 0);
}
TEST(Constructors, CapacityFillCtor) {
  const std::string PATTERN = "ABAD1DEA";
  PFAString myVector(10, PATTERN);

  EXPECT_EQ(myVector.get_capacity(), 10);
  EXPECT_EQ(myVector.get_size(), 10);

  for (int i = 0; i < myVector.get_size(); i++) {
    EXPECT_EQ(myVector[i], PATTERN);
  }
}
TEST(Constructors, CopyCtor) {
  PFAString myVector(10, "DEADBEEF");
  PFAString myCopy(myVector);

  EXPECT_EQ(myCopy.get_capacity(), myVector.get_size());
  EXPECT_EQ(myCopy.get_size(), myVector.get_size());

  for (int i = 0; i < myCopy.get_size(); i++) {
    EXPECT_EQ(myCopy[i], myVector[i]);
  }
}

TEST(Destructor, Verification) {
  // TODO: Figure out how to test this -- maybe valgrind?
}

TEST(Methods, GetCapacity) {
  PFAString myVector(10);
  EXPECT_EQ(myVector.get_capacity(), 10);
}
TEST(Methods, GetSize) {
  PFAString myVector;
  EXPECT_EQ(myVector.get_size(), 0);

  myVector.push_back("DA7ABA5E");
  EXPECT_EQ(myVector.get_size(), 1);
}
TEST(Methods, PushBack) {
  PFAString myVector;
  const std::string PATTERN = "DEFACE";
  myVector.push_back(PATTERN);
  EXPECT_EQ(myVector[0], PATTERN);
}
TEST(Methods, PopBack) {
  PFAString myVector;
  myVector.push_back("F007BA11");
  EXPECT_EQ(myVector.get_size(), 1);
  myVector.pop_back();
  EXPECT_EQ(myVector.get_size(), 0);
}
TEST(Methods, Resize) {
  PFAString myVector;
  myVector.resize(10);
  EXPECT_EQ(myVector.get_capacity(), 10);
}
TEST(Methods, ResizeWithFill) {
  PFAString myVector(5, "C0DE");
  myVector.resize(10, "DEAD");
  EXPECT_EQ(myVector.get_size(), 10);
  EXPECT_EQ(myVector.get_capacity(), 10);
  for (int i = 0; i < 10; i++) {
    if (i < 5) {
      EXPECT_EQ(myVector[i], "C0DE");
    } else {
      EXPECT_EQ(myVector[i], "DEAD");
    }
  }
}
TEST(Methods, EmptyArray) {
  const std::string PATTERN = "FACADE";
  PFAString myVector(10, PATTERN);

  myVector.empty_array();

  EXPECT_EQ(myVector.get_size(), 0);
  EXPECT_EQ(myVector.get_capacity(), 10);
}

TEST(Operators, Index) {
  const std::string PATTERN = "DECADE";
  PFAString myVector(10, PATTERN);

  for (int i = 0; i < myVector.get_size(); i++) {
    EXPECT_EQ(myVector[i], PATTERN);
  }
}
TEST(Operators, IndexLValue) {
  const std::string PATTERN1 = "BEFA11";
  const std::string PATTERN2 = "AFFEC7";
  PFAString myVector(10, PATTERN1);

  myVector[1] = PATTERN2;
  EXPECT_EQ(myVector[1], PATTERN2);
}
TEST(Operators, Assignment) {
  const std::string PATTERN = "A110C8D";
  PFAString myVector(10, PATTERN);

  PFAString myCopy;
  myCopy = myVector;

  EXPECT_EQ(myVector.get_capacity(), myCopy.get_capacity());
  EXPECT_EQ(myVector.get_size(), myCopy.get_size());

  for (int i = 0; i < myCopy.get_size(); i++) {
    EXPECT_EQ(myCopy[i], PATTERN);
  }
}
TEST(Operators, Equality) {
  const std::string PATTERN = "B100D";
  PFAString myVector(10, PATTERN);

  PFAString myCopy = myVector;

  EXPECT_TRUE(myVector == myCopy);
}
TEST(Operators, LTLength) {
  PFAString myVector1;
  PFAString myVector2;

  myVector1.push_back("Abacus");
  myVector1.push_back("Batman");
  myVector1.push_back("Conflagration");
  myVector1.push_back("Diagonilly");

  myVector2.push_back("Abacus");
  myVector2.push_back("Batman");
  myVector2.push_back("Conflagration");

  EXPECT_TRUE(myVector2 < myVector1);
}
TEST(Operators, LTContent) {
  PFAString myVector1;
  PFAString myVector2;

  myVector1.push_back("Abacus");
  myVector1.push_back("Batman");
  myVector1.push_back("Conflagration");
  myVector1.push_back("Diagonilly");

  myVector2.push_back("Abacus");
  myVector2.push_back("Batman");
  myVector2.push_back("Conflagration");
  myVector2.push_back("Dickus, Biggus");

  EXPECT_TRUE(myVector1 < myVector2);
}
TEST(Operators, GTLength) {
  PFAString myVector1;
  PFAString myVector2;

  myVector1.push_back("Abacus");
  myVector1.push_back("Batman");
  myVector1.push_back("Conflagration");
  myVector1.push_back("Dickus, Biggus");

  myVector2.push_back("Abacus");
  myVector2.push_back("Batman");
  myVector2.push_back("Conflagration");

  EXPECT_TRUE(myVector1 > myVector2);
}
TEST(Operators, GTContent) {
  PFAString myVector1;
  PFAString myVector2;

  myVector1.push_back("Abacus");
  myVector1.push_back("Batman");
  myVector1.push_back("Conflagration");
  myVector1.push_back("Diagonilly");

  myVector2.push_back("Abacus");
  myVector2.push_back("Batman");
  myVector2.push_back("Conflagration");
  myVector2.push_back("Dickus, Biggus");

  EXPECT_TRUE(myVector2 > myVector1);
}
TEST(Operators, LTELength) {
  PFAString myVector1;
  PFAString myVector2;

  myVector1.push_back("Abacus");
  myVector1.push_back("Batman");
  myVector1.push_back("Conflagration");
  myVector1.push_back("Diagonilly");

  myVector2.push_back("Abacus");
  myVector2.push_back("Batman");
  myVector2.push_back("Conflagration");

  EXPECT_TRUE(myVector2 <= myVector1);
}
TEST(Operators, LTEContent) {
  PFAString myVector1;
  PFAString myVector2;

  myVector1.push_back("Abacus");
  myVector1.push_back("Batman");
  myVector1.push_back("Conflagration");
  myVector1.push_back("Diagonilly");

  myVector2.push_back("Abacus");
  myVector2.push_back("Batman");
  myVector2.push_back("Conflagration");
  myVector2.push_back("Dickus, Biggus");

  EXPECT_TRUE(myVector1 <= myVector2);
}
TEST(Operators, LTEEqual) {
  PFAString myVector1;
  PFAString myVector2;

  myVector1.push_back("Abacus");
  myVector1.push_back("Batman");
  myVector1.push_back("Conflagration");
  myVector1.push_back("Diagonilly");

  myVector2.push_back("Abacus");
  myVector2.push_back("Batman");
  myVector2.push_back("Conflagration");
  myVector2.push_back("Diagonilly");

  EXPECT_TRUE(myVector2 <= myVector1);
}
TEST(Operators, GTELength) {
  PFAString myVector1;
  PFAString myVector2;

  myVector1.push_back("Abacus");
  myVector1.push_back("Batman");
  myVector1.push_back("Conflagration");
  myVector1.push_back("Dickus, Biggus");

  myVector2.push_back("Abacus");
  myVector2.push_back("Batman");
  myVector2.push_back("Conflagration");

  EXPECT_TRUE(myVector1 >= myVector2);
}
TEST(Operators, GTEContent) {
  PFAString myVector1;
  PFAString myVector2;

  myVector1.push_back("Abacus");
  myVector1.push_back("Batman");
  myVector1.push_back("Conflagration");
  myVector1.push_back("Diagonilly");

  myVector2.push_back("Abacus");
  myVector2.push_back("Batman");
  myVector2.push_back("Conflagration");
  myVector2.push_back("Dickus, Biggus");

  EXPECT_TRUE(myVector2 >= myVector1);
}
TEST(Operators, GTEEqual) {
  PFAString myVector1;
  PFAString myVector2;

  myVector1.push_back("Abacus");
  myVector1.push_back("Batman");
  myVector1.push_back("Conflagration");
  myVector1.push_back("Diagonilly");

  myVector2.push_back("Abacus");
  myVector2.push_back("Batman");
  myVector2.push_back("Conflagration");
  myVector2.push_back("Diagonilly");

  EXPECT_TRUE(myVector1 >= myVector2);
}

TEST(Expectations, AutoExpandBy2X) {
  PFAString myVector;
  const std::string PATTERN = "CAFEBABE";

  EXPECT_EQ(myVector.get_capacity(), 0);

  myVector.push_back(PATTERN);
  EXPECT_EQ(myVector.get_capacity(), 1);

  myVector.push_back(PATTERN);
  EXPECT_EQ(myVector.get_capacity(), 2);

  myVector.push_back(PATTERN);
  EXPECT_EQ(myVector.get_capacity(), 4);

  myVector.push_back(PATTERN);
  myVector.push_back(PATTERN);
  EXPECT_EQ(myVector.get_capacity(), 8);
}
TEST(Expectations, DieOnAccessViolation) {
  PFAString myVector(2);
  myVector.push_back("Test String");

  ASSERT_DEATH(myVector[8], "");
}
TEST(Expectations, NoNegitiveCapacities) {
  PFAString myVector;

  myVector.resize(-1);
  EXPECT_EQ(myVector.get_size(), 0);
}
TEST(Expectations, NoCapacityChangeOnNegitiveResize) {
  PFAString myVector(10, "");
  myVector.resize(1);

  EXPECT_EQ(myVector.get_capacity(), 10);
  EXPECT_EQ(myVector.get_size(), 1);
}
TEST(Expectations, NoCapacityChangeOnEmptyArray) {
  PFAString myVector(10, "");
  myVector.empty_array();

  EXPECT_EQ(myVector.get_capacity(), 10);
  EXPECT_EQ(myVector.get_size(), 0);
}