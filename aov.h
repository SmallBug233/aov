#ifndef _AOV_AOV_AOV_H 
#define _AOV_AOV_AOV_H
#include "iostream"
#include "string"
using namespace std;

#define kMaxVex 1000

//有向图邻接表边节点结构
struct EdgeNode
{
	int adjvex;
	struct EdgeNode * next;
};
//有向图领结表头节点结构
struct VertexNode
{
	int in;
	int data;
	EdgeNode * first_edge;
};
//有向图AOV类定义
class Graph
{
public: 
	Graph();
	~Graph();
	int VertexAmount();
	int TopologicalSort(int topsort_sequence[]);//ToplogicalSort函数传送一个topsort_sequence作为其拓扑排序的结果输出
	void CreateGraph();

private:
	VertexNode adjlist_[kMaxVex];
	int vertex_amount_, edge_amount_;
};

template<class type>
class Stack
{
public:
	Stack(){ top_ = 0; }
	~Stack(){}
	type Pop();
	void Push(type);
	bool IsEmpty();

private:
	int top_;
	type data_[kMaxVex];
};
#endif 