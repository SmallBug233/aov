/*copyright 2014 SmallBug*/
/*����������google���*/
/*����Ϊ��Сд*/
/*����Ϊ��Сд���*/
/*����ΪСд����֮�����»���*/
/*���Ա����֮���_*/
#include "stdafx.h"
#include "iostream"
using namespace std;
template<class type>
 void Stack<type>::Push(type elem)
 {
 	data_[top_] = elem;
 	top_++;
 }
 template<class type>
 type Stack<type>::Pop()
 {	
	 return data_[(top_--) -1];
 }
 template<class type>
 bool Stack<type>::IsEmpty()
 {
	 if (0 == top_)
		 return 1;
	 else
		 return 0;
 }
 Graph::Graph()
 {
	 int i = 0;
	 for (i = 0; i < kMaxVex; i++)
	 {
		 adjlist_[i].first_edge = NULL;
		 adjlist_[i].in = -1;
		 adjlist_[i].data = 0;
	 }
 }
 Graph::~Graph()
 {
 	int i = 0;
 	EdgeNode *temp_edgenode, *edgenode;
 	for (i = 0; i < vertex_amount_; i++)
 	{
 		edgenode = adjlist_[i].first_edge;
 		while (edgenode != NULL)
 		{
 			temp_edgenode = edgenode->next;
 			delete(edgenode);
 			edgenode = temp_edgenode;
 		}
 
 	}
 }
 int Graph::VertexAmount()
 {
	 return vertex_amount_;
 }
void Graph::CreateGraph()
{
	int i,start_edge;
	EdgeNode *point_edgenode ;
	vertex_amount_	= 0;
	edge_amount_	= 0;
	i = 0;

	cout << "�����붥������" << endl;
	cin >> vertex_amount_;
	for (i = 0; i < vertex_amount_;i++)
	{
		adjlist_[i].in = 0;
	}
	cout << "�����������" << endl;
	cin >> edge_amount_;
	for (i = 0; i < edge_amount_; i++)
	{
		point_edgenode = new EdgeNode;
		cout << "������ߵ���Ϣ(��� �յ�)" << endl;
		cin  >> start_edge  >> point_edgenode->adjvex;
		++adjlist_[point_edgenode->adjvex].in;
		point_edgenode->next = adjlist_[start_edge].first_edge;
		adjlist_[start_edge].first_edge = point_edgenode;
	}
}
int Graph::TopologicalSort(int topsort_order[])
{
	int i, adjvex,count;
	EdgeNode *edgenode;
	Stack<int> stack;
	i = 0;
	count = 0;
	for (i = 0; i < vertex_amount_; i++)
	{
		if (adjlist_[i].in == 0)
			stack.Push(i);
	}
	while (!stack.IsEmpty())
	{
		adjvex = stack.Pop();
		topsort_order[count] = adjvex;
		edgenode = adjlist_[adjvex].first_edge;
		while (edgenode != NULL)
		{
			adjlist_[edgenode->adjvex].in--;
			if (0 == adjlist_[edgenode->adjvex].in)
			{
				stack.Push(edgenode->adjvex);
			}
			edgenode = edgenode->next;
		}
		count++;
	}
	if (count < edge_amount_)
		return 0;
	else
		return 1;
}
int _tmain(int argc, _TCHAR* argv[])
{
	char input;
	Graph g; 
	int topsort_sequence[kMaxVex],vertex_amount,i;
	while (true)
	{
		cout << "1.����ƻ�" << endl;
		cout << "2.����üƻ�����������ֻ���һ����" << endl;
		cout << "3.��������" << endl;
		cin >> input;
		switch (input)
		{
		case '1':
			g.CreateGraph();
			break;
		case '2':
			if (g.TopologicalSort(topsort_sequence))
			{
				vertex_amount = g.VertexAmount();
				for (i = 0; i < vertex_amount; i++)
				{
					cout << topsort_sequence[i];
					if (i != vertex_amount - 1)
						cout << "->";
				}
			}
			else
				cout << "������ͼ�л�·";
			cout << endl;
			break;
		case '3':
			exit(1);
			break;
		default:
			break;
		}
	}
	
	return 0;
}

