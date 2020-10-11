#ifndef _MY_VECTOR_
#define _MY_VECTOR_

#include <iostream>

using namespace std;

const int MAX_VECTOR_SIZE = 100000;

//������ �������
template <class ValType>
class TVector
{
protected:
  ValType* pVector;
  int size;
public:
  TVector();
  TVector(int _v);
  TVector(int s, int si);
  TVector(const TVector& v);                // ����������� �����������
  virtual ~TVector();

  int GetSize() { return size; } // ������ �������

  ValType& operator[](int pos);             // ������
  bool operator==(const TVector& v) const;  // ���������
  TVector& operator=(const TVector& v);     // ������������

  // ��������� ��������
  TVector  operator+(const ValType& val);   // ��������� ������
  TVector  operator-(const ValType& val);   // ������� ������
  TVector  operator*(const ValType& val);   // �������� �� ������
  TVector  operator/(const ValType& val);   //������ �� ������

  // ��������� ��������
  TVector  operator+(const TVector& v);     // ��������
  TVector  operator-(const TVector& v);     // ���������
  TVector  operator*(const TVector& v);     // ��������� ������������

   // ����-�����
  friend istream& operator>>(istream& in, TVector& v)
  {
    for (int i = 0; i < v.size; i++)
      in >> v.pVector[i];
    return in;
  }
  friend ostream& operator<<(ostream& out, const TVector& v)
  {
    for (int i = 0; i < v.size; i++)
      out << v.pVector[i] << ' ';
    return out;
  }
};

template<class ValType>
inline TVector<ValType>::TVector()
{
  size = 0;
}

template<class ValType>
TVector<ValType>::TVector(int v)
{
  if (v < 0 || v > MAX_VECTOR_SIZE)
  {
    throw "Oshibka";
  }

  size = v;
  pVector = new ValType[size];
  for (int i = 0; i < size; i++)
  {
    pVector[i] = v;
  }
}

template <class ValType>
TVector<ValType>::TVector(int s, int si)
{
  if (si < 0)
  {
    throw "Oshibka";
  }
  size = s;
  pVector = new ValType[size];

  for (int i = 0; i < size; i++)
  {
    pVector[i] = si;
  }
}

template <class ValType> //����������� �����������
TVector<ValType>::TVector(const TVector<ValType>& v)
{
  size = v.size;
  pVector = new ValType[size];
  for (int i = 0; i < size; i++)
  {
    pVector[i] = v.pVector[i];
  }
}

template <class ValType>
TVector<ValType>::~TVector()
{
  if (pVector != 0)
  {
    delete[] pVector;
  }
  pVector = 0;
}

template <class ValType> // ������
ValType& TVector<ValType>::operator[](int index)
{
  if (index < 0 || index > size)
  {
    throw "Oshibka";
  }

  if ((index >= 0) && (index < size))
  {
    return pVector[index];
  }

  return pVector[0];
}

template <class ValType> // ���������
bool TVector<ValType>::operator==(const TVector& v) const
{
  bool res = true;

  if (size != v.size)
  {
    res = false;
  }

  for (int i = 0; i < size; i++)
  {
    if (pVector[i] != v.pVector[i])
    {
      res = false;
    }
  }

  return res;
}

template <class ValType> // ������������
TVector<ValType>& TVector<ValType>::operator=(const TVector& v)
{
  if (this == &v)
  {
    return *this;
  }

  size = v.size;
  pVector = new ValType[size];
  for (int i = 0; i < size; i++)
  {
    pVector[i] = v.pVector[i];
  }
  return *this;
}

template <class ValType> // ��������� ������
TVector<ValType> TVector<ValType>::operator+(const ValType& val)
{
  TVector<ValType> res;
  res.size = size;
  res.pVector = new ValType[res.size];

  for (int i = 0; i < res.size; i++)
  {
    res.pVector[i] = pVector[i] + val;
  }
  return res;
}

template <class ValType> // ������� ������
TVector<ValType> TVector<ValType>::operator-(const ValType& val)
{
  TVector<ValType> res;
  res.size = size;
  res.pVector = new ValType[res.size];

  for (int i = 0; i < res.size; i++)
  {
    res.pVector[i] = pVector[i] - val;
  }
  return res;
}

template <class ValType> // �������� �� ������
TVector<ValType> TVector<ValType>::operator*(const ValType& val)
{
  TVector<ValType> res;
  res.size = size;
  res.pVector = new ValType[res.size];

  for (int i = 0; i < res.size; i++)
  {
    res.pVector[i] = pVector[i] * val;
  }
  return res;
}

template<class ValType>
inline TVector<ValType> TVector<ValType>::operator/(const ValType& val)
{
  TVector<ValType> res;
  res.size = size;
  res.pVector = new ValType[res.size];

  for (int i = 0; i < res.size; i++)
  {
    res.pVector[i] = pVector[i] / val;
  }
  return res;
}

template <class ValType> // ��������
TVector<ValType> TVector<ValType>::operator+(const TVector<ValType>& v)
{
  if (v.size != size)
  {
    throw "Oshibka";
  }
  TVector<ValType> res;
  res.size = size;
  res.pVector = new ValType[res.size];
  for (int i = 0; i < res.size; i++)
  {
    res.pVector[i] = pVector[i] + v.pVector[i];
  }
  return res;
}

template <class ValType> // ���������
TVector<ValType> TVector<ValType>::operator-(const TVector<ValType>& v)
{
  if (v.size != size)
  {
    throw "Oshibka";
  }
  TVector<ValType> res;
  res.size = size;
  res.pVector = new ValType[res.size];
  for (int i = 0; i < res.size; i++)
  {
    res.pVector[i] = pVector[i] - v.pVector[i];
  }
  return res;
}

template <class ValType> // ��������� ������������
TVector<ValType> TVector<ValType> ::operator*(const TVector<ValType>& v)
{
  if (v.size != size)
  {
    throw "Oshibka";
  }
  TVector<ValType> res;
  res.size = size;
  res.pVector = new ValType[res.size];
  for (int i = 0; i < res.size; i++)
  {
    res.pVector[i] = pVector[i] * v.pVector[i];
  }
  return res;
}
#endif