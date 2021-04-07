#include <string>
#include <map>
#include "Direction.hpp"
#include <iostream>
#include <stdbool.h>

namespace ariel{
    class Board{
        private:
        std::map<uint,std::map<uint,std::string>> board;
        uint end_row=0;
        uint end_column=0;
        public:
            Board(){ //constructor (empty)
            
         }
            void post(unsigned int row, unsigned int column, Direction Direct , const std::string ad);

            std::string read(unsigned int row, unsigned int column, Direction Direct, unsigned int ad_length);

            void show();
    };
}