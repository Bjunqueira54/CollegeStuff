// Biblioteca Consola para TP de POO
// Ultima alteracao: 17/18 - Nov 2018
// J

/*
Versoes e historial
Dez 2010 - Implementacao: Funcoes da consola + exemplo + comentarios
Nov 2013 - Pequenas correcoes
Dez 2015 - Comentarios melhorados
Dez 2016 - Exemplo melhorado.
         - Compatibilidade com mingw automatizada
         - As funcoes passaram a ser estaticas
Nov 2018 - Pequenos melhoramentos nos comentarios
*/



#ifndef __CONSOLA_H__
#define __CONSOLA_H__

#include <windows.h>

class Consola {

	static HANDLE hconsola;
	static HANDLE hStdin;
	static HWND hwnd;

public:

	// para usar nas cores
	const static int PRETO = 0;
	const static int AZUL = 1;
	const static int VERDE = 2;
	const static int CYAN = 3;
	const static int VERMELHO = 4;
	const static int ROXO = 5;
	const static int AMARELO = 6;
	const static int BRANCO = 7;
	const static int CINZENTO = 8;
	const static int AZUL_CLARO = 9;
	const static int VERDE_CLARO = 10;
	const static int CYAN_CLARO = 11;
	const static int VERMELHO_CLARO = 12;
	const static int COR_DE_ROSA = 13;
	const static int AMARELO_CLARO = 14;
	const static int BRANCO_CLARO = 15;

	// para usar em getch
	const static char ESQUERDA = 1;
	const static char DIREITA = 2;
	const static char CIMA = 3;
	const static char BAIXO = 4;
	const static char ENTER = 13;
	const static char ESCAPE = 27;

	Consola() = delete;  // Nao quero objectos disto a proliferarem por ai.
	                     // As funcoes sao estaticas por alguma razao.
	                     // ----------> C++ 2011 ou posterior

	// Posiciona o cursor na posicao x,y
	// - Os proximos cout/cin serao feitos a partir dao
	static void gotoxy(int x, int y);

	// Limpa o ecra
	// - Usa a cor de fundo que estiver definida
	static void clrscr();

	// Muda a cor das letras
	// - Os cout/cin seguintes usarao essa cor
	static void setTextColor(WORD color);

	// Muda a cor de fundo
	// - Os printf/cout seguintes usarao essa cor
	// - Os clrsrc() seguintes usarao essa cor de fundo
	static void setBackgroundColor(WORD color);

	// Muda a dimensao do ecra para NLinhas x NCols
	// - O redimensionamento pode falhar se o tamanho
	//   indicado for excessivo ou se for demasiado
	//   pequeno
	// - Limpa o ecra usando a cor que estiver definida?
	static void setScreenSize(int nLinhas, int nCols);

	// Muda (tenta mudar) o tamanho da letra
	// - Esta funcao pode falhar em determinadas situacoes
	//   (falhar = nao muda nada)
	//   O mais provavel falhar no sistemas antigos (XP)
	// - Ver tambem setSTextSizeXP
	static void setTextSize(int x, int y); // ##### Mingw ->Sem efeito (Nao disponivel) #####

	// Muda (tenta mudar) o tamanho da letra para XP (alguem ainda usa isso?)
	// - Esta funcao e para usar apenas no caso do sistema
	//   ser o XP
	//   No outros sistemas existe a funcao setTextSize
	// - Pode falhar em determinadas situacoes
	//   (falhar = nao muda nada)
	// - Ver tambem setSTextSizeXP
	static void setTextSizeXP(int x, int y);  // ##### Mingw ->Sem efeito (Nao disponivel) #####

	// Le um caracter sem precisar de "enter" no fim
	// - Util para fazer pausas do tipo
	//   "press any key to continue"
	// - Esta funcionalidade tambem se consegue de
	//   outras formas
	static char getch(void);

	// As duas funcoes seguintes sao pouco interessantes

	// Desenha uma linha usando pixeis (nao e com caracteres)
	// - Esta e uma funcao grafica. Trabalha com pixeis
	// - Os pixeis da linha ficam sobrepostos ao texto
	// Esta funcao e pouco interessante porque:
	// - A linha nao fica memorizada. Desaparece quando:
	//   . Se oculta e volta a mostrar a janela da consola
	//   . Se redimensiona a janela
	static void drawLine(int x1, int y1, int x2, int y2, int cor);  // ##### Mingw ->Sem efeito (Nao disponivel) #####

	// Desenha um circulo usando pixeis (nao e com caracteres)
	// - Esta e uma funcao grafica. Trabalha com pixeis
	// - Os pixeis do circulo ficam sobrepostos ao texto
	// Esta funcao e pouco interessante porque:
	// - O circulo nao fica memorizado. Desaparece quando:
	//   . Se oculta e volta a mostrar a janela da consola
	//   . Se redimensiona a janela
	static void drawCircle(int X, int Y, int R, int Pen, int Fill);  // ##### Mingw ->Sem efeito (Nao disponivel) #####
};

#endif