using System;

class echoechoecho {
    public static void Main(string[] args) {
        string s;
        while(true) {
            s = Console.ReadLine();
            if(1<=s.Length & s.Length <= 15) {
                break;
            }
        }
        for(int i = 0; i<3;i++) {
            Console.Write(s + " ");
        }
    }
}