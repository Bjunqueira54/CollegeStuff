//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated from a template.
//
//     Manual changes to this file may cause unexpected behavior in your application.
//     Manual changes to this file will be overwritten if the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------

namespace F6Ex2.DAL
{
    using System;
    using System.Collections.Generic;
    using System.ComponentModel.DataAnnotations;

    public partial class Produtos
    {
        public int Id { get; set; }
        public string Nome { get; set; }

        public string Descricao { get; set; }
        public double Preco { get; set; }

        public Nullable<int> CategoriasId { get; set; }   
        public virtual Categorias Categoria { get; set; }
    }
}
