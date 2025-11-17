#include "GraphReader.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>

// ===================================================
// TRIỂN KHAI MATRIX READER
// ===================================================

// Triển khai 1: Đọc Ma trận Kề từ tên file (MatrixReader)
Graph MatrixReader::readGraph(const std::string& filename) {
    std::ifstream file(filename);
    Graph g;
    int N = 0;

    if (!file.is_open()) {
        std::cerr << "Lỗi: MatrixReader không thể mở file " << filename << std::endl;
        return g;
    }

    if (!(file >> N)) {
        std::cerr << "Lỗi: Không đọc được số lượng đỉnh (N) trong MatrixReader." << std::endl;
        return g;
    }

    for (int i = 0; i < N; ++i) g.addVertex(Vertex(i));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            double weight;
            if (!(file >> weight)) {
                std::cerr << "Lỗi: Định dạng ma trận không đúng." << std::endl;
                return g;
            }

            if (weight != 0.0) {
                g.addEdge(Vertex(i), Vertex(j), weight);
            }
        }
    }
    return g;
}

// Triển khai 2: Đọc Ma trận Kề từ luồng (MatrixReader) - Tạm thời không hỗ trợ format này
Graph MatrixReader::readGraph(std::istream& is, int N_vertices) {
    std::cerr << "Lỗi: MatrixReader không hỗ trợ định dạng đọc từ luồng này." << std::endl;
    return Graph();
}

// ===================================================
// TRIỂN KHAI ADJACENCY LIST READER
// ===================================================

// Triển khai 1: Đọc Danh sách Kề từ tên file (AdjacencyListReader) - Cần 2 lần đọc
Graph AdjacencyListReader::readGraph(const std::string& filename) {
    std::ifstream file(filename);
    Graph g;
    std::string line;
    int maxID = -1; 

    if (!file.is_open()) {
        std::cerr << "Lỗi: AdjacencyListReader không thể mở file " << filename << std::endl;
        return g;
    }
    
    // Lần đọc 1: Tìm maxID và thêm đỉnh
    std::streampos current_pos = file.tellg(); 
    
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        int srcID;
        if (ss >> srcID) {
            if (srcID > maxID) maxID = srcID;
            int destID;
            double weight;
            while (ss >> destID >> weight) {
                if (destID > maxID) maxID = destID;
            }
        }
    }
    
    for (int i = 0; i <= maxID; ++i) g.addVertex(Vertex(i));

    // Reset con trỏ file
    file.clear();
    file.seekg(current_pos, std::ios::beg);

    // Lần đọc 2: Thêm các cạnh
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        int srcID;
        if (ss >> srcID) {
            int destID;
            double weight;
            while (ss >> destID >> weight) {
                g.addEdge(Vertex(srcID), Vertex(destID), weight);
            }
        }
    }
    return g;
}

// Triển khai 2: Đọc Danh sách Kề từ luồng (AdjacencyListReader) - Dùng cho LienThongBFS
Graph AdjacencyListReader::readGraph(std::istream& is, int N_vertices) {
    Graph g;
    
    // 1. Thêm tất cả các đỉnh (ID từ 1 đến N_vertices)
    for (int i = 1; i <= N_vertices; ++i) {
        g.addVertex(Vertex(i));
    }
    
    // 2. Đọc N_vertices dòng tiếp theo cho danh sách kề từ luồng
    for (int i = 1; i <= N_vertices; ++i) {
        int neighborID;
        // Đọc các đỉnh kề cho đỉnh i, dừng khi gặp -1
        while (is >> neighborID && neighborID != -1) {
            // Đồ thị vô hướng: Thêm cạnh 2 chiều
            g.addEdge(Vertex(i), Vertex(neighborID), 0.0);
            g.addEdge(Vertex(neighborID), Vertex(i), 0.0); 
        }
    }
    
    return g;
}

// ===================================================
// TRIỂN KHAI EDGE LIST READER
// ===================================================

// Triển khai 1: Đọc Danh sách Cạnh từ tên file (EdgeListReader)
Graph EdgeListReader::readGraph(const std::string& filename) {
    std::ifstream file(filename);
    Graph g;
    int srcID, destID;
    double weight;
    int maxID = -1; 

    if (!file.is_open()) {
        std::cerr << "Lỗi: EdgeListReader không thể mở file " << filename << std::endl;
        return g;
    }

    // Lần đọc 1: Tìm maxID và thêm đỉnh
    std::streampos current_pos = file.tellg();
    
    while (file >> srcID >> destID >> weight) {
        if (srcID > maxID) maxID = srcID;
        if (destID > maxID) maxID = destID;
    }

    for (int i = 0; i <= maxID; ++i) g.addVertex(Vertex(i));

    // Reset con trỏ file
    file.clear();
    file.seekg(current_pos, std::ios::beg);

    // Lần đọc 2: Thêm các cạnh
    while (file >> srcID >> destID >> weight) {
        g.addEdge(Vertex(srcID), Vertex(destID), weight);
    }
    return g;
}

// Triển khai 2: Đọc Danh sách Cạnh từ luồng (EdgeListReader) - Tạm thời không hỗ trợ format này
Graph EdgeListReader::readGraph(std::istream& is, int N_vertices) {
    std::cerr << "Lỗi: EdgeListReader không hỗ trợ định dạng đọc từ luồng này." << std::endl;
    return Graph();
}