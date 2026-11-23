namespace LegnagyobbHaszon;

class Program
{
    public struct Termek
    {
        public int besz, eladas1, eladas2, kedv, alap;
    }

    static void Main(string[] args)
    {
        int.TryParse(Console.ReadLine(), out int n);

        Termek[] termekek = new Termek[n];

        for (int i = 0; i < n; i++)
        {
            string[] sor = Console.ReadLine()!.Split();

            int.TryParse(sor[0], out termekek[i].besz);
            int.TryParse(sor[1], out termekek[i].alap);
            int.TryParse(sor[2], out termekek[i].kedv);
            int.TryParse(sor[3], out termekek[i].eladas1);
            int.TryParse(sor[4], out termekek[i].eladas2);
        }

        int maxhaszon = 0;

        for (int i = 0; i < n; i++)
        {
            if (termekek[i].eladas2 > termekek[i].eladas1)
            {
                int haszon = haszonCalc(termekek[i]);
                if (haszon > maxhaszon)
                {
                    maxhaszon = haszon;
                }
            }
        }

        Console.WriteLine(maxhaszon);
    }

    static int haszonCalc(Termek term)
    {
        return (term.kedv - term.besz) * term.eladas2;
    }
}
