using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PWeb_Ficha2_Ex1
{
    class Program
    {
        static void Main(string[] args)
        {
            List<string> listastrings = new List<string>() { "C#", "Entity Framework", "ASP.NET MVC com C#", "Linq", "Lambda", "Identity Framework" };

            var ListaA = new List<string>();

            foreach (var x in listastrings)
                if (x.Contains("C#"))
                    ListaA.Add(x);

            var ListaB = from s in listastrings where s.Contains("C#") select s;

            var ListaC = listastrings.Where(l=>l.Contains("C#"));

            string[] ListaUm = { "C#", "AprenderC#", "ASP.NETMVCcomC#", "EntityFramework", "Bootstrap", "Identity", "Lambda", "Delegates", "Linq", "POOcomC# " };

            string[] ListaDois = { "C#", "ASP.NETMVC", "Linq", "Lambda e C#" };

            int[] Numeros = { 10, 23, 54, 77, 85, 12, 1, 4, 53 };

            var _solucao = from x in ListaUm where x.Length < 6 select x;
            var solucao_ = ListaUm.Where(x => x.Length < 6);
        }
    }
}
