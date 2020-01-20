include makeutil.mak

TOP_DIR=../
OBJ_DIR = $(TOP_DIR)makefiles/obj
ELF_DIR = $(TOP_DIR)makefiles/bin


#-----------------------------------------------------------------------------
.SILENT:
  TEA = 2>&1 | tee _$@-comp.err

all: test2
	$(ECHO) "    All done.\n"

test2:
	$(ECHO) "    ARM STM32L467 Demo rom image building started:"
	$(MKDIR) ./$(OBJ_DIR)
	$(MKDIR) ./$(ELF_DIR)
	make -f make_demo TOP_DIR=$(TOP_DIR) OBJ_DIR=$(OBJ_DIR) ELF_DIR=$(ELF_DIR) $@ $(TEA)
