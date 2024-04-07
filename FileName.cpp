#include <iostream>
#include <string>

using namespace std;

/* Паттерн Строитель отделяет конструирование сложного объекта от его представления, так что
	   в результате одного и того же процесса конструирования могут получаться разные представления.
	Применимость
	   - алгоритм создания сложного объекта не должен зависеть от того, из каких частей состоит объект и как они стыкуются между собой;
	   - процесс конструирования должен обеспечивать различные представления конструируемого объекта.
   Достоинства паттерна строитель и его применения:
	- позволяет изменять внутреннее представление продукта
	- изолирует код, реализующий конструирование и представление
	- дает более тонкий контроль над процессом конструирования
   */

   /*
		* Pizza (продукт) представляет сложный конструируемый объект.
		* ConcreteBuilder строит внутреннее представление продукта и определяет процесс его сборки.
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

// Abstract Builder задает абстрактный интерфейс (класс) для создания частей объекта Product (в нашем случае, Pizza);
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

// ConcreteBuilder выполняет следующие действия:
// - конструирует и собирает вместе части продукта посредством реализации интерфейса Builder;
// - определяет создаваемое представление и следит за ним;
// - предоставляет интерфейс для доступа к продукту

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

// Director(распорядитель) - конструирует объект (Pizza), пользуясь интерфейсом Builder
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
// клиент создает объект-распорядитель Director и конфигурирует его нужным объектом-строителем Builder
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