#include "../../../../class/Graph.h"
#include "../../../../class/GraphReader.h" // Dùng AdjacencyListReader đã cập nhật
#include "../BFS_Recursive.cpp" 

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdio> // Cho freopen

int main() {
    std::string baseName = "LienThongBFS";
    std::string inputFileName = baseName + ".INP";
    std::string outputFileName = baseName + ".OUT";

    // Thiết lập I/O redirection
    freopen(inputFileName.c_str(), "r", stdin); 
    freopen(outputFileName.c_str(), "w", stdout); 

    // 1. Đọc N (số đỉnh) và X (đỉnh khởi đầu)
    int N = 0;
    int startX = -1;
    if (!(std::cin >> N >> startX)) {
        return 0;
    }
    
    // 2. Đọc và xây dựng đồ thị SỬ DỤNG ĐA HÌNH
    // Khai báo con trỏ của lớp cơ sở
    GraphReader* reader = new AdjacencyListReader();
    
    // Gọi phương thức đọc chuyên biệt từ luồng (std::cin)
    Graph g = reader->readGraph(std::cin, N);
    
    // Dọn dẹp
    delete reader; 

    // 3. Chạy thuật toán BFS
    BFS_Recursive bfs(g);
    std::vector<int> traversalOrder = bfs.run(startX);
    
    // 4. In kết quả
    int k = traversalOrder.size();
    
    std::cout << k << std::endl;
    std::sort(traversalOrder.begin(), traversalOrder.end());
    
    for (size_t i = 0; i < traversalOrder.size(); ++i) {
        std::cout << traversalOrder[i] << (i == traversalOrder.size() - 1 ? "" : " ");
    }
    std::cout << std::endl;
    
    return 0;
}