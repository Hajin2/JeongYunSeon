#include<iostream>
using namespace std;

class Count
{
private:
	int x, y;
public:
	Count(int a, int b)
	{
		x = a;
		y = b;
	}
	void Print()
	{
		cout << "x = " << x << ", y = " << y << endl;
	}
	Count operator / (Count tmp);
};
Count Count::operator / (Count tmp)
{
	cout << "°´Ã¼ / °´Ã¼" << endl;
	if (this->x > tmp.x)
		this->x = this->x / tmp.x;
	else
		this->x = tmp.x / this->x;
	if (this->y > tmp.y)
		this->y = this->y / tmp.y;
	else
		this->y = tmp.y / this->y;
	return *this;
}
void main()
{
	Count A(10, 20), B(5, 40);
	A.Print();
	B.Print();
	A = A / B;
	A.Print();
	return;
}