/* Takes a sudoku matrix and checks wether is a suitable solution or not */ 

#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

const unsigned sizeSudoku=9;

bool rowsAreOk(const unsigned sudoku[][sizeSudoku]);
bool colsAreOk(const unsigned sudoku[][sizeSudoku]);
bool areasAreOk(const unsigned sudoku[][sizeSudoku]);

bool arrayIsOk(unsigned v[sizeSudoku]);

bool sudokuIsOk(const unsigned sudoku[][sizeSudoku]);

int main(){

    unsigned sudokuToCheck[sizeSudoku][sizeSudoku]={
                    {6,7,3,9,8,4,5,2,1},
                    {1,8,9,5,6,2,7,3,4},
                    {4,5,2,7,1,3,6,9,8},
                    {7,2,8,1,4,6,9,5,3},
                    {5,9,4,8,3,7,2,1,6},
                    {3,6,1,2,9,5,4,8,7},
                    {8,1,7,6,2,9,3,4,5},
                    {2,3,5,4,7,8,1,6,9},
                    {9,4,6,3,5,1,8,7,2}
    };

    if(sudokuIsOk(sudokuToCheck)){
        cout<< "The solution is correct" << endl;
        return 1;
    }else{
        cout<< "The solution is NOT correct"<<endl;
       
    }
     return -1;

}


bool sudokuIsOk(const unsigned sudoku[][sizeSudoku]){
    return rowsAreOk(sudoku) && colsAreOk(sudoku) && areasAreOk(sudoku);
}

bool rowsAreOk(const unsigned sudoku[][sizeSudoku]){
    unsigned v[sizeSudoku];
    for(int i=0; i<sizeSudoku; ++i){
        for(int j=0;j<sizeSudoku;++j){
            v[j]=sudoku[i][j];
        }
        if(!arrayIsOk(v)){
            cout<<"row "<< i<< " not ok"<<endl;
            return false;
        }
    }
return true;

}

bool colsAreOk(const unsigned sudoku[][sizeSudoku]){
    unsigned v[sizeSudoku];
    for(int j=0; j<sizeSudoku; ++j){
        for(int i=0;i<sizeSudoku;++i){
            v[i]=sudoku[i][j];
        }
        if(!arrayIsOk(v)){
            cout<<"col "<< j<< " not ok"<<endl;
            return false;
        }
    }
return true;

}

bool areasAreOk(const unsigned sudoku[][sizeSudoku]){
    unsigned rootSize=sqrt(sizeSudoku);
    unsigned v[sizeSudoku];
    unsigned ind;

    
    for(unsigned rAreas=0; rAreas<rootSize; ++rAreas){
         for(unsigned kAreas=0; kAreas<rootSize; ++kAreas){
            ind=0;
            for(unsigned r=0; r<rootSize;++r){
                for(unsigned k=0;k<rootSize;++k){
                    
                v[ind++]=sudoku[rootSize*rAreas+r][rootSize*kAreas+k];
                }

            }
            if(!arrayIsOk(v)){
                cout<<"area ("<< rAreas<< " "<< kAreas<< ") not ok"<<endl;
                return false;}

        }


    }

    return true;

}

bool arrayIsOk(unsigned v[sizeSudoku]){
    sort(v,v+sizeSudoku);
    for(unsigned i=0; i<sizeSudoku;i++){
        if(i+1 != v[i]){return false;}
    }
    return true;
}