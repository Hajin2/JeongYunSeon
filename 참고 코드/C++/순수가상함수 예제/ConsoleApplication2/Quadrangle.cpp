#include "Quadrangle.h"



Quadrangle::Quadrangle()
{
}

void Quadrangle::SetSize()
{
	cout << "���� : ";
	cin >> x;
	cout << "���� : ";
	cin >> y;
}


void Quadrangle::Draw()
{
	cout << "���� : " << x << " ���� : " << y << " �� �簢���� �׷Ƚ��ϴ�." << endl;
}


Quadrangle::~Quadrangle()
{
}
