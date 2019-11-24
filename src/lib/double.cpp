#include <sstream>

#include "double.h"

using namespace lr4;

bool Double::operator==(const Double &other) const {
    return abs(*this - other).value < EPSILON;
}

Double Double::operator-(const Double &other) const {
    return {value - other.value};
}

Double Double::operator-() const {
    return {-this->value};
}

Double Double::operator+(const Double &other) const {
    return {value + other.value};
}

Double Double::operator*(const Double &other) const {
    return {value * other.value};
}

Double Double::operator^(const Double &exponent) const {
    return {pow(value, exponent.value)};
}

Double Double::operator/(const Double &other) const {
    return {value / other.value};
}

Double lr4::abs(const Double &num) {
    return {fabs(num.value)};
}

std::istream &lr4::operator>>(std::istream &stream, Double &num) {
    stream >> num.value;
    return stream;
}

std::ostream &lr4::operator<<(std::ostream &stream, const Double &num) {
    stream << num.value;
    return stream;
}
