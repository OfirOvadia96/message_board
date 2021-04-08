#include "Board.hpp"
using ariel::Board;
using ariel::Direction;
using namespace std;
//Horizontal, Vertical
		
// A short program that uses a board object and its functions

int main(){
    Board b;
    //clean underlines for beauty:
    for(unsigned int i=0; i < 15; i++){
        for(unsigned int j=0; j < 40; j++){
            b.post(i,j,Direction::Horizontal," ");
        }
    }
    b.post(2,5,Direction::Horizontal,"This Is My Dynamic Board:");
    //"I Love C++":

    //I
    b.post(4,1,Direction::Horizontal,"___");
    b.post(5,2,Direction::Vertical,"||||");
    b.post(8,1,Direction::Horizontal,"---");
    //Love
    b.post(5,11,Direction::Vertical,"||||");
    b.post(8,12,Direction::Horizontal,"____");
    b.post(6,15,Direction::Vertical,"(");
    b.post(6,16,Direction::Vertical,"O");
    b.post(6,17,Direction::Vertical,")");
    b.post(5,20,Direction::Vertical,"\\");
    b.post(6,21,Direction::Vertical,"\\");
    b.post(7,22,Direction::Vertical,"\\");
    b.post(8,23,Direction::Vertical,"\\");
    b.post(8,24,Direction::Vertical,"/");
    b.post(7,25,Direction::Vertical,"/");
    b.post(6,26,Direction::Vertical,"/");
    b.post(5,27,Direction::Vertical,"/");
    b.post(5,32,Direction::Vertical,"||||");
    b.post(4,33,Direction::Horizontal,"___");
    b.post(6,33,Direction::Horizontal,"___");
    b.post(8,33,Direction::Horizontal,"___");
    //c++:
    b.post(11,2,Direction::Horizontal,"ccc");
    b.post(12,2,Direction::Horizontal,"ccc");
    b.post(13,2,Direction::Horizontal,"ccc");
    b.post(12,11,Direction::Horizontal,"---");
    b.post(11,10,Direction::Vertical,"|||");
    b.post(12,7,Direction::Horizontal,"---");
    b.post(12,20,Direction::Horizontal,"---");
    b.post(11,19,Direction::Vertical,"|||");
    b.post(12,16,Direction::Horizontal,"---");

    //can be expanded:
    string text = "expansion";
    b.post(15,15,Direction::Vertical,text);
    b.post(6,45,Direction::Horizontal,text);

    b.show(); //print the board
    
    //show how read function works:
    string ans1 = b.read(15 ,15, Direction::Vertical , text.length()); //need to be "expansion"
    string ans2 = b.read(6 ,45, Direction::Horizontal , text.length()); //need to be "expansion"
    if(ans1 == text && ans2 == text){
        cout << endl;
        cout << "function read works well" <<endl;
    }
    return 0;
}