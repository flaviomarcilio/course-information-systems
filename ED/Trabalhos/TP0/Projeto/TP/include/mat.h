#ifndef MATH
#define MATH

typedef struct mat {
	double **matrix;
	int rows, columns;
	int id;
} mat_tipo;

void criaMatriz(mat_tipo *mat, int rows, int columns, int id);
void inicializaMatrizNula(mat_tipo *mat);
void inicializaMatrizAleatoria(mat_tipo *mat);
double acessaMatriz(mat_tipo *mat);
void imprimeMatriz(mat_tipo *mat);
void escreveElemento(mat_tipo *mat, int x, int y, double v);
double leElemento (mat_tipo *mat, int x, int y);
void copiaMatriz(mat_tipo *src, mat_tipo *dst, int dst_id);
void somaMatrizes(mat_tipo *a, mat_tipo *b, mat_tipo *c);
void multiplicaMatrizes(mat_tipo *a, mat_tipo *b, mat_tipo *c);
void transpoeMatriz(mat_tipo *a);
void destroiMatriz(mat_tipo *a);

#endif
