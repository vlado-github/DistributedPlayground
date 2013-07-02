// SmartPointerDemo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "GenericPoolManager.h"
#include "Event.h"
#include "SmartPointerRefCount.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "*****Memory pool demo*****\n";
	//GenericPoolManager<Event,20> eventPool;
	GenericPoolManager<MouseEvent,20> mouseEventPool;
	GenericPoolManager<KeyEvent,20> keyEventPool;
	GenericPoolManager<BLOBEvent,20> blobEventPool;
	
	cout << "EventPool size = " << keyEventPool.getFreeSpaceSize() << "\n";

	KeyEvent* e1 = keyEventPool.allocate();
	e1->setId(120);
	cout << "Key event id=" << e1->getId() << "\n";
	cout << "KeyEventPool size = " << keyEventPool.getFreeSpaceSize() << "\n";

	MouseEvent* e2 = mouseEventPool.allocate();
	e2->setId(124);
	cout << "Mouse event id=" << e2->getId() << "\n";
	cout << "MouseEventPool size = " << mouseEventPool.getFreeSpaceSize() << "\n";

	// Test SmartPointer offset 
	if(true){
		SmartPointer<BLOBItem> sp = new BLOBItem('abc');
	}


	SmartPointer<BLOBItem> spBLOB = new BLOBItem('def');
	spBLOB->setLargeData('def');
	BLOBEvent* e3 = blobEventPool.allocate();
	e3->setId(126);
	e3->setBLOBPtr(spBLOB);
	cout << "BLOB event id=" << e3->getId() << "\n";
	cout << "BLOBEventPool size = " << blobEventPool.getFreeSpaceSize() << "\n";


	//return memory blocks back to pool
	keyEventPool.release((KeyEvent*)e1);
	mouseEventPool.release((MouseEvent*)e2);
	blobEventPool.release((BLOBEvent*)e3);
	cout << "After release KeyEventPool size = " << keyEventPool.getFreeSpaceSize() << "\n";
	cout << "After release MouseEventPool size = " << mouseEventPool.getFreeSpaceSize() << "\n";
	cout << "After release BLOBEventPool size = " << blobEventPool.getFreeSpaceSize() << "\n";

	//reference pointer demo
	SmartPointerRefCount<BLOBItem> sprc01 = new BLOBItem('a');
	SmartPointerRefCount<BLOBItem> sprc02, sprc03, sprc04;

	sprc01->setLargeData('q');
	sprc02 = sprc03 = sprc04 = sprc01;
	cout << "sprc01: " << sprc01->getLargeData() << "\n";
	cout << "sprc02: " << sprc02->getLargeData() << "\n";
	cout << "sprc03: " << sprc03->getLargeData() << "\n";
	cout << "sprc04: " << sprc04->getLargeData() << "\n";

	sprc03->setLargeData('w');
	cout << "sprc01: " << sprc01->getLargeData() << "\n";
	cout << "sprc02: " << sprc02->getLargeData() << "\n";
	cout << "sprc03: " << sprc03->getLargeData() << "\n";
	cout << "sprc04: " << sprc04->getLargeData() << "\n";
}

