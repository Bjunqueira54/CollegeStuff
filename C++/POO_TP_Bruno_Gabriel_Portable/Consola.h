// Biblioteca Consola para TP de POO
// Ultima alteracao: 17/18 - Nov 2018
// J

/*
Versoes e historial
Dez 2010 - Implementação: Funcoes da consola + exemplo + comentarios
Nov 2013 - Pequenas correções
Dez 2015 - Comentários melhorados
Dez 2016 - Exemplo melhorado.
         - Compatibilidade com mingw automatizada
         - As funções passaram a ser estáticas
Nov 2018 - Pequenos melhoramentos nos comentários
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
	                     // As funçõe são estáticas por alguma razão.
	                     // ----------> C++ 2011 ou posterior

	// Posiciona o cursor na posição x,y
	// - Os proximos cout/cin serão feitos a partir daí
	static void gotoxy(int x, int y);

	// Limpa o ecrã
	// - Usa a cor de fundo que estiver definida
	static void clrscr();

	// Muda a cor das letras
	// - Os cout/cin seguintes usarão essa cor
	static void setTextColor(WORD color);

	// Muda a cor de fundo
	// - Os printf/cout seguintes usarão essa cor
	// - Os clrsrc() seguintes usarão essa cor de fundo
	static void setBackgroundColor(WORD color);

	// Muda a dimensõo do ecrâ para NLinhas x NCols
	// - O redimensionamento pode falhar se o tamanho
	//   indicado for excessivo ou se for demasiado
	//   pequeno
	// - Limpa o ecrã usando a cor que estiver definida?
	static void setScreenSize(int nLinhas, int nCols);

	// Muda (tenta mudar) o tamanho da letra
	// - Esta função pode falhar em determinadas situações
	//   (falhar = não muda nada)
	//   É mais provável falhar no sistemas antigos (XP)
	// - Ver tambêm setSTextSizeXP
	static void setTextSize(int x, int y); // ##### Mingw ->Sem efeito (Não disponivel) #####

	// Muda (tenta mudar) o tamanho da letra para XP (alguêm ainda usa isso?)
	// - Esta função é para usar apenas no caso do sistema
	//   ser o XP
	//   No outros sistemas existe a função setTextSize
	// - Pode falhar em determinadas situações
	//   (falhar = não muda nada)
	// - Ver tambêm setSTextSizeXP
	static void setTextSizeXP(int x, int y);  // ##### Mingw ->Sem efeito (Não disponivel) #####

	// Lê um caracter sem precisar de "enter" no fim
	// - Util para fazer pausas do tipo
	//   "press any key to continue"
	// - Esta funcionalidade tambêm se consegue de
	//   outras formas
	static char getch(void);

	// As duas funções seguintes são pouco interessantes

	// Desenha uma linha usando pixeis (não é com caracteres)
	// - Esta é uma função gráfica. Trabalha com pixeis
	// - Os pixeis da linha ficam sobrepostos ao texto
	// Esta função é pouco interessante porque:
	// - A linha não fica memorizada. Desaparece quando:
	//   . Se oculta e volta a mostrar a janela da consola
	//   . Se redimensiona a janela
	static void drawLine(int x1, int y1, int x2, int y2, int cor);  // ##### Mingw ->Sem efeito (Não disponivel) #####

	// Desenha um círculo usando pixeis (não é com caracteres)
	// - Esta é uma função gráfica. Trabalha com pixeis
	// - Os pixeis do círculo ficam sobrepostos ao texto
	// Esta função é pouco interessante porque:
	// - O círculo não fica memorizado. Desaparece quando:
	//   . Se oculta e volta a mostrar a janela da consola
	//   . Se redimensiona a janela
	static void drawCircle(int X, int Y, int R, int Pen, int Fill);  // ##### Mingw ->Sem efeito (Não disponivel) #####
};

#endif