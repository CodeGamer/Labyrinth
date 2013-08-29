#pragma once
#include <string.h>

class CDataList{
public:
	CDataList(unsigned int elementSize, unsigned int initialSize = 2);
	virtual ~CDataList(void);

	void setData(unsigned int index, void* pData);
	void setDatas(unsigned int index, unsigned int numElements, void* pDatas);

	void getData(unsigned int index, void* pTarget);
	void getDatas(unsigned int index, unsigned int numElements, void* pTarget);

	void addData(void* pData);
	void addDatas(unsigned int numElements , void* pDatas);

	void reserveMemory(unsigned int numExtraElements);

	void deleteElement(unsigned int index);

	void deleteElements(unsigned int index, unsigned int numElements);
protected:
	char* pData;
	
	unsigned int elementSize;
	unsigned int numElements;
	unsigned int capacity;

protected:

};