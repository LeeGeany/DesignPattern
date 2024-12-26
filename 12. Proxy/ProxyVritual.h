#include <string>
#include <iostream>

class Image
{
protected:
	virtual void draw() = 0;
};

class Bitmap : public Image
{
public:
	Bitmap(const std::string& filename)
	:filename{filename}
	{
		std::cout << "Loading Image from " << filename << std::endl;
	}

	virtual void draw() override
	{
		std::cout << "Drawing Image " << filename << std::endl;
	}

private:
	std::string filename;
};

class LazyBitmap : public Image
{
public:
	LazyBitmap(const std::string& filename)
	:filename{ filename }
	{
		std::cout << "Loading Image from " << filename << std::endl;
	}
	virtual ~LazyBitmap()
	{
		delete bmp;
	}

public:
	virtual void draw() override
	{
		if (!bmp)
		{
			bmp = new Bitmap(filename);
		}
		bmp->draw();
	}

private:
	std::string filename;
	Bitmap* bmp{ nullptr };
};