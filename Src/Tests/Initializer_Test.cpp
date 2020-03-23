#include <gtest/gtest.h>
#include "../Initializer/Initializer.cpp"

class Initializer_Test:public testing::Test{
 protected:
  virtual void TearDown() {

  }
  virtual void SetUp() {

  }

  Initializer initializer;


};

