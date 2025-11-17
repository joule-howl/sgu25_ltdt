#include "GraphReader.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>

// ===================================================
// TRIỂN KHAI MATRIX READER
// ===================================================

// Định dạng file: Dòng 1: Số lượng đỉnh (N). N dòng tiếp theo là ma trận N x N.
Graph MatrixReader::readGraph(const std::string& filename) {
    std::ifstream file(filename);
    Graph g;
    int N = 0;

    if (!file.is_open()) {
        std::cerr << "Lỗi: MatrixReader không thể mở file " << filename << std::endl;
        return g;
    }

    // Đọc số lượng đỉnh N
    if (!(file >> N)) {
        std::cerr << "Lỗi: Không đọc được số lượng đỉnh (N) trong MatrixReader." << std::endl;
        return g;
    }

    // 1. Thêm tất cả các điểm (ID từ 0 đến N-1)
    for (int i = 0; i < N; ++i) {
        g.addPoint(Point(i));
    }

    // 2. Đọc ma trận và thêm cạnh
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            double weight;
            if (!(file >> weight)) {
                std::cerr << "Lỗi: Định dạng ma trận không đúng (kích thước sai)." << std::endl;
                return g;
            }

            if (weight != 0.0) {
                g.addEdge(Point(i), Point(j), weight);
            }
        }
    }

    return g;
}

// ===================================================
// TRIỂN KHAI ADJACENCY LIST READER
// ===================================================

// Định dạng file: Các dòng là Danh sách Kề (ID_nguồn ID_đích trọng_số ID_đích trọng_số...).
Graph AdjacencyListReader::readGraph(const std::string& filename) {
    std::ifstream file(filename);
    Graph g;
    std::string line;
    int maxID = -1; 

    if (!file.is_open()) {
        std::cerr << "Lỗi: AdjacencyListReader không thể mở file " << filename << std::endl;
        return g;
    }

    // Lần đọc 1 (Tìm maxID và thêm điểm)
    std::streampos current_pos = file.tellg(); // Ghi lại vị trí bắt đầu dữ liệu
    
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
    
    // Thêm tất cả các điểm (từ 0 đến maxID)
    for (int i = 0; i <= maxID; ++i) {
        g.addPoint(Point(i));
    }

    // Reset con trỏ file về vị trí ban đầu của dữ liệu
    file.clear();
    file.seekg(current_pos, std::ios::beg);

    // Lần đọc 2 (Thêm các cạnh)
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        int srcID;
        if (ss >> srcID) {
            int destID;
            double weight;
            
            while (ss >> destID >> weight) {
                g.addEdge(Point(srcID), Point(destID), weight);
            }
        }
    }

    return g;
}

// ===================================================
// TRIỂN KHAI EDGE LIST READER
// ===================================================

// Định dạng file: Các dòng là Danh sách Cạnh (ID_nguồn ID_đích trọng_số).
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

    // Lần đọc 1 (Tìm maxID và thêm điểm)
    std::streampos current_pos = file.tellg();
    
    while (file >> srcID >> destID >> weight) {
        if (srcID > maxID) maxID = srcID;
        if (destID > maxID) maxID = destID;
    }

    // Thêm tất cả các điểm (từ 0 đến maxID)
    for (int i = 0; i <= maxID; ++i) {
        g.addPoint(Point(i));
    }

    // Reset con trỏ file về vị trí ban đầu của dữ liệu
    file.clear();
    file.seekg(current_pos, std::ios::beg);

    // Lần đọc 2 (Thêm các cạnh)
    while (file >> srcID >> destID >> weight) {
        g.addEdge(Point(srcID), Point(destID), weight);
    }

    return g;
}