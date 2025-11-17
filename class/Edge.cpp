#include "Edge.h"

// Constructor
Edge::Edge(const Point& src, const Point& dest, double w)
    : source(src), destination(dest), weight(w) {}

// Getters
Point Edge::getSource() const {
    return source;
}

Point Edge::getDestination() const {
    return destination;
}

double Edge::getWeight() const {
    return weight;
}

// Operator overloading
bool Edge::operator<(const Edge& other) const {
    if (source < other.source) return true;
    if (other.source < source) return false;
    return destination < other.destination;
}