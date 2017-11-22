// Lab4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h" 
#include "iostream"

class Node
{
public:
	double data;
	Node* link;
	Node(double x);
};

Node::Node(double x)
{
	data = x;
	link = 0;
}

class List
{
public:
	Node* Head;
	List();
	~List();
	Node* InsertNode(int index, double data); 
	void DeleteNode(int index);
	void MoveNode(int OldIndex, int NewIndex);
	Node* GetElement(int index);
	int GetIndex(Node* node);
	int GetLast();
};

List::List()
{
	Head = 0;
}

List::~List()
{
	Node* CurrentNode = Head;
	Node* NextNode = 0;
	while (CurrentNode != 0)
	{
		NextNode = CurrentNode->link;
		delete CurrentNode;
		CurrentNode = NextNode;
	}
}

Node* List::InsertNode(int index, double data)
{
	if (index < 0)
	{
		return 0;
	}
	int CurrentIndex = 1;
	Node* CurrentNode = Head;
	while (CurrentNode && index > CurrentIndex)
	{
		CurrentNode = CurrentNode->link;
		CurrentIndex++;
	}
	if (index > 0 && CurrentNode == 0)
	{
		return 0;
	}
	Node* newNode = new Node(data);
	if (index == 0)
	{
		newNode->link = Head;
		Head = newNode;
	}
	else 
	{
		newNode->link = CurrentNode->link;
		CurrentNode->link = newNode;
	}
	return newNode;
}

void List::DeleteNode(int index)
{
	Node* PreviousNode = 0;
	Node* CurrentNode = Head;
	if (index == 0)
	{
		Head = CurrentNode->link;
		delete CurrentNode;
	}
	else
	{
		for (int i = 0; i < index; i++)
		{
			PreviousNode = CurrentNode;
			CurrentNode = CurrentNode->link;
		}
		PreviousNode->link = CurrentNode->link;
		delete CurrentNode;
	}
}

void List::MoveNode(int OldIndex, int NewIndex)
{
	double data = 0;
	Node* TempNode = Head;
	if (OldIndex == 0)
	{
		TempNode = Head;
		data = TempNode->data;
	}
	else
	{
		for (int i = 0; i < OldIndex; i++)
		{
			TempNode = TempNode->link;
		}
		data = TempNode->data;
	}
	if (OldIndex > NewIndex)
	{
		InsertNode(NewIndex, data);
		DeleteNode(OldIndex + 1);
	}
	else if (NewIndex > OldIndex)
	{
		DeleteNode(OldIndex);
		InsertNode(NewIndex, data);
	}
}

Node* List::GetElement(int index)
{
	Node* TempNode = Head;
	for (int i = 0; i < index; i++)
	{
		TempNode = TempNode->link;
	}
	return TempNode;
}

int List::GetIndex(Node* node)
{
	Node* TempNode = Head;
	int index = 0;
	while (TempNode != node)
	{
		index++;
		TempNode = TempNode->link;
	}
	return index;
}

int List::GetLast()
{
	Node* TempNode = Head;
	int index = 0;
	while (TempNode->link != 0)
	{
		index++;
		TempNode = TempNode->link;
	}
	return index;
}

int main()
{
	List list;
	list.InsertNode(0, 47);
	list.InsertNode(1, 12);
	list.InsertNode(2, 92);
	list.InsertNode(3, 65);
	list.InsertNode(4, 80);
	list.InsertNode(5, 46);
	list.InsertNode(6,5);
	list.InsertNode(7, 78);
	Node* first = list.Head;
	Node* second = first->link;
	Node* current = list.GetElement(3);
	Node* temp = list.GetElement(5);
	Node* last = list.GetElement(list.GetLast());
	//std::cout << list.GetLast() << std::endl;
	//std::cout << list.GetIndex(current) << std::endl;
	//list.DeleteNode(3);
	//list.MoveNode(0, 2);
	//std::cout << list.GetElement(2)->data << std::endl;
    return 0;
}

