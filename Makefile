DIR_IND = Inc
DIR_SRC = Src
DIR_OBJ = Obj
DIR_BUILD = Build

SRC = $(wildcard $(DIR_SRC)/*.c)
INC = $(wildcard $(DIR_IND)/*.h)
OBJ = $(patsubst $(DIR_SRC)%.c,$(DIR_OBJ)%.o,$(SRC))

Del = del

Target = $(DIR_BUILD)/main


all: createDir $(Target)

$(Target):$(OBJ) $(DIR_OBJ)/main.o
	gcc  $^ -o $@
	
$(DIR_OBJ)/%.o : $(DIR_SRC)/%.c 
	gcc $< -c -o $@ -I$(DIR_IND) 

$(DIR_OBJ)/main.o:main.c
	gcc  $< -c -o $@

clean:
	$(Del)  $(DIR_OBJ)\*.o
	$(Del)  $(DIR_BUILD)\*.exe
	

run:all
	$(DIR_BUILD)/./main
 
createDir:
	$(shell if not exist $(DIR_BUILD) mkdir $(DIR_BUILD))
	$(shell if not exist $(DIR_OBJ) mkdir $(DIR_OBJ))



