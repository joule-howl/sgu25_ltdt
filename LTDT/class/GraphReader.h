#ifndef GRAPH_READER_H
#define GRAPH_READER_H

#include "Graph.h"
#include <string>
#include <iostream>

// ===================================================
// LỚP CƠ SỞ TRỪU TƯỢNG (INTERFACE)
// ===================================================
class GraphReader {
public:
    // Phương thức 1 (Trừu tượng): Đọc từ tên file (dùng cho các định dạng file truyền thống)
    virtual Graph readGraph(const std::string& filename) = 0;

    // Phương thức 2 (Trừu tượng): Đọc từ luồng (std::istream) với số lượng đỉnh đã biết N
    virtual Graph readGraph(std::istream& is, int N_vertices) = 0; 

    // Virtual Destructor là bắt buộc cho lớp cơ sở
    virtual ~GraphReader() = default; 
};

// ===================================================
// CÁC LỚP CON CỤ THỂ
// ===================================================

class MatrixReader : public GraphReader {
public:
    // Triển khai đọc Ma trận Kề từ tên file
    Graph readGraph(const std::string& filename) override; 
    
    // Phương thức đọc từ luồng (không được dùng trong kịch bản này, nhưng phải triển khai)
    Graph readGraph(std::istream& is, int N_vertices) override; 
};

class AdjacencyListReader : public GraphReader {
public:
    // Triển khai đọc Danh sách Kề từ tên file
    Graph readGraph(const std::string& filename) override;
    
    // Triển khai đọc từ luồng (Dùng cho LienThongBFS.INP)
    Graph readGraph(std::istream& is, int N_vertices) override; 
};

class EdgeListReader : public GraphReader {
public:
    // Triển khai đọc Danh sách Cạnh từ tên file
    Graph readGraph(const std::string& filename) override;
    
    // Phương thức đọc từ luồng (không được dùng trong kịch bản này, nhưng phải triển khai)
    Graph readGraph(std::istream& is, int N_vertices) override; 
};

#endif // GRAPH_READER_H