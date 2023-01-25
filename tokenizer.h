#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <string>
#include <vector>

class Tokenizer {
   public:
    std::vector<std::string> tokenize(std::string expression);
};

#endif  // TOKENIZER_H