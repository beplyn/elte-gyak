namespace LegkisebbOszto;

class Program
{
    static void Main(string[] args)
    {
        // Csak a sor első számát olvassuk be
        string[] bemenet = Console.ReadLine()!.Split(' ', StringSplitOptions.RemoveEmptyEntries);
        int n = int.Parse(bemenet[0]);

        int i = 2;
        while (n % i != 0)
        {
            i++;
        }
        int legkisebbOszto = i;

        Console.WriteLine(legkisebbOszto);
    }
}
