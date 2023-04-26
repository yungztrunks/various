while True:
    height = input("Height:")
    try:
       height = int(height)
    except ValueError:
       print("Please only type in an integer number between 1 and 8 (inclusive)")
       continue
    if 1 <= height <= 8:
       break
    else:
       print("Number must be between 1 and 8 (inclusive)")

for i in range(height):
    for j in range(height-i-1):
        print(" ", end="")
    for k in range(i+1):
        print("#", end="")
    print("  ", end="")
    for m in range(i+1):
        print("", end="#")
    print()

"""
short story time:
i once made a program in C# which solved a similiar problem, and I solved it with a 2D-Array
I really cant try it for this problem here in python so here is a small snippet which I gave up upon
Python is still super new to me. 

array = [["X"] *height] * height
for i in range(height,-1,-1):
    array[0][height-i -1] = "#"

Here is the C# Code for the other assignement too, just in case:
- yungztr

// Aufgabe Nachthimmel (Assignement: Nightsky)

Console.WriteLine("Höhe:"); // Height
int n= Convert.ToInt32(Console.ReadLine());

string[,] array = new string[n,n];
int anzahlZeilen = array.GetLength(0);
int anzahlSpalten = array.GetLength(1);

for (int i = 0; i < anzahlZeilen; i++) {
    for (int j = 0; j < anzahlSpalten; j++) {
        array[i, j] = ".";
    }
}
for (int i = 0; i < anzahlZeilen; i++) {
    array[i, 0] = "*";
    array[n-1, i] = "*";
}
Console.WriteLine("cool");
for (int i = 0; i<anzahlZeilen; i++) {
    array[i, i] = "*";
}
for (int i = 0; i < anzahlZeilen; i++) {
    for (int j = 0; j < anzahlSpalten; j++) {
        Console.Write(array[i, j]);
    }
    Console.WriteLine(" ");
}
"""
