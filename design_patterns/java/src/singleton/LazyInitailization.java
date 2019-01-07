package singleton;

public class LazyInitailization {
	private static LazyInitailization instance;
	private LazyInitailization() {}
	
	public static LazyInitailization getInstance()
	{
		if ( instance == null )
		{
			System.out.println("instance create...");
			instance = new LazyInitailization();
		}
		return instance;
	}
	
	public void print()
	{
		System.out.println("instance hashCode > " + instance.hashCode());
	}
	
	public static void main(String args[])
	{
		System.out.println("Start..");
		LazyInitailization.getInstance().print();
		System.out.println("End..");
	}
}
