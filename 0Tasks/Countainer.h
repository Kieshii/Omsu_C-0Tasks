#pragma once
#include<vector>
#include"Box.h"

class Container {
private:
    vector<Box> BoxArray;
    int length;
    int width;
    int height;
    int maxWeight;
public:
    Container(vector<Box> BoxArray, int length, int width, int height, int maxWeight);
    int addBoxToContainer(int k, Box newBox);
    void deleteBoxFromContainer(int i);
    int countBoxesInContainer();
    double sumWeightInContainer();
    int sumValueInContainer();
    Box returnBoxByIndex(int i);
    Box& operator[](const int index);

    friend istream& operator >> (istream& in, Container& container);
    friend ostream& operator << (ostream& out, Container& container);
};


class WeightException: public exception {
    const char* what() const throw () {
        return "Превышен максимальный вес!";
    }
};
