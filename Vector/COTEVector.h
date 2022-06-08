#pragma once
#include <utility>
#include <sstream>

//-------------------------------------------------------------------------------------------------
// 벡터 (vector) 클래스 구현하기
//
// 본 header 파일에서는, 신입 입사지원자의 과제용으로, 간단한 벡터를 구현하기 위한,
// MyVector 라는 클래스를 정의하고 있습니다.
//
// 소스와 주석을 참고하여, 필요한 기능들을 구현하여,
// MyVector.h 파일과 MyVector.cpp, 2개의 파일을 제출해주시면 됩니다.
// (제출하시는 파일들의 인코딩을 utf-8 로 맞춰주시면 감사하겠습니다.)
//
// 주의: std::vector 와 같은, 이미 구현된 벡터를 감싸는식으로 구현하지 마시고,
//    직접 자신의 코드로 기능을 구현 부탁드립니다.
//
// 참고: 영어로 작성된 부분이 많은 것에 대한 설명을 드리자면,
//    영어 실력을 중요하게 여긴다기 보다는, 번역기를 돌리던 관련 한글 문서를 찾던,
//    어떻게 해서든 원서의 내용을, 이해/학습하는 능력이 중요하기 때문입니다.
//-------------------------------------------------------------------------------------------------


//-------------------------------------------------------------------------------------------------
// 벡터란? (http://www.cplusplus.com/reference/vector/vector/)
//
// Vectors are sequence containers representing arrays that can change in size.
// Just like arrays, vectors use contiguous storage locations for their elements,
// which means that their elements can also be accessed using offsets on regular pointers
// to its elements, and just as efficiently as in arrays. But unlike arrays,
// their size can change dynamically, with their storage being handled automatically
// by the container.
//
// Internally, vectors use a dynamically allocated array to store their elements.
// This array may need to be reallocated in order to grow in size when new elements are inserted,
// which implies allocating a new array and moving all elements to it.
// This is a relatively expensive task in terms of processing time, and thus,
// vectors do not reallocate each time an element is added to the container.
//
// Instead, vector containers may allocate some extra storage to accommodate for possible growth,
// and thus the container may have an actual capacity greater than the storage strictly needed to
// contain its elements (i.e., its size). Libraries can implement different strategies for growth
// to balance between memory usage and reallocations, but in any case,
// reallocations should only happen at logarithmically growing intervals of size
// so that the insertion of individual elements at the end of the vector can be provided with
// amortized constant time complexity.
//-------------------------------------------------------------------------------------------------

#include <string>

//-------------------------------------------------------------------------------------------------
// MyVector 가 관리하는 오브젝트
//-------------------------------------------------------------------------------------------------
struct MyObject
{
    int _id;
};

//-------------------------------------------------------------------------------------------------
// MyVector 클래스.
//-------------------------------------------------------------------------------------------------
class MyVector
{
private: // 구현에 필요한 멤버 추가 함수/변수들을 자유롭게 아래에 정의 합니다.
    using iterator = MyObject*;
    using const_iterator = const MyObject*;
    
    MyObject* _container = nullptr;   // 구조체 배열로 써야할듯
    int _capacity = 0;    // 벡터의 용량
    int _size = 0;        // 벡터의 크기

    void reallocate(int newCapacity)
    {
        // 1. 새로운 메모리를 할당
        MyObject* newContainer = new MyObject[newCapacity];

        // 2. 이전 메모리의 데이터를 복사
        for (size_t i = 0; i < _size; i++)
        {
            newContainer[i] = _container[i];
        }

        // 3. 이전 메모리 해제
        delete[] _container;

        // 4. 필드 데이터 수정
        _container = newContainer;
        _capacity = newCapacity;
    }

    void reserve(int newCapacity)
    {
        if (_capacity >= newCapacity)
        {
            return;
        }
        
        reallocate(newCapacity);
    }

    void clear()
    {
        delete[] _container;
        _container = nullptr;
        _size = 0;
        _capacity = 0;
    }

    iterator erase(iterator pos)
    {
        if (_size == 0)
        {
            return end();
        }

        iterator last = end() - 1;

        for (iterator iter = pos; iter != last; iter++)
        {
            *iter = *(iter + 1);
        }

        _size--;

        return pos;
    }

    // 첫 번째 요소를 가리키는 반복자를 반환한다.
    MyObject* begin()
    {
        // 벡터가 비어있다면 end()를 반환
        if (empty())
        {
            return end();
        }

        // 벡터가 비어있지 않다면 첫 번째 원소를 가리키는 반복자를 반환한다.
        return _container;
    }

    const MyObject* begin() const
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
    MyObject* end() { return _container + _size; }

    const MyObject* end() const { return _container + _size; }

    // 컨테이너가 비었는지 검사한다.
    bool empty() const
    {
        if (0 == _size)
        {
            return true;
        }
        else
            return false;
    }

    // pos에 위치한 원소의 참조를 반환한다.
    // vector<int> v;
    // v[2];
    MyObject& operator[](size_t pos) { return _container[pos]; }
    const MyObject& operator[](size_t pos) const { return _container[pos]; }

    // 컨테이너의 첫 번째 원소의 참조를 반환한다.
    MyObject& front() { return *begin(); }
    const MyObject& front() const { return *begin(); }

    // 컨테이너의 마지막 원소의 참조를 반환한다.
    MyObject& back() { return *(end() - 1); }
    const MyObject& back() const { return *(end() - 1); }

public: // 생성자, 복사생성자, 할당연산자, 소멸자를 .cpp 파일에 구현합니다.
    MyVector() = default;

    // Constructor.
    MyVector(int capacity)
        : _container(new MyObject[capacity]), _size(0), _capacity(capacity) { }

    // Copy constructor.
    MyVector(const MyVector& other)
        : _container(new MyObject[other._capacity]), _size(other._size), _capacity(other._capacity)
    {
        for (size_t i = 0; i < _size; i++)
        {
            _container[i] = other._container[i];
        }
    }

    // Assignment operator.
    MyVector& operator=(const MyVector& other)
    {
        if (this == &other)
        {
            return *this;
        }

        MyVector temp(other);

        std::swap(_container, temp._container);
        std::swap(_size, temp._size);
        std::swap(_capacity, temp._capacity);

        return *this;
    }

    // Destructor.
    ~MyVector()
    {
        clear();
    }

public: // 아래 기능 함수들을 .cpp 파일에 구현합니다.

    // Returns current capacity of this vector.
    int GetCapacity() const { return _capacity; }

    // Returns current size of this vector.
    int GetSize() const { return _size; }

    // Creates a new MyObject instance with the given ID, and appends it to the end of this vector.
    void Add(int id)
    {
        // 1. 용량을 확인한다.
        if (_size == _capacity)
        {
            reserve((_capacity == 0) ? 1 : _capacity * 2);
        }

        // 2. 삽입
        _container[_size]._id = id;

        // 3. 필드 데이터 최신화
        ++_size;
    }

    // Returns the first occurrence of MyObject instance with the given ID.
    // Returns nullptr if not found.
    MyObject* FindById(int MyObjectId) const
    {
        for (size_t i = 0; i < _size; i++)
        {
            if (_container[i]._id == MyObjectId)
            {
                return &_container[i];
            }
        }

        return nullptr;
    }

    // Trims the capacity of this vector to current size.
    void TrimToSize()
    {
        if (_size == _capacity)
        {
            return;
        }

        // 새로운 메모리를 할당하고, 복사
        reallocate(_size);
    }

    // Returns the MyObject instance at the specified index.
    MyObject& operator[](size_t index) { return _container[index]; }

    // Returns string representation of the vector.
    std::string ToString() const
    {
        // { 1, 2, 3, 4, 5}
        // [1,2,3,4,5]
        std::stringstream ss;

        ss << "[";
        for (size_t i = 0; i < _size; i++)
        {
            ss << _container[i]._id << ",";
        }
        ss << "]";

        return ss.str();
    }

    // Remove all MyObject instances with the given ID in this vector.
    void RemoveAll(int MyObjectId)
    {
        iterator iter = begin();

        while (iter != end())
        {
            if (iter->_id == MyObjectId)
            {
                iter = erase(iter);
            }
            else
            {
                ++iter;
            }
        }
    }

    // Returns a newly allocated array of MyVector objects,
    // each of whose elements have the same "_id" value of the MyObject struct.
    // The 'numGroups' is an out parameter, and its value should be set to
    // the size of the MyVector array to be returned.
    MyVector* GroupById(int* numGroups)
    {
        MyVector ids;
        for (size_t i = 0; i < _size; i++)
        {
            if (nullptr == ids.FindById(_container[i]._id))
            {
                ids.Add(_container[i]._id);
            }
        }

        int count = ids.GetSize();
        MyVector* result = new MyVector[count];

        for (size_t i = 0; i < _size; i++)
        {
            size_t index = ids.FindById(_container[i]._id) - ids.begin();
            result[index].Add(_container[i]._id);
        }

        *numGroups = count;
        return result;
    }
};

