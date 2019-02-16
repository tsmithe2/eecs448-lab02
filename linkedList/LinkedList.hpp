/**
*	@author 
*	@date 
*	@file LinkedList.hpp
*	@brief Implementation file for templated LinkedList class
*/

template <typename T>
LinkedList<T>::LinkedList() : m_front(nullptr), m_size(0)
{

}

template <typename T>
LinkedList<T>::~LinkedList() 
{
	while(!isEmpty())
	{
		removeFront();
	}
}

template <typename T>
bool LinkedList<T>::isEmpty() const
{
	return(m_size == 0);
}

template <typename T>
int LinkedList<T>::size() const
{
	//Should just return m_size
	return(m_size);
}

template <typename T>
bool LinkedList<T>::search(T value) const
{
	Node<T>* temp = m_front;
	bool isFound = false;

	while (temp != nullptr)
	{
		/*temp has access to getValue() and getNext()
		if the temp value is 'value' then isFound is true
		need to exit while-loop with break
		otherwise keep looping through temp's next value
		*/
		if (temp->getValue() == value)
		{
			isFound = true;
			break;
		}
		temp = temp->getNext();
	}
	return(isFound);
}

template <typename T>
std::vector<T> LinkedList<T>::toVector() const
{
	std::vector<T> vec;
	Node<T>* temp = m_front;

	while( temp != nullptr )
	{
		vec.push_back(temp->getValue());
		temp = temp->getNext();
	}

	return(vec);	
	
}

template <typename T>
void LinkedList<T>::addBack(T value)
{
	Node<T>* temp = nullptr;

	if(isEmpty())
	{
		m_front = new Node<T>(value);	
	}
	else
	{
		temp = m_front;
		while(temp->getNext() != nullptr)
		{
			temp = temp->getNext();
		}

		temp->setNext( new Node<T>(value) );		
	}

	m_size++;
}

template <typename T>
void LinkedList<T>::addFront(T value)
{
	Node<T>* temp = m_front;
	m_front = new Node<T>(value);
	m_front->setNext( temp );
	m_size++;
}

template <typename T>
bool LinkedList<T>::removeBack()
{
	Node<T>* lastNode = nullptr;
	Node<T>* secondintoLast = nullptr;
	bool isRemoved = false;

	if (isEmpty())
	{
		//list is empty. Return isRemoved.
		return isRemoved;
	}
	else
	{
		if (size() == 1)
		{
			delete m_front;
			m_front = nullptr;
			lastNode = nullptr;
			isRemoved = true;
			m_size--;
		}
		else
		{
			//need to establish the front and last pointer
			secondintoLast = m_front;
			lastNode = secondintoLast->getNext();

			/*
			while there are more nodes to traverse we need to
			set the last node as the next node until the next
			node is null
			*/
			while (lastNode->getNext() != nullptr)
			{
				lastNode = secondintoLast;
				lastNode = lastNode->getNext();
			}

			//clean up
			delete lastNode;
			secondintoLast->setNext(nullptr);
			m_size--;
			isRemoved = true;
		}
	}
	return(isRemoved);
}	

template <typename T>
bool LinkedList<T>::removeFront()
{
	Node<T>* temp = nullptr;
	bool isRemoved = false;

	if(!isEmpty())
	{
		temp = m_front;
		m_front = temp->getNext();
		delete temp;
		m_size--;
		isRemoved = true;
	}

	return(isRemoved);
}
