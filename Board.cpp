#include "Board.hpp"
using namespace std;

  namespace ariel{

    bool not_empty(string ad){
        bool ans = false;
        for(unsigned int i=0; i < ad.length(); i++){
            if(ad.at(i) != '_'){
                ans = true;
                break;
            }
        }
        return ans;
    }

    void Board::post(unsigned int row, unsigned int column, Direction Direct , string ad){
        if(not_empty(ad)){   

            if(Direct==Direction::Vertical) {
                unsigned int start_r=row;
                for(unsigned int i=0; start_r<row+ad.size(); i++){
                    this->board[start_r][column] = ad.at(i);
                    start_r++;
                }
            }

            if(Direct==Direction::Horizontal){
                unsigned int start_c = column;
                for(unsigned int i=0; start_c < column+ad.size(); i++){
                    this->board[row][start_c] = ad.at(i);
                    start_c++;
                }
            }
        }
    }


    string Board::read(unsigned int row, unsigned int column, Direction Direct, unsigned int ad_length){
         if(this->end_row > row)  {
                end_row = row;
        }
        if(this->end_column < column) {
           end_column = column;
        }

        string ad;
        if(Direct == Direction::Horizontal){
            unsigned int start_c =column;
            while(start_c<ad_length+column){
               
                if(board[row][start_c].empty()){
                    ad += "_";
                }
                else {
                    ad += board[row][start_c];
                }
                start_c++;
           }
       }
        
        else if(Direct==Direction::Vertical){
            unsigned int start_r =row;
            while(start_r<ad_length+row){
                
                if(board[start_r][column].empty()){
                    ad += "_";
                }
                else {
                    ad += board[start_r][column];
                }
                start_r++;
           } 
       }
       return ad;
}

    void Board::show(){
       for(unsigned int i=0; i < this->end_row; i++){
           for(unsigned int j=0; j < this->end_column; j++){
               if(this->board[i][j].empty()){
                   cout << '_';
               }
               else{
                   cout << this->board[i][j];
               }
           }
           cout << endl; //downline
        } 
    }
}