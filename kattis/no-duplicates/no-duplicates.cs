using System;
using System.Linq;

class nodup {
    public static void Main(string[] args) {
        string s = "";
        while(true) {
            s = Console.ReadLine();
            if (s.Length < 81) {
                break;
            }
        }
        
        string[] array = s.Split(" ");
        if (array.Length != array.Distinct().Count())
{
    Console.WriteLine("no");
} else {
    Console.WriteLine("yes");
}
        
        
    }
}