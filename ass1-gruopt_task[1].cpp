#include <iostream>

using namespace std;

struct matrix{
    int** data;       // Pointer to 2-D array that will simulate matrix
    int row, col;};

void createMatrix(int row,int col,int num[],matrix& mat);
void showMatrix(matrix& mat);
//------part1
int num();
matrix operator+(matrix mat1,matrix mat2);
matrix operator-(matrix mat1,matrix mat2);
matrix operator*(matrix mat1,matrix mat2);
matrix operator+ (matrix mat1, int scalar);
matrix operator- (matrix mat1, int scalar);
matrix operator* (matrix mat1, int scalar);
//-------part2
matrix operator+= (matrix& mat1, matrix mat2);
matrix operator-= (matrix& mat1, matrix mat2);
matrix operator+= (matrix& mat, int scalar);
matrix operator-= (matrix& mat, int scalar);
void   operator++ (matrix& mat);
void   operator-- (matrix& mat);
istream& operator>> (istream& in, matrix& mat);
//-------part3
ostream& operator<< (ostream& out, matrix mat);
bool   operator== (matrix mat1, matrix mat2);
bool   operator!= (matrix mat1, matrix mat2);
bool   isSquare   (matrix mat);
bool   isSymetric (matrix mat);
bool   isIdentity (matrix mat);
matrix transpose(matrix mat);

int main(){
   int x;
   cout<<"Choose Number:\n1-mat3=mat1+mat2\n2-mat3=mat1-mat2\n3-mat3=mat1*mat2\n4-mat3=mat1+num\n5-mat3=mat1-num\n6-mat3=mat1*num\n7-mat1=mat1+mat2\n8-mat1=mat1-mat2\n9-mat1=mat1+num\n10-mat1=mat1-num\n11-mat1++\n12-mat1--\n";
   cin>>x;
  int data1[]={1,2,3,4,5,6,7,8};
  int data2[]={10,100,10,100,10,100,10,100};
  int data3[]={13,233,3,4,5,6};
  matrix mat1,mat2,mat3,mat4;
  createMatrix(4,2,data1,mat1);
  createMatrix(4,2,data2,mat2);
  createMatrix(2,3,data3,mat3);
switch(x){
//-------part1
case(1):
  mat4=mat1+mat2;
  break;
case(2):
  mat4=mat2-mat1;
  break;
case(3):
  mat4=mat2*mat3;
  break;
case(4):
  operator+(mat1,num());
  break;
case(5):
  operator-(mat2,num());
  break;
case(6):
  operator*(mat3,num());
  break;
//-------part2
case(7):
  operator+=(mat1,mat2);
  break;
case(8):
  operator-=(mat2,mat1);
  break;
case(9):
  operator+=(mat3,num());
  break;
case(10):
  operator-=(mat3,num());
  break;
case(11):
  operator++(mat1);
  break;
case(12):
  operator--(mat1);
  break;
//case(1):
  //operator>>(in,mat1)
  //break;
//-------part3

}
    return 0;}

void createMatrix (int row,int col,int num[],matrix& mat){
  mat.row=row;
  mat.col=col;
  mat.data=new int*[row]; //?????
  for(int i=0;i<row;i++)
    mat.data[i]=new int[col];
  for(int i=0;i<row;i++)
    for(int j=0;j<col;j++)
      mat.data[i][j]=num[i*col+j];}

void showMatrix(matrix& mat){
     cout<<"Matrices= "<<endl;
     for(int i=0;i<mat.row;i++){
        for(int j=0;j<mat.col;j++){
            cout<<mat.data[i][j]<<" ";}
            cout<<endl;}
        cout<<endl;}


/*****************************__________part1______________________********************************/


int num(){
    int num;
    cout<<"Enter the Number you want calculate:"<<endl;
    cin>>num;
    return num;}
//----------------------------------------------------------------------------------------------
matrix operator+(matrix mat1,matrix mat2){
    showMatrix(mat1);
    showMatrix(mat2);
    matrix mat3;
    int data[mat1.row*mat1.col];
    createMatrix(mat1.row,mat1.col,data,mat3);
    if(mat1.row== mat2.row && mat1.col==mat2.col){
        for(int i=0;i<mat1.row;i++){
                for(int j=0;j<mat1.col;j++){
                    mat3.data[i][j]=mat1.data[i][j]+mat2.data[i][j];}}
        cout<<"Add of ";

    showMatrix(mat3);
    }
    else{cout<<"Matrices have different dimensions"<<endl;}

return mat3;
}

matrix operator-(matrix mat1,matrix mat2){
    showMatrix(mat1);
    showMatrix(mat2);
    matrix mat3;
    int data[mat1.row*mat1.col];
    createMatrix(mat1.row,mat1.col,data,mat3);
    if(mat1.row== mat2.row && mat1.col==mat2.col){
        for(int i=0;i<mat1.row;i++){
                for(int j=0;j<mat1.col;j++){
                    mat3.data[i][j]=mat1.data[i][j]-mat2.data[i][j];}}
        cout<<"Sub of ";
        showMatrix(mat3);
    }
    else{cout<<"Matrices have different dimensions"<<endl;}

return mat3;
}

matrix operator*(matrix mat1,matrix mat2){
    showMatrix(mat1);
    showMatrix(mat2);
    matrix mat3;
    int data[mat1.row*mat2.col];
    createMatrix(mat1.row,mat2.col,data,mat3);
    if(mat1.col==mat2.row){
        for(int i=0;i<mat2.col;i++){
            for(int j=0;j<mat1.row;j++){
                mat3.data[j][i]=0;
                for(int r=0;r<mat1.col;r++){
                    mat3.data[j][i]=(mat1.data[i][r]*mat2.data[r][i])+ mat3.data[j][i];
        }}}
        cout<<"Multi of ";
        showMatrix(mat3);
   }
    else{cout<<"matrix1 columns not equal matrix2 rows"<<endl;}

return mat3;
}
//-------------------------------------------------------------------------------------------

matrix operator+(matrix mat1,int scalar){
    showMatrix(mat1);
    matrix mat2;
        int data[mat1.row*mat1.col];
        createMatrix(mat1.row,mat1.col,data,mat2);
        for(int i=0;i<mat1.row;i++){
                for(int j=0;j<mat1.col;j++){
                    mat2.data[i][j]=mat1.data[i][j]+scalar;}}
        cout<<"Add of ";
        showMatrix(mat2);
return mat2;
}

matrix operator-(matrix mat1,int scalar){
      showMatrix(mat1);
      matrix mat2;
      int data[mat1.row*mat1.col];
      createMatrix(mat1.row,mat1.col,data,mat2);
      for(int i=0;i<mat1.row;i++){
          for(int j=0;j<mat1.col;j++){
              mat2.data[i][j]=mat1.data[i][j]-scalar;}}
        cout<<"New ";
        showMatrix(mat2);

return mat2;
}

matrix operator*(matrix mat1,int scalar){
      showMatrix(mat1);
      matrix mat2;
      int data[mat1.row*mat1.col];
      createMatrix(mat1.row,mat1.col,data,mat2);
      for(int i=0;i<mat1.row;i++){
          for(int j=0;j<mat1.col;j++){
              mat2.data[i][j]=mat1.data[i][j]*scalar;}}
        cout<<"Multi of ";
        showMatrix(mat2);

return mat2;
}

/*****************************__________part2______________________********************************/


matrix operator+= (matrix& mat1, matrix mat2)
{
    showMatrix(mat1);
    showMatrix(mat2);
    for(int i=0; i<mat1.row; i++)
    {
        for(int j=0; j<mat1.col; j++)
        {
            mat1.data[i][j]=mat1.data[i][j]+mat2.data[i][j];
        }
    }
    cout<<"New ";
    showMatrix(mat1);
    return mat1;
}

matrix operator-= (matrix& mat1, matrix mat2)
{
    showMatrix(mat1);
    showMatrix(mat2);
    for(int i=0; i<mat1.row; i++)
    {
        for(int j=0; j<mat1.col; j++)
        {
            mat1.data[i][j]=mat1.data[i][j]-mat2.data[i][j];
        }
    }
    cout<<"New ";
    showMatrix(mat1);
    return mat1;
}

matrix operator+= (matrix& mat, int scalar)
{
    showMatrix(mat);
    for(int i=0; i<mat.row; i++)
    {
        for(int j=0; j<mat.col; j++)
        {
            mat.data[i][j]=mat.data[i][j]+scalar;
        }
    }
    cout<<"New ";
    showMatrix(mat);
    return mat;
}

matrix operator-= (matrix& mat, int scalar)
{
    showMatrix(mat);
    for(int i=0; i<mat.row; i++)
    {
        for(int j=0; j<mat.col; j++)
        {
            mat.data[i][j]=mat.data[i][j]-scalar;
        }
    }
    cout<<"New ";
    showMatrix(mat);
    return mat;
}

void   operator++ (matrix& mat)
{
    showMatrix(mat);
    for(int i=0; i<mat.row; i++)
    {
        for(int j=0; j<mat.col; j++)
        {
            mat.data[i][j]=mat.data[i][j]+1;
        }
    }
    cout<<"New ";
    showMatrix(mat);
}

void   operator-- (matrix& mat)
{
    showMatrix(mat);
    for(int i=0; i<mat.row; i++)
    {
        for(int j=0; j<mat.col; j++)
        {
            mat.data[i][j]=mat.data[i][j]-1;
        }
    }
    cout<<"New ";
    showMatrix(mat);
}

istream& operator>> (istream& in, matrix& mat)
{
    in>>mat.row>>mat.col;
    for(int i=0; i<mat.row; i++)
    {
        for(int j=0; j<mat.col; j++)
        {
            in>>mat.data[i][j];
        }
    }
    cout<<"New ";
    showMatrix(mat);
    return in;
}

/*****************************__________part3______________________********************************/

bool   operator== (matrix mat1, matrix mat2)
{
    int n=0;
    if (mat1.col == mat2.col && mat1.row == mat2.row)
    {
        for(int i=0; i<mat1.row; i++)
        {
            for(int j=0; j<mat1.col; j++)
            {
                if (mat1.data[i][j]== mat2.data[i][j])
                    n++;
            }
        }
    }
    else
    {
        return 0;
    }
    if (n== mat1.row*mat1.col)
        return 1;
    else
        return 0;
}

bool   operator!= (matrix mat1, matrix mat2)
{
    int n=0;
    for(int i=0; i<mat1.row; i++)
    {
        for(int j=0; j<mat1.col; j++)
        {
            if (mat1.data[i][j]= mat2.data[i][j])
                n++;
        }
    }
    if (n==(mat1.row*mat1.col )&& (mat2.row *mat2.col))
        return 0;
    else
        return 1;
}

bool   isSquare   (matrix mat)
{
    if (mat.row == mat.col)
        return 1;
    else
        return 0;
}

bool   isSymetric (matrix mat)
{
    if(mat == transpose(mat))
        return 1;
    else
        return 0 ;
}

ostream& operator<< (ostream& out, matrix mat)
{
    for(int i=0; i<mat.row; i++)
    {
        for(int j=0; j<mat.col; j++)
        {

            out<<mat.data[i][j]<<" ";
        }
        out<<endl;
    }
    return out;
}
matrix transpose(matrix mat)
{
    matrix neww;
    neww.row=mat.col;
    neww.col=mat.row;
    neww.data = new int* [neww.row];

    for (int i = 0; i < neww.row; i++)
        neww.data[i] = new int [neww.col];

    for(int i=0; i<neww.row; i++)
    {
        for(int j=0; j<neww.col; j++)
        {
            neww.data[i][j]=mat.data[j][i];
        }
    }
    return neww;
}

bool   isIdentity (matrix mat)
{
    int c=0;
    if(isSquare(mat) )
    {
        for(int i=0; i<mat.row; i++)
        {
            for(int j=0 ; j<mat.col; j++)
            {
                if( i==j && mat.data[i][j]==1)
                    c++;
                if (mat.data[i][j]==0 && i!=j)
                    c++;
            }
        }
    }

    if(c==mat.row*mat.col)
        return 1;
    else
        return 0;
}


