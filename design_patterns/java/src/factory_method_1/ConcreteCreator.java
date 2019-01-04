package factory_method_1;
import concretes.*;

public class ConcreteCreator extends Creator{

	@Override
	public Product createProduct(String type, String name, int price) 
	{
		if(type.equals("computer"))
		{
			return new Computer(name, price);
		}
		else if(type.equals("camera"))
		{
			return new Camera(name, price);
		}
		
		return null;
	}
}
