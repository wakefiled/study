package builder;
import concretes.*;

public interface Builder {
	public void BuildProductName(String name);
	public void BuildProductPrice(int price);
	public void BuildProductCpu(String cpu);
	public void BuildProductRam(String ram);
	public void BuildProductStorage(String storage);
	public Product build();
}
