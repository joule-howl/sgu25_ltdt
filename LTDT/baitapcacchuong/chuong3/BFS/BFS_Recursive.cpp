#include "../../../class/Graph.h"
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>

using VisitedFlags = std::vector<bool>;

class BFS_Recursive {
private:
    const Graph& graph;
    VisitedFlags visited;
    std::vector<int> traversalOrder;
    int maxVertexID; // Đã đổi tên

    void recursiveBFS(std::queue<int>& q) {
        if (q.empty()) {
            return;
        }

        int currentID = q.front();
        q.pop();
        traversalOrder.push_back(currentID);

        try {
            Vertex currentVertex = graph.getVertexByID(currentID); // Đã đổi tên
            std::vector<Edge> neighbors = graph.getNeighbors(currentVertex.getID());

            for (const auto& edge : neighbors) {
                int neighborID = edge.getDestination().getID();

                if (neighborID >= 0 && neighborID <= maxVertexID && !visited[neighborID]) { // Đã đổi tên
                    visited[neighborID] = true;
                    q.push(neighborID);
                }
            }
        } catch (const std::out_of_range& e) {
            std::cerr << "Lỗi: Đỉnh ID " << currentID << " không hợp lệ trong đồ thị." << std::endl;
        }

        recursiveBFS(q);
    }

public:
    BFS_Recursive(const Graph& g) : graph(g) {
        maxVertexID = -1; // Đã đổi tên
        for (const auto& v : graph.getAllVertices()) { // Đã đổi tên
            if (v.getID() > maxVertexID) { // Đã đổi tên
                maxVertexID = v.getID(); // Đã đổi tên
            }
        }
        visited.resize(maxVertexID + 1, false); // Đã đổi tên
    }

    std::vector<int> run(int startID) {
        std::fill(visited.begin(), visited.end(), false);
        traversalOrder.clear();

        if (startID < 0 || startID > maxVertexID || !graph.containsVertex(startID)) { // Đã đổi tên
            std::cerr << "Lỗi: Đỉnh khởi đầu " << startID << " không hợp lệ." << std::endl;
            return {};
        }

        std::queue<int> q;
        q.push(startID);
        visited[startID] = true;
        recursiveBFS(q);

        return traversalOrder;
    }
};