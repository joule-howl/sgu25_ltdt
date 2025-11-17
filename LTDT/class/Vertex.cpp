#include "Vertex.h"

// Constructor
Vertex::Vertex(int _id) : id(_id) {}

// Getters
int Vertex::getID() const {
    return id;
}

// Operator overloading
bool Vertex::operator<(const Vertex& other) const {
    return id < other.id;
}

bool Vertex::operator==(const Vertex& other) const {
    return id == other.id;
}