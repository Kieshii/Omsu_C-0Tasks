#include"Box.h"

	Box::Box(int setLength, int setWidth, int setHeight, double setWeight, int setValue) {
		length = setLength;
		width = setWidth;
		height = setHeight;
		value = setValue;
		weight = setWeight;
	}
	int Box::getLength() {
		return length;
	}
	int Box::getWidth() {
		return width;
	}
	int Box::getHeight() {
		return height;
	}
	int Box::getValue() {
		return value;
	}
	double Box::getWeight() {
		return weight;
	}
	int Box::getValueSum(Box boxes[], int size) {
		int ValueSum = 0;
		for (int i = 0; i < size; i++) {
			ValueSum += boxes[i].getValue();
		}
		return ValueSum;
	}
	bool Box::checkLWHsumm(Box boxes[], int size, int req) {
		int LWHsum = 0;
		for (int i = 0; i < size; i++) {
			LWHsum += boxes[i].getLength() + boxes[i].getHeight() + boxes[i].getWidth();
		}
		if (LWHsum <= req) {return true;}
		return false;
	}
	double Box::getMaxWeight(Box boxes[], int size, double maxV) {
		double MaxWeight = 0;
		for (int i = 0; i < size; i++) {
			if (MaxWeight < boxes[i].getWeight()) { MaxWeight = boxes[i].getWeight(); }
		}
		return MaxWeight;
	}
	bool Box::checkPossibilityAllBoxInBox(Box boxes[], int size) {
		int countSize = 0;
		int countV = 0;
		int Comb = ( ((size - 1)*(size))/2 ); //сочетания с повторениями
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if ((boxes[i].getLength() * boxes[i].getWidth() * boxes[j].getHeight() < boxes[j].getLength() * boxes[j].getWidth() * boxes[j].getHeight()))
				{
					countV++;
				}
			}
		}
		if (Comb == countV)
		{
			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size; j++) {
					if ((boxes[i].getLength() < boxes[j].getLength() && boxes[i].getHeight() < boxes[j].getHeight() && boxes[i].getWidth() < boxes[j].getWidth()))
					{
						countSize++;
					}
				}
			}
			if (Comb != countSize) {
				return false;
			}
			return true;
		}
		else return false;
	} 


ostream& operator<<(ostream& out, Box& box)
{
	out << "Box(" << box.height << ", " << box.width << ", " << box.length << ", " << box.weight << ", " << box.value << ")";
	return out;
}

istream& operator>>(istream& in, Box& box)
{
	in >> box.height;
	in >> box.width;
	in >> box.length;
	in >> box.weight;
	in >> box.value;
	return in;
}

bool operator==(Box & box1, Box & box2)
{
	return (box1.getLength() == box2.getLength()
		&& box1.getHeight() == box2.getHeight()
		&& box1.getWidth() == box2.getWidth()
		&& box1.getValue() == box2.getValue()
		&& box1.getWeight() == box2.getWeight());
}
