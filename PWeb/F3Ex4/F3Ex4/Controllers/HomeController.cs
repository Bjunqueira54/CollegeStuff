using System.Web.Mvc;

namespace F3Ex4.Controllers
{
    public class HomeController : Controller
    {
        public ActionResult Index()
        {
            return View();
        }

        public ActionResult About()
        {
            ViewBag.Message = "Relação de Unidades Curriculares do Curso.";

            return View();
        }

        public ActionResult Contact()
        {
            ViewBag.Message = "Para informações sobre o curso, contacte-nos pelo telefone 239790200 ou pelo mail pweb@isec.px.";

            return View();
        }
    }
}