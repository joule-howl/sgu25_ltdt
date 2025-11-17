#ifndef POINT_H
#define POINT_H

class Point {
private:
    int id;

public:
    // Constructor
    Point(int _id);

    // Getters
    int getID() const;

    // Operator overloading
    bool operator<(const Point& other) const;
    bool operator==(const Point& other) const;
};

#endif // POINT_H