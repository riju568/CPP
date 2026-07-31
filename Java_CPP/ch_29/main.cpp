#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <optional>
#include <limits>
#include <algorithm>
#include <queue>
#include <stdexcept>
#include <iomanip>


class Edge {
protected:
    int u;
    int v;

public:
    Edge(int u, int v) : u(u), v(v) {}
    virtual ~Edge() = default;

    int getU() const noexcept { return u; }
    int getV() const noexcept { return v; }
    void setU(int u_val) noexcept { u = u_val; }
    void setV(int v_val) noexcept { v = v_val; }

    virtual bool equals(const Edge& other) const noexcept {
        return u == other.u && v == other.v;
    }
};

class WeightedEdge : public Edge {
public:
    double weight;

    WeightedEdge(int u, int v, double weight) : Edge(u, v), weight(weight) {}

    bool operator>(const WeightedEdge& other) const noexcept {
        return weight > other.weight;
    }
    bool operator<(const WeightedEdge& other) const noexcept {
        return weight < other.weight;
    }
};

template <typename V>
class SearchTree {
protected:
    int root;
    std::vector<int> parent;
    std::vector<int> searchOrder;
    std::vector<V> vertices; // Reference snapshot of graph vertices

public:
    SearchTree(int root, std::vector<int> parent, std::vector<int> searchOrder, std::vector<V> vertices)
        : root(root), parent(std::move(parent)), searchOrder(std::move(searchOrder)), vertices(std::move(vertices)) {}

    int getRoot() const noexcept { return root; }
    int getParent(int v) const { return parent.at(v); }
    const std::vector<int>& getSearchOrder() const noexcept { return searchOrder; }
    size_t getNumberOfVerticesFound() const noexcept { return searchOrder.size(); }

    std::vector<V> getPath(int index) const {
        std::vector<V> path;
        do {
            path.push_back(vertices.at(index));
            index = parent.at(index);
        } while (index != -1);
        return path;
    }

    void printPath(int index) const {
        std::vector<V> path = getPath(index);
        std::cout << "A path from " << vertices.at(root) << " to " << vertices.at(index) << ": ";
        for (auto it = path.rbegin(); it != path.rend(); ++it) {
            std::cout << *it << " ";
        }
    }

    void printTree() const {
        std::cout << "Root is: " << vertices.at(root) << "\nEdges: ";
        for (size_t i = 0; i < parent.size(); ++i) {
            if (parent[i] != -1) {
                std::cout << "(" << vertices.at(parent[i]) << ", " << vertices.at(i) << ") ";
            }
        }
        std::cout << "\n";
    }
};

template <typename V>
class UnweightedGraph {
protected:
    std::vector<V> vertices;
    std::vector<std::vector<std::shared_ptr<Edge>>> neighbors;

public:
    UnweightedGraph() = default;

    UnweightedGraph(const std::vector<V>& verts, const std::vector<std::pair<int, int>>& edges) {
        for (const auto& vertex : verts) {
            addVertex(vertex);
        }
        createAdjacencyLists(edges);
    }

    virtual ~UnweightedGraph() = default;

    size_t getSize() const noexcept { return vertices.size(); }
    const std::vector<V>& getVertices() const noexcept { return vertices; }

    V getVertex(int index) const {
        if (index < 0 || static_cast<size_t>(index) >= vertices.size()) {
            throw std::out_of_range("Vertex index out of bounds.");
        }
        return vertices[index];
    }

    int getIndex(const V& v) const {
        auto it = std::find(vertices.begin(), vertices.end(), v);
        if (it != vertices.end()) {
            return static_cast<int>(std::distance(vertices.begin(), it));
        }
        return -1;
    }

    std::vector<int> getNeighbors(int index) const {
        std::vector<int> result;
        for (const auto& edge : neighbors.at(index)) {
            result.push_back(edge->getV());
        }
        return result;
    }

    size_t getDegree(int v) const {
        return neighbors.at(v).size();
    }

    void clear() noexcept {
        vertices.clear();
        neighbors.clear();
    }

    bool addVertex(const V& vertex) {
        if (std::find(vertices.begin(), vertices.end(), vertex) == vertices.end()) {
            vertices.push_back(vertex);
            neighbors.push_back(std::vector<std::shared_ptr<Edge>>());
            return true;
        }
        return false;
    }

    bool addEdge(std::shared_ptr<Edge> e) {
        if (e->getU() < 0 || static_cast<size_t>(e->getU()) >= getSize()) {
            throw std::invalid_argument("Invalid starting vertex index: " + std::to_string(e->getU()));
        }
        if (e->getV() < 0 || static_cast<size_t>(e->getV()) >= getSize()) {
            throw std::invalid_argument("Invalid ending vertex index: " + std::to_string(e->getV()));
        }

        neighbors[e->getU()].push_back(e);
        return true;
    }

    bool addEdge(int u, int v) {
        return addEdge(std::make_shared<Edge>(u, v));
    }

private:
    void createAdjacencyLists(const std::vector<std::pair<int, int>>& edges) {
        for (const auto& [u, v] : edges) {
            addEdge(u, v);
        }
    }
};

template <typename V>
class WeightedGraph : public UnweightedGraph<V> {
public:
    class MST : public SearchTree<V> {
    private:
        double totalWeight;

    public:
        MST(int root, std::vector<int> parent, std::vector<int> searchOrder, double totalWeight, std::vector<V> vertices)
            : SearchTree<V>(root, parent, searchOrder, vertices), totalWeight(totalWeight) {}

        double getTotalWeight() const noexcept { return totalWeight; }
    };

    WeightedGraph() = default;

    struct WeightedEdgeTuple {
        int u;
        int v;
        double weight;
    };

    WeightedGraph(const std::vector<V>& verts, const std::vector<WeightedEdgeTuple>& edges) {
        this->vertices = verts;
        for (size_t i = 0; i < verts.size(); ++i) {
            this->neighbors.push_back(std::vector<std::shared_ptr<Edge>>());
        }
        for (const auto& edge : edges) {
            addEdge(edge.u, edge.v, edge.weight);
        }
    }

    bool addEdge(int u, int v, double weight) {
        return this->addEdge(std::make_shared<WeightedEdge>(u, v, weight));
    }

    std::vector<std::vector<std::optional<double>>> getAdjacentMatrix() const {
        size_t n = this->getSize();
        std::vector<std::vector<std::optional<double>>> m(n, std::vector<std::optional<double>>(n, std::nullopt));

        for (size_t i = 0; i < n; ++i) {
            for (const auto& edge : this->neighbors[i]) {
                auto wEdge = std::dynamic_pointer_cast<WeightedEdge>(edge);
                if (wEdge) {
                    m[edge->getU()][edge->getV()] = wEdge->weight;
                }
            }
        }
        return m;
    }

    MST getMinimumSpanningTree(int startingVertex = 0) const {
        size_t n = this->getSize();
        if (startingVertex < 0 || static_cast<size_t>(startingVertex) >= n) {
            throw std::out_of_range("Invalid starting vertex for MST.");
        }

        std::vector<double> cost(n, std::numeric_limits<double>::infinity());
        cost[startingVertex] = 0;

        std::vector<int> parent(n, -1);
        double totalWeight = 0;
        std::vector<int> T;

        auto m = getAdjacentMatrix();

        while (T.size() < n) {
            int u = -1;
            double currentMinCost = std::numeric_limits<double>::infinity();

            for (size_t i = 0; i < n; ++i) {
                if (std::find(T.begin(), T.end(), static_cast<int>(i)) == T.end() && cost[i] < currentMinCost) {
                    currentMinCost = cost[i];
                    u = static_cast<int>(i);
                }
            }

            if (u == -1) break; // Terminate if remaining graph vertices are unreachable

            T.push_back(u);
            totalWeight += cost[u];

            for (size_t k = 0; k < n; ++k) {
                if (m[u][k].has_value() && std::find(T.begin(), T.end(), static_cast<int>(k)) == T.end() && cost[k] > m[u][k].value()) {
                    cost[k] = m[u][k].value();
                    parent[k] = u;
                }
            }
        }

        return MST(startingVertex, parent, T, totalWeight, this->vertices);
    }
};

int main() {
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try {
        const bool DEBUG_MODE = false;

        std::vector<std::string> vertices = {
            "Seattle", "San Francisco", "Los Angeles", "Denver", "Kansas City",
            "Chicago", "Boston", "New York", "Atlanta", "Miami", "Dallas", "Houston"
        };

        std::vector<WeightedGraph<std::string>::WeightedEdgeTuple> edges = {
            {0, 1, 807}, {0, 3, 1331}, {0, 5, 2097},
            {1, 0, 807}, {1, 2, 381}, {1, 3, 1267}, {2, 1, 381},
            {2, 3, 1015}, {2, 4, 1663}, {2, 10, 1435}, {3, 0, 1331},
            {3, 1, 1267}, {3, 2, 1015}, {3, 4, 599}, {3, 5, 1003},
            {4, 2, 1663}, {4, 3, 599}, {4, 5, 533}, {4, 7, 1260},
            {4, 8, 864}, {4, 10, 496}, {5, 0, 2097}, {5, 3, 1003},
            {5, 4, 533}, {5, 6, 983}, {5, 7, 787}, {6, 5, 983},
            {6, 7, 214}, {7, 4, 1260}, {7, 5, 787}, {7, 6, 214},
            {7, 8, 888}, {8, 4, 864}, {8, 7, 888}, {8, 9, 661},
            {8, 10, 781}, {8, 11, 810}, {9, 8, 661}, {9, 11, 1187},
            {10, 2, 1435}, {10, 4, 496}, {10, 8, 781}, {10, 11, 239},
            {11, 8, 810}, {11, 9, 1187}, {11, 10, 239}
        };

        WeightedGraph<std::string> graph1(vertices, edges);
        auto tree1 = graph1.getMinimumSpanningTree(0);

        std::cout << "Total weight is " << tree1.getTotalWeight() << "\n";
        tree1.printTree();

        if (DEBUG_MODE) {
            std::cout << "\nAdjacency Matrix:\n";
            auto matrix = graph1.getAdjacentMatrix();
            for (const auto& row : matrix) {
                for (const auto& val : row) {
                    if (val.has_value()) {
                        std::cout << std::setw(6) << val.value() << " ";
                    } else {
                        std::cout << std::setw(6) << "inf" << " ";
                    }
                }
                std::cout << "\n";
            }
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Standard exception caught: " << e.what() << '\n';
        return 1;
    }
    catch (...) {
        std::cerr << "An unknown non-standard exception occurred.\n";
        return 2;
    }

    return 0;
}