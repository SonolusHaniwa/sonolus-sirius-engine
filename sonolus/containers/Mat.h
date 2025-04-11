#ifndef Mat_H
#define Mat_H

class Matrix {
    public:

    Array<Array<Variable, 4>, 4> m;

    Constructor Matrix(){}
    Constructor Matrix(double a) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                m[i][j] = a;
            }
        }
    }
    Constructor Matrix(FuncNode a) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                m[i][j] = a;
            }
        }
    }
    Constructor Matrix(vector<vector<FuncNode> > a) {
        for (int i = 0; i < min(4, int(a.size())); i++) {
            for (int j = 0; j < min(4, int(a[i].size())); j++) {
                m[i][j] = a[i][j];
            }
        }
    }
    
    Blocked Matrix mul(const Matrix &mat) {
        Matrix res;
        FuncNode m1[4][4], m2[4][4], m3[4][4];
        for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) m1[i][j] = m[i][j];
        for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) m2[i][j] = mat.m[i][j];
        for (int i = 0; i < 4; i++) for (int k = 0; k < 4; k++)
            for (int j = 0; j < 4; j++) m3[i][j] = m3[i][j] + m1[i][k] * m2[k][j];
        for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) res.m[i][j] = m3[i][j]; 
        return res;
    }
    
    static Blocked Matrix identity() {
        return Matrix({
            { 1, 0, 0, 0 },
            { 0, 1, 0, 0 },
            { 0, 0, 1, 0 },
            { 0, 0, 0, 1 }
        });
    }
    static Blocked Matrix translation(FuncNode x, FuncNode y) {
        return Matrix({
            { 1, 0, 0, x },
            { 0, 1, 0, y },
            { 0, 0, 1, 0 },
            { 0, 0, 0, 1 }
        });
    }
    static Blocked Matrix scaling(FuncNode x, FuncNode y) {
        return Matrix({
            { x, 0, 0, 0 },
            { 0, y, 0, 0 },
            { 0, 0, 1, 0 },
            { 0, 0, 0, 1 }
        });
    }
    static Blocked Matrix rotation(FuncNode angle) {
        FuncNode c = FuncNode("Cos", { angle });
        FuncNode s = FuncNode("Sin", { angle });
        return Matrix({
            { c, -s, 0, 0 },
            { s, c, 0, 0 },
            { 0, 0, 1, 0 },
            { 0, 0, 0, 1 }
        });
    }
    Blocked Matrix translate(FuncNode x, FuncNode y) {
        return Matrix::translation(x, y).mul(*this);
    }
    Blocked Matrix scale(FuncNode x, FuncNode y) {
        return Matrix::scaling(x, y).mul(*this);
    }
    Blocked Matrix rotate(FuncNode angle) {
        return Matrix::rotation(angle).mul(*this);
    }

    Matrix operator * (const Matrix &a) {
        return mul(a);
    }
    FuncNode operator == (const Matrix &a) {
        FuncNode m1[4][4], m2[4][4];
        for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) m1[i][j] = m[i][j];
        for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) m2[i][j] = a.m[i][j];
        FuncNode res = true;
        for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) res = FuncNode("And", { res, m1[i][j] == m2[i][j] });
        return res;
    }
};

using Mat = Matrix;

#endif