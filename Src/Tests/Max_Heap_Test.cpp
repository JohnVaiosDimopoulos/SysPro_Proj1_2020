#include <gtest/gtest.h>
#include "../Max_heap/Max_Heap.cpp"
#include "../Max_heap/Max_heap_node.cpp"

class Max_Heap_Test:public testing::Test{
 protected:

  virtual void SetUp() {
    Heap=new Max_Heap();
  }

  virtual void TearDown() {
    delete Heap;
  }
  Max_Heap* Heap;
};

TEST_F(Max_Heap_Test,Heap_test){

  Heap->heap_insert({5,"6"});
  Heap->heap_insert({10,"1"});
  Heap->heap_insert({6,"5"});
  Heap->heap_insert({7,"4"});
  Heap->heap_insert({1,"10"});
  Heap->heap_insert({8,"3"});
  Heap->heap_insert({4,"7"});
  Heap->heap_insert({9,"2"});
  Heap->heap_insert({2,"9"});
  Heap->heap_insert({3,"8"});

  Heap->Print_Max_K(10);


}

