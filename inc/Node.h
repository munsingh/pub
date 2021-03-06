//Copyright �2018, multics, Inc.All rights reserved.

#pragma once

#include <iostream>

template <class T> class Node {
	public:
		//constructors
				Node(const T& oData, Node<T>* pNext = nullptr)
					: m_oData(oData), m_pNext(pNext) {};
				Node(const Node<T>& oData)
					: Node(oData.GetData(), oData.m_pNext) {};
				Node(const Node<T>* pNode)
					: Node(pNode->GetData(), pNode->GetNext()) {};
		virtual ~Node() { m_pNext = nullptr; }
		Node<T>& operator = (const Node<T>& oNode) {
			if (this != &oNode) {
				m_oData = oNode.m_oData;
				m_pNext = oNode.m_pNext;
			}

			return *this;
		}
	
		void		SetData(const T& oData) { m_oData = oData; };
		const T&	GetData() const { return m_oData; };

		void		SetNext(Node<T>* pNext) { m_pNext = pNext; };
		Node<T>*	GetNext() const { return m_pNext; };

		//TODO:: Move constructor

		//overloaded opertors
		template <class T>
		friend std::ostream& operator<< (std::ostream& out, const Node<T>* pNode);
	private:
		//hidden constructor
		Node();

		//member variables
		T			m_oData;
		Node<T>*	m_pNext = nullptr;
};

template <class T>
std::ostream& operator<< (std::ostream& out, const Node<T>* pNode) {
	//Here we print item on the console
	//the data->
	//for example
	//2->NULL, if this is the last node
	//otherwise just 2-> if it is not the last node
	out << pNode->GetData() << "->";
	if (!pNode->GetNext()) {
		out << "NULL";
	}

	return out;
}