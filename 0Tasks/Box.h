#pragma once
using namespace std;
#include <iostream>
#include <stdio.h>

struct Box {
private:
	int length, width, height, value;
	double weight;
public:
	Box(int setLength, int setWidth, int setHeight, double setWeight, int setValue);
	int getLength();
	int getWidth();
	int getHeight();
	int getValue();
	double getWeight();
	int getValueSum(Box boxes[], int size);
	bool checkLWHsumm(Box boxes[], int size, int req);
	double getMaxWeight(Box boxes[], int size, double maxV);
	bool checkPossibilityAllBoxInBox(Box boxes[], int size);
	friend ostream& operator<<(ostream& out, Box& box);
	friend istream& operator>>(istream& in, Box& box);
	friend bool operator==(Box& box1, Box& box2);
};
