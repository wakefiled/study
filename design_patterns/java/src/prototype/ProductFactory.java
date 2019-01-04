package prototype;
import concretes.*;
import java.util.ArrayList;
import java.util.List;

public class ProductFactory implements Cloneable{
	private List<Product> productList;
	
	public ProductFactory()
	{
		productList = new ArrayList<Product>();
	}
	
	public void loadData()
	{
		// load database or files.
		productList.add(new Computer("LG-Gram", 120, "i7", "8G", "256G"));
		productList.add(new Computer("MAC-Pro", 200, "i7", "16G", "512G"));
		productList.add(new Computer("Samsung-Ultra", 170, "i7", "16G", "256G"));
	}
	
	public List<Product> getProductList()
	{
		return productList;
	}
	
	public ProductFactory clone()
	{
		try
		{
			ProductFactory copy = (ProductFactory)super.clone();
			
			return copy;	
		}
		catch(CloneNotSupportedException e)
		{
			e.printStackTrace();
			return null;
		}
	}
}
