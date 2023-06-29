OBJ = compito.o tipo.o liste.o grafo.o
FINAL_TARGET = esame_prog2
CXXFLAG = -Wall

$(FINAL_TARGET): $(OBJ)
	g++ $(CXXFLAG) -o $(FINAL_TARGET) $(OBJ)
	./$(FINAL_TARGET) # Esecuzione diretta di $(FINAL_TARGET)

-include dependencies

.PHONY: depend clean cleanall
depend:
	@echo "Compiling Object Files..."
	g++ -MM *.cc > dependencies
clean:
	@echo "Cleaning up temporary files..."
	rm -f $(OBJ)
cleanall:
	@echo "Cleaning up all files..."
	rm -rf $(FINAL_TARGET) $(OBJ)
