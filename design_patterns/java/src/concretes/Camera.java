package concretes;

public class Camera extends Product {
	private String name;
	private int price;
	private String pixels;
	private String type;
	
	public Camera (String name, int price) {
		this.name = name;
		this.price = price;
	}

	public Camera (String name, int price, String pixels, String type) {
		this.name = name;
		this.price = price;
		this.pixels = pixels;
		this.type = type;
	}
	
	@Override
	public String getName()
	{
		return "[CAM]" + this.name;
	}
	
	@Override
	public int getPrice()
	{
		return this.price;
	}
	
	@Override
	public String getInfo()
	{
		return pixels + " " + type;
	}
}
