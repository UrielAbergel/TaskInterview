//
// Created by uriel on 06/08/2020.
//

#include "Pictrue.h"
#include <iostream>
using namespace std;

template<typename T>
T& Pictrue<T>::operator[](std::pair<int, int> location) {
    return this->_Pic.at(location.first).at(location.second);
}

template<typename T>
T Pictrue<T>::operator[](std::pair<int, int> location) const {
    return this->_Pic.at(location.first).at(location.second);
}

template<typename T>
void Pictrue<T>::draw_A_line(int x1, int y1, int x2, int y2 ,T value) {
    if(x1 >= _cols || x2 >=_cols || x1 < 0 || x2 < 0) throw out_of_range("x1 | x2 not in range");
    if(y1 >= _rows || y2 >=_rows || y1 < 0 || y2 < 0) throw out_of_range("y1 || y2 not in range");
    int m_new = 2 * (y2 - y1);
    int slope_error_new = m_new - (x2 - x1);
    for (int x = x1, y = y1; x <= x2; x++)
    {
        this->_Pic.at(y).at(x) = value ;

        // Add slope to increment angle formed
        slope_error_new += m_new;

        // Slope error reached limit, time to
        // increment y and update slope error.
        if (slope_error_new >= 0)
        {
            y++;
            slope_error_new  -= 2 * (x2 - x1);
        }
    }

    cout << "====================="  << endl;
}

template<typename T>
void Pictrue<T>::displayPic() {
    for (int i = 0; i <this->_rows ; ++i) {
        for (int j = 0; j < this->_cols; ++j) {
            cout << this->_Pic.at(i).at(j);
        }
        cout << "\n" ;
    }
}