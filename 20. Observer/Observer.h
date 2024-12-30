#include <string>
#include <mutex>
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
	std::mutex mtx;

public:
	void notify(T& source, const std::string& name)
	{
		std::lock_guard<std::mutex> lock(mtx);
		for (auto obs : observers)
		{
			// 재진입성 해결
			if (obs)
			{
				obs->field_changed(source, name);
			}
		}
	}

	void subscribe(Observer<T>* f) 
	{
		std::lock_guard<std::mutex> lock(mtx);
		observers.push_back(f); 
	}

	void unsubscribe(Observer<T>* observer)
	{
		auto it = find(observers.begin(), observers.end(), 0);
		if (it != observers.end())
		{
			*it = nullptr;
		}
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
