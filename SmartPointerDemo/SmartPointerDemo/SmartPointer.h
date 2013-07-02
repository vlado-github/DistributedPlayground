#pragma once
#include <iostream>

template<class T> class SmartPointer
{
public:
	// Constructors
	SmartPointer(T* ptr = 0) : mPointer(ptr){
	};
	
	SmartPointer(T& ptr)
	{
		mPointer = ptr.mPointer;
		ptr.mPointer = 0;
	};

	// Destructor
	~SmartPointer(void)
	{
		cout << "SmartPointer destructor called!" << "\n";
		delete mPointer;
	};
	
	// Override operator ->
	T* operator->() const
	{
		if(mPointer!=0)
		{
			return mPointer;
		}
		else
		{
			return 0;
		}
	};

	// Override operator *
	T& operator*() const
	{
		if(mPointer!=0)
		{
			return *mPointer;
		}
		else
		{
			return 0;
		}
	};

	// Override operator =
	SmartPointer& operator=(SmartPointer& ptr)
	{
		if(this == &ptr)
		{
			return *this;
		}
		delete mPointer;
		mPointer = ptr.mPointer;
		ptr.mPointer = 0;
		return *this;
	};

private:
	T* mPointer;
};

