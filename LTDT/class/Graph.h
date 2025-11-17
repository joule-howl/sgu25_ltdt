#ifndef GRAPH_H
#define GRAPH_H

#include "Vertex.h" // Đã đổi tên
#include "Edge.h"
#include <map>
#include <vector>
#include <memory>
#include <string>

using AdjacencyList = std::map<int, std::vector<Edge>>;

class Graph {
private:
    std::map<int, Vertex> vertices; // Đã đổi tên thành vertices
    AdjacencyList adjList;
    std::vector<Edge> allEdges; 

public:
    Graph();

    // Phương thức truy cập đỉnh theo ID
    Vertex getVertexByID(int vertexID) const; // Đã đổi tên
    // Lấy tất cả các cạnh
    std::vector<Edge> getAllEdges() const;

    // Thêm đỉnh
    bool addVertex(const Vertex& v); // Đã đổi tên
    // Thêm cạnh
    bool addEdge(const Vertex& src, const Vertex& dest, double weight = 0.0); // Đã đổi tên

    // Kiểm tra tồn tại đỉnh
    bool containsVertex(int vertexID) const; // Đã đổi tên
    std::vector<Edge> getNeighbors(int vertexID) const;
    std::vector<Vertex> getAllVertices() const; // Đã đổi tên
};

#endif // GRAPH_H