using System;
using System.Collections.Generic;
using System.Data;
using System.Data.Entity;
using System.Linq;
using System.Net;
using System.Web.Mvc;
using F6Ex2.DAL;
using F6Ex2.ViewModels;

using PagedList;


namespace F6Ex2.Controllers
{
    public class ProdutosController : Controller
    {
        private TTDatabaseDF db = new TTDatabaseDF();

        // GET: Produtos
        // NOVO 2g: int? página

        public ActionResult Index(string categoria, string procura, string ordem, int? pagina)
        {
            ProdutosIndexViewModel pvm = new ProdutosIndexViewModel();

            var produtos = db.Produtos.Include(p => p.Categoria);

            //FILTRA POR PROCURA
            if (!String.IsNullOrEmpty(procura))
            {
                produtos = produtos.Where(p => p.Categoria.Nome.Contains(procura)
                    || p.Nome.Contains(procura) || p.Descricao.Contains(procura));

                //Guarda a procura (introduzida na textbox) no pvm
                pvm.Procura = procura;
                }

            //Agrupa os resultados da procura em categorias e conta quantos produtos existem em cada categoria
            pvm.CategoriasComContagemDeProdutos(produtos);

            //FILTRA POR CATEGORIA
            if (!String.IsNullOrEmpty(categoria)) {
                produtos = produtos.Where(p => p.Categoria.Nome == categoria);
                pvm.Categoria = categoria;
                }

            //PÁGINAS e FILTRAGEM POR ORDEM (2g)
            int nreg = 5;
            int pag = (pagina ?? 1); //Se pagina for um valor não nulo pag= pagina; senão pag= 1.

            //Alterado (2g)
            pvm.OrdenarProdutos(ordem, produtos, pag, nreg);

            return View(pvm);
            }

        // GET: Produtos/Details/5
        public ActionResult Details(int? id)
        {
            if (id == null)
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);

            Produtos produtos = db.Produtos.Find(id);
            if (produtos == null) return HttpNotFound();

            return View(produtos);
            }

        // GET: Produtos/Create
        public ActionResult Create()
        {
            ViewBag.CategoriasId = new SelectList(db.Categorias, "Id", "Nome");
            return View();
        }

        // POST: Produtos/Create
        // To protect from overposting attacks, please enable the specific properties you want to bind to, for 
        // more details see https://go.microsoft.com/fwlink/?LinkId=317598.

        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult Create([Bind(Include = "Id,Nome,Descricao,Preco,CategoriasId")] Produtos produtos)
        {
            if (ModelState.IsValid)
            {
                db.Produtos.Add(produtos);
                db.SaveChanges();
                return RedirectToAction("Index");
            }

            ViewBag.CategoriasId = new SelectList(db.Categorias, "Id", "Nome", produtos.CategoriasId);
            return View(produtos);
        }

        // GET: Produtos/Edit/5
        public ActionResult Edit(int? id)
        {
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            Produtos produtos = db.Produtos.Find(id);
            if (produtos == null)
            {
                return HttpNotFound();
            }
            ViewBag.CategoriasId = new SelectList(db.Categorias, "Id", "Nome", produtos.CategoriasId);
            return View(produtos);
        }

        // POST: Produtos/Edit/5
        // To protect from overposting attacks, please enable the specific properties you want to bind to, for 
        // more details see https://go.microsoft.com/fwlink/?LinkId=317598.

        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult Edit([Bind(Include = "Id,Nome,Descricao,Preco,CategoriasId")] Produtos produtos)
        {
            if (ModelState.IsValid)
            {
                db.Entry(produtos).State = EntityState.Modified;
                db.SaveChanges();
                return RedirectToAction("Index");
            }
            ViewBag.CategoriasId = new SelectList(db.Categorias, "Id", "Nome", produtos.CategoriasId);
            return View(produtos);
        }

        // GET: Produtos/Delete/5
        public ActionResult Delete(int? id)
        {
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            Produtos produtos = db.Produtos.Find(id);
            if (produtos == null)
            {
                return HttpNotFound();
            }
            return View(produtos);
        }

        // POST: Produtos/Delete/5
        [HttpPost, ActionName("Delete")]
        [ValidateAntiForgeryToken]
        public ActionResult DeleteConfirmed(int id)
        {
            Produtos produtos = db.Produtos.Find(id);
            db.Produtos.Remove(produtos);
            db.SaveChanges();
            return RedirectToAction("Index");
        }

        protected override void Dispose(bool disposing)
        {
            if (disposing)
            {
                db.Dispose();
            }

            base.Dispose(disposing);
        }
    }
}
