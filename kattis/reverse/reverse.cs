using System;

class ofugsnuid {
    public static void Main(string[] args) {
        int n = Convert.ToInt32(Console.ReadLine());
        int[] array = new int[n];
        for (int i = 0; i<n;i++) {
            array[i] = Convert.ToInt32(Console.ReadLine());
        }
        for (int i = array.Length - 1; i>=0;i--) {
            Console.WriteLine(array[i]);
        }
    }
}