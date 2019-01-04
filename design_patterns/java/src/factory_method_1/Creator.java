package factory_method_1;
import concretes.*;

public abstract class Creator {
	public abstract Product createProduct(String type, String name, int price);
}
