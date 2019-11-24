using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Web;

namespace F6Ex2.DAL
{
    [MetadataType(typeof(ProdutosMetaData))]
    public partial class Produtos { }

    public partial class ProdutosMetaData
    {
        [Display(Name = "Descrição")]
        public string Descricao { get; set; }

        [Display(Name = "Preço")]
        public double Preco { get; set; }
        }
}