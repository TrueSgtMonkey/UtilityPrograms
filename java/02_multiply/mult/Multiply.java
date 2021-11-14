package mult;

public class Multiply
{
  private add.Add add;

  public Multiply()
  {
    add = new add.Add();
  }

  public Multiply(int x)
  {
    add = new add.Add(x);
  }

  public void mult(int x)
  {
    int num = add.get();
    if(num != 0)
    {
      if(x > 0)
      {
        for(int i = 1; i < x; i++)
        {
          add.add(num);
        }
      }  
      else if(x < 0)
      {
        x *= -1;
        num *= -1;
        add = new add.Add(num);
        for(int i = 1; i < x; i++)
        {
          add.add(num);
        }
      }
      else //x == 0
      {
        add = new add.Add();
      }
    }
  }

  public int get()
  {
    return add.get();
  }

  public void set(int x)
  {
    add.set(x);
  }
}
