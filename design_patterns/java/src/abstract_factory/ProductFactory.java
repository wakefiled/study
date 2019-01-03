package abstract_factory;
import concretes.*;

public class ProductFactory {
	public static Product getProduct(ProductAbstractFactory product)
	{
		return product.createProduct();
	}
}
