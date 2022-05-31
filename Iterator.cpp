#include <iostream>
#include "Iterator.h"

     Iterator::Iterator(){}


	Iterator::Iterator(AbsFSys filesys){
	 Filesys=filesys;
	 end_FS=filesys.kolvoClast;
	}

	void Iterator::StartPosition( long position){
		if (position<end_FS)
			Position=position;
	}

	unsigned int Iterator::CurrentPosition(){
	  return Position;
	}


	void Iterator::FinalPosition(unsigned long position){
		if(position<=end_FS)
			final=position;
	}

	void Iterator::First(){
       Position=0;
	}

	void Iterator::End(){
	  final=end_FS;
	}

	void Iterator::Next(){
	  Position++;
	}
	void Iterator::Back(){
	  Position--;
	}

	bool Iterator::IsDone(){
	if(Position>final)
	return true;
	else
	return false;
	}
	bool Iterator::IsStart(){
	if(Position<final || Position>end_FS)
	return true;
	else
	return false;
	}




	bool Iterator::GetCurrent(byte *dataBuffer){
		return Filesys.ReedCluster(Position,dataBuffer);
	}
