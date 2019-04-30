ASM = nasm
ASM_FLAGS = -felf64 -g -Icore/
LINKER = ld

all: bin/forthochka

bin/forthochka: objects/forthochka.o 
	mkdir -p bin
	$(LINKER) -o bin/forthochka $(LINKERFLAGS) -o bin/forthochka objects/forthochka.o $(LIBS)

objects/forthochka.o:	core/forthochka.asm core/macro.inc core/interpreter.inc core/forth-utils.inc 
	mkdir -p objects
	$(ASM) $(ASM_FLAGS) core/forthochka.asm -o objects/forthochka.o
clean:
	rm -rf bin objects

.PHONY: clean
