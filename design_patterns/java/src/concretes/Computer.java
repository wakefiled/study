package concretes;

public class Computer extends Product {
	private String name;
	private int price;
	private String cpu;
	private String ram;
	private String storage;
	
	public Computer (String name, int price) {
		this.name = name;
		this.price = price;
	}
	
	public Computer (String name, int price, String cpu, String ram, String storage) {
		this.name = name;
		this.price = price;
		this.cpu = cpu;
		this.ram = ram;
		this.storage = storage;
	}
	
	@Override
	public String getName()
	{
		return "[PC]" + this.name;
	}
	
	@Override
	public int getPrice()
	{
		return this.price;
	}
	
	@Override
	public String getInfo()
	{
		return cpu + " " + ram + " " + storage;
	}
}
