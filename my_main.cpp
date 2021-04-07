#include "Board.hpp"
using ariel::Board;
using ariel::Direction;
using namespace std;
//Horizontal, Vertical
		
// A short program that uses a board object and its functions

int main(){
    Board b;
    b.show();
    
    b.post(15,15,Direction::Horizontal,"def");
    b.show();

    return 0;
}