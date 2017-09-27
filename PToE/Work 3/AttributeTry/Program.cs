using System;

namespace AttributeTry
{
    class Program
    {
        static void Main(string[] args)
        {
            Loader loader = new Loader();
            Console.WriteLine("File size: {0} bytes.",loader.load());
            Console.ReadLine();
        }
    }
}
