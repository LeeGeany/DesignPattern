#include <iostream>

class Renderer
{
public:
	virtual void render_circle(float x, float y, float radius) = 0;
};

class VectorRender : public Renderer
{
public:
	virtual void render_circle(float x, float y, float radius) override
	{
		std::cout << "Vectorizing Circle of Radius\n";
	}
};

class RasterRender : public Renderer
{
public:
	virtual void render_circle(float x, float y, float radius) override
	{
		std::cout << "Raterizing Circle of Radius\n";
	}
};

class Shape
{
protected:
	Renderer& renderer;
	Shape(Renderer& renderer) : renderer(renderer) {}

public:
	virtual void draw() = 0;
	virtual void resize(float factor) = 0;
};

class Circle : public Shape
{
private:
	float x, y, radius;

public:
	Circle(Renderer& renderer, float x, float y, float radius)
	: Shape{ renderer }, x{ x }, y{ y }, radius{radius}
	{
	
	}

	virtual void draw() override
	{
		Shape::renderer.render_circle(x, y, radius);
	}

	virtual void resize(float factor) override
	{
		radius *= factor;
	}
};

//===========================================
int main(void)
{
	RasterRender rr;
	VectorRender vr;

	Circle Circle(rr, 1, 2, 3);
	Circle.draw();
	Circle.resize(2);
	Circle.draw();
	
	return 0;
}