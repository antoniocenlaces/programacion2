const int N = 4;
using Tablero = int[N][N];

const int MOVIMIENTOS[8][2] = {
    {1, -2},
    {-1, -2},
    {-2, -1},
    {-2, 1},
    {-1, 2},
    {1, 2},
    {2, 1},
    {2, -1}
};

//Pre: true
//Post: dentro(i, j) ↔ 0 ≤ i < N ∧ 0 ≤ j < N
bool dentro(int i, int j);

//Pre: true
//Post: ∀α ∈ [0, N − 1].∀β ∈ [0, N − 1].t[α][β] = 0
void initTab(Tablero t);

//Pre: 0 ≤ i < N ∧ 0 ≤ j < N ∧ 1 ≤ m ≤ 8
//Post: (ii, jj) será la casilla alcanzada desde
// (i, j) con el movimiento m
void move(int i, int j, int& ii, int& jj, int m);

//Pre: true
//Post: Muestra el tablero por "cout"
void writeTab(const Tablero t);

//Pre: "t" tiene ya recorridos "numExitos"
// casillas desde la inicial."(i,j)"
// es una casilla alcanzable por el caballo
// desde la última del recorrido
//Post: Si completa un recorrido desde "(i,j)"
// toma valor "true", "numExitos"=N2
// y el recorrido se almacena en "t"
// Si no, devuelve falso; "t" y "numExitos"
// no se modifican
bool caballo(Tablero t, int i, int j,
int &numExitos, int &llamada);