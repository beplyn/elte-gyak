namespace olcsoFenyofa;

class Program
{
    static void Main(string[] args)
    {
        string[] elsoSor = Console.ReadLine()!.Split();
        int n = int.Parse(elsoSor[0]);
        int k = int.Parse(elsoSor[1]);

        int[] ar = new int[n];
        for (int j = 0; j < n; j++)
        {
            ar[j] = int.Parse(Console.ReadLine()!);
        }

        int i = 0;
        while (i < n && ar[i] >= k)
        {
            i++;
        }

        bool van = i < n;
        int sorszam;

        if (van)
        {
            sorszam = i + 1;
        }
        else
        {
            sorszam = -1;
        }

        Console.WriteLine(sorszam);
    }
}
