#include <cstdlib>
#include "Container.cpp"

class ContainerOp
{
    Container first;
    Container second;
    int op;
public:
    void setFirst(Container f)
    {
        first=f;
    }
    void setSecond(Container s)
    {
        second=s;
    }
    Container getFirst()
    {
        return first;
    }
    Container getSecond()
    {
        return second;
    }
    void setOp(int o)
    {
        op=o;
    }
    int getOp()
    {
        return op;
    }

    Container performOp()
    {
        if(op==0) {
            if (first.getStoredType() == 1) {
                Container res;
                int *valueArray;
                int l;
                int val;
                int **valueMat;
                int m;
                switch (second.getStoredType()) {
                    case 1:
                        res.setItem(*(int *) first.getItem() + *(int *) second.getItem());
                        return res;
                    case 2:
                        valueArray = (int *) second.getItem();
                        l = second.getFirstDim();
                        val = *(int *) first.getItem();
                        for (int i = 0; i < l; i++) {
                            valueArray[i] += val;
                        }
                        res.setItem(valueArray, l);
                        return res;
                    default:
                        valueMat = (int **) second.getItem();
                        l = second.getFirstDim();
                        m = second.getSecondDim();
                        val = *(int *) first.getItem();
                        for (int i = 0; i < l; i++) {
                            for (int j = 0; j < m; j++) {
                                valueMat[i][j] += val;
                            }
                        }
                        res.setItem(valueMat, l, m);
                        return res;
                }
            } else if (first.getStoredType() == 2) {
                Container res;
                int *valueArray;
                int l;
                int val;
                switch (second.getStoredType()) {
                    case 1:
                        valueArray = (int *) first.getItem();
                        l = second.getFirstDim();
                        val = (int) second.getItem();
                        for (int i = 0; i < l; i++) {
                            valueArray[i] += val;
                        }
                        res.setItem(valueArray, l);
                        return res;
                    default:
                        return first;
                }
            } else {
                Container res;
                int **valueMat;
                int l;
                int m;
                int val;
                switch (second.getStoredType()) {
                    case 1:
                        valueMat = (int **) first.getItem();
                        l = second.getFirstDim();
                        m = second.getSecondDim();
                        val = *(int *) second.getItem();
                        for (int i = 0; i < l; i++) {
                            for (int j = 0; j < m; j++) {
                                valueMat[i][j] += val;
                            }
                        }
                        res.setItem(valueMat, l, m);
                        return res;
                    default:
                        return first;
                }
            }
        }else{
            if (first.getStoredType() == 1) {
                Container res;
                int *valueArray;
                int l;
                int val;
                int **valueMat;
                int m;
                switch (second.getStoredType()) {
                    case 1:
                        res.setItem(*(int *) second.getItem() - *(int *) first.getItem());
                        return res;
                    case 2:
                        valueArray = (int *) second.getItem();
                        l = second.getFirstDim();
                        val = *(int *) first.getItem();
                        for (int i = 0; i < l; i++) {
                            valueArray[i] -= val;
                        }
                        res.setItem(valueArray, l);
                        return res;
                    default:
                        valueMat = (int **) second.getItem();
                        l = second.getFirstDim();
                        m = second.getSecondDim();
                        val = *(int *) first.getItem();
                        for (int i = 0; i < l; i++) {
                            for (int j = 0; j < m; j++) {
                                valueMat[i][j] -= val;
                            }
                        }
                        res.setItem(valueMat, l, m);
                        return res;
                }
            } else if (first.getStoredType() == 2) {
                Container res;
                int *valueArray;
                int l;
                int val;
                switch (second.getStoredType()) {
                    case 1:
                        valueArray = (int *) first.getItem();
                        l = first.getFirstDim();
                        val = *(int *) second.getItem();
                        for (int i = 0; i < l; i++) {
                            valueArray[i] -= val;
                        }
                        res.setItem(valueArray, l);
                        return res;
                    default:
                        return first;
                }
            } else {
                Container res;
                int **valueMat;
                int l;
                int m;
                int val;
                switch (second.getStoredType()) {
                    case 1:
                        valueMat = (int **) first.getItem();
                        l = first.getFirstDim();
                        m = first.getSecondDim();
                        val = *(int *) second.getItem();
                        for (int i = 0; i < l; i++) {
                            for (int j = 0; j < m; j++) {
                                valueMat[i][j] -= val;
                            }
                        }
                        res.setItem(valueMat, l, m);
                        return res;
                    default:
                        return first;
                }
            }
        }
    }
};

int main()
{
            Container a(100);
//            a.print();

            int *arr = new int[3];
            arr[0] = 10;
            arr[1] = 20;
            arr[2] = 30;

            Container b(arr, 3);
//            b.print();

            int **mat = new int*[2];
            mat[0] = new int[3];
            mat[0][0] = 1;
            mat[0][1] = 2;
            mat[0][2] = 3;
            mat[1] = new int[3];
            mat[1][0] = 4;
            mat[1][1] = 5;
            mat[1][2] = 6;
            Container c(mat, 2, 3);
//            c.print();

            cout<<"operation + for int and array:"<<endl;
            ContainerOp z;
            z.setFirst(a);
            z.setSecond(b);
            z.setOp(0);
            Container r=z.performOp();
            r.print();

            cout<<"operation - for int and array:"<<endl;
            z.setFirst(a);
            z.setSecond(b);
            z.setOp(1);
            r=z.performOp();
            r.print();

            cout<<"operation + for int and array:"<<endl;
            Container d(10);
            z.setFirst(d);
            z.setSecond(c);
            z.setOp(0);
            r=z.performOp();
            r.print();
}



