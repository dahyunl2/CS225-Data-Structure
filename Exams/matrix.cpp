#include "matrix.h"
#include <iostream>
using namespace std;

exam::Matrix::Matrix(){

}
exam::Matrix::Matrix(int rows, int columns){

}
int exam::Matrix::get_coord(int rows, int columns) const{
    
}
void exam::Matrix::set_coord(int rows, int columns, int i){
    
}
int exam::Matrix::get_num_rows() const{
    return num_rows_;
}
int exam::Matrix::get_num_columns() const{
    return num_columns_;
}
void exam::Matrix::display(){
    for(int i=0;i<num_rows_;i++){
        for(int j=0;j<num_columns_;j++){
            if(j<num_columns_-1){
                std::cout<<get_coord(i,j)<<" ";
            }
            else{
                std::cout<<get_coord(i,j);
            }
        }
        std::cout<<"\n";
    }
}

void exam::Matrix::_copy(const Matrix & m){
    data_=m.data_;
    num_rows_=m.num_rows_;
    num_columns_=m.num_columns_;
}