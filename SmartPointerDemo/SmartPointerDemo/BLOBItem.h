#pragma once

class BLOBItem
{
public:
	BLOBItem(char largeData){ mLargeData = largeData; }
	void setLargeData(char largeData)
	{
		mLargeData = largeData;
	}
private:
	char mLargeData;
};
