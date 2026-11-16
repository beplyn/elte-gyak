namespace DolgozokKulonbozoEletkora;

class Program
{
    public struct Munkas
    {
        public int kor;
        public int fizu;
    };
    static void Main(string[] args)
    {
        int n, kEDSz;

        int.TryParse(Console.ReadLine(), out n);

        Munkas[] k = new Munkas[n];
        for (int i = 0; i < n; i++)
        {
            string[] tmp = Console.ReadLine().Split();
            int.TryParse(tmp[0], out k[i].kor);
        }


        kEDSz = 0;

        for (int i = 0; i < n; i++)
        {
            int j = 0;

            while (i <= i - 1 && !(k[j].kor == k[i].kor))
            {
                j++;
            }
            bool van = j <= i - 1;

            if (!van)
                kEDSz++;
        }

        Console.WriteLine(kEDSz);
    }
}
