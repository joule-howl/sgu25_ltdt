#ifndef GRAPH_READER_H
#define GRAPH_READER_H

#include "Graph.h"
#include <string>

// ===================================================
// LỚP CƠ SỞ TRỪU TƯỢNG (INTERFACE)
// ===================================================
class GraphReader {
public:
    // Phương thức trừu tượng: chỉ trả về đối tượng Graph
    virtual Graph readGraph(const std::string& filename) = 0;
    
    // Virtual Destructor là bắt buộc cho lớp cơ sở
    virtual ~GraphReader() = default; 
};

// ===================================================
// CÁC LỚP CON CỤ THỂ
// ===================================================

class MatrixReader : public GraphReader {
public:
    // Triển khai logic đọc Ma trận Kề
    Graph readGraph(const std::string& filename) override;
};

class AdjacencyListReader : public GraphReader {
public:
    // Triển khai logic đọc Danh sách Kề
    Graph readGraph(const std::string& filename) override;
};

class EdgeListReader : public GraphReader {
public:
    // Triển khai logic đọc Danh sách Cạnh
    Graph readGraph(const std::string& filename) override;
};

#endif // GRAPH_READER_H