using System.Collections.Generic;
using System.Linq;
using System.Web.Mvc;
using F6Ex2.DAL;

// NOVO 2g:
using PagedList;

namespace F6Ex2.ViewModels
{
    public class CategoriaComContagem
    {
        public string NomeDaCategoria { get; set; }
        public int NumeroDeProdutos { get; set; }

        public string NomeDaCategoriaComContagem
        {
            get {return $"{NomeDaCategoria} ({NumeroDeProdutos.ToString()})"; }
            }
        }

    // NOVO 2g:
    public class ProdutosIndexViewModel
    {
        public string Categoria { get; set; }
        public string Procura { get; set; }

        public IPagedList<Produtos> Produtos { get; set; }
        public IEnumerable<CategoriaComContagem> CategoriasComContagem { get; set; }

        public string Ordem { get; set; }
        public Dictionary<string, string> TiposDeOrdenacao { get; set; }

        //Construtor:
        public ProdutosIndexViewModel()
        {
            TiposDeOrdenacao= new Dictionary<string, string> { { "Preço ascendente", "asc" }, { "Preço descendente", "desc" } };

            }

        //Propriedade: gera a lista de categorias usada na dropdownlist:

        public IEnumerable<SelectListItem> CategoriasSelectListItems
        {
            get
            {
                return CategoriasComContagem.Select(cc => new SelectListItem
                { Value = cc.NomeDaCategoria, Text = cc.NomeDaCategoriaComContagem });
            }
        }

        //Método: agrupa em categorias e conta quantos produtos existem em cada categoria:

        public void CategoriasComContagemDeProdutos(IQueryable<Produtos> produtos)
        {
            CategoriasComContagem = from p in produtos
                                    where p.CategoriasId != null
                                    group p by p.Categoria.Nome into catGroup
                                    select new CategoriaComContagem() { NomeDaCategoria = catGroup.Key, NumeroDeProdutos = catGroup.Count() };

            return;
            }


        //NOVO 2g
        public void OrdenarProdutos(string orderby, IQueryable<Produtos> produtos, int pag, int nreg)
        {
            switch (orderby)
            {
                case "asc":
                    Produtos = produtos.OrderBy(p => p.Preco).ToPagedList(pag, nreg);
                    break;
                case "desc":
                    Produtos = produtos.OrderByDescending(p => p.Preco).ToPagedList(pag, nreg); ;
                    break;
                default:
                    Produtos = produtos.OrderBy(p => p.Nome).ToPagedList(pag, nreg); ;
                    break;
                }

            Ordem= orderby;
            return;
            }
    }
}