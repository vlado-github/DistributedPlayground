#pragma once
#include<list>
using namespace std;

template<class T, int size> class GenericPoolManager
{
private:
	list<T*> m_freeList; //list of available memory resources
public:
	/* Constructor - allocates specified amount of memory */
	GenericPoolManager()
	{
		for(int i=0; i<size; i++)
		{
			m_freeList.push_back(::new T);
		}
	}
	
	/* Allocate - returns first available block */
	T* allocate()
	{
		T* resource = 0;
		if(m_freeList.size() > 0)
		{
			resource = *m_freeList.begin();
			m_freeList.pop_front();
			return resource;
		}
		else
		{
			return 0;
		}

	}
	
	/* Release - returns borrowed resource block to the pool */
	void release(T* resource)
	{
		m_freeList.push_back(resource);
	}

	/* Size - available space */
	int getFreeSpaceSize()
	{
		return m_freeList.size();
	}
};