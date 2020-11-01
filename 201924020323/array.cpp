//array.cpp 
#include <iostream> 
#include <string> 
#include "array.h"
using namespace std; 

//������Ϣ
string errorMsg[] = {
    "Invalid array size",
    "Memory allocation error",
    "Invalid index: "
};

//��������
void Array::handleError(ErrorType error, int badIndex) const {
    cout << errorMsg[error]; //���ݴ������ͣ������Ӧ������Ϣ
    if (error == indexOutOfRange)
        cout << badIndex; //������±�Խ��������������±�ֵ
    cout << endl;
    exit(-1);
}

//���캯��
Array::Array(int sz) {
    if (sz <= 0) //����Ƿ�sz<= 0 
        handleError(invalidArraySize);
    size = sz;
    data = new int[size];
    if(data == NULL) {
        handleError(memoryAllocationError);
    }
}//finished

//��������
Array::~Array() {
    if (data) {
        delete[] data;
    }
}//finished

//���ƹ��캯��
Array::Array(const Array& a) {
    if(a.data == NULL) {
        handleError(invalidArraySize);
    }
    size = a.size;
    data = data = new int[size];
    if(data == NULL) {
        handleError(memoryAllocationError);
    }
    for (int i = 0; i < size; i++) {
        if (a.data + i) {
            *(data + i) = *(a.data + i);
        }
    }
}//finished

//���������±�Ϊn��Ԫ�ص�ֵΪvalue
void Array::setElement(int n, int value) {
    if(n >= size) {
        handleError(indexOutOfRange,n);
    }
    *(data + n) = value;
}//finished

//ȡ�����±�Ϊn��Ԫ�ص�ֵ
int& Array::getElement(int n) {
    if(n >= size) {
        handleError(indexOutOfRange,n);
    }
    return  *(data + n);
}//finished

//���������С
int Array::arraySize() const {
    return size;
}//finished

//�������С�޸�Ϊsz 
void Array::resize(int sz) {
    if (sz <= 0) //����Ƿ�sz<= 0 
        handleError(invalidArraySize);
    if (sz == size) //���size==sz�����˳�������
        return;

    int* newlist = new int[sz]; //�����µ������ڴ�
    if (newlist == NULL) //�ڴ������Ƿ�ɹ���
        handleError(memoryAllocationError);

    int n = (sz <= size) ? sz : size;

    int* srcptr = data; //ԭ�����׵�ַ 
    int* destptr = newlist; //�������׵�ַ
    while (n--) {
        *destptr++ = *srcptr++; //��������Ԫ��
    }
    delete[] data; //�ͷ�ԭ������ռ�ڴ�
    data = newlist; //ʹdataָ�������� 
    size = sz; //����
}
