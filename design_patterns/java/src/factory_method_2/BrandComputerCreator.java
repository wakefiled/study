package factory_method_2;
import concretes.*;

public class BrandComputerCreator extends Creator {
	
	@Override
	public Product createProduct(String type, String name, int price)
	{
		if(type.equals("computer"))
		{
			switch(name)
			{
				case "LG-Gram": return new Computer(name, price, "i7", "8G", "256G");
				case "MAC-Pro": return new Computer(name, price, "i7", "16G", "512G");
				case "Samsung-Ultra": return new Computer(name, price, "i7", "8G", "256G");
			}
		}

		return new Creator().createProduct(type, name, price);
	}
}
