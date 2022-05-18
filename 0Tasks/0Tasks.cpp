#include"Countainer.h"
//#include"ComplesNamespace.h"
//using namespace BoxAndContainer;

using namespace std;

int main()
{
    Box box1 = Box(1, 1, 1, 1.0, 1);
    Box box2 = Box(2, 2, 2, 2.0, 2);
    Box box3(3, 3, 3, 3.0, 3);
    Box box4(4, 4, 4, 4.0, 4);
    Box boxArray[] = { box1,box2,box3,box4 };
    cout << box1 << endl; //проверка, что все создается корректно
    cout << box1.getValueSum(boxArray, 4) << endl; // максимальная сумма = 10
    cout << box1.checkLWHsumm(boxArray, 4, 20) << endl; //сумма параметров больше заданного (0)
    cout << box1.checkLWHsumm(boxArray, 4, 50) << endl; //сумма параметров меньше заданного (1)
    cout << box1.getMaxWeight(boxArray, 4, 30) << endl; //максимальный вес = 4
    cout << box1.checkPossibilityAllBoxInBox(boxArray, 4) << endl; //возможно (1)

    vector<Box> boxArr = { box1,box2,box3,box4 };
    Container cont(boxArr, 10, 10, 10, 100);
    Box box5(5, 5, 5, 5.0, 5);
    cont.addBoxToContainer(1, box5);
    cout << cont << endl;
    cont.deleteBoxFromContainer(2);
    cout << cont.countBoxesInContainer() << endl; //в контейнере 4 коробки
    cout << cont.sumWeightInContainer() << endl; //14
    cout << cont.sumValueInContainer() << endl; //14
    cout << cont << endl;
    cout << cont[1] << endl;
}

