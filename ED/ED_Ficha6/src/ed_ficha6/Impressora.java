package ed_ficha6;

import java.util.Comparator;
import java.util.PriorityQueue;

public class Impressora
{
    private String nome, marca, modelo, driver, versao;
    private Integer porto;
    private PriorityQueue<Trabalho> pq = new PriorityQueue<Trabalho>(
            
            new Comparator<Trabalho>()
            {
                @Override
                public int compare(Trabalho o1, Trabalho o2)
                {
                    return o1.getPaginas() - o2.getPaginas();
                }
            });
    
    public Impressora(String nome, Integer porto, String marca, String modelo, String driver, String versao)
    {
        this.nome = nome;
        this.porto = porto;
        this.marca = marca;
        this.modelo = modelo;
        this.driver = driver;
        this.versao = versao;
    }

    public String getDriver() { return driver; }

    public String getMarca() { return marca; }

    public String getModelo() { return modelo; }

    public String getNome() { return nome; }

    public Integer getPorto() { return porto; }

    public String getVersao() { return versao; }
    
    public void show()
    {
        System.out.println(this.nome+" | "+this.marca+" | "+this.modelo+" | "+this.porto+" | "+this.driver+" | "+this.versao);
    }
    
    public boolean temProximoTrabalho() { return !pq.isEmpty(); }
    
    public Trabalho proximoTrabalho() { return pq.poll(); }
    
    public void enviaTrabalho(Trabalho trabalho) { pq.add(trabalho); }
    
    public int getNumeroTrabalhos() { return pq.size(); }
}