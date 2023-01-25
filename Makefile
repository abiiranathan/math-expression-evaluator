all: main.cpp lexer.cpp parser.cpp tokenizer.cpp
	g++ -std=c++11 main.cpp lexer.cpp parser.cpp tokenizer.cpp