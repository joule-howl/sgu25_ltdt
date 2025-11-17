#ifndef VERTEX_H
#define VERTEX_H

class Vertex {
private:
    int id;

public:
    // Constructor
    Vertex(int _id);

    // Getters
    int getID() const;

    // Operator overloading để hỗ trợ so sánh
    bool operator<(const Vertex& other) const;
    bool operator==(const Vertex& other) const;
};

#endif // VERTEX_H