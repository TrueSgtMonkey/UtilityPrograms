package add;

public class Add
{
  private int x;

  public Add()
  {
    this.x = 0;
  }

  public Add(int x)
  {
    this.x = x;
  }

  public void add(int x)
  {
    this.x += x;
  }

  public int get()
  {
    return x;
  }

  public void set(int x)
  {
    this.x = x;
  }
}
