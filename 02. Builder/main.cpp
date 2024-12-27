#include "CHtmlElement.h"
#include "CHtmlElement1.h"
#include "CHtmlBuilder.h"
#include "CHtmlBuilder1.h"

#include "P.h"
#include "CImg.h"

#include "CPerson.h"
#include "CPersonBuilderBase.h"

int main(void)
{
	/*
	std::string words[] = { "hello", "world" };


	CHtmlElement list{ "<ul>", "C++" };

	for (auto w : words)
	{
		list.element.emplace_back(CHtmlElement("<li>", w));
	}

	list.str();


	CHtmlBuilder builder{ "<ul>" };
	builder.add_child("<li>", "hello");
	builder.add_child("<li>", "hello");
	builder.str();


	CHtmlBuilder1 builder{ "<ul>" };
	builder.add_child("<li>", "hello").add_child("<li>", "hello").add_child("<li>", "good");
	builder.str();


	auto builder = CHtmlElement1::build("<ul>");
	builder->add_child("<li>", "hello");
	builder->add_child("<li>", "world");
	builder->str();
		
	P{
	CImg{ "Image1.jpg" },
	CImg{ "Image2.jpg" },
	CImg{ "Image3.jpg" },
	CImg{ "Image4.jpg" },
	CImg{ "Image5.jpg" }
	};

	*/
	CPerson p = CPerson::create()
		.lives().at("123 London Road").with_postcode("SW1 1GB").in("London")
		.works().at("PragmaSoft").as_a("Consultant").earning(10e6);

	return 0;
}