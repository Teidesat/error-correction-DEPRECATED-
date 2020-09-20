//
// Created by jsier on 19/09/2020.
//

#ifndef TSAT_TC_CMATRIX_H
#define TSAT_TC_CMATRIX_H

#include <type_traits>
#include <stdexcept>
#include <iostream>
#include <iomanip>
#include <iostream>


template<class T>
class CMatrix { // Column first in memory matrix for faster access in same column
public:

    class Row {
    public:
        Row(T* data, size_t rows, size_t row)
            : rows(rows)
            , row(row)
            , data(data)
        {}
        const T& operator[](size_t col) const {
            return data[col * rows + row];
        }
        T& operator[](size_t col) {
            return data[col * rows + row];
        }
    private:
        size_t rows;
        size_t row;
        T* data;
    };

    CMatrix(size_t rows, size_t cols)
            : rows(rows)
            , cols(cols)
            , data(nullptr)
    {
        data = (T*)malloc(rows * cols * sizeof(T));
    }

    CMatrix(size_t rows, size_t cols, const T& value)
        : rows(rows)
        , cols(cols)
        , data(nullptr)
    {
        data = (T*)malloc(rows * cols *  sizeof(T));
        for (size_t i = 0; i < rows * cols; ++i) // TODO it could be possible to have a faster implementation (calloc, memset, etc, std::fill)
            data[i] = value;
    }

    ~CMatrix() {
        free(data);
    }

    size_t getRows() {
        return rows;
    }

    size_t getCols() {
        return cols;
    }

    Row operator[](size_t row) const {
        return Row(data, rows, row);
    }

    Row operator[](size_t row) {
        return Row(data, rows, row);
    }

private:
    size_t rows;
    size_t cols;
    T *data;

    friend std::ostream& operator<<(std::ostream &os, const CMatrix& m) {
        for (size_t row = 0; row < m.rows; ++row) {
            for (size_t col = 0; col < m.cols; ++col) {
                os << std::setw(5) << m[row][col] << ' ';
            }
            os << '\n';
        }
        return os;
    }
};


#endif //TSAT_TC_CMATRIX_H
