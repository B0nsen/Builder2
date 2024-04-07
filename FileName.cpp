#include <iostream>
#include <string>

using namespace std;

/* ������� ��������� �������� ��������������� �������� ������� �� ��� �������������, ��� ���
	   � ���������� ������ � ���� �� �������� ��������������� ����� ���������� ������ �������������.
	������������
	   - �������� �������� �������� ������� �� ������ �������� �� ����, �� ����� ������ ������� ������ � ��� ��� ��������� ����� �����;
	   - ������� ��������������� ������ ������������ ��������� ������������� ��������������� �������.
   ����������� �������� ��������� � ��� ����������:
	- ��������� �������� ���������� ������������� ��������
	- ��������� ���, ����������� ��������������� � �������������
	- ���� ����� ������ �������� ��� ��������� ���������������
   */

   /*
		* Pizza (�������) ������������ ������� �������������� ������.
		* ConcreteBuilder ������ ���������� ������������� �������� � ���������� ������� ��� ������.
		* */
class Car
{
	std::string body;
	int engine;
	int wheels;
	int gear_box;
	std::string gear_box_s;
public:
	void SetBody(string body)
	{
		this->body = body;
	}
	string GetBody()
	{
		return this->body;
	}
	void SetEngine(int engine)
	{
		this->engine = engine;
	}
	int GetEngile()
	{
		return this->engine;
	}
	void SetWheels(int Wheels)
	{
		this->wheels = wheels;
	}
	int GetWheels()
	{
		return this->wheels;
	}
	void SetGearBoxS(string gear_box_s)
	{
		this->gear_box_s = gear_box_s;
	}
	string GetGearBoxS()
	{
		return this->gear_box_s;
	}
	void SetGearBox(int gear_box)
	{
		this->gear_box = gear_box;
	}
	int GetGearBox()
	{
		return this->gear_box;
	}
	void ShowCar()
	{
		cout << "Body: " << body << "\nEngine: " << engine << "horse power\nWheels: " << wheels << "\nGear box: " << gear_box << ' ' << gear_box_s << '\n';
	}
};

// Abstract Builder ������ ����������� ��������� (�����) ��� �������� ������ ������� Product (� ����� ������, Pizza);
/** "Abstract Builder" */
class CarBuilder abstract
{
protected:
	Car car;
public:
	Car GetCar()
	{
		return car;
	}
	virtual void BuildEngine() abstract;
	virtual void BuildBody() abstract;
	virtual void BuildWheels() abstract;
	virtual void BuildGearBox() abstract;
};

// ConcreteBuilder ��������� ��������� ��������:
// - ������������ � �������� ������ ����� �������� ����������� ���������� ���������� Builder;
// - ���������� ����������� ������������� � ������ �� ���;
// - ������������� ��������� ��� ������� � ��������

class LanosBuilder : public CarBuilder
{
public:
	void BuildBody() override
	{
		car.SetBody("Sedan");
	}
	void BuildEngine() override
	{
		car.SetEngine(98);
	}
	void BuildWheels() override
	{
		car.SetWheels(13);
	}
	void BuildGearBox() override
	{
		car.SetGearBox(5);
		car.SetGearBoxS("Manual");
	}
};

class FordBuilder : public CarBuilder
{
public:
	void BuildBody() override
	{
		car.SetBody("Cupe");
	}
	void BuildEngine() override
	{
		car.SetEngine(160);
	}
	void BuildWheels() override
	{
		car.SetWheels(14);
	}
	void BuildGearBox() override
	{
		car.SetGearBox(4);
		car.SetGearBoxS("Auto");
	}
};

// Director(�������������) - ������������ ������ (Pizza), ��������� ����������� Builder
class UazBuilder : public CarBuilder
{
public:
	void BuildBody() override
	{
		car.SetBody("Universal");
	}
	void BuildEngine() override
	{
		car.SetEngine(120);
	}
	void BuildWheels() override
	{
		car.SetWheels(16);
	}
	void BuildGearBox() override
	{
		car.SetGearBox(4);
		car.SetGearBoxS("Manual");
	}
};

class HyundaiBuilder : public CarBuilder
{
public:
	void BuildBody() override
	{
		car.SetBody("Hetchback");
	}
	void BuildEngine() override
	{
		car.SetEngine(66);
	}
	void BuildWheels() override
	{
		car.SetWheels(13);
	}
	void BuildGearBox() override
	{
		car.SetGearBox(4);
		car.SetGearBoxS("Auto");
	}
};

class Factory
{
	CarBuilder* builder;
public:
	void SetBuilder(CarBuilder* builder)
	{
		this->builder = builder;
	}
	void ConstructCar()
	{
		builder->BuildBody();
		builder->BuildEngine();
		builder->BuildGearBox();
		builder->BuildWheels();
	}
	Car GetCar()
	{
		return builder->GetCar();
	}
};
// ������ ������� ������-������������� Director � ������������� ��� ������ ��������-���������� Builder
void client(CarBuilder* builder)
{
	Factory factory;
	factory.SetBuilder(builder);
	factory.ConstructCar();
	Car car = factory.GetCar();
	car.ShowCar();
}

void main()
{
	CarBuilder* builder = new FordBuilder();
	client(builder);
	delete builder;
	builder = new HyundaiBuilder();
	client(builder);
	delete builder;
}