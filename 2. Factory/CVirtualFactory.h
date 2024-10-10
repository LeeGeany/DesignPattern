#include <iostream>
#include <memory>
#include <string>
#include <map>
#include <functional>

class HotDrink
{
public:
	HotDrink() = default;
	virtual ~HotDrink() = default;

public:
	virtual void prepare(int voluem) = 0;
};

class Tea : public HotDrink
{
public:
	Tea() = default;
	virtual ~Tea() = default;
	virtual void prepare(int voluem) final
	{
		std::cout << "Tea\n";
	}
};

class Coffee : public HotDrink
{
public:
	Coffee() = default;
	virtual ~Coffee() = default;
	virtual void prepare(int voluem) final
	{
		std::cout << "Coffee\n";
	}
};

class HotDrinkFactory
{
public:
	virtual std::unique_ptr<HotDrink> make() const = 0;
};

class CoffeeFactory : public HotDrinkFactory
{
public:
	virtual std::unique_ptr<HotDrink> make() const final
	{
		return std::make_unique<Coffee>();
	}
};

class TeaFactory : public HotDrinkFactory
{
public:
	virtual std::unique_ptr<HotDrink> make() const final
	{
		return std::make_unique<Tea>();
	}
};

class DrinkFactory
{
public:
	DrinkFactory()
	{
		hot_factory["coffee"] = std::make_unique<CoffeeFactory>();
		hot_factory["tea"] = std::make_unique<TeaFactory>();
	}
	virtual ~DrinkFactory() = default;

	std::unique_ptr<HotDrink> make_drink(const std::string name)
	{
		auto drink = hot_factory[name]->make();
		drink->prepare(200);
		return drink;
	}

private:
	std::map<std::string, std::unique_ptr<HotDrinkFactory>> hot_factory;
};

class DrinkWithVolumeFactory
{
public:
	DrinkWithVolumeFactory()
	{
		factory["coffee"] = [] { auto coffee = std::make_unique<Coffee>(); coffee->prepare(200); return coffee; };
		factory["tea"] = [] { auto tea = std::make_unique<Tea>(); tea->prepare(200); return tea; };
	}
	virtual ~DrinkWithVolumeFactory() = default;

	inline std::unique_ptr<HotDrink> make_drink(const std::string name)
	{
		return factory[name]();
	}

private:
	std::map<std::string, std::function<std::unique_ptr<HotDrink>()>> factory;
};


static std::unique_ptr<HotDrink> make_drink(std::string type)
{
	std::unique_ptr<HotDrink> drink;
	if (type == "tea")
	{
		drink = std::make_unique<Tea>();
		drink->prepare(200);
	}
	else if (type == "coffee")
	{
		drink = std::make_unique<Coffee>();
		drink->prepare(50);
	}
	return drink;
}