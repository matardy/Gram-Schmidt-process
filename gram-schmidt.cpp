#include<vector>
#include<cstdlib>
#include<cmath>
#include<iostream> 
#include<time.h>
using namespace std ; 
vector <double> restar(vector <double> a, vector <double> b){
    vector <double> res ; 
    int i=0, j=0;
    while(i<=a.size()-1 && j<=b.size()-1){
        res.push_back(a[i] - b[j]) ; 
        i++; 
        j++ ; 
    }
    
    return res ; 
}
vector <double> dot(vector <double> a, double b){
    vector <double> res ; 
    int i=0 ; 
    while(i<=a.size()-1){
        res.push_back(b*a[i]) ; 
        i++; 
         
    }
    
    return res ; 
}
double escalar(vector <double> &a, vector<double> &b){
    double res = 0 ;
    int i=0, j=0 ; 
        while(i<=a.size() && j<=b.size()){
            res += a[i]*b[j] ; 
            i++ ; 
            j++ ; 
        }
    return res ; 
}
vector <double> vec1(int n){
    srand(time(NULL));
     vector <double> res ; 
    for(int i=0; i<n; i++){
            res.push_back(rand()%40) ; 
        }
        return res ; 
 }
vector <double> vec2(int n){
    srand(time(NULL));
    vector <double> res ;
    for(int j=0; j<n; j++){
            res.push_back(rand()%41) ;
            }
            return res ;  
}
void mostrar(vector <double> a){
    for(int i=0; i<a.size(); i++){
            cout<< a[i] << "  " ; 
        }
    return ; 
}
void ortogonalizar(vector<double> v1, vector<double> v2,
  vector <double> &w1, vector<double> &w2){
    w1 = v1 ; 
    double fact ; 
    fact = escalar(v2, w1) / escalar(w1,w1) ; 
    w2 = restar(v2,dot(w1,fact)) ; 
     return ; 
  }



int main()
{
    vector <double> a;
    vector <double> b;
    vector <double> w1;
    vector <double> w2; 
    int n ; 
    cout<< "Ingresar la longitud de los vectores: " <<endl; 
    cin>>n ; 
    a = vec1(n) ; 
    b = vec2(n) ; 
    cout<<"Los vectores aleatorios a ortogonalizar son : " <<endl ; 
    mostrar(a) ;
    cout<<endl; 
    mostrar(b) ; 
    if(escalar(a,b)!=0){
        cout<<endl;
        cout<< "Los vectores aletorios no son ortogonales, se aplica proceso de GS: " <<endl;
        ortogonalizar(a,b,w1,w2) ; 
        cout<< "\n" <<endl; 
        cout<<"Los vectores ortogonales generados son : " <<endl; 
        mostrar(w1) ;
        cout<<endl; 
        mostrar(w2) ; 
        cout<<endl; 
        cout<<endl; 
        cout<<"Y su producto escalar es: " <<endl; 
        cout<< escalar(w1,w2) <<endl;
    }else{
        cout<< "Los vectores aleatorios son ortogonales." <<endl ; 
    }
 
    

    return 0;
}