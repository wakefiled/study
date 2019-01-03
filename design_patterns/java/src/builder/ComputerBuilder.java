package builder;
import concretes.*;

public class ComputerBuilder implements Builder{

	private String name;
	private int price;
	private String cpu;
	private String ram;
	private String storage;
	
	public void BuildProductName(String name)
	{
		this.name = name;
	}
	
	public void BuildProductPrice(int price)
	{
		this.price = price;
	}
	
	public void BuildProductCpu(String cpu)
	{
		this.cpu = cpu;
	}
	
	public void BuildProductRam(String ram)
	{
		this.ram = ram;
	}
	
	public void BuildProductStorage(String storage)
	{
		this.storage = storage;
	}
	
	public Product build()
	{
		return new Computer(name, price, cpu, ram, storage);
	}
}

