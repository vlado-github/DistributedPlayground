#pragma once

/* Smart pointer with reference counting */
template<class T> class SmartPointerRefCount
{
public:
	// Constructor
	SmartPointerRefCount(T* ptr = 0):mPointer(ptr)
	{
		mRefCnt = new int(1);
	}
	
	// Copy constructor
	SmartPointerRefCount(SmartPointerRefCount& spRefCount)
	{
		mPointer = spRefCount.mPointer;
		mRefCnt - spRefCount.mRefCnt;
		++*mRefCnt;
	}
	
	// Destructor
	~SmartPointerRefCount()
	{
		if(--*mRefCnt == 0)
		{
			delete mPointer;
			delete mRefCnt;
		}
	}

	// Override operator =
	SmartPointerRefCount& operator=(SmartPointerRefCount& spRefCount)
	{
		if(this == &spRefCount)
			return *this;

		if(--*mRefCnt == 0)
		{
			delete mPointer;
			delete mRefCnt;
		}
		mPointer = spRefCount.mPointer;
		mRefCnt = spRefCount.mRefCnt;
		++*(spRefCount.mRefCnt);

		return *this;
	}

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

private:
	T* mPointer;
	int* mRefCnt;
};

