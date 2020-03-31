using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;

namespace Ficha7.Models
{
    public class Aluno
    {
        public int AlunoID { get; set; }
        public string AlunoNome { get; set; }
        public DateTime? DataNascimento { get; set; }
    }
}
