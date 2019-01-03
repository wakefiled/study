package builder;
import concretes.*;

public class Director{
	public static Product createLGGramProduct(Builder builder)
	{	
		builder.BuildProductCpu("i7");
		builder.BuildProductPrice(120);
		builder.BuildProductName("LG-Gram");
		builder.BuildProductRam("8G");
		builder.BuildProductStorage("256G");

		return builder.build();
	}
	
	public static Product createMACProduct(Builder builder)
	{	
		builder.BuildProductCpu("i7");
		builder.BuildProductPrice(250);
		builder.BuildProductName("MAC-PRO");
		builder.BuildProductRam("16G");
		builder.BuildProductStorage("512G");

		return builder.build();
	}	
}
