#include<stdlib.h>
#include<string.h>
#include<assert.h>

struct _matrix {
	int rows;
	int cols;
	double *data;
};

typedef struct _matrix matrix;

#define ELEM(mtx,row,col)\
	mtx->data [(col-1)*mtx->rows + (row-1)]

matrix *newMatrix(int rows, int cols){
	if (rows <= 0 || cols <=0)
		return NULL;
	matrix *m = (matrix *) malloc(sizeof(matrix));

	m->rows = rows;
	m->cols = cols;

	m->data =(double *) malloc(rows*cols*sizeof(double));

	int i;
	for(i=0;i<rows*cols;i++){
		m->data[i]=0.0;
	}
	return m;
}

matrix *copyMatrix(matrix *mtx){
	if(!mtx)
		return NULL;
	matrix *cp= newMatrix(mtx->rows,mtx->cols);
	memcpy(cp->data, mtx->data, mtx->rows * mtx->cols *sizeof(double));
	return cp;
}

int deleteMatrix(matrix *mtx){
	if(!mtx)
		return -1;
	assert(mtx->data);
	free(mtx->data);
	free(mtx);
	return 0;
}

int setElement(matrix *mtx, int row, int col, double val){
	if(!mtx)
		return -1;
	assert(mtx->data);
	if(row<=0||col<=0||row>mtx->rows||col>mtx->cols)
		return-2;
	ELEM(mtx,row,col) = val;
	return 0;
}

int getElement(matrix *mtx, int row, int col, double *val){
	if(!mtx||!val)
		return -1;
	assert(mtx->data);
	if(row<=0||col<=0||row>mtx->rows||col>mtx->cols)
		return-2;
	*val = ELEM(mtx,row,col);
	return 0;
}

int nRows(matrix *mtx, int *n){
	if(!mtx||!n)
		return -1;
	*n=mtx->rows;
	return 0;
}

int nCols(matrix *mtx, int *n){
	if(!mtx||!n)
		return -1;
	*n=mtx->cols;
	return 0;
}

int printMatrix(matrix *mtx) {
	if(!mtx)
		return -1;
	int row,col;
	for (row=1;row<=mtx->rows;row++){
		for(col=1;col<=mtx->cols;col++) {
			printf("%6.2f", ELEM(mtx,row,col));
		}
		printf("\n");
	}
	return 0;
}

int transpose(matrix *in, matrix *out){
	if(!in||!out)
		return -1;
	if(in->rows != out->cols || in->cols != out->rows)
		return -2;

	int row,col;
	for(row=1;row<=in->rows;row++)
		for(col=1;col<=in->cols;col++)
			ELEM(out,col,row)=ELEM(in,row,col);
	return 0;
}

int sum(matrix *mtx1, matrix *mtx2, matrix *sum){
	if(!mtx1 || !mtx2 || !sum)
		return -1;
	if(mtx1->rows != mtx2->rows || mtx1->rows != sum->rows || mtx1->cols != mtx2->cols || mtx1->cols != sum->cols)
		return -2;
	int row,col;
	for(col=1;col<=mtx1->cols;col++)
		for(row=1;row<=mtx1->rows;row++)
			ELEM(sum,row,col) = ELEM(mtx1,row,col) + ELEM(mtx2,row,col);
	return 0;
}

int product(matrix *mtx1, matrix *mtx2, matrix *prod){
	if(!mtx1 || !mtx2 || !prod)
		return -1;
	if(mtx1->cols != mtx2->rows || mtx1->rows != prod->rows || mtx2->cols != prod->cols )
		return -2;
	int row,col,k;
	for(col=1;col<=mtx2->cols;col++){
		for(row=1;row<=mtx1->rows;row++) {
			double val=0.0;
			for(k=1;k<=mtx1->cols;k++)
				val+=ELEM(mtx1,row,k) * ELEM(mtx2,k,col);
			ELEM(prod,row,col)=val;
		}
	}
	return 0;
}

int dotProduct(matrix *mtx1, matrix *mtx2, double *prod){
	if(!mtx1 || !mtx2 || !prod)
		return -1;
	if(mtx1->cols != 1 || mtx2->cols != 1 )
		return -2;
	if(mtx1->rows != mtx2->rows)
		return -3;
	*prod=0;
	int i;
	for(i=1;i<mtx1->rows;i++)
		*prod += ELEM(mtx1,i,1) * ELEM(mtx2,i,1);
	return 0;
}
