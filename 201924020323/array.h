#ifndef ARRAY_H 
#define ARRAY_H 
using namespace std;

//�������ͼ��ϣ������������͵Ĵ��������С�����ڴ���������±�Խ��
enum ErrorType {
    invalidArraySize,
    memoryAllocationError,
    indexOutOfRange
};

class Array {
public:
    Array(int sz = 50); //���캯��
    Array(const Array& a); //���ƹ��캯��
    ~Array(); //�������� 
    void setElement(int n, int value); //���õ�n��Ԫ�أ������±�Ϊn-1����ֵΪvalue
    int& getElement(int n); //ȡ��n��Ԫ�أ������±�Ϊn-1����Ԫ��
    int arraySize() const; //���������С
    void resize(int sz); //��̬�ı�����Ĵ�С
private:
    int* data; //int����ָ�룬���ڴ�Ŷ�̬����������ڴ��׵�ַ
    int size; //�����С
    void handleError(ErrorType error, int badIndex = 0) const; //��������
};

#endif 

