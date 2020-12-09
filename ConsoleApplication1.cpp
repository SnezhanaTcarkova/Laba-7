#include <iostream>
using namespace std;


template <class T>
class Matrix
{
private:
    int n;
    int m;
    T** mas;

public:
    Matrix(int n1 = 0,int m1=0)
    {
        m = m1;
        n = n1;
        mas = new T * [n];

        for (int i = 0;i < n; i++)
        {
            mas[i] = new int[m];
        }
    }

    Matrix(const Matrix& obj)
    {
        m = obj.m;
        n = obj.n;
        mas = new T*[n];
        for (int i = 0; i < n; i++)

            mas[i] = new int[m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                mas[i][j] = obj.mas[i][j];
            }
        }
    }
    ~Matrix()
    { //delete[] mas; 
    }

    void Vvod()
    {

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cin >> mas[i][j];

        }
    }

    void Vivod()
    {

        cout << "array is :" << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cout << mas[i][j] << endl;
        }
    }

    T Max(Matrix mas1, Matrix mas2)
    {
        T temp1 = 0;
        T temp2 = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {

                if (mas1.mas[i][j] > temp1)
                    temp1 = mas1.mas[i][j];      
            }
        }


        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {

               

                if (mas2.mas[i][j] > temp2)
                    temp2 = mas2.mas[i][j];
            }

        }

        cout << "Max elem  v 1 mas" << temp1 << endl;
        cout << "Max elem  v 2 mas" << temp2 << endl;
        if (temp1 > temp2)
            cout << "Max elem" << temp1 << endl;
        else
            cout << "Max elem" << temp2 << endl;



        return 0;
    }

    T Av(Matrix mas1, Matrix mas2)
    {
        T av1 = 0, av2 = 0;
        T sum1 = 0, sum2 = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                sum1 += mas1.mas[i][j];
                sum2 += mas2.mas[i][j];
            }
        }
        av1 = sum1 / n;
        av2 = sum2 / n;
        cout << "Average mas1= " << av1 << " Average mas2= " << av2 << endl;
        return 0;
        //   через accumulate??
    }

    T operator+(const Matrix &massiv)

    {
        Matrix masSloz(*this);

        cout << "Slozenie  mas" << endl;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                masSloz.mas[i][j] += massiv.mas[i][j];
            }

        for (int i = 0; i < n; i++)
            for (int j=0;j<m;j++)
            cout << masSloz.mas[i][j] << endl;
        return 0;
        
    }

   T operator < ( Matrix right)
   {
       int k = 0;
       int k1=0;
      
        Matrix left(*this);
        
        cout << "Novii mas" << endl;
        for (int i=0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                if (left.mas[i][j] <= right.mas[i][j])
                {
                    k++;
                   
                }
            }
        k1 = k;

        T* masNew = new T[k1];
        if (k1 > 0)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {


                    for (int l = 0; l < k1; l++)
                    {
                        if (left.mas[i][j] <= right.mas[i][j])
                        {   
                            masNew[l] = left.mas[i][j];
                            // !!!!!!
                            cout << "elem " << l << "= " << masNew[l] << endl;

                        }

                    }

                }

            }
        }
        else
            cout << "No elements" << endl;

        for (int l = 0; l < k1; l++)
           
            {// некоректный вывод
            cout << "elem " << l << "= " << masNew[l] << endl;
            }
        return 0;
    }
};


int main()
{
    //  setlocale(LC_ALL,"Russian");

    int n = 0;
    int m = 0;
    cout << "vvedite kolvo strok ";
    cin >> n;

    cout << "vvedite kolvo stolbcov";
    cin >> m;


    Matrix<int> sloz1(n, m);
 
    Matrix<int> mas1(n,m);

   
    cout << " Vvedite znach 1 mas" << endl;
    mas1.Vvod();
    mas1.Vivod();



    Matrix<int> mas2 = mas1;
    cout << "Vvedite znach 2 mas" << endl;

    mas2.Vvod();
    mas2.Vivod();

    mas1.Max(mas1, mas2);
    cout << "Checking" << endl;

    mas1.Av(mas1, mas2);
    cout << "Checking2" << endl;

   sloz1 = mas2 + mas1;
   Matrix<int> raz1 = mas1<mas2;

    return 0;
   
}

