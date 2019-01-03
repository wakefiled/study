package concretes;

public abstract class Product {
	public abstract String getName();
	public abstract int getPrice();
	public abstract String getInfo();
	
	@Override
	public String toString() {
		return "product:" + getName() + ", price:" + getPrice() + ", info:" + getInfo();
	}
}
