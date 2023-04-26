Console.WriteLine("Bitte Anzahl n angeben");
int n = Convert.ToInt32(Console.ReadLine());

string[,] array = new string[n, n];
int anzahlZeilen = array.GetLength(0);
int anzahlSpalten = array.GetLength(1);

for (int i = 0; i < anzahlZeilen; i++)
{
    for (int j = 0; j < anzahlSpalten; j++)
    {
        array[i, j] = ".";
    }
}
for (int i = 0; i < anzahlZeilen; i++)
{
    array[i, 0] = "*";
    array[n - 1, i] = "*";
}
for (int i = 0; i < anzahlZeilen; i++)
{
    array[i, i] = "*";
}

for (int i = 0; i < anzahlZeilen; i++)
{
    for (int j = 0; j < anzahlSpalten; j++)
    {
        Console.Write(array[i, j]);
    }
    Console.WriteLine(" ");
}