#ifndef _MATRIX_
#define _MATRIX_
#include "MyVector.h"

const int MAX_MATRIX_SIZE = 100000;

// Верхнетреугольная матрица
template <class ValType>
class TMatrix : public TVector<TVector<ValType> >
{
private:
  int mSize;
public:
  TMatrix(int s = 10);
  TMatrix(const TMatrix& mt);                    // копирование
  TMatrix(const TVector<TVector<ValType> >& mt); // преобразование типа
  ~TMatrix();

  int GetSize() { return mSize; }; //Получение размера
  bool operator==(const TMatrix& mt) const;      // сравнение
  TMatrix& operator= (const TMatrix& mt);        // присваивание
  TMatrix  operator+ (const TMatrix& mt);        // сложение
  TMatrix  operator- (const TMatrix& mt);        // вычитание
  TMatrix  operator* (const TMatrix& mt);        // умножение

  // ввод / вывод
  friend istream& operator>>(istream& in, TMatrix& mt)
  {
    for (int i = 0; i < mt.Size; i++)
    {
      in >> mt.pVector[i];
    }
    return in;
  }
  friend ostream& operator<<(ostream& out, const TMatrix& mt)
  {
    for (int i = 0; i < mt.Size; i++)
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
    throw "Error";
  }
  mSize = s;

  for (int i = 0; i < s; i++)
  {
    this->pVector[i] = TVector<ValType>(s - i);
  }

}

template <class ValType> // конструктор копирования
inline TMatrix<ValType>::TMatrix(const TMatrix<ValType>& mt) : TVector<TVector<ValType> >(mt)
{
  mSize = mt.mSize;
}

template <class ValType> // конструктор преобразования типа
inline TMatrix<ValType>::TMatrix(const TVector<TVector<ValType> >& mt) : TVector<TVector<ValType> >(mt)
{
}

template<class ValType>
inline TMatrix<ValType>::~TMatrix()
{
  if (mSize != 0)
  {
    mSize = NULL;
  }
}

template <class ValType> // сравнение
bool TMatrix<ValType>::operator==(const TMatrix<ValType>& mt) const
{
  bool res = true;
  int S = this->Size;
  if (S != mt.Size)
  {
    res = false;
  }
  for (int i = 0; i < S; i++)
  {
    if (this->pVector[i] == mt.pVector[i])
    {
      res = true;
    }
    else res = false;
  }
  return res;
}

template <class ValType> // присваивание
inline TMatrix<ValType>& TMatrix<ValType>::operator=(const TMatrix<ValType>& mt)
{
  if (this != &mt)
  {
    if (this->Size != mt.Size)
    {
      if (this->pVector != NULL)
      {
        delete[] this->pVector;
      }
      this->pVector = new TVector<ValType>[mt.Size];
    }
    this->Size = mt.Size;
    for (int i = 0; i < this->Size; i++)
    {
      this->pVector[i] = mt.pVector[i];
    }
  }
  return *this;
}

template <class ValType> // сложение
inline TMatrix<ValType> TMatrix<ValType>::operator+(const TMatrix<ValType>& mt)
{
  if (this->GetSize() != mt.Size)
  {
    throw "Error";
  }

  TMatrix<ValType> tmp(*this);
  for (int i = 0; i < this->Size; i++)
  {
    tmp.pVector[i] = tmp.pVector[i] + mt.pVector[i];
  }
  return tmp;
}

template <class ValType> // вычитание
inline TMatrix<ValType> TMatrix<ValType>::operator-(const TMatrix<ValType>& mt)
{
  if (this->GetSize() != mt.Size)
  {
    throw "Error";
  }

  TMatrix<ValType> tmp(*this);
  for (int i = 0; i < this->Size; i++)
  {
    tmp.pVector[i] = tmp.pVector[i] - mt.pVector[i];
  }
  return tmp;
}

template<class ValType>
inline TMatrix<ValType> TMatrix<ValType>::operator*(const TMatrix& mt)
{
  if (this->GetSize() != mt.Size)
  {
    throw "Error";
  }

  TMatrix<ValType> tmp(*this);
  TMatrix<ValType> res(this->Size);

  int row = this->Size;
  int col = this->Size;


  for (int i = 0; i < row; i++)
  {
    for (int j = 0; j < col; j++)
    {
      res.pVector[i][j] = 0;
      for (int k = 0; k < col; k++)
      {
        res.pVector[i][j] += (tmp.pVector[i][k] * mt.pVector[k][j]);
      }
      col--;
    }
  }
  return res;
}

#endif