using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace ASP.Net_Aula1.Controllers
{
    public class UCsController: Controller
    {
        // GET: UCSs
        public ActionResult Index()
        {
            string list =   "<ul><li>Estratégia Organizacional</li>" +
                            "<li>Arguiteturas Móveis</li>" +
                            "<li>Programação Distribuída</li>" +
                            "<li>Inteligência Computacional</li>";

            return Content(list);
        }
    }
}