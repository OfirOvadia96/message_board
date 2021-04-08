#include "Board.hpp"
using namespace std;

  namespace ariel{

    void Board::update_size(unsigned int row , unsigned int column , unsigned int ad_length , Direction Direct ){
        
        if(Direct == Direction::Vertical) {
            
            if(this->end_row < row+ad_length)  {
                end_row = row+ad_length;
            }
            if(this->end_column < column) {
                end_column = column;
            }
        }

        else if(Direct==Direction::Horizontal){
            if(this->end_row < row)  {
                end_row = row;
            }
            if(this->end_column < column+ad_length) {
                end_column = column+ad_length;
            }
        }
    }

    void Board::post(unsigned int row, unsigned int column, Direction Direct , string ad){
        if(ad.length() > 0){   

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
            update_size(row, column , ad.length(), Direct); //update the board size
        }
        
    }


    string Board::read(unsigned int row, unsigned int column, Direction Direct, unsigned int ad_length){
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
        unsigned int k = 0;
       for(unsigned int i=0; i <= this->end_row; i++){
           for(unsigned int j=0; j <= this->end_column; j++){
               if(this->board[i][j].empty()){
                    cout << '_';
               }
               else{
                   cout << this->board[i][j].at(k);
               }
           }
           cout << endl; //downline
        }
    }
}