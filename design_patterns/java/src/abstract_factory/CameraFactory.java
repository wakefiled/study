package abstract_factory;
import concretes.*;

public class CameraFactory implements ProductAbstractFactory{
	private String name;
	private int price;
	private String pixels;
	private String types;
	
	public CameraFactory(String name, int price, String pixels, String types)
	{
		this.name = name;
		this.price = price;
		this.pixels = pixels;
		this.types = types;
	}
	
	public Product createProduct() {
		return new Camera(name, price, pixels, types);
	}
}
