using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PWeb_Ficha1_Ex2
{
    class Funcionario
    {
        private string nome;
        private string apelido;
        private int nif { get; }

        private double sal_base;
        private double vendas;
        private double comissao;

        public Funcionario()
        {
            this.nome = "John";
            this.apelido = "Doe";
            this.nif = 123456789;

            this.sal_base = 500;

            this.vendas = 5000;
            this.comissao = 0.25;
        }

        public Funcionario(string nome, string apelido, int nif, double sal_base, double comissao, double vendas)
        {
            this.nome = nome;
            this.apelido = apelido;

            this.nif = nif;
            
            SalarioBase = sal_base;
            Vendas = vendas;
            Comissao = comissao;
        }

        public double Vendas
        {
            get { return this.vendas; }

            set
            {
                if(value < 0)
                    throw new ArgumentOutOfRangeException(nameof(value), value, $"{nameof(this.vendas)} tem de ser >= 0");

                this.vendas = value;
            }
        }

        public double Comissao
        {
            get { return this.comissao; }

            set
            {
                if (value < 0 || value > 1)
                    throw new ArgumentOutOfRangeException(nameof(value), value, $"{nameof(this.comissao)} tem de ser > 0 e < 1");

                this.comissao = value;
            }
        }

        public double SalarioBase
        {
            get { return this.sal_base; }

            set
            {
                if (value < 0)
                    throw new ArgumentOutOfRangeException(nameof(value), value, $"{nameof(this.sal_base)} tem de ser > 0");

                this.sal_base = value;
            }
        }

        public string NomeCompleto
        {
            get
            {
                return this.nome + " " + this.apelido;
            }
        }

        public float getSalVar() { return (float) (this.Vendas * this.Comissao); }

        public float getSalarioFinal() { return ((float) this.SalarioBase + getSalVar()); }
            
        public string getInfo()
        {
            if (this.SalarioBase == 0)
                return
                "Funcionario: " + this.NomeCompleto + "\n" +
                "NIF: " + nif.ToString() + "\n" +
                "Vendas Totais: " + this.Vendas.ToString() + "\n" +
                "Comissao de Vendas: " + this.Comissao.ToString() + "\n" +
                "Vencimento Final: " + getSalarioFinal().ToString() + "\n";
            else
                return
                    "Funcionario: " + this.NomeCompleto + "\n" +
                    "NIF: " + nif.ToString() + "\n" +
                    "Vendas Totais: " + Vendas.ToString() + "\n" +
                    "Comissao de Vendas: " + Comissao.ToString() + "\n" +
                    "Vencimento Base: " + SalarioBase.ToString() + "\n" +
                    "Vencimento Final: " + getSalarioFinal().ToString() + "\n";
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Funcionario A = new Funcionario("Bruno", "Junqueira", 123456789, 0, 0.5, 5000);
            Funcionario B = new Funcionario("Cassandra", "Dimas", 987654321, 600, 0.15, 3500);

            Console.WriteLine(A.getInfo());
            Console.WriteLine(B.getInfo());

            Console.ReadKey();
        }
    }
}
