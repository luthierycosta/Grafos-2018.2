#include <iostream>		// cin e cout
#include <algorithm>	// max
#include <list>
#include <iterator>
#include <utility>		// pair

using namespace std;

class Graph {
	list<Vertex> vertList;
	list<Edge> edgeList;

public:
	void addVert(int id) {
		vertList.push_back(new Vertex(id));
	}

	void addEdge(Vertex a, Vertex b, int value) {
		edgeList.push_back(new Edge(a, b, value));
	}

	int degree() {
		int res = 0;
		for (Vertex v: vertList)
			res = max(res, v.degree());

		return res;
	}

	bool isConnected() {
		for (Vertex v: vertList)
			if (!v.isConnected())
				return false;

		return true;
	}

	~Graph() {
		for (Vertex v: vertList) delete(v);
		for (Edge ed: edgeList)	delete(ed);
	}
}

class Vertex {
	int id;
	list<Vertex> adj_list;

public:
	Vertex(int new_id) {
		this.id = new_id;
	}

	void addAdj(Vertex v) {
		this.adj_list.push_back(v);
	}

	int degree() {
		return adj_list.size;
	}

	bool isConnected() {
		return (adj_list.size != 0);
	}
}

class Edge {
	int value;
	pair<Vertex,Vertex> vertices;

public:
	Edge(Vertex a, Vertex b, int value) {
		this.value = value;
		vertices = make_pair(a, b);
		a.addAdj(b);
		b.addAdj(a);
	}

	bool isLoop() {
		return (vertices.first == vertices.second);
	}
}