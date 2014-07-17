#ifndef _AOV_AOV_AOV_H 
#define _AOV_AOV_AOV_H
#include "iostream"
#include "string"
using namespace std;

#define kMaxVex 1000

//����ͼ�ڽӱ�߽ڵ�ṹ
struct EdgeNode
{
	int adjvex;
	struct EdgeNode * next;
};
//����ͼ����ͷ�ڵ�ṹ
struct VertexNode
{
	int in;
	int data;
	EdgeNode * first_edge;
};
//����ͼAOV�ඨ��
class Graph
{
public: 
	Graph();
	~Graph();
	int VertexAmount();
	int TopologicalSort(int topsort_sequence[]);//ToplogicalSort��������һ��topsort_sequence��Ϊ����������Ľ�����
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