using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.Extensions.Logging;
using Alturas;

namespace APIPAlturas.Controllers
{
    [Route("api/[controller]")]

    public class ConversorAlturasController: Controller
    {
        [HttpGet("PesMetros/{pes}")]

        public object Get(double pes)
        {
            return new {
                alturaPes = pes,
                AlturaMetros = ConversorAlturas.PesParaMetros(pes)
            };
        }
    }
}
