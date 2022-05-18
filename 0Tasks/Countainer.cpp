#include"Countainer.h"


Container::Container(vector<Box> setBoxArray, int setLength, int setWidth, int setHeight, int setMaxWeight) {
    int sum = 0;
    for (int i = 0; i < BoxArray.size(); i++) {
        sum += BoxArray[i].getWeight();
    }
    if (sum > maxWeight) {
        throw WeightException();
    }
    BoxArray = setBoxArray;
    length = setLength;
    width = setWidth;
    height = setHeight;
    maxWeight = setMaxWeight;
}


int Container::addBoxToContainer(int k, Box newBox) {
    double sum = 0;
    for (int i = 0; i < BoxArray.size(); i++) {
        sum += BoxArray[i].getWeight();
    }
    if ((sum + newBox.getWeight()) > maxWeight) {
        throw WeightException();
    }
    auto iter = BoxArray.begin();
    BoxArray.insert(iter + k - 1, newBox);
    return k;
}

void Container::deleteBoxFromContainer(int i) {
    auto iter = BoxArray.cbegin();
    BoxArray.erase(iter + i - 1);
}

int Container::countBoxesInContainer() {
    return BoxArray.size();
}

double Container::sumWeightInContainer() {
    double sum = 0;
    for (int i = 0; i < BoxArray.size(); i++) {
        sum += BoxArray[i].getWeight();
    }
    return sum;
}

int Container::sumValueInContainer() {
    int sum = 0;
    for (int i = 0; i < BoxArray.size(); i++) {
        sum += BoxArray[i].getValue();
    }
    return sum;
}

Box Container::returnBoxByIndex(int i) {
    return BoxArray[i];
}

ostream& operator <<(ostream& out, Container& container) {
    out << "Container(" << container.length << ", " << container.width << ", " << container.height << ", " << container.maxWeight << ", ";
    for (int i = 0; i < container.BoxArray.size(); i++) {
        out << container.BoxArray[i] << ", ";
    }
    out << ")";
    return out;
}

istream& operator >> (istream& in, Container& container) {
    in >> container.height;
    in >> container.width;
    in >> container.length;
    in >> container.maxWeight;
    for (int i = 0; i < container.BoxArray.size(); i++) {
        in >> container.BoxArray[i];
    }
    return in;
}

Box& Container::operator[](const int i) {
    return BoxArray[i];
}
