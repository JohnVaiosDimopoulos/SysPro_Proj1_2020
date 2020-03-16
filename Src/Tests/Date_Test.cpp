#include <gtest/gtest.h>
#include "../Date/Date.cpp"

class Date_test: public testing:: Test{

 protected:
  Date* date1;
  Date* date2;
  Date* date3;
  Date* date4;
  Date* date5;
  virtual void TearDown() {
    delete date1;
    delete date2;
    delete date3;
    delete date4;
    delete date5;
  }

  virtual void SetUp() {
    date1 = new Date(2000,12,15);
    date2 = new Date(2001,12,3);
    date3 = new Date(1999,12,3);
    date4 = new Date(2000,12,16);
    date5 = new Date(2000,11,3);
  }

};



TEST_F(Date_test,test_comparizon){
  ASSERT_EQ(0,date1->compare_with_other_date(*date1));
  ASSERT_EQ(1,date1->compare_with_other_date(*date3));
  ASSERT_EQ(-1,date1->compare_with_other_date(*date2));
  ASSERT_EQ(1,date1->compare_with_other_date(*date5));
  ASSERT_EQ(-1,date1->compare_with_other_date(*date4));


}
