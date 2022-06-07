#pragma once
template <typename T>
class A
{
public:
	void SetData(const T& data);
	T GetData() const;
private:
	T _data;
};