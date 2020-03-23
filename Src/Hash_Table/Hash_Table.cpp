#include "Hash_Table.h"
//==CONSTRUCTOR-DESTRUCTOR==//

Hash_Table::Hash_Table(int table_size, int bucket_size) : table_size(table_size), bucket_size(bucket_size) {
  this->table = new Generic_List<Hash_Bucket_Node>[table_size];
}

Hash_Table::~Hash_Table() {
 delete table;
}

//==PRIVATE-FUNCTIONS==//
unsigned int Hash_Table::hash_fun(std::string& name) {
  //SAX hash function for strings

  unsigned int hash_value = 0;
  for(int i=0;i<name.length();i++){
    hash_value ^=(hash_value<<5)+(hash_value>>2)+name[i];
  }
  return hash_value%table_size;
}

void Hash_Table::insert_new(list_node<Patient_Record> *node, std::string name, Generic_List<Hash_Bucket_Node> bucket) {
  if (bucket.get_tail()->get_data().is_full())
    bucket.insert_node(Hash_Bucket_Node{bucket_size});
  bucket.get_tail()->get_data().insert(node, name);
}

int Hash_Table::find_element_in_table(std::string &name, Generic_List<Hash_Bucket_Node> bucket) {
  for(int i =0;i<bucket.num_of_nodes;i++){
    if(bucket[i].is_in_table(name))
      return i;
  }
  return -1;
}

void Hash_Table::insert_date(list_node<Patient_Record> *node,std::string &name,Generic_List<Hash_Bucket_Node> bucket) {
  bucket[find_element_in_table(name, bucket)].insert_date(node,name);
}


//==API==//
void Hash_Table::insert(list_node<Patient_Record> *node,std::string name){
  //get hash
  unsigned int hash_value = hash_fun(name);

  //check if element is already in table
  if(find_element_in_table(name, table[hash_value]) != -1)
    insert_date(node, name, table[hash_value]);
  else
    insert_new(node, name, table[hash_value]);
}





