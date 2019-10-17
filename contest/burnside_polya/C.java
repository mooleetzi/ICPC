
/*
    正方形置换群8个
    奇：
        0 : m^(n*n)
        +90,-90 : m^((n*n+3)/4)
        180:m^((n*n+1)/2)
        对角线，非对角线:m^((n*n+n)/2)
    偶：
        类似讨论
*/
import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        BigInteger m, res;
        int n;
        while (cin.hasNext()) {
            n = cin.nextInt();
            m = cin.nextBigInteger();
            res = BigInteger.ZERO;
            if (n % 2 == 0) {
                res = res.add(m.pow(n * n / 4).multiply(BigInteger.valueOf(2))); // +-90
                res = res.add(m.pow(n * n / 2)); // 180
                res = res.add(m.pow(n * n)); // 0
                res = res.add(m.pow(n * n / 2).multiply(BigInteger.valueOf(2)));
                res = res.add(m.pow((n * n + n) / 2).multiply(BigInteger.valueOf(2)));
            } else {
                res = res.add(m.pow((n * n + 3) / 4).multiply(BigInteger.valueOf(2))); // +-90
                res = res.add(m.pow((n * n + 1) / 2)); // 180
                res = res.add(m.pow(n * n)); // 0
                res = res.add(m.pow((n * n + n) / 2).multiply(BigInteger.valueOf(4)));
            }
            res = res.divide(BigInteger.valueOf(8));
            System.out.println(res);
        }
    }
}
