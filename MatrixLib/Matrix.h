#ifndef _MATRIX_
#define _MATRIX_
#include "MyVector.h"

const int MAX_MATRIX_SIZE = 100000;

// ����������������� �������
template <class ValType>
class TMatrix : public TVector<TVector<ValType> >
{
private:
  int mSize;
public:
  TMatrix(int s);
  TMatrix(const TMatrix& mt);                    // �����������
  TMatrix(const TVector<TVector<ValType> >& mt); // �������������� ����
  ~TMatrix();

  int GetSize() { return mSize; }; //��������� �������
  bool operator==(const TMatrix& mt) const;      // ���������
  TMatrix& operator= (const TMatrix& mt);        // ������������
  TMatrix  operator+ (const TMatrix& mt);        // ��������
  TMatrix  operator- (const TMatrix& mt);        // ���������
  TMatrix  operator* (const TMatrix& mt);        // ���������

  // ���� / �����
  friend istream& operator>>(istream& in, TMatrix& mt)
  {
    for (int i = 0; i < mt.size; i++)
    {
      in >> mt.pVector[i];
    }
    return in;
  }
  friend ostream& operator<<(ostream& out, const TMatrix& mt)
  {
    for (int i = 0; i < mt.size; i++)
    {
      out << mt.pVector[i] << endl;
    }
    return out;
  }
};

template<class ValType>
inline TMatrix<ValType>::TMatrix(int s) : TVector<TVector <ValType> >(s)
{
  if (s < 0 || s > MAX_MATRIX_SIZE)
  {
    throw "Oshibka";
  }

  mSize = s;
}

template <class ValType> // ����������� �����������
inline TMatrix<ValType>::TMatrix(const TMatrix<ValType>& mt) : TVector<TVector<ValType> >(mt)
{
  mSize = mt.mSize;
}

template <class ValType> // ����������� �������������� ����
inline TMatrix<ValType>::TMatrix(const TVector<TVector<ValType> >& mt) : TVector<TVector<ValType> >(mt)
{
}

template<class ValType>
inline TMatrix<ValType>::~TMatrix()
{
}

template <class ValType> // ���������
bool TMatrix<ValType>::operator==(const TMatrix<ValType>& mt) const
{
  bool res = true;

  if (this->size != mt.size)
  {
    res = false;
  }
  else 
  {
    for (int i = 0; i < this->size; i++)
    {
      if (this->pVector[i] == mt.pVector[i])
      {
        res = true;
      }
      else res = false;
    }
  }

  return res;
}

template <class ValType> // ������������
inline TMatrix<ValType>& TMatrix<ValType>::operator=(const TMatrix<ValType>& mt)
{
  if (this != &mt)
  {
    if (this->size != mt.size)
    {
      if (this->pVector != NULL)
      {
        delete[] this->pVector;
      }
      this->pVector = new TVector<ValType>[mt.size];
    }

    this->size = mt.size;

    for (int i = 0; i < this->size; i++)
    {
      this->pVector[i] = mt.pVector[i];
    }
  }
  return *this;
}

template <class ValType> // ��������
inline TMatrix<ValType> TMatrix<ValType>::operator+(const TMatrix<ValType>& mt)
{
  if (this->size != mt.size)
  {
    throw "Oshibka";
  }

  TMatrix<ValType> temp(*this);

  for (int i = 0; i < this->size; i++)
  {
    temp.pVector[i] = temp.pVector[i] + mt.pVector[i];
  }
  return temp;
}

template <class ValType> // ���������
inline TMatrix<ValType> TMatrix<ValType>::operator-(const TMatrix<ValType>& mt)
{
  if (this->size != mt.size)
  {
    throw "Oshibka";
  }

  TMatrix<ValType> temp(this->size);
  for (int i = 0; i < this->size; i++)
  {
    temp.pVector[i] = temp.pVector[i] - mt.pVector[i];
  }
  return temp;
}

template<class ValType>
inline TMatrix<ValType> TMatrix<ValType>::operator*(const TMatrix& mt)
{
  TMatrix<ValType> temp(this->size);
  for (int i = 0; i < this->size; i++)
  {
    temp.pVector[i] = temp.pVector[i] * mt.pVector[i];
  }
  return temp;
}
#endif