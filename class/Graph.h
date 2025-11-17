#ifndef GRAPH_H
#define GRAPH_H

#include "Point.h"
#include "Edge.h"
#include <map>
#include <vector>
#include <memory>
#include <string>

using AdjacencyList = std::map<int, std::vector<Edge>>;

class Graph {
private:
    std::map<int, Point> points;
    std::vector<Edge> Edges; 
    AdjacencyList adjList;

public:
    Graph();

    // Phương thức truy cập điểm theo ID
    Point getPointByID(int pointID) const;
    // Phương thức mới: Lấy tất cả các cạnh
    std::vector<Edge> getAllEdges() const;

    // Thêm điểm
    bool addPoint(const Point& p);
    // Thêm cạnh với trọng số mặc định 0.0
    bool addEdge(const Point& src, const Point& dest, double weight = 0.0);

    // Kiểm tra tồn tại điểm
    bool containsPoint(int pointID) const;
    std::vector<Edge> getNeighbors(int pointID) const;
    std::vector<Point> getAllPoints() const;
};

#endif // GRAPH_H