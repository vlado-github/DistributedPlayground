// SmartPointerDemo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "GenericPoolManager.h"
#include "Event.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "*****Memory pool demo*****\n";
	GenericPoolManager<Event,20> eventPool;
	
	cout << "EventPool size = " << eventPool.getFreeSpaceSize() << "\n";

	KeyEvent* e1 = (KeyEvent*) eventPool.allocate();
	e1->setId(120);
	cout << "Key event id=" << e1->getId() << "\n";
	cout << "EventPool size = " << eventPool.getFreeSpaceSize() << "\n";

	MouseEvent* e2 = (MouseEvent*) eventPool.allocate();
	e2->setId(124);
	cout << "Mouse event id=" << e2->getId() << "\n";
	cout << "EventPool size = " << eventPool.getFreeSpaceSize() << "\n";

	// Test SmartPointer offset 
	if(true){
		SmartPointer<BLOBItem> sp = new BLOBItem('abc');
		//sp->setLargeData('abc');
	}


	SmartPointer<BLOBItem> spBLOB = new BLOBItem('def');
	spBLOB->setLargeData('def');
	BLOBEvent* e3 = (BLOBEvent*) eventPool.allocate();
	//e3->setBLOBPtr(spBLOB);
	e3->setId(126);
	cout << "BLOB event id=" << e3->getId() << "\n";
	cout << "EventPool size = " << eventPool.getFreeSpaceSize() << "\n";


	//return memory blocks back to pool
	eventPool.release((Event*)e1);
	eventPool.release((Event*)e2);
	eventPool.release((Event*)e3);
	cout << "After release EventPool size = " << eventPool.getFreeSpaceSize() << "\n";
}

