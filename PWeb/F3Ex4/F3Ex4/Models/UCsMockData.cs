using System.Collections.Generic;
using System.Linq;

namespace F3Ex4.Models
{
    static public class UCsMockData
    {
        //Field
        private static List<UnidadeCurricular> ucs;

        //Property
        public static List<UnidadeCurricular> ListaUCs
        {
            get
            {
                if (ucs == null) ucs = UCsMockInitialData();
                return ucs;
                }
            }


    static private List<UnidadeCurricular> UCsMockInitialData()
    {
      List<UnidadeCurricular> ucs = new List<UnidadeCurricular> {
            new UnidadeCurricular {Id= 1, Nome="Programação Web", ECTS= 6, Licenciatura= "Engenharia Informática", Semestre= 5, Ramo="TC"},
            new UnidadeCurricular {Id= 2, Nome="Arquiteturas Móveis", ECTS= 6, Licenciatura= "Engenharia Informática", Semestre= 5, Ramo= "DA"},
            new UnidadeCurricular {Id= 3, Nome="Programação Distribuída", ECTS= 6, Licenciatura= "Engenharia Informática", Semestre= 5, Ramo= "DA"},
            new UnidadeCurricular {Id= 4, Nome="Inteligência Computacional", ECTS= 6, Licenciatura= "Engenharia Informática", Semestre= 5, Ramo= "SI"}
            };

      return ucs;
      }

    }
}