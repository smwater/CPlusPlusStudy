#include <iostream>
#include <vector>

using namespace std;

int main()
{
	// 벡터 생성하기
	vector<int> vec;
	cout << boolalpha << vec.empty() << endl;
	cout << vec.size() << endl;
	cout << vec.capacity() << endl;
	
	// 삽입
	// push back : 벡터의 맨 끝에 데이터 삽입
	vec.push_back(4);
	vec.push_back(5);
	vec.push_back(72);
	// { 4, 5, 72}
	
	// 반복자
	// begin() : 컨테이너의 첫 원소를 가리키는 반복자
	// end() : 컨테이너의 마지막 원소의 다음을 가리키는 반복자
	for (vector<int>::iterator iter = vec.begin(); iter != vec.end(); ++iter)
	{
		cout << *iter << ",";
	}
	cout << endl;

	// rbegin() : 컨테이너의 마지막 원소를 가리키는 반복자
	// rend() : 컨테이너의 첫 원소의 이전을 가리키는 반복자
	/*for (vector<int>::reverse_iterator iter = vec.rbegin(); iter != vec.rend(); ++iter)
	{
		cout << *iter << ",";
	}
	cout << endl;*/

	// insert : pos 이전에 데이터를 삽입
	vector<int>::iterator iter = vec.begin();
	++iter;

	iter = vec.insert(iter, 16);	// { 4, 16, 5, 72}, iter = &vec[1] (16)
	iter = vec.insert(iter, 3, 5);  // { 4, 5, 5, 5, 16, 5, 72} iter = &vec[1] (5)
	iter = vec.insert(iter, vec.begin() + 3, vec.end() - 1);	// {4, 5, 16, 5, 5, 5, 5, 16, 5, 72}
	for (vector<int>::iterator iter = vec.begin(); iter != vec.end(); ++iter)
	{
		cout << *iter << ",";
	}
	cout << endl;

	// 삭제
	// pop_back : 맨 끝에 있는 데이터를 삭제
	// vec : {4, 5, 16, 5, 5, 5, 5, 16, 5, 72}
	vec.pop_back();
	vec.pop_back();
	vec.pop_back();
	// vec : {4, 5, 16, 5, 5, 5, 5}

	// erase : pos에 있는 데이터를 삭제
	vec.erase(vec.begin());
	// vec : {5, 16, 5, 5, 5, 5}
	vec.erase(vec.begin() + 1, vec.begin() + 3);
	// vec : {5, 5, 5, 5}

	// 읽기
	cout << vec.front() << endl; // 5
	cout << vec.back() << endl; // 5
	cout << vec[2] << endl; // 5

	// 검색 => 메소드가 아니라 알고리즘 라이브러리에 존재

	// 다른 생성
	vector<int> vec2(5); // {0, 0, 0, 0, 0};
	vector<int> vec3(5, 10); // {10, 10, 10, 10, 10};


	return 0;
}