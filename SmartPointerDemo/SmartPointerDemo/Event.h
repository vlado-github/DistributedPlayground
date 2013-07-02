#pragma once
#include "SmartPointer.h"
#include "BLOBItem.h"

class Event
{
public:
	void setId(int id);
	int getId();
private:
	int m_id;
};

/* Represents key press event */
class KeyEvent : public Event
{
public:
	int getKeyCode()
	{
		return m_keycode;
	}
private:
	int m_keycode;
};

/* Represents mouse click event */
class MouseEvent : public Event
{
public:
	int getX()
	{
		return m_x;
	}

	int getY()
	{
		return m_y;
	}
private:
	int m_x;
	int m_y;
};

/* Represents event with binary large object (BLOB) */
class BLOBEvent : public Event
{
public :
	BLOBEvent():mBLOBPtr(new BLOBItem('s'))
	{
	}

	void setBLOBPtr(SmartPointer<BLOBItem> BLOBPtr)
	{ 
		mBLOBPtr = BLOBPtr; 
	} 
private:
	SmartPointer<BLOBItem> mBLOBPtr;
};