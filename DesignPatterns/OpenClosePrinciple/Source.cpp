#include <iostream>
#include <vector>

using namespace std;

enum Color
{
	Red,
	Green,
	Blue
};

enum Size
{
	Small,
	Medium,
	Large
};

class Product
{
	public:
		string name;
		Color color;
		Size s;
};

// Incorrect way starts
class ProductFilter
{
	public:
		static vector<Product*> items_by_color(vector<Product*> items, Color color)
		{
			vector<Product*> result;
			vector<Product*>::iterator it = items.begin();

			for (it; it != items.end(); it++)
			{
				if ((*it)->color == color )
				{
					result.push_back(*it);
				}
			}
			return result;
		}

		static vector<Product*> items_by_size(vector<Product*> items, Size size)
		{
			vector<Product*> result;
			vector<Product*>::iterator it = items.begin();

			for (it; it != items.end(); it++)
			{
				if ((*it)->s == size)
				{
					result.push_back(*it);
				}
			}
			return result;
		}

		static vector<Product*> items_by_color_and_size(vector<Product*> items, Color color, Size size)
		{
			vector<Product*> result;
			vector<Product*>::iterator it = items.begin();

			for (it; it != items.end(); it++)
			{
				if ((*it)->color == color && (*it)->s == size)
				{
					result.push_back(*it);
				}
			}
			return result;
		}
};

// Incorrect way ends

template <typename T> class ISpecification
{
	public:
		virtual bool is_satisfied(T* item) = 0;
};

template <typename T> class IFilter
{
	public:
		virtual vector<T*> filter(vector<T*> items, ISpecification<T>& spec) = 0;
};

class BetterFilter : public IFilter<Product>
{
	public:
		virtual vector<Product*> filter(vector<Product*> items, ISpecification<Product>& spec)
		{
			ProductList result;

			for (ProductList::iterator it = items.begin(); it != items.end(); it++)
			{
				if (spec.is_satisfied(*it))
				{
					result.push_back(*it);
				}
			}
			return result;
		}

	private:
		typedef vector<Product*> ProductList;
};

class ColorSpecification : public ISpecification<Product>
{
	public:
		ColorSpecification(const Color color) : color(color)
		{

		}

		virtual bool is_satisfied(Product* item)
		{
			return item->color == color;
		}

	private:
		Color color;
};

class SizeSpecification : public ISpecification<Product>
{
public:
	SizeSpecification(const Size Size) : Size(Size)
	{

	}

	virtual bool is_satisfied(Product* item)
	{
		return item->s == Size;
	}

private:
	Size Size;
};

template <typename T> class AndSpecification : public ISpecification<Product>
{
	public:
		AndSpecification(ISpecification<T>& first, ISpecification<T>& second) : first(first), second(second)
		{

		}

		virtual bool is_satisfied(T* item)
		{
			return first.is_satisfied(item) && second.is_satisfied(item);
		}

	private:
		AndSpecification<T> first;
		AndSpecification<T> second;
};

int main()
{
	Product apple{ "Apple", Color::Green, Size::Small };
	Product tree{ "Tree", Color::Green, Size::Large };
	Product house{ "House", Color::Blue, Size::Large };

	typedef vector<Product*> ProductList;

	ProductList products{ &apple, &tree, &house };

	BetterFilter bf;

	ColorSpecification green(Color::Green);

	ProductList filteredItems = bf.filter(products, green);

	for (ProductList::iterator it = filteredItems.begin(); it != filteredItems.end(); it++)
	{
		cout << (*it)->name.c_str() << endl;
	}
	
	getchar();
	return 0;
}