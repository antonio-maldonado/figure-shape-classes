/** 
* Archivo: PruebaFiguras.cpp
* Codigo base de la jerarquia de herencia de Figuras
* para mostrar el uso del polimorfismo
* Author: MCC Enrique Ayala Franco
*/
//Antonio Maldonado
#include <iostream>
#include <string>
#include <ctime> // prototipo para time()
#include <cstdlib> // para rand y srand
#include<vector>
using namespace std;

class Figura{ // si al menos una funcion es virtual pura, la clase es Abstract
	
	friend Figura * figuraalAzar(); // declaraci?n de amistad
	
protected:
	double area;
	
public:
	Figura() {  area=0; }
	virtual ~Figura(){
		cout<<"Destructor Figura"<<endl;
	}
	double getArea()
	{ 
		return area; 
	}
	
	/*virtual void escribeArea()
	{ 
		string mensaje = "soy Figura "; 
		cout << mensaje << " con area: "<<getArea()<<endl;
	} */
	virtual void escribeArea(){
	
	}
	virtual void dibuja(){
		
	}
}; // fin de Figura


class Circulo : public Figura{
	
private:
	double radio;
	
public:
	Circulo (double r) {
		radio= r;
	}
	~Circulo(){
		cout<<"Destructor Circulo"<<endl;
	}
	double getArea() {
		area = 3.14 * (radio * radio );
		return (area);
	}
	
	void escribeArea() {
		string mensaje= "Area del Circulo de radio = ";
		cout << mensaje << radio << " es: " << getArea()<<endl<< endl;
	}
}; // fin de Circulo


class Rectangulo : public Figura{
	
private:
	double alto;
	double ancho;
	
public:
	Rectangulo(double alto, double ancho) {
		this->alto = alto;
		this->ancho = ancho;
	}
	~Rectangulo(){
		cout<<"Destructor Rectangulo"<<endl;
	}
	double getArea() {
		this->area = alto * ancho;
		return (this->area);
	}  
	
	void escribeArea() {
		string mensaje= "Area del Rectangulo de alto=";
		cout << mensaje << alto << "  y de ancho= " <<ancho
			<< " es: "<< getArea() <<endl<< endl;
	}
}; // fin de Rectangulo

class Triangulo : public Figura{
	
private:
	double base;
	double altura;
	
public: 
	Triangulo(double base, double altura) {
		this->base = base;
		this->altura = altura;
	}
	~Triangulo(){
		cout<<"Destructor triangulo"<<endl;
	}
	double getArea() {
		area = (base * altura)/2.0;
		return (area);
	}
	
	void escribeArea() {
		string mensaje("Area del Triangulo de base=");
		cout << mensaje << base << "  y de altura= " <<altura
			<< " es: "<< getArea() << endl << endl;
	}
}; // fin de Triangulo

/*********************************************/
static int numero(){ //genera un numero al azar entre 5 y 50
	return ( 5 + rand() % 45 );
}

class Pentagono : public Figura{
private:
	double perimetro;
	double apotema;
	
public:
	Pentagono(double perimetro,double apotema){
		this-> perimetro=perimetro;
		this-> apotema=apotema;
	}
	~Pentagono(){
		cout<<"Destructor Pentagono"<<endl;
	}
	double getArea() {
		area = (apotema * perimetro)/2.0;
		return (area);
	}
	void escribeArea() {
		string mensaje("Area del Pentagono de perimetro=");
		cout << mensaje << perimetro << "  y de apotema= " <<apotema
			<< " es: "<< getArea() << endl << endl;
	}
};
// Crea una figura al azar y devuelve su referencia
// mediante una variable de superclase
// figuraalazar() es amiga (friend) de Figura
Figura *figuraalAzar() {
	int mirand=(rand() % 4); // de 0 a 2
	switch (mirand) {
	case 0 : return new Circulo(numero() );
	case 1 : return new Rectangulo(numero(),numero());
	case 2 : return new Triangulo(numero(), numero() );
	case 3: return new Pentagono(numero(),numero());
	default : return NULL;
	}
}
/*******************************************/

int main( ) {
	srand((unsigned) time(0) ); 
	const int LENGTH=9;
	//Figura *f[LENGTH]; // arreglo de apuntadores a Objetos Figura
	// llena el arreglo con figuras
	vector <Figura*>*fig=new vector<Figura*>(LENGTH);
//	for ( int i=0; i < LENGTH; i++ )
	//	f[i] = figuraalAzar();  //crea diferentes objetos y devuelve una referencia
	
	// Hace llamadas a los metodos polim?rficos
	//for ( int i=0; i < LENGTH; i++ )
	//{
		//f[i]->escribeArea();  // enlace din?mico, se llama el m?todo adecuado
//	}
	for(int i=0;i<LENGTH;i++){
		fig->at(i)=figuraalAzar();
	}
	for ( int i=0; i < LENGTH; i++ ){
		fig->at(i)->escribeArea();
	}
    //for(int i=0;i<LENGTH;i++){
		//delete f[i];
	//}
	for(int i=0;i<LENGTH;i++){
		delete fig->at(i);
		}
	
	cout <<"Fin del programa..."<<endl;
	system("pause");
	return 0;
} // fin de main
