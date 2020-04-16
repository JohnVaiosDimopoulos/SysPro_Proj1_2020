#include "Command_Reader.h"
#include "../System_Commands/Global_Disease/Global_Disease.h"
#include "../System_Commands/Disease_Frequency/Disease_Frequency.h"
#include "../System_Commands/TopK_Diseases/TopK_Diseases.h"
#include "../System_Commands/TopK_Countries/TopK_Countries.h"
#include "../System_Commands/Record_Patient_Exit/Record_Patient_Exit.h"
#include "../System_Commands/Num_Current_Patients/Num_Current_Patients.h"
#include "../System_Commands/Insert_Patient_Record/Insert_Patient_Record.h"

void Command_Reader::start_reading(System_Data *system_data) {


  std::string command;
  bool system_working= true;
  while (system_working){
    std::cout<<"Please give command"<<std::endl;
    std::getline(std::cin,command);

    Generic_List<std::string> tokenized_command = tokenizer.tokenize_command(command);


    if(tokenized_command[0] == "/globalDiseaseStats"){
      Global_Disease global_disease;
      global_disease.Execute_Command(system_data,&tokenized_command);

    }
    else if(tokenized_command[0] == "/diseaseFrequency"){
      Disease_Frequency disease_frequency;
      disease_frequency.Execute_Command(system_data,&tokenized_command);

    }
    else if(tokenized_command[0] == "/topk-Diseases"){
      TopK_Diseases topK_diseases;
      topK_diseases.Execute_Command(system_data,&tokenized_command);

    }
    else if(tokenized_command[0] == "/topk-Countries"){
      TopK_Countries topK_countries;
      topK_countries.Execute_Command(system_data,&tokenized_command);

    }
    else if(tokenized_command[0] == "/insertPatientRecord"){
      Insert_Patient_Record insert_patient_record;
      insert_patient_record.Execute_Command(system_data,&tokenized_command);
    }
    else if(tokenized_command[0] == "/recordPatientExit"){
      Record_Patient_Exit record_patient_exit;
      record_patient_exit.Execute_Command(system_data,&tokenized_command);
    }
    else if(tokenized_command[0] == "/numCurrentPatients"){
      Num_Current_Patients num_current_patients;
      num_current_patients.Execute_Command(system_data,&tokenized_command);
    }

    else if(tokenized_command[0]=="/exit")
      system_working= false;

  }
}
