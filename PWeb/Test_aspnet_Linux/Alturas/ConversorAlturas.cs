using System;

namespace Alturas
{
    public static class ConversorAlturas
    {
        public static double PesParaMetros(double pes)
        {
            double res;

            res = pes * 0.3048;

            Math.Round(res, 4);

            return res;
        }
    }
}
