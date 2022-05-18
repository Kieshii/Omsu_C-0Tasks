#pragma once
#include <iostream>
#include <stdio.h>
#include<vector>
#include"Box.h"

namespace BoxAndContainer {
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

		friend ostream& operator <<(ostream& out, Box& box);
		friend istream& operator >> (istream& in, Box& box);
		friend bool operator == (Box& box1, Box& box2);
	};

	class Container {
	private:
		vector<Box> array;
		int length;
		int width;
		int height;
		int maxWeight;
	public:
		Container(vector<Box> array, int length, int width, int height, int maxWeight);
		int addBoxToContainer(int k, Box newBox);
		void deleteBoxFromContainer(int i);
		int countBoxesInContainer();
		double sumWeightInContainer();
		int sumValueInContainer();
		Box returnBoxByIndex(int i);
		Box& operator[](const int index);

		friend istream& operator >> (istream& in, Container& container);
		friend ostream& operator <<(ostream& out, Container& container);
	};

}