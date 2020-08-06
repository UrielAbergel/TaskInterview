//
// Created by uriel on 06/08/2020.
//

#ifndef TASKINTERVIEW_PICTRUE_H
#define TASKINTERVIEW_PICTRUE_H

#include <cstdint>
#include "vector"


using namespace std;


struct RGB {
    uint8_t red, green, blue;
public:
    RGB(): red(0), green(0), blue(0) {}
    RGB(uint8_t red, uint8_t green, uint8_t blue): red(red), green(green), blue(blue) {}
};

template<typename T = unsigned char>
class Pictrue {

private:
   vector<vector<T>> _Pic ;
   unsigned int _rows;
   unsigned int _cols;

public:
    Pictrue(unsigned row ,unsigned cols,const vector<vector<T>> pic): _rows(row),_cols(cols),_Pic(row, std::vector<T>(cols))
    {
        _Pic = pic; // the operator = is deep copy in vector class
    }

    virtual ~Pictrue()
    {

    }

    T& operator[](std::pair<int,int> location);

    T operator[](std::pair<int,int> location) const;

    void draw_A_line(int x1 ,int y1 ,int x2,int y2 , T value);

    void displayPic();






};




#endif //TASKINTERVIEW_PICTRUE_H
