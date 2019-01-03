package abstract_factory;
import concretes.*;

public class ComputerFactory implements ProductAbstractFactory{
	private String name;
	private int price;
	private String cpu;
	private String ram;
	private String storage;
	
	public ComputerFactory(String name, int price, String cpu, String ram, String storage)
	{
		this.name = name;
		this.price = price;
		this.cpu = cpu;
		this.ram = ram;
		this.storage = storage;
	}
	
	public Product createProduct() {
		return new Computer(name, price, cpu, ram, storage);
	}
}
