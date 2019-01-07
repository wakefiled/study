package singleton;

public class ThreadSafeInitailazation {
	private static ThreadSafeInitailazation instance;
	private ThreadSafeInitailazation() {}
	
	public static synchronized ThreadSafeInitailazation getInstance()
	{
		if(instance == null)
		{
			System.out.println("instance create...");
			instance = new ThreadSafeInitailazation();
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
		ThreadSafeInitailazation.getInstance().print();
		System.out.println("End..");
	}
}
