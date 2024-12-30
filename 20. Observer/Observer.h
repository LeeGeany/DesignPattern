#include <string>
#include <vector>
#include <iostream>

template<typename T> struct Observer
{
	virtual void field_changed(T& source, const std::string& field_name) = 0;
};

template <typename T> class Observable
{
private:
	std::vector<Observer<T>*> observers;

public:
	void notify(T& source, const std::string& name)
	{
		for (auto obs : observers)
		{
			obs->field_changed(source, name);
		}
	}

	void subscribe(Observer<T>* f) 
	{
		observers.push_back(f); 
	}

	void unsubscribe(Observer<T>* observer)
	{
		observers.erase(
			remove(observers.begin(), observers.end(), observer), observers.end());
	}
};

class Person : public Observable<Person>
{
private:
	int age;

public:
	Person(int age) : age(age) {}
	int get_age() const { return age; }
	void set_age(int value)
	{
		if (this->age == value)
		{
			return;
		}
		this->age = value;
		notify(*this, "age");
	}
};


class ConsolePersonObServer : public Observer<Person>
{
public:
	void field_changed(Person& source, const std::string& field_name) override
	{
		std::cout << "Person's " << field_name << "has changed to " << source.get_age() << ".\n";
	}
};
