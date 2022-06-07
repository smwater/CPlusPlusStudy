#pragma once
#include <utility>

class MyVector
{
public:
    // 기본 생성자
    MyVector() = default;

    // count만큼 공간이 할당된 생성자
    explicit MyVector(size_t count)
        : _container(new int[count]), _size(count), _capacity(count)
    {
        for (size_t i = 0; i < count; i++)
        {
            _container[i] = 0;
        }
    }

    // 복사 생성자. 깊은 복사(deep copy)가 이뤄져야 한다.
    MyVector(const MyVector& other)
        : _container(new int[other._capacity]), _size(other._size), _capacity(other._capacity)
    {
        
        for (size_t i = 0; i < _size; i++)
        {
            _container[i] = other[i];
        }
        
    }

    // 할당 연산자. 깊은 복사(deep copy)가 이뤄져야 한다.
    MyVector& operator=(MyVector rhs)
    {
        std::swap(_container, rhs._container);
        std::swap(_size, rhs._size);
        std::swap(_capacity, rhs._capacity);

        return *this;
    }

    // 소멸자
    ~MyVector()
    {
        clear();
    }

    // 첫 번째 요소를 가리키는 반복자를 반환한다.
    int* begin()
    {
        // 벡터가 비어있다면 end()를 반환
        if (empty())
        {
            return end();
        }

        // 벡터가 비어있지 않다면 첫 번째 원소를 가리키는 반복자를 반환한다.
        return _container;
    }

    const int* begin() const
    {
        // 벡터가 비어있다면 end()를 반환
        if (empty())
        {
            return end();
        }

        // 벡터가 비어있지 않다면 첫 번째 원소를 가리키는 반복자를 반환한다.
        return _container;
    }

    // 마지막 요소의 다음 번째를 가리키는 반복자를 반환한다.
    int* end() { return _container + _size; }

    const int* end() const { return _container + _size; }

    // 컨테이너가 비었는지 검사한다.
    bool                empty() const
    {
        if (0 == _size)
        {
            return true;
        }
        else
            return false;
    }

    // 원소의 개수를 반환한다.
    size_t              size() const { return _size; }

    // 현재 할당된 공간의 크기를 반환한다.
    size_t              capacity() const { return _capacity; }

    // pos에 위치한 원소의 참조를 반환한다.
    // vector<int> v;
    // v[2];
    int& operator[](size_t pos) { return _container[pos]; }
    const int& operator[](size_t pos) const { return _container[pos]; }

    // 컨테이너의 첫 번째 원소의 참조를 반환한다.
    int& front() { return *begin(); }
    const int& front() const { return *begin(); }

    // 컨테이너의 마지막 원소의 참조를 반환한다.
    int& back() { return *(end() - 1); }
    const int& back() const { return *(end() - 1); }

    // 컨테이너를 비운다.
    void                clear()
    {
        delete[] _container;
        _container = nullptr;
        _size = 0;
        _capacity = 0;
    }

    // pos 이전 위치에 value를 삽입한다.
    // value가 삽입된 곳을 가리키는 포인터를 반환한다.
    int* insert(int* pos, int value)
    {
        // 1. 얼마나 떨어져있는지 확인한다.
        int dist = pos - begin();

        // 2. 용량을 확인한다.
        if (_capacity == 0)
        {
            reserve(1);

            pos = begin() + dist;
        }
        else if (_size == _capacity)
        {
            reserve(_capacity * 2);

            pos = begin() + dist;
        }

        // 3. 삽입
        for (int* iter = end(); iter != pos; --iter)
        {
            *iter = *(iter - 1);
        }
        *pos = value;

        // 4. 필드 데이터 최신화
        ++_size;

        return pos;
    }

    // pos에 위치한 원소를 지운다.
    // 삭제된 요소의 다음 포인터를 반환한다.
    int* erase(int* pos)
    {
        // 1. 비어있다면 end() 반환
        if (_size == 0)
        {
            return end();
        }

        // 2. 데이터 이동(삭제)
        int* last = end() - 1;
        for (int* iter = pos; iter != last; iter++)
        {
            *iter = *(iter + 1);
        }

        // 3. 필드 업데이트
        _size--;

        return pos;
    }

    // 컨테이너의 맨 끝에 원소를 추가한다.
    void                push_back(int value) { insert(end(), value); }

    // 컨테이너의 마지막 원소를 삭제한다.
    void                pop_back() { erase(end() - 1); }

    // value가 존재하는지 검사한다.
    bool                contains(int value)
    {
        for (size_t i = 0; i < _size; i++)
        {
            if (value == _container[i])
            {
                return true;
            }
        }

        return false;
    }

    // 컨테이너의 용량을 newCapacity보다 같거나 크게 늘린다.
    // newCapacity > _capacity라면 새로운 메모리를 할당하고,
    // 그렇지 않다면 아무 동작도 수행하지 않는다.
    void                reserve(size_t newCapacity)
    {
        // 1. newCapacity가 _capacity보다 큰지 비교
        if (newCapacity <= _capacity)
        {
            return;
        }

        // 2. 새로운 메모리를 할당
        int* newContainer = new int[newCapacity];

        // 3. 이전 메모리의 데이터를 복사
        for (size_t i = 0; i < _size; i++)
        {
            newContainer[i] = _container[i];
        }

        // 4. 이전 메모리 해제
        delete[] _container;

        // 5. 필드 데이터 수정
        _container = newContainer;
        _capacity = newCapacity;
    }

private:
    int*                _container = nullptr;
    size_t              _size = 0;      // 현재 원소의 갯수
    size_t              _capacity = 0;  // 최대 원소의 갯수
};

