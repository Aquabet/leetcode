/**
 **����� 201924020323
 **���ڴ���Ĳ���Feature ������BUG������BUG����
 **������δ��ʼ����Ԫ�� ����C������Ƶġ�Feature�� Ϊһ��δ��ʼ������
 **Array::arraySize()�����ķ���ֵ�������Ԫ�ظ���n, ������±�Ϊ�� 0 ~ (n-1)��
 **/
#include <iostream> 
#include <ctime>
#include "array.h"

using namespace std; 

int main() {
    Array a(10);
    srand(time(0));
    int i;

    for (i = 0; i < 10; ++i)
        a.setElement(i, 1 + rand() % 9);

    cout << "Size Of Array ��" << a.arraySize() << endl;
    cout << "����a��Ԫ��ֵ��";
    for (i = 0; i < a.arraySize(); ++i)
        cout << a.getElement(i) << " ";
    cout << endl;

    cout << "��������a�Ĵ�СΪԭ����2��: " << endl;
    a.resize(a.arraySize() * 2);
    cout << "������С������Ĵ�С: " << a.arraySize() << endl;

    cout << "�ø��ƹ��캯����������a��ʼ��b" << endl;
    Array b(a);

    cout << "�޸�����a�����һ��Ԫ��ֵΪ100" << endl;
    a.setElement(a.arraySize() - 1, 100);
    cout << "����a��ֵ: ";
    for (i = 0; i < a.arraySize(); ++i)
        cout << a.getElement(i) << " ";
    cout << endl;

    cout << "����b��Ԫ��ֵ: ";
    for (i = 0; i < b.arraySize(); ++i)
        cout << b.getElement(i) << " ";
    cout << endl;
    
//	���������
//	a.resize(-10);
//  a.setElement(1000, 1000);
//  a.getElement(1000);

    cout << "Quit...." << endl;
    return 0;
}
