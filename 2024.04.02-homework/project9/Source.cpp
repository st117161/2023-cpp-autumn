#include <iostream>
#include <cmath>

struct SEdge
{
    int a;
    int b;
    int w;
    SEdge(int a = 0, int b = 0, int w = 1) : a(a), b(b), w(w) {}
    SEdge(const SEdge &src) : a(src.a), b(src.b), w(src.w) {}
    ~SEdge() {}
    void set(int a, int b, int w)
    {
        this->a = a;
        this->b = b;
        this->w = w;
    }
    friend std::ostream &operator<<(std::ostream &stream, const SEdge &edge);
};

class CGraph
{
public:
    CGraph();
    CGraph(int vertexes, int edges);
    ~CGraph();
    void PrintEdges();
    void ReadMatrix(int vertexes, std::istream &stream);
    void ReadEdges(int edges, bool haveweight = false);
    int edgesCount();
    int roadsCount();
    int vertexCount();
    int CountEgesfromVertex(int vertex);
    void getIndexesUnitedVertex(int vertex);
    void PrintAdjacency(int vertex);

private:
    int CGraph::power(int vertex);
    void init();
    void initMatrix();
    void initEdges();
    void initMatrixFromEdges();
    void initEdgesFromMatrix();
    int getVertexesCountFromEdges();
    int getEdgesCountFromMatrix();
    void dispose();
    void disposeMatrix();
    void disposeEdges();

    int _vertexes;
    int _edges;
    int **_matrix;
    SEdge *_edge;
};

int main(int argc, char *argv[])
{
    CGraph graph;
    int v = 0;
    std::cin >> v;
    int g = 0;
    std::cin >> g;
    graph.ReadEdges(g);
    graph.PrintAdjacency(v);

    return EXIT_SUCCESS;
}

CGraph::CGraph()
    : _vertexes(0), _edges(0), _matrix(nullptr), _edge(nullptr) {}

CGraph::CGraph(int vertexes, int edges)
    : _vertexes(vertexes), _edges(edges), _matrix(nullptr), _edge(nullptr)
{
    init();
}

CGraph::~CGraph()
{
    dispose();
}

void CGraph::PrintEdges()
{
    if (_edge == nullptr)
    {
        if (_matrix == nullptr)
        {
            std::cout << "Graph empty" << std::endl;
            return;
        }
        initEdgesFromMatrix();
    }
    for (int i = 0; i < _edges; ++i)
    {
        std::cout << _edge[i] << std::endl;
    }
}

void CGraph::ReadMatrix(int vertexes, std::istream &stream)
{
    _vertexes = vertexes;
    initMatrix();
    for (int i = 0; i < _vertexes; ++i)
    {
        for (int j = 0; j < _vertexes; ++j)
        {
            stream >> _matrix[i][j];
        }
    }
}

void CGraph::ReadEdges(int edges, bool haveweight)
{
    _edges = edges;
    initEdges();
    for (int i = 0; i < _edges; ++i)
    {
        std::cin >> _edge[i].a >> _edge[i].b;
        if (haveweight)
        {
            std::cin >> _edge[i].w;
        }
    }
}

int CGraph::edgesCount()
{
    if (_edge == nullptr)
    {
        initEdgesFromMatrix();
    }
    return _edges;
}

int CGraph::roadsCount()
{
    return edgesCount() / 2;
}

int CGraph::vertexCount()
{
    if (_matrix == nullptr)
    {
        initMatrixFromEdges();
    }
    return _vertexes;
}

void CGraph::init()
{
    dispose();
    initMatrix();
    initEdges();
}

void CGraph::initMatrix()
{
    if (_vertexes == 0)
    {
        return;
    }
    _matrix = new int *[_vertexes];
    for (int i = 0; i < _vertexes; ++i)
    {
        _matrix[i] = new int[_vertexes]{0};
    }
}

void CGraph::initEdges()
{
    if (_edges == 0)
    {
        return;
    }
    _edge = new SEdge[_edges];
}

void CGraph::initMatrixFromEdges()
{
    disposeMatrix();
    _vertexes = getVertexesCountFromEdges();
    initMatrix();
    for (int i = 0; i < _edges; ++i)
    {
        _matrix[_edge[i].a][_edge[i].b] = _edge[i].w;
    }
}

int CGraph::getEdgesCountFromMatrix()
{
    int count = 0;
    for (int i = 0; i < _vertexes; ++i)
    {
        for (int j = 0; j < _vertexes; ++j)
        {
            count += (_matrix[i][j] != 0);
        }
    }
    return count;
}

void CGraph::dispose()
{
    disposeMatrix();
    disposeEdges();
}

void CGraph::disposeMatrix()
{
    if (_matrix != nullptr)
    {
        for (int i = 0; i < _vertexes; ++i)
        {
            delete[] _matrix[i];
        }
        delete[] _matrix;
        _matrix = nullptr;
    }
}

void CGraph::disposeEdges()
{
    if (_edge != nullptr)
    {
        delete[] _edge;
        _edge = nullptr;
    }
}

void CGraph::initEdgesFromMatrix()
{
    disposeEdges();
    _edges = getEdgesCountFromMatrix();
    initEdges();
    for (int i = 0, k = 0; i < _vertexes && k < _edges; ++i)
    {
        for (int j = 0; j < _vertexes && k < _edges; ++j)
        {
            if (_matrix[i][j] != 0)
            {
                _edge[k++].set(i + 1, j + 1, _matrix[i][j]);
            }
        }
    }
}

int CGraph::getVertexesCountFromEdges()
{
    int res = 0;
    for (int i = 0; i < _edges; ++i)
    {
        res = (res > _edge[i].a ? res : _edge[i].a);
        res = (res > _edge[i].b ? res : _edge[i].b);
    }
    return res + 1;
}

std::ostream &operator<<(std::ostream &stream, const SEdge &edge)
{
    stream << edge.a << " " << edge.b;
    if (edge.w > 1)
    {
        stream << " " << edge.w;
    }
    return stream;
}

int CGraph::CountEgesfromVertex(int vertex)
{
    int c = 0;
    initMatrixFromEdges();
    for (int i = 0; i < vertexCount(); ++i)
    {
        c += (_matrix[vertex + 1][i] != 0);
    }
    return c;
}

void CGraph::getIndexesUnitedVertex(int vertex)
{
    int i = 0;
    for (int j = 0; j < vertexCount(); ++j)
    {
        if (_matrix[vertex + 1][j] != 0)
        {
            std::cout << j << " ";
        }
    }
}

int CGraph::power(int vertex)
{
    int pw = 0;
    for (int j = 0; j < _vertexes; ++j)
    {
        pw += _matrix[vertex][j];
    }
    return pw;
}

void CGraph::PrintAdjacency(int vertex)
{
    _vertexes = vertex;
    initMatrixFromEdges();
    std::cout << _vertexes;
    for (int i = 0; i < _vertexes; ++i)
    {
        std::cout << power(i);
        for (int j = 0; j < _vertexes; ++j)
        {
            if (_matrix[i][j] != 0)
            {
                std::cout << j + 1;
            }
        }
    }
}
/* 0 1 1 1 1
   1 0 1 1 1
   1 1 0 1 1
   1 1 1 0 1
   1 1 1 1 0
*/