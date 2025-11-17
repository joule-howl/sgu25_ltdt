#include "Point.h"

// Constructor
Point::Point(int _id) : id(_id) {}

// Getters
int Point::getID() const {
    return id;
}

// Operator overloading (so sánh int thay vì string)
bool Point::operator<(const Point& other) const {
    return id < other.id;
}

bool Point::operator==(const Point& other) const {
    return id == other.id;
}