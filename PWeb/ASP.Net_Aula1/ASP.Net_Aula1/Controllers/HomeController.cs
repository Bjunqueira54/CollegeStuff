using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace ASP.Net_Aula1.Controllers
{
    public class HomeController : Controller
    {
        // GET: Home
        public ActionResult Index()
        {
            ViewBag.UC = "Progrmação Web";
            ViewBag.ECTS = 6;
            ViewBag.Curso = "Engenharia Informática";
            ViewBag.Semestre = 5;

            return View();
        }
    }
}