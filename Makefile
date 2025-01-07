#TODO: Add Support for windows and linux and also fix macos issues
CXX=clang++
CXXFLAGS=-fPIC -std=c++20
LLVM_DIR=/usr/local/opt/llvm
CLANG_DIR=$(LLVM_DIR)/tools/clang
LLVM_INCLUDE_DIRS=$(LLVM_DIR)/include
CLANG_INCLUDE_DIRS=$(CLANG_DIR)/include
LLVM_LIB_DIR=$(LLVM_DIR)/lib
CLANG_LIBS=-lLLVMX86CodeGen -lLLVMExecutionEngine -lLLVMAsmPrinter -lLLVMAnalysis -lLLVMCore -lLLVMSupport -lclangFrontend -lclangAST -lclangBasic -lclangDriver -lclangFrontendTool -lclangLex -lclangParse -lclangSema
SRC=CNoCurseWords.cpp
OBJ=$(SRC:.cpp=.o)
OUTPUT=libCNoCurseWords.dylib
all:$(OUTPUT)
$(OUTPUT):$(OBJ)
	$(CXX) -shared -o $@ $(OBJ) -L$(LLVM_LIB_DIR) $(CLANG_LIBS)
$(OBJ):$(SRC)
	$(CXX) $(CXXFLAGS) -I$(LLVM_INCLUDE_DIRS) -I$(CLANG_INCLUDE_DIRS) -c $(SRC) -o $(OBJ)
clean:
	rm -f $(OBJ) $(OUTPUT)
.PHONY:all clean

