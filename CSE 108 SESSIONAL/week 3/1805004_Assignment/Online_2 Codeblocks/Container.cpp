# include <iostream>
using namespace std;

# define INTEGER 1
# define INT_ARRAY 2
# define INT_MATRIX 3

class Container
{
    int *value;
    int *valueArray;
    int **valueMatrix;
    int firstDim, secondDim;
    int storedType;

    void reset()
    {
        if (value != NULL)
        {
            delete value;
        }
        if (valueArray != NULL)
        {
            delete [] valueArray;
        }
        if (valueMatrix != NULL)
        {
            for(int i=0; i<firstDim; i++)
            {
                delete []valueMatrix[i];
            }
            delete []valueMatrix;
        }
        firstDim = 0;
        secondDim = 0;
        storedType = -1;
    }

public:
    Container()
    {
        cout << "Constructing Container with empty parameter" << endl;
        cout << "___________________________________________" << endl;
        value = NULL;
        valueArray = NULL;
        valueMatrix = NULL;
        firstDim = 0;
        secondDim = 0;
        storedType = -1;
    }

    Container (int val)
    {
        cout << "Constructing Container with a single integer parameter" << endl;
        cout << "______________________________________________________" << endl;
        value=new int(val);
        valueArray = NULL;
        valueMatrix = NULL;
        firstDim = 0;
        secondDim = 0;
        storedType = INTEGER;
    }

    Container (int *valArr, int len)
    {
        cout << "Constructing Container with integer array parameter" << endl;
        cout << "___________________________________________________" << endl;
        value=NULL;
        valueMatrix = NULL;
        valueArray=new int[len];
        for(int i=0; i<len; i++)
        {
            valueArray[i]=valArr[i];
        }
        firstDim = len;
        secondDim = 0;
        storedType = INT_ARRAY;
    }

    Container (int **valMat, int r, int c)
    {
        cout << "Constructing Container with integer matrix parameter" << endl;
        cout << "____________________________________________________" << endl;
        value=NULL;
        valueArray=NULL;
        valueMatrix=new int*[r];
        for(int i=0; i<r; i++)
        {
            valueMatrix[i]=new int[c];
        }
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                valueMatrix[i][j]=valMat[i][j];
            }
        }
        firstDim=r;
        secondDim=c;
        storedType=INT_MATRIX;
    }

    Container(const Container &ob)
    {
        cout << "Calling copy constructor of Container" << endl;
        cout << "_____________________________________" << endl;
        value=NULL;
        valueArray=NULL;
        valueMatrix=NULL;
        if(ob.storedType==INTEGER)
        {
            firstDim=0;
            secondDim=0;
            storedType=INTEGER;
            value=new int(*ob.value);
        }
        if(ob.storedType==INT_ARRAY)
        {
            firstDim=ob.firstDim;
            secondDim=0;
            storedType=INT_ARRAY;
            valueArray=new int[ob.firstDim];
            for(int i=0; i<ob.firstDim; i++)
            {
                valueArray[i]=ob.valueArray[i];
            }
        }
        if(ob.storedType==INT_MATRIX)
        {
            firstDim=ob.firstDim;
            secondDim=ob.secondDim;
            storedType=INT_MATRIX;
            valueMatrix=new int*[ob.firstDim];
            for(int i=0; i<ob.firstDim; i++)
            {
                valueMatrix[i]=new int[ob.secondDim];
            }
            for(int i=0; i<ob.firstDim; i++)
            {
                for(int j=0; j<ob.secondDim; j++)
                {
                    valueMatrix[i][j]=ob.valueMatrix[i][j];
                }
            }
        }
    }


    void setItem (int val)
    {
        reset();
        value=new int;
        *value=val;
        firstDim = 0;
        secondDim = 0;
        storedType = INTEGER;
    }

    void setItem(int *valArr, int len)
    {
        reset();
        valueArray=new int[len];
        for(int i=0; i<len; i++)
        {
            valueArray[i]=valArr[i];
        }
        firstDim = len;
        secondDim = 0;
        storedType = INT_ARRAY;
    }
    void setItem(int **valMat, int r, int c)
    {
        reset();
        valueMatrix=new int*[r];
        for(int i=0; i<r; i++)
        {
            valueMatrix[i]=new int[c];
        }
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                valueMatrix[i][j]=valMat[i][j];
            }
        }
        firstDim=r;
        secondDim=c;
        storedType=INT_MATRIX;
    }

    void * getItem()
    {
        if (value != NULL)
            return value;
        if (valueArray != NULL)
            return valueArray;
        if (valueMatrix != NULL)
            return valueMatrix;
        return NULL;
    }

    int getFirstDim()
    {
        return firstDim;
    }

    int getSecondDim()
    {
        return secondDim;
    }

    int getStoredType()
    {
        return storedType;
    }

    void print()
    {
        if (value != NULL)
        {
            cout << "There is only an integer value in the container object" << endl;
            cout << "The value is: " << *value << endl;
        }
        else if (valueArray != NULL)
        {
            cout << "There is an integer array in the container object" << endl;
            cout << "The values stored in the array are:" << endl;
            for (int i=0; i<firstDim; i++)
            {
                cout << valueArray[i] << " ";
            }
            cout << endl;
        }
        else if (valueMatrix != NULL)
        {
            cout << "There is an integer matrix in the container object" << endl;
            cout << "The values stored in the matrix are:" << endl;
            for (int i=0; i<firstDim; i++)
            {
                for (int j=0; j<secondDim; j++)
                {
                    cout << valueMatrix[i][j] << " ";
                }
                cout << endl;
            }
        }
        else
        {
            cout << "The object has no elements" << endl;
        }
    }

    ~Container()
    {
        if (value != NULL)
        {
            cout << "Freeing allocated memory for a single integer" << endl;
            delete value;// free memory occupied by value
        }
        if (valueArray != NULL)
        {
            cout << "Freeing allocated memory for integer array" << endl;
            delete []valueArray;// free memory occupied by valueArray
        }
        if (valueMatrix != NULL)
        {
            cout << "Freeing allocated memory for integer matrix" << endl;
            for(int i=0; i<firstDim; i++) // free memory occupied by valueMatrix
            {
                delete []valueMatrix[i];
            }
            delete []valueMatrix;
        }
        firstDim = 0;
        secondDim = 0;
        storedType = -1;
        cout << "_____________________" << endl;
        cout << "Destructing Container" << endl;
    }
};
