package mult;
import java.util.*;

public class EntryPoint
{
    public static void main(String args[])
    {
      int num1, num2;
      String op, numstr = "", operator;
      Scanner sc = new Scanner(System.in);

      System.out.print("statement: ");
      op = sc.nextLine();
      numstr = getStr(op, '*');
      num1 = getInt(numstr);
      //System.out.println("op: " + op);

      op = op.substring(numstr.length()+1, op.length());
      operator = op.substring(0, 1);
      //System.out.println("op: " + op);

      op = op.substring(2, op.length());
      //System.out.println("op: " + op);
      num2 = getInt(op);

      operation(num1, operator, num2);
    }

    public static String getStr(String s, char stopChar)
    {
      String str = "";
      for(int i = 1; i < s.length(); i++)
      {
        str = s.substring(0, i);
        char c = str.charAt(i-1);
        if(c == ' ' || c == stopChar)
        {
          str = str.substring(0, str.length() - 1);
          break;
        }
      }
      return str;
    }

    public static int getInt(String s)
    {
      int sum = 0;
      int start = 0;
      int mult = 1;
      if(s.length() > 1 && s.charAt(0) == '-')
      {
        start = 1;
        mult = -1;
        if(s.charAt(1) >= 48 && s.charAt(1) <= 57)
          sum -= (s.charAt(1) - 48);
        else
        {
          System.out.println("Cannot multiply anything else besides numbers!");
          System.exit(1);
        }
      }
      for(int i = start; i < s.length(); i++)
      {
        char c = s.charAt(i);
        if(c >= 48 && c <= 57)
        {
          sum = (sum * 10) + ((c - 48) * mult);
        }
        else
        {
          System.out.println("Cannot multiply anything else besides numbers!");
          System.exit(1);
        }
      }
      return sum;
    }

    public static void operation(int num1, String op, int num2)
    {
      if(op.equals("*"))
      {
        Multiply mult = new Multiply(num1);
        mult.mult(num2);
        int res = mult.get();
        System.out.println(num1 + " * " + num2 + " = " + res);
      }
      else if(op.equals("+"))
      {
        add.Add add = new add.Add(num1);
        add.add(num2);
        int res = add.get();
        System.out.println(num1 + " + " + num2 + " = " + res);
      }
      else
      {
        System.out.println("Cannot operate with " + op);
        System.exit(1);
      }
    }
}
