#include "Graph.h"
#include <algorithm>
#include <stdexcept>

Graph::Graph() {}

// Thêm đỉnh vào đồ thị
bool Graph::addVertex(const Vertex& v) {
    int id = v.getID();
    if (vertices.count(id)) {
        return false;
    }
    vertices.emplace(id, v); // Đã đổi tên vertices
    adjList[id] = {};
    return true;
}

// Thêm cạnh vào đồ thị
bool Graph::addEdge(const Vertex& src, const Vertex& dest, double weight) {
    int srcID = src.getID();
    int destID = dest.getID();

    // Kiểm tra tồn tại đỉnh
    if (!containsVertex(srcID) || !containsVertex(destID)) {
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
    allEdges.push_back(newEdge);
    
    return true;
}

// Lấy tất cả các đỉnh
std::vector<Vertex> Graph::getAllVertices() const {
    std::vector<Vertex> allVertices;
    for (const auto& pair : vertices) {
        allVertices.push_back(pair.second);
    }
    return allVertices;
}

// Lấy tất cả các cạnh
std::vector<Edge> Graph::getAllEdges() const {
    return allEdges;
}

// Kiểm tra xem đỉnh có tồn tại hay không
bool Graph::containsVertex(int vertexID) const {
    return vertices.count(vertexID);
}

// Lấy các cạnh kề từ một đỉnh
std::vector<Edge> Graph::getNeighbors(int vertexID) const {
    if (adjList.count(vertexID)) {
        return adjList.at(vertexID);
    }
    return {};
}

// Phương thức truy cập đỉnh theo ID
Vertex Graph::getVertexByID(int vertexID) const {
    auto it = vertices.find(vertexID);
    if (it == vertices.end()) {
        throw std::out_of_range("Lỗi: Đỉnh (Vertex) với ID này không tồn tại trong đồ thị.");
    }
    return it->second;
}