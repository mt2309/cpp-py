#include "parser/parser.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <string>


int main(int argc, char *argv[])
{
    if (argc == 1) {
        std::cerr << "Please specify at least one input file" << std::endl;
        return 1;
    }
    
    std::vector<std::string> files;
    
    for (int i = 1; i < argc; ++i)
    {
        files.emplace_back(argv[i]);
    }
    
    std::for_each(
                  files.begin(),
                  files.end(),
                  [](auto file) {
                      std::cout << "Parsing file: " << file << std::endl;
                      std::ifstream fileStream;
                      fileStream.open(file);
                      if (not fileStream.good())
                      {
                          std::cerr << "Could not open file: " << file << " for reading, skipping\n";
                          return;
                      }
                      
                      Parser::Parser parser(fileStream);
    });
    
    return 0;
}