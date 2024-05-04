#include <iostream>

using namespace std;

template<class T>
class Test
{
public:
	static void sort(T* array, int len, bool(*compare)(T &a, T &b))
	{
		T temp;
		for (int i = 0; i < len - 1; i++)
		{
			for (int j = 0; j < len - i -1 ; j++)
			{
				if (compare(array[j],array[j + 1]))
				{
					temp = array[j];
					array[j] = array[j + 1];
					array[j + 1] = temp;
				}
			}
		}
	}
};

template <class T>
bool descend(T& a, T& b)
{
	return a < b ? true : false;
}

template <class T>
bool ascend(T& a, T& b)
{
	return a > b ? true : false;
}

template <class T>
class MyRect
{
public:
	MyRect() :len(0), high(0) {}
	MyRect(T a, T b) :len(a), high(b) {}
	T area() { return len * high; }

private:
	T len;
	T high;
};

template<class T>
bool operator>(MyRect<T>& rect1, MyRect<T>& rect2)
{
	return rect1.area() > rect2.area() ? true : false;
}

template<class T>
bool operator<(MyRect<T>& rect1, MyRect<T>& rect2)
{
	return rect1.area() < rect2.area() ? true : false;
}

int main()
{
	int int_array[10] = { 4,3,7,6,2,1,9,8,5,10 };
	float float_array[10] = { 4.0f,3.0f,7.0f,6.0f,2.0f,1.0f,9.0f,8.0f,5.0f,10.0f };
	MyRect<int> rect_array[4] = { MyRect<int>(3,4),MyRect<int>(5,6) ,MyRect<int>(4,6) ,MyRect<int>(3,5) };

	Test<int>::sort(int_array, 10,descend<int>);
	for (int i = 0; i < 10; i++)
	{
		cout << int_array[i] << " ";
	}	
	cout << endl;
	Test<int>::sort(int_array, 10, ascend<int>);
	for (int i = 0; i < 10; i++)
	{
		cout << int_array[i] << " ";
	}
	cout << endl;

	Test<float>::sort(float_array, 10, descend<float>);
	for (int i = 0; i < 10; i++)
	{
		cout << float_array[i] << " ";
	}
	cout << endl;
	Test<float>::sort(float_array, 10, ascend<float>);
	for (int i = 0; i < 10; i++)
	{
		cout << float_array[i] << " ";
	}
	cout << endl;

	Test<MyRect<int>>::sort(rect_array, 4, descend<MyRect<int>>);
	for (int i = 0; i < 4; i++)
	{
		cout << rect_array[i].area() << " ";
	}
	cout << endl;
	Test<MyRect<int>>::sort(rect_array, 4, ascend<MyRect<int>>);
	for (int i = 0; i < 4; i++)
	{
		cout << rect_array[i].area() << " ";
	}
	cout << endl;

	return 0;
}
