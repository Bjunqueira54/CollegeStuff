using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace F3Ex4.Models
{
    public class UnidadeCurricular
    {
        public int Id { get; set; }
        public string Nome { get; set; }
        public int ECTS { get; set; }
        public string Licenciatura { get; set; }
        public string Ramo { get; set; }
        public int Semestre { get; set; }

    }
}