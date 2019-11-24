#pragma once

#include <iostream>
#include <set>
#include <vector>
#include "config.h"

namespace lr4 {
    /**
     * Double - primitive double data type wrapper
     */
    template <typename T>
    class Matrix {
    public:
        Matrix(int width, int height) : width(width), height(height)
        {
            data = new T*[width];
            for (int i = 0; i < width; ++i) {
                data[i] = new T[height];
            }
        }

        bool operator==(const Matrix &other) const {
            for (int i = 0; i < width; ++i) {
                for (int j = 0; j < height; ++j) {
                    if (other.at(i, j) != other.at(i, j)) {
                        return false;
                    }
                }
            }
            return true;
        }

        T &at(int i, int j) {
            if (i >= width || j >= height) {
                throw std::runtime_error("array index out of bounds");
            }
            return data[i][j];
        }

        bool isLatinSquare() {
            if (width != height) {
                return false;
            }

            std::vector<std::set<T> > columnUsed (width);
            std::vector<std::set<T> > rowUsed (width);

            for (int i = 0; i < width; ++i) {
                for (int j = 0; j < width; ++j) {
                    if (columnUsed[j].count(at(i, j)) || rowUsed[i].count(at(i, j)) || at(i, j) > width || at(i, j) < 1) {
                        return false;
                    }
                    columnUsed[j].insert(at(i, j));
                    rowUsed[i].insert(at(i, j));
                }
            }

            return true;
        }

        ~Matrix() {
            for (int i = 0; i < width; ++i) {
                delete data[i];
            }
            delete data;
        }

        int width = 0;
        int height = 0;
        T **data = 0;
    };

    template <typename T>
    std::istream& operator>>(std::istream& stream, Matrix<T>& matrix) {
        for (int i = 0; i < matrix.width; ++i) {
            for (int j = 0; j < matrix.height; ++j) {
                stream >> matrix.at(i, j);
            }
        }
        return stream;
    }

    template <typename T>
    std::ostream& operator<<(std::ostream& stream, const Matrix<T>& matrix) {
        stream.width(COLUMN_WIDTH);
        for (int i = 0; i < matrix.width; ++i) {
            for (int j = 0; j < matrix.height; ++j) {
                stream << matrix.at(i, j);
            }
            stream << std::endl;
        }
        stream.width();
        return stream;
    }
}