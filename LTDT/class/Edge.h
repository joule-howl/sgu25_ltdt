#ifndef EDGE_H
#define EDGE_H

#include "Vertex.h" // Đã đổi tên

class Edge {
private:
    Vertex source; // Đã đổi tên
    Vertex destination; // Đã đổi tên
    double weight; // Trọng số của cạnh

public:
    // Constructor với trọng số mặc định 0.0
    Edge(const Vertex& src, const Vertex& dest, double w = 0.0);

    // Getters
    Vertex getSource() const;
    Vertex getDestination() const;
    double getWeight() const;

    // Operator overloading
    bool operator<(const Edge& other) const;
};

#endif // EDGE_H