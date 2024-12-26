template <typename T> class Property
{
public:
	T value;

	Property(const T initial_value)
	{
		*this = initial_value;
	}

	operator T()
	{
		return value;
	}

	T operator=(T new_value)
	{
		return value = new_value;
	}
};