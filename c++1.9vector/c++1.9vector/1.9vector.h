#pragma once
#include <assert.h>

namespace jhx
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;

		// 17:05继续
		iterator begin()
		{
			return _start;
		
		}


		iterator end()
		{
			return _finish;
		}


		const_iterator begin() const
		{
			return  _start;
		
		}


		const_iterator end() const
		{
		
			return _finish;
		
		}


		vector()
			:_start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{}

	/*	~vector()
		{
			delete[] _start;
			_start = _finish = _end_of_storage = nullptr;
		}*/

		size_t capacity() const
		{
			return _end_of_storage - _start;
		
		}


		const T& operator[](size_t pos) const
		{
			return *(_start + pos);
		
		}


		T& operator[](size_t pos)
		{
			return *(_start + pos);
		
		}


		size_t size() const
		{
			return _finish - _start;
		}


		void reserve(size_t n)
		{
			if (n > capacity())
			{

				size_t sz = size();
				T* tmp = new T[n];

				memcpy(tmp, _start, sizeof(T)*sz);


				delete[]_start;
				_start = tmp;

				_finish = _start + sz;
				_end_of_storage = _start + n;

			}



		
		}


		void push_back(const T& x)
		{
			if (capacity() == size())
			{

				if (capacity() == 0)
				{

					reserve(4);
				}
				else
				{
					reserve(2 * capacity());

				}
		


			}
			
			*_finish = x;
			_finish++;

		
		}



		void pop_back()
		{
			_finish--;
		
		}


		void insert(iterator pos, const T& x)
		{
			assert(pos >= _start);
			assert(pos <= _finish);
			size_t sz = size();
			if (capacity() == sz)
			{
				int posindex = pos - _start;

				if (capacity() == 0)
				{
					reserve(10);
				}
				else
				{

					
					reserve(2 * capacity());
				}

				pos = _start + posindex;
			}

			int i =0;
			while (i<(_finish-pos))
			{
				*(_finish-i) = *(_finish-i -1);
				i++;
			}


			_finish++;
			*pos = x;
		}


		// stl 规定erase返回删除位置下一个位置迭代器
		iterator erase(iterator pos)
		{
		
			int i = 0;
			while (i < (_finish - pos-1))
			{
				*(pos+i) = *(pos + 1+i);
				i++;
			}
			_finish--;
			return pos ;
		}

	private:
		iterator _start;
		iterator _finish;
		iterator _end_of_storage;
	};

	//void Func(const vector<int>& v)
	//{
	//	vector<int>::const_iterator it = v.begin();
	//	while (it != v.end())
	//	{
	//		//*it = 10;
	//		cout << *it << " ";
	//		++it;
	//	}
	//	cout << endl;

	//	for (auto e : v)
	//	{
	//		cout << e << " ";
	//	}
	//	cout << endl;
	//}

	void test_vector1()
	{
		/*double d = 2.2;
		const int& i = d;

		vector<string> v;
		v.push_back("xxxxx");*/

		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(5);
		v.push_back(6);
		v.insert(v.begin()+3, 4);
		for (size_t i = 0; i < v.size(); ++i)
		{
			cout << v[i] << " ";
		}
		cout << endl;

		vector<int>::iterator it = v.begin();
		while (it != v.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;

		v.pop_back();
		v.pop_back();

		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	void test_vector2()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
	
	//v.push_back(5);

		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;

		auto p = find(v.begin(), v.end(), 3);
		if (p != v.end())
		{
			// 在p位置插入数据以后，不要访问p，因为p可能失效了。
			v.insert(p, 30);

			//cout << *p << endl;
			//v.insert(p, 40);
		}




		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
v.insert(v.begin(), 1);
		
	}

	void test_vector3()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;

		auto p = find(v.begin(), v.end(), 3);
		if (p != v.end())
		{
			v.erase(p);
		}

		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;

		v.erase(v.begin());

		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	//void test_vector4()
	//{
	//	// 正常运行
	//	vector<int> v;
	//	v.push_back(1);
	//	v.push_back(2);
	//	v.push_back(3);
	//	v.push_back(4);
	//	v.push_back(5);

	//	// 要求删除所有的偶数
	//	auto it = v.begin();
	//	while (it != v.end())
	//	{
	//		if (*it % 2 == 0)
	//		{
	//			v.erase(it);
	//		}

	//		++it;
	//	}

	//	for (auto e : v)
	//	{
	//		cout << e << " ";
	//	}
	//	cout << endl;
	//}

	//void test_vector4()
	//{
	//	// 崩溃
	//	vector<int> v;
	//	v.push_back(1);
	//	v.push_back(2);
	//	v.push_back(3);
	//	v.push_back(4);

	//	// 要求删除所有的偶数
	//	auto it = v.begin();
	//	while (it != v.end())
	//	{
	//		if (*it % 2 == 0)
	//		{
	//			v.erase(it);
	//		}
	//		++it;
	//	}

	//	for (auto e : v)
	//	{
	//		cout << e << " ";
	//	}
	//	cout << endl;
	//}

	//void test_vector4()
	//{
	//	// 结果不对
	//	vector<int> v;
	//	v.push_back(1);
	//	v.push_back(2);
	//	v.push_back(4);
	//	v.push_back(3);
	//	v.push_back(4);
	//	v.push_back(5);

	//	// 要求删除所有的偶数
	//	auto it = v.begin();
	//	while (it != v.end())
	//	{
	//		if (*it % 2 == 0)
	//		{
	//			v.erase(it);
	//		}
	//			
	//		++it;
	//	}

	//	for (auto e : v)
	//	{
	//		cout << e << " ";
	//	}
	//	cout << endl;
	//}

	// 正确的方式
	void test_vector4()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(4);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);

		// 要求删除所有的偶数
		auto it = v.begin();
		while (it != v.end())
		{
			if (*it % 2 == 0)
			{
				it = v.erase(it);
			}
			else
			{
				++it;

			}
		}

		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
	}
}