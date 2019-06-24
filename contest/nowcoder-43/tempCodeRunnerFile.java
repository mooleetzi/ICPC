import java.util.*;
import java.math.*;
public class B{
    public static void main(String args[]) {
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        while(t>0){
            BigDecimal a=sc.nextBigDecimal();
            BigDecimal b=sc.nextBigDecimal();
            int l=sc.nextInt();
            int r=sc.nextInt();
            a=a.divide(b,r+2,RoundingMode.HALF_UP);
            String ans=a.toString();
            int idx=ans.indexOf(".");
            ans=ans.substring(idx,ans.length()-idx-1);
            for (int i=l;i<=r;i++)
                System.out.print(ans.charAt(i));
            System.out.println();
            t--;
        }
    }
}