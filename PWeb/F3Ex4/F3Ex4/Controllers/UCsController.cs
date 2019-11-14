using System.Linq;
using System.Web.Mvc;

using F3Ex4.Models;

namespace F3Ex4.Controllers
{
    public class UCsController : Controller
    {

        // GET: UCs
        public ActionResult Index()
        {
            return View(UCsMockData.ListaUCs);
            }

        // GET: UCs/Details/5
        public ActionResult Details(int id)
        {
            UnidadeCurricular uc = UCsMockData.ListaUCs.FirstOrDefault(s => s.Id == id);
            if (uc == null) return RedirectToAction("Index");

            return View(uc);
            }

        // GET: UCs/Create
        public ActionResult Create()
        {
            return View();
        }

        // POST: UCs/Create
        [HttpPost]
        public ActionResult Create(FormCollection collection)
        {
            try
            {
                UnidadeCurricular nova = new UnidadeCurricular();
                int maxId = (from x in UCsMockData.ListaUCs select x.Id).Max();

                nova.Id = maxId+1;
                nova.Nome = collection["Nome"];
                nova.Licenciatura = collection["Licenciatura"];
                nova.Ramo = collection["Ramo"];

                if (int.TryParse(collection["Semestre"], out int semestre))
                    if(semestre > 0 && semestre < 7)
                        nova.Semestre = semestre;
                    else return View(nova);
                else return View(nova);

                if (int.TryParse(collection["ECTS"], out int ects))
                    if(ects > 0 && ects < 31)
                        nova.ECTS = ects;
                    else return View(nova);
                else return View(nova);

                UCsMockData.ListaUCs.Add(nova);
                return RedirectToAction("Index");
            }
            catch
            {
                return View();
            }
        }

        // GET: UCs/Edit/5
        public ActionResult Edit(int id)
        {
            UnidadeCurricular uc = UCsMockData.ListaUCs.FirstOrDefault(s => s.Id == id);
            if (uc == null) return RedirectToAction("Index");

            return View(uc);
            }

        // POST: UCs/Edit/5
        [HttpPost]
        public ActionResult Edit(int id, FormCollection collection)
        {
            UnidadeCurricular uc = UCsMockData.ListaUCs.FirstOrDefault(s => s.Id == id);
            if (uc == null) return RedirectToAction("Index");

            try
            {
                uc.Nome = collection["Nome"];
                uc.Licenciatura = collection["Licenciatura"];
                uc.Ramo = collection["Ramo"];

                if (int.TryParse(collection["Semestre"], out int semestre))
                    if (semestre > 0 && semestre < 7)
                        uc.Semestre = semestre;
                    else return View(uc);
                else return View(uc);

                if (int.TryParse(collection["ECTS"], out int ects))
                    if (ects > 0 && ects < 31)
                        uc.ECTS = ects;
                    else return View(uc);
                else return View(uc);

                return RedirectToAction("Index");
                }
            catch
            {
                return View();
            }
        }

        // GET: UCs/Delete/5
        public ActionResult Delete(int id)
        {
            UnidadeCurricular uc = UCsMockData.ListaUCs.FirstOrDefault(s => s.Id == id);
            if (uc == null) return RedirectToAction("Index");

            return View(uc);
            }

        // POST: UCs/Delete/5
        [HttpPost]
        public ActionResult Delete(int id, FormCollection collection)
        {
            UnidadeCurricular uc = UCsMockData.ListaUCs.FirstOrDefault(s => s.Id == id);
            if (uc == null) return RedirectToAction("Index");

            try
            {
                UCsMockData.ListaUCs.Remove(uc);
                return RedirectToAction("Index");
            }
            catch
            {
                return View();
            }
        }
    }
}
