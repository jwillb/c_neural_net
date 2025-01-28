#define VECTOR float*
#define MATRIX float**
#define VMTX(v) &v
#define MVEC(m) *m

#undef RAND_MAX
#define RAND_MAX 100

VECTOR newVec(int n);
VECTOR setVec(int n, float array[n]);
VECTOR add(VECTOR v1, VECTOR v2, int n);
VECTOR subtract(VECTOR v1, VECTOR v2, int n);
float dot(VECTOR v1, VECTOR v2, int n);
void printVec(VECTOR v, int n);
//VECTOR randVec(int n);

MATRIX newMtx(int r, int c);
MATRIX randMtx(int r, int c);
MATRIX setMtx(int r, int c, float array[r][c]);
void printMtx(MATRIX m, int r, int c);
void freeMtx(MATRIX m, int r);
VECTOR col(MATRIX m, int r, int c, int col_index);
void vAdd(MATRIX m, int r, int c, VECTOR v, int n);
MATRIX transpose(MATRIX m, int r, int c);
MATRIX multiply(MATRIX m1, int r1, int c1, MATRIX m2, int r2, int c2);

