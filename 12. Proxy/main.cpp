int main(void)
{
	Property<int> strength{ 10 };
	Property<int> agility{ 5 };

	std::cout << strength << std::endl;
	std::cout << agility << std::endl;

	LazyBitmap bm("ImageFile.png");
	bm.draw();

	pong pp;

	for (int i = 0; i < 3; ++i)
	{
		tryit(pp);
	}
}