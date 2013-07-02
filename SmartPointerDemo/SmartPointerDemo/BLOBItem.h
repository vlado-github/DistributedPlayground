#pragma once

class BLOBItem
{
public:
	BLOBItem(char largeData){ mLargeData = largeData; }
	
	void setLargeData(char largeData)
	{
		mLargeData = largeData;
	}
	
	char getLargeData()
	{
		return mLargeData;
	}
private:
	char mLargeData;
};
