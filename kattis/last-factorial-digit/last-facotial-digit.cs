using System;

class lastfactorialdigit {
    
    public static void Main(string[] args) {
        int[] array = new int[] { 1, 2, 6, 4, 0, 0, 0, 0, 0, 0 };
int n = Convert.ToInt32(Console.ReadLine());
    for (int i = 0; i < n; i++) {
    Console.WriteLine(array[Convert.ToInt32(Console.ReadLine()) - 1]);
        
    }
    }
}