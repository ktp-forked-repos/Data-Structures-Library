#include <iostream>

using namespace std;

template <class T>
struct node
{
	T data;
	node *next;
};

template <class T>
class Stack
{
	private :
	node<T> *start;
	unsigned int numElements;

	node<T>* createNewNode (T data1)
	{
		node<T> *temp;	
		temp = new node<T>;
		temp->data=data1;
		temp->next=NULL;

	return temp;
	}
	

	
	public :

	// Constructor	
	Stack ()
	{
		start=NULL;
		numElements=0;
	}
	// Destructor
	~Stack ()
	{
		node<T> *temp;	
		temp=start;
		while (temp!=NULL)
		{	
			delete temp;
			temp=temp->next;
		}
	}

	// getDataAtIndex Function
	/*
	 Returns Data At Given Index As Argument.
	   If Index Is Invalid The Returns The Data Of 1st Element 
	*/	
	T getDataAtIndex (unsigned int index)
	{
		node<T> *temp=start;		
		if (index < numElements)
		{		
			node<T> *temp=start;		
			for (int i=0;i<index;i++)
				temp=start->next;
		}
	return temp->data;
	
	}

	unsigned int getIndexOf (T data1)
	{
		unsigned int index=0;		
		node<T> *temp=start;
		
		while (temp!=NULL)
		{	
			if (temp->data == data1)	
				return index;
			index++;
			temp=temp->next;
		}
		
	return -1;
	}


	T top ()
	{
		return start->data;
	}
	// Acessor Function Of Class LinkedList	- Returns The Start Pointer Of The Linked List

	node<T>* begin ()
	{
		return start;
	}


	node<T>* end ()
	{
		return NULL;
	}

	// Inserts A Given Node At Begenning Of List
	/* 
	Returns 0 If No Memory Along With Error Message
	Returns 1 If Sucessfully Inserted
	*/ 	

	int push (T data1)
	{
		node<T> *temp;
		temp=createNewNode (data1);
		
		if (temp==NULL)
		{
			cerr<<"\n No Memory In Heap \n";
			return 0;
		}
		
		else 
		{
			if (start!=NULL)		
			{
				temp->next=start;
				start=temp;
				numElements++;
			}
			else
			{
				start=temp;
				numElements++;
			}
		}
	return 1;
	}

	// Deletes Node From Begenning Of List
	/*
	Returns 0 If Empty List
	Returns 1 If Sucessfully Deleted
	*/

	int pop ()
	{
		if (numElements==0)
		{
			cerr<<"\n Nothing To Delete \n";
			return 0;
		}
		else 
		{		
			node<T> *temp;	
			temp=start;
			start=start->next;
			delete temp;
			numElements--;
		return 1;
		}
	}

	unsigned int size ()
	{
		return numElements;
	}
	
	void printStack ()
	{
		cout<<"\n";		
		node<T> *temp=start;
		while (temp!=NULL)
		{
			cout<<temp->data<<"\t";
			temp=temp->next;
		}	
		cout<<"\n";
	}


	class iterator : public std::iterator<std::forward_iterator_tag,node<T>*>
	{
		node<T>* itr;

		public :

		iterator (node<T>* temp) : itr(temp) {}
		iterator (const iterator& myitr) : itr(myitr.itr) {}
		iterator& operator++ ()
		{
			itr = itr->next;
			return *this;

		}
		iterator operator++ (int) 
		{
  			iterator result(*this);
 			++*this;
  			return result;
		}

		bool operator== (const iterator& rhs) 
		{
			return itr == rhs.itr;

		}
		bool operator!= (const iterator& rhs) 
		{
			return itr != rhs.itr;

		}
		T& operator*()
		{
			return itr->data;
		}
		T *operator->() 
		{
  			return &itr->data;
		}

	};

	
};

int main ()
{
	Stack<int> S;
	
	for (int i=1;i<6;i++)
		S.push (i);

	S.printStack();
	
	S.push (6);
	
	S.printStack();
		
	S.pop ();
	
	S.printStack();

	
	cout<<"\n Index Of 4 Is  "<<S.getIndexOf (4)<<"\n";

	for (Stack<int>::iterator it = S.begin ();it!=S.end ();it++)
	{
		cout<<*it<<"\t";
	}
	cout<<"\n";

	

return 0;
}	

