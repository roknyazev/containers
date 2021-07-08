//
// Created by Wolmer Rudy on 6/16/21.
//

#ifndef CONTAINERS_NODE_HPP
#define CONTAINERS_NODE_HPP

template <typename T>
class Node
{
public:
	T content;
	Node *prev;
	Node *next;
	Node()
	{};
	Node(T content, Node<T> *prev, Node<T> *next)
	{
		this->content = content;
		this->prev = prev;
		this->next = next;
	}
};

#endif //CONTAINERS_NODE_HPP
