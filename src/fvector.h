#define VECTOR float*
#define MATRIX float**
#define VMTX(v) &v
#define MVEC(m) *m

VECTOR newVec(int n);
VECTOR setVec(int n, float array[n]);
VECTOR add(VECTOR v1, VECTOR v2, int n);
VECTOR subtract(VECTOR v1, VECTOR v2, int n);
float dot(VECTOR v1, VECTOR v2, int n);
void printVec(VECTOR v, int n);

MATRIX newMtx(int r, int c);
MATRIX setMtx(int r, int c, float array[r][c]);
void printMtx(MATRIX mtx, int r, int c);
void freeMtx(MATRIX mtx, int r);
VECTOR col(MATRIX mtx, int r, int c, int col_index);
void vAdd(MATRIX m, int r, int c, VECTOR v, int n);
MATRIX multiply(MATRIX mtx1, int r1, int c1, MATRIX mtx2, int r2, int c2);
MATRIX transpose(MATRIX mtx, int r, int c);
