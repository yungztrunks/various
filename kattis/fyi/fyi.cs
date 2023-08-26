using System;

class fyi {
    public static void Main(string[] args) {
        int n = Convert.ToInt32(Console.ReadLine());
        n = n / 10000;
        if (n==555) {
            Console.WriteLine("1");
        } else {
            Console.WriteLine("0");
        }
    }
}