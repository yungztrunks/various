using System;

class digitswap {
    public static void Main(string[] args) {
        int n = Convert.ToInt32(Console.ReadLine());
        int x = ((n%10) * 10) + (n/10);
        Console.WriteLine(x);
    }
}