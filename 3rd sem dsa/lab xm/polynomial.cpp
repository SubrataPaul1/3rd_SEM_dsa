#include <bits/stdc++.h>
using namespace std;
struct Qnode
{
    int coeficent;
    int power;
    Qnode *nxt;
    Qnode(int coeff, int pow)
    {
        coeficent = coeff;
        power = pow;
        nxt = NULL;
    }
};
struct polynomial
{
    Qnode *equation1, *equation2;
    polynomial()
    {
        equation1 = NULL;
        equation2 = NULL;
    }
    void add1(int coeff, int pow)
    {
        Qnode *temp = new Qnode(coeff, pow);
        if (equation1 == NULL)
        {
            equation1 = temp;
        }
        else
        {
            equation1->nxt = temp;
            temp->nxt = NULL;
        }
        cout << temp->coeficent << "x" << temp->power;
    }
};
int main()
{
    polynomial eq1;
    eq1.add1(7, 2);
  
}
