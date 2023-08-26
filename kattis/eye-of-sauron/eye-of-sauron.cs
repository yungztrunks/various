using System;
using System.Linq;

class eyeofsauron {
    public static void Main(string[] args) {
        string s = Console.ReadLine();
        string[] array = s.Split("()");
        if(array[0].Length == array[1].Length) {
            Console.WriteLine("correct");
        } else {
            Console.WriteLine("fix");
        }
    }
}