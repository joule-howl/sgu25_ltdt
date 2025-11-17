#ifndef EDGE_H
#define EDGE_H

#include "Point.h"

class Edge {
private:
    Point source;
    Point destination;
    double weight; // Trọng số của cạnh

public:
    // Constructor với trọng số mặc định 0.0
    Edge(const Point& src, const Point& dest, double w = 0.0);

    // Getters
    Point getSource() const;
    Point getDestination() const;
    double getWeight() const;

    // Operator overloading
    bool operator<(const Edge& other) const;
};

#endif // EDGE_H