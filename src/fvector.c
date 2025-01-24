#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "fvector.h"

VECTOR newVec(int n) {
    VECTOR v = calloc(n, sizeof(float));
    assert(v);

    return v;
}

VECTOR setVec(int n, float array[n]) {
    VECTOR v = newVec(n);

    for (int i = 0; i < n; i++) {
        v[i] = array[i];
    }

    return v;
}

VECTOR add(VECTOR v1, VECTOR v2, int n) {
    VECTOR v = newVec(n);

    for (int i = 0; i < n; i++) {
        v[i] = v1[i] + v2[i];
    }

    return v;
}

VECTOR subtract(VECTOR v1, VECTOR v2, int n) {
    VECTOR v = newVec(n);

    for (int i = 0; i < n; i++) {
        v[i] = v1[i] - v2[i];
    }

    return v;
}

float dot(VECTOR v1, VECTOR v2, int n) {
    float ans = 0;

    for (int i = 0; i < n; i++) {
        ans += (v1[i] * v2[i]);
    }

    return ans;
}

void printVec(VECTOR v, int n) {
    printf("< ");
    for (int i = 0; i < n; i++) {
        printf("%6.3f ", v[i]);
    }
    printf(">\n");
}

MATRIX newMtx(int r, int c) {
    MATRIX m = malloc(r * sizeof(float*));
    assert(m);

    for (int i = 0; i < r; i++) {
        m[i] = calloc(c, (sizeof(float)));
        assert(m[i]);
    }
    return m;
}

MATRIX setMtx(int r, int c, float array[r][c]) {
    MATRIX m = newMtx(r, c);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            m[i][j] = array[i][j];
        }
    }
    return m;
}

void printMtx(MATRIX m, int r, int c) {
    for (int i = 0; i < r; i++) {
        printf("[ ");
        for (int j = 0; j < c; j++) {
            printf("%6.3f ", m[i][j]);
        }
        printf("]");
        printf("\n");
    }
}

void freeMtx(MATRIX m, int r) {
    for (int i = 0; i < r; i++) {
        free(m[i]);
    }
    free(m);
}

VECTOR col(MATRIX m, int r, int c, int col_index) {
    assert(col_index < c);

    VECTOR v;
    v = malloc(r * sizeof(float));

    for (int i = 0; i < r; i++) {
        v[i] = m[i][col_index];
    }
    return v;
}

void vAdd(MATRIX m, int r, int c, VECTOR v, int n) {
    assert(r == n);
    
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            m[i][j] = m[i][j] + v[j];
        }
    }
}

MATRIX transpose(MATRIX m, int r, int c) {
    MATRIX mt = newMtx(c, r);

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            mt[j][i] = m[i][j];
        }
    }
    return mt;
}

MATRIX multiply(MATRIX m1, int r1, int c1, MATRIX m2, int r2, int c2) {
    MATRIX m;

    if (r2 == 1 || c2 == 1) {
        m = newMtx(1, r1);
        VECTOR v = (r2 == 1 ? *m2 : MVEC(transpose(m2, r2, c2)));

        for (int i = 0; i < r1; i++) {
            m[0][i] = dot(v, m1[i], c2);
        }

        if (c2 == 1) free(v);
    }
    else {
        assert(r2 == c1);
        m = newMtx(r1, c2);

        for (int i = 0; i < r1; i++) {
            for (int j = 0; j < c2; j++) {
                VECTOR jth_col = col(m2, r2, c2, j);
                m[i][j] = dot(m1[i], jth_col, r2);
                free(jth_col);
            }
        }
    }
    return m;
}
