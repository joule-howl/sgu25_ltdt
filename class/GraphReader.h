#ifndef GRAPH_READER_H
#define GRAPH_READER_H

#include "Graph.h"
#include <string>
#include <utility> // Dùng cho std::pair

// Kiểu trả về bao gồm cả Đồ thị và ID điểm khởi đầu (Y)
using GraphReadResult = std::pair<Graph, int>; 

// ===================================================
// LỚP CƠ SỞ TRỪU TƯỢNG (INTERFACE)
// ===================================================
class GraphReader {
public:
    // Phương thức trừu tượng để đọc và trả về Graph cùng với StartID
    virtual GraphReadResult readGraph(const std::string& filename) = 0;
    
    // Virtual Destructor là bắt buộc cho lớp cơ sở
    virtual ~GraphReader() = default; 
};

// ===================================================
// CÁC LỚP CON CỤ THỂ
// ===================================================

class MatrixReader : public GraphReader {
public:
    // Triển khai logic đọc Ma trận Kề
    GraphReadResult readGraph(const std::string& filename) override;
};

class AdjacencyListReader : public GraphReader {
public:
    // Triển khai logic đọc Danh sách Kề
    GraphReadResult readGraph(const std::string& filename) override;
};

class EdgeListReader : public GraphReader {
public:
    // Triển khai logic đọc Danh sách Cạnh
    GraphReadResult readGraph(const std::string& filename) override;
};

#endif // GRAPH_READER_H