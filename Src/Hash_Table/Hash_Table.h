
#ifndef PROJ_1_HASH_TABLE_H
#define PROJ_1_HASH_TABLE_H

#include "../Generic_List/Generic_List.h"
#include "../Patient_Record/Patient_Record.h"
#include "Hash_Bucket_Node.h"

class Hash_Table {
 private:
  int bucket_size;
  int table_size;
  Generic_List<Hash_Bucket_Node>* table;
  //==INNER-FUNCTIONS==//
  unsigned int hash_fun(std::string&);
  void insert_new(list_node<Patient_Record> *node, std::string name, Generic_List<Hash_Bucket_Node> bucket);
  static int find_element_in_table(std::string &name, Generic_List<Hash_Bucket_Node> bucket);
  static void insert_date(list_node<Patient_Record> *node,std::string &name,Generic_List<Hash_Bucket_Node> bucket);


    public:
  //==CONSTRUCTOR-DESTRUCTOR==//
  Hash_Table(int table_size,int bucket_size);
  virtual ~Hash_Table();
  //==API==//
  void insert(list_node<Patient_Record>* node,std::string name);

};

#endif //PROJ_1_HASH_TABLE_H
