#include "Temp.h"

template <typename T>
void A<T>::SetData(const T& data)
{
	_data = data;
}

template <typename T>
T A<T>::GetData() const
{
	return _data;
}