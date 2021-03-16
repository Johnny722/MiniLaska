#include<stdio.h>
#include "ml_lib.h"

#define NUMERO_PEDINE 7

typedef struct s_node t_node;

/*alfa -> [-1,1]*/

struct s_node { /*coppia valore,mossa*/
	int alfa; /*indice */
	point start;
	point end;
	pedina *data;
};

/* \fn catchInput(int *cord, pedina **board)
*   \brief Legge l'input da tastiera
*	\param cord array contenente le coordinate di partenza e destinazione della pedina
*   \param board matrice linearizzata della scacchiera
*
* 	Legge l'input dall'utente e traduce le coordinate in int, che vengono inseriti in un array apposito.
*/

void catchInput_Autoplay(int *cord, t_node result);

/* \fn can_eat(pedina **board, point p)
*   \brief Verifica la possibilità di mangiare
*   \param board matrice linearizzata della scacchiera
*   \param p punto in cui si trova la pedina nella scacchiera
*
*	Verifica la possibilità della pedina in \a x , \a y di mangiare le pedine avversarie intorno a sé
*/

int can_be_eaten(pedina **board, point p);

/* Rotuine di controllo per la chiamata ricorsiva di minimax
*/

void check_son(pedina **board, t_node *res, int x, int y, t_node *node, int *alfa, int depth, int turn);

    /* Verifica la possibilità che la pedina può mangiare 
	*	o altrimenti essere mangiata
	*	Fine della mossa
	*/


int evaluate(pedina **board, t_node node);

/*
function minimax(nodo, profondità)

    SE nodo è un nodo terminale OPPURE profondità = 0
        return il valore euristico del nodo 
		
    SE l'avversario deve giocare
        α := +∞
        PER OGNI figlio di nodo
            α := min(α, minimax(figlio, profondità-1))
			
			
    ALTRIMENTI dobbiamo giocare noi
        α := -∞
        PER OGNI figlio di nodo
            α := max(α, minimax(figlio, profondità-1))
			
			
    return α
*/

t_node minimax(pedina **board, t_node node, int depth, int turn);

/*
* 1) Selezione riga
* 2) Selezione max alfa;
* 3) Ritorno pedina,mossa (t_node)
*/

t_node select_pedina(t_node db[NUMERO_PEDINE]);
