#pragma once
#include <stdlib.h>
template <class T> class CLinkedList{
public:
	CLinkedList(void):
	firstKnot(NULL),
	lastKnot(NULL),
	selectedKnot(NULL),
	numElements(0)
	{
	
	}
	virtual ~CLinkedList(void){
		deleteEverything();
	}

	void addDataAtEnd(T& data){
		CDataKnot* newKnot = new CDataKnot(data);
		if(numElements == 0){
			selectedKnot = firstKnot = lastKnot = newKnot;
		}else{
			lastKnot->sucessor = newKnot;
			newKnot->predecessor = lastKnot;
			lastKnot = newKnot;
		}
		numElements ++;
	}

	void addDataAtBeginning(T& data){
		CDataKnot* newKnot = new CDataKnot(data);
		if(numElements == 0){
			selectedKnot = firstKnot = lastKnot = newKnot;
		}else{
			firstKnot->predecessor = newKnot;
			newKnot->sucessor = lastKnot;
			firstKnot = newKnot;
		}
		numElements ++;
	}

	void setSelectedData(T& data){
		selectedKnot->setData(data);
	}

	void addDataAfterSelected(T& data){
		CDataKnot* newKnot = new CDataKnot(data);
		if(numElements == 0){
			selectedKnot = firstKnot = lastKnot = newKnot;
		}else{
			if(selectedKnot->sucessor){
				selectedKnot->sucessor->predecessor = newKnot;
				newKnot->sucessor = selectedKnot->sucessor;
			}
			selectedKnot->sucessor = newKnot;
			newKnot->predecessor = selectedKnot;
		}
		numElements ++;
	}

	void addDataBeforeSelected(T& data){
		CDataKnot* newKnot = new CDataKnot(data);
		if(numElements == 0){
			selectedKnot = firstKnot = lastKnot = newKnot;
		}else{
			if(selectedKnot->predecessor){
				selectedKnot->predecessor->sucessor = newKnot;
				newKnot-predecessor = selectedKnot->predecessor;
			}
			selectedKnot->predecessor = newKnot;
			newKnot->sucessor = selectedKnot;
		}
		numElements ++;
	}

	void deleteSelectedAndMoveRight(void){
		deleteSelectedAndMove(true);
	}

	void deleteSelectedAndMoveLeft(void){
		deleteSelectedAndMove(false);
	}

	void deleteEverything(void){
		goToFirstKnot();
		for(unsigned int i = 0; i < numElements; i++){
			deleteSelectedAndMoveRight();
		}
	}

	void goToFirstKnot(void){
		selectedKnot = firstKnot;
	}
	void goToLastKnot(void){
		selectedKnot = lastKnot;
	}
	void goRight(void){
		if(selectedKnot->sucessor)
			selectedKnot = selectedKnot->sucessor;
	}
	void goLeft(void){
		if(selectedKnot->predecessor)
			selectedKnot = selectedKnot->predecessor;
	}
	bool lastKnotReached(void){
		return selectedKnot == lastKnot;
	}
	bool firstKnotReached(void){
		return selectedKnot == firstKnot;
	}

	unsigned int getNumElements(void){
		return numElements;
	}

	T& getSelectedData(void){
		return selectedKnot->getData();
	}

	void operator ++ (int){
		goRight();
	}

	void operator -- (int){
		goLeft();
	}

protected:
	void deleteSelectedAndMove(bool right){
		CDataKnot* nextKnot;
		if(right){
			nextKnot = selectedKnot->sucessor;
			if(!nextKnot)
				nextKnot = selectedKnot->predecessor;
		}else{
			nextKnot = selectedKnot->predecessor;
			if(!nextKnot)
				nextKnot = selectedKnot->sucessor;
		}
		if(numElements == 1){
			firstKnot = lastKnot = NULL;
		}else if(selectedKnot == lastKnot){
			lastKnot = selectedKnot->predecessor;
		}else if(selectedKnot == firstKnot){
			firstKnot = selectedKnot->sucessor;
		}

		delete selectedKnot;
		selectedKnot = nextKnot;
		numElements --;
	}
	class CDataKnot{
	public:
		CDataKnot(T& data):
		predecessor(NULL),
		sucessor(NULL)
		{
			pData = (T*)malloc(sizeof(T));
			*pData = data;
		}
		virtual ~CDataKnot(){
			free(pData);
			if(predecessor){
				predecessor->sucessor = sucessor;
			}
			if(sucessor){
				sucessor->predecessor = predecessor;
			}
		}
		T& getData(void){
			return *pData;
		}
		void setData(T& data){
			*pData = data;
		}
	CDataKnot* predecessor;
	CDataKnot* sucessor;
	protected:
		T* pData;
		
	};

protected:
	CDataKnot* firstKnot;
	CDataKnot* lastKnot;
	CDataKnot* selectedKnot;
	unsigned int numElements;
};