#pragma once
#include <D3D10.h>
#include "DataList.h"

enum BUFFER_TYPE{BUFFER_TYPE_VERTEXBUFFER, BUFFER_TYPE_INDEXBUFFER};

class CBuffer: public CDataList{

public:
	CBuffer(UINT elementSize, UINT numElements, bool dynamic, BUFFER_TYPE bufferType, void* pInitialData, ID3D10Device* device);
	virtual ~CBuffer(void);
	void update(void);
	
	void activate(void);
protected:
	void recreateBuffer(void);
	void updateDynamicBuffer(void);

protected:
	ID3D10Buffer* buffer;

	bool dynamic;
	BUFFER_TYPE bufferType;
	ID3D10Device* device;

	UINT numElementsInBuffer;
	DXGI_FORMAT indexFormat;
};