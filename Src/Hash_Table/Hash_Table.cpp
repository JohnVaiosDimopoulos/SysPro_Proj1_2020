#include "Hash_Table.h"
//==CONSTRUCTOR-DESTRUCTOR==//

Hash_Table::Hash_Table(int table_size, int bucket_size) : table_size(table_size), bucket_size(bucket_size) {
  this->table = new Generic_List<Hash_Bucket_Node*>[table_size];
}

Hash_Table::~Hash_Table() {
  delete[] table;
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

void Hash_Table::insert_new(list_node<Patient_Record> *node, std::string name, Generic_List<Hash_Bucket_Node*>* bucket) {
  if (bucket->get_tail() == NULL||bucket->get_tail()->get_data()->is_full())
    bucket->insert_node(new Hash_Bucket_Node{bucket_size});
  bucket->get_tail()->get_data()->insert(node, name);
}

int Hash_Table::find_element_in_table(std::string &name, Generic_List<Hash_Bucket_Node*>* bucket) {
  for(int i =0;i<bucket->num_of_nodes;i++){
    if(bucket[0][i]->is_in_table(name))
      return i;
  }
  return -1;
}

void Hash_Table::insert_date(list_node<Patient_Record> *node,std::string &name,Generic_List<Hash_Bucket_Node*>* bucket) {
  (*bucket)[find_element_in_table(name, bucket)]->insert_date(node,name);
}


//==API==//
void Hash_Table::insert(list_node<Patient_Record> *node,std::string name){
  //get hash
  unsigned int hash_value = hash_fun(name);

  //check if element is already in table
  if(find_element_in_table(name, &table[hash_value]) != -1)
    insert_date(node, name, &table[hash_value]);
  else
    insert_new(node, name, &table[hash_value]);
}

//==Commands==//

void Hash_Table::num_current_patients() {

  for(int i = 0;i<table_size;i++){
    for(int j =0;j<table[i].get_num_of_nodes();j++){
      for(int k =0;k<table[i][j]->get_num_of_elements();k++){
        int num = table[i][j]->get_elements()[k].date_tree.num_of_current_Patients();
        std::cout<< table[i][j]->get_elements()[k].name<<" "<<num<<std::endl;
      }
    }
  }
}

void Hash_Table::num_current_patients(std::string disease) {
  int hash_value = hash_fun(disease);

  for(int i = 0;i<table[hash_value].get_num_of_nodes();i++){
    for(int j=0;j<table[hash_value][i]->get_num_of_elements();j++){
      if(table[hash_value][i]->get_elements()[j].name == disease){
        int num = table[hash_value][i]->get_elements()[j].date_tree.num_of_current_Patients();
        std::cout<<table[hash_value][i]->get_elements()[j].name<<" "<<num<<std::endl;
        return;
      }
    }
  }

  std::cout<<"The disease was not found"<<std::endl;


}

void Hash_Table::global_disease_stats() {

  for(int i =0;i<table_size;i++){
    for(int j=0;j<table[i].get_num_of_nodes();j++){
      for(int k=0;k<table[i][j]->get_num_of_elements();k++){
        int num = table[i][j]->get_elements()[k].date_tree.get_num_of_nodes();
        std::cout<< table[i][j]->get_elements()[k].name<<" "<<num<<std::endl;
      }
    }
  }
}

void Hash_Table::global_disease_stats(Date start, Date end) {

  for(int i =0;i<table_size;i++){
    for(int j=0;j<table[i].get_num_of_nodes();j++){
      for(int k=0;k<table[i][j]->get_num_of_elements();k++){
        int num = table[i][j]->get_elements()[k].date_tree.global_disease_num(start, end);
        std::cout<< table[i][j]->get_elements()[k].name<<" "<<num<<std::endl;
      }
    }
  }

}

void Hash_Table::diseaseFrequency(std::string virus, Date start, Date end) {
  int hash_value = hash_fun(virus);

  for(int i = 0;i<table[hash_value].get_num_of_nodes();i++){
    for(int j=0;j<table[hash_value][i]->get_num_of_elements();j++){
      if(table[hash_value][i]->get_elements()[j].name == virus){
        int num = table[hash_value][i]->get_elements()[j].date_tree.global_disease_num(start,end);
        std::cout<<table[hash_value][i]->get_elements()[j].name<<" "<<num<<std::endl;
      }
    }
  }
}

void Hash_Table::diseaseFrequency(std::string virus, Date start, Date end, std::string country) {
  int hash_value = hash_fun(virus);

  for(int i = 0;i<table[hash_value].get_num_of_nodes();i++){
    for(int j=0;j<table[hash_value][i]->get_num_of_elements();j++){
      if(table[hash_value][i]->get_elements()[j].name == virus){
        int num = table[hash_value][i]->get_elements()[j].date_tree.global_disease_num(start,end,country);
        std::cout<<table[hash_value][i]->get_elements()[j].name<<" "<<num<<std::endl;
      }
    }
  }

}

void Hash_Table::topk_diseases(int k, std::string country) {
  int hash_value = hash_fun(country);

  for(int i = 0;i<table[hash_value].get_num_of_nodes();i++){
    for(int j = 0;j<table[hash_value][i]->get_num_of_elements();j++){
      if(table[hash_value][i]->get_elements()[j].name == country){
        Max_Heap* heap = table[hash_value][i]->get_elements()[j].date_tree.get_topk_diseases_heap();
        heap->Print_Max_K(k);
        delete heap;
      }
    }
  }
}

void Hash_Table::topk_diseases(int k, std::string country, Date start, Date end) {
  int hash_value = hash_fun(country);

  for(int i = 0;i<table[hash_value].get_num_of_nodes();i++){
    for(int j = 0;j<table[hash_value][i]->get_num_of_elements();j++){
      if(table[hash_value][i]->get_elements()[j].name == country){
        Max_Heap* heap = table[hash_value][i]->get_elements()[j].date_tree.get_topk_diseases_heap(start, end);
        heap->Print_Max_K(k);
        delete heap;

      }
    }
  }
}

void Hash_Table::topk_countries(int k, std::string disease) {
  int hash_value = hash_fun(disease);

  for(int i = 0;i<table[hash_value].get_num_of_nodes();i++){
    for(int j = 0;j<table[hash_value][i]->get_num_of_elements();j++){
      if(table[hash_value][i]->get_elements()[j].name == disease){
        Max_Heap* heap = table[hash_value][i]->get_elements()[j].date_tree.get_topk_countries_heap();
        heap->Print_Max_K(k);
        delete heap;
      }
    }
  }

}

void Hash_Table::topk_countries(int k, std::string disease, Date start, Date end) {
  int hash_value = hash_fun(disease);

  for(int i = 0;i<table[hash_value].get_num_of_nodes();i++){
    for(int j = 0;j<table[hash_value][i]->get_num_of_elements();j++){
      if(table[hash_value][i]->get_elements()[j].name == disease){
        Max_Heap* heap = table[hash_value][i]->get_elements()[j].date_tree.get_topk_countries_heap();
        heap->Print_Max_K(k);
        delete heap;
      }
    }
  }

}







