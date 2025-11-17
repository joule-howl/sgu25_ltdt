#include "Graph.h"
#include <algorithm>
#include <stdexcept>

Graph::Graph() {}

// Thêm điểm vào đồ thị
bool Graph::addPoint(const Point& p) {
    int id = p.getID();
    if (points.count(id)) {
        return false;
    }
    points.emplace(id, p);
    adjList[id] = {};
    return true;
}

// Thêm cạnh vào đồ thị
bool Graph::addEdge(const Point& src, const Point& dest, double weight) {
    int srcID = src.getID();
    int destID = dest.getID();

    if (!containsPoint(srcID) || !containsPoint(destID)) {
        return false;
    }

    Edge newEdge(src, dest, weight);

    std::vector<Edge>& neighbors = adjList[srcID];

    // Kiểm tra cạnh đã tồn tại chưa
    for (const auto& edge : neighbors) {
        if (edge.getDestination() == dest) {
            return false;
        }
    }

    // Thêm cạnh vào danh sách kề và danh sách tất cả các cạnh
    neighbors.push_back(newEdge);
    Edges.push_back(newEdge);
    
    return true;
}

// Lấy tất cả các điểm
std::vector<Point> Graph::getAllPoints() const {
    std::vector<Point> allPoints;
    for (const auto& pair : points) {
        allPoints.push_back(pair.second);
    }
    return allPoints;
}

// Lấy tất cả các cạnh (Phương thức mới)
std::vector<Edge> Graph::getAllEdges() const {
    return Edges;
}

// Kiểm tra xem điểm có tồn tại hay không
bool Graph::containsPoint(int pointID) const {
    return points.count(pointID);
}

// Lấy các cạnh kề từ một điểm
std::vector<Edge> Graph::getNeighbors(int pointID) const {
    if (adjList.count(pointID)) {
        return adjList.at(pointID);
    }
    return {};
}

// Phương thức truy cập điểm theo ID
Point Graph::getPointByID(int pointID) const {
    auto it = points.find(pointID);
    if (it == points.end()) {
        throw std::out_of_range("Lỗi: Điểm (Point) với ID này không tồn tại trong đồ thị.");
    }
    return it->second;
}