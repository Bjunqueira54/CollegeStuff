package Ficha3_Ex4;

import java.util.HashMap;
import java.util.Map;

public class Dicionario
{
    static String linguas[] = {"ingles", "portugues", "frances"};
    
    static String LinguaAtual;
    
    Map<String, Map<String, String>> dicionario;
    
    public Dicionario()
    {
	dicionario = new HashMap<>();
	LinguaAtual = "ingles";
    }
    
    public boolean add(String lingua, String def, String traducao)
    {
	if (!isValid(lingua))
	    return false;
	
	String lang = lingua.toLowerCase().trim();
	
	if(dicionario.get(lang) == null)
	    dicionario.put(lang, new HashMap<String, String>());
	
	Map aux = dicionario.get(lang);
	
	if( aux.put(def.trim().toUpperCase(), traducao.trim().toLowerCase()) == null)
	    return false;
	
	return true;
    }
    
    public void defineLingua(String lingua)
    {
	if(!isValid(lingua))
	    return;
	LinguaAtual = lingua;
    }
    
    public String get(String def)
    {
	Map<String, String> aux = dicionario.get(LinguaAtual);
	
	if(aux == null)
	    return null;
	
	return aux.get(def.trim().toUpperCase());
    }
    
    private boolean isValid(String lang)
    {
	for (String lingua : linguas)
	{
	    if(lingua.compareToIgnoreCase(lang) == 0)
		return true;
	}
	
	return false;
    }
}