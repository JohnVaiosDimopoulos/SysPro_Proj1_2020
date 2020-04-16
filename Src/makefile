.SUFFIXES: .cpp .o
CC = g++
FLAGS = -std=c++11
OBJDIR = object_files
vpath %.cpp main Argument_Data Argument_Manager AVL_Tree Command_Reader Date Hash_Table Hash_Bucket_Node Initializer Max_Heap Max_heap_node  Patients_List Patient_Record System_Commands/Disease_Frequency System_Commands/Global_Disease System_Commands/Insert_Patient_Record System_Commands/Num_Current_Patients System_Commands/Record_Patient_Exit System_Commands/TopK_Countries System_Commands/TopK_Diseases System_Data Tokenizer
OUT = diseaseMonitor
OBJ = $(addprefix $(OBJDIR)/,Argument_Data.o Argument_Manager.o AVL_Tree.o AVL_Tree_Node.o Command_Reader.o Date.o Hash_Table.o Hash_Bucket_Node.o Initializer.o Max_Heap.o Max_heap_node.o Patients_List.o Patient_Record.o Disease_Frequency.o Global_Disease.o Insert_Patient_Record.o Num_Current_Patients.o Record_Patient_Exit.o TopK_Countries.o TopK_Diseases.o System_Data.o Tokenizer.o main.o)

make: make_dir $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(OUT)

$(OBJDIR)/%.o : %.cpp
	$(CC) $(CFLAGS) -c $< -o $@ 

make_dir:
	mkdir $(OBJDIR)

clean:
	rm $(OBJDIR)/*.o
	rmdir $(OBJDIR)