#include <iostream>
#include <stdlib.h>
#include <string>
#include <windows.h> 
#include <iomanip>
#include <conio.h>
#include <fstream>

using namespace std;

int x = 0;
int menu, cl, mod;
bool b = false;
string sn;

//Tablas para los articulos
struct videojuegos
{
    int id;
    string nombre;
    int anio;
    string clas;
    string carac;
    string desc;
    string gen;
    float precio;
    float imp;
    float total;
}registro[100];

void color(int a)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), a);
}

void lista(int y, int j)
{
    if (b == false) // validar si hay registros
    {
        color(14);
        cout << "No hay juegos registrados. Presiona una tecla para continuar...";
        return;
    }

    color(11);
    cout << " ID  \xB3 ";
    color(15);
    cout << "Nombre del videojuego     \xB3 ";
    color(11);
    cout << "A\xA4o de lanza. \xB3 ";
    color(15);
    cout << "Clasf \xB3 ";
    color(11);
    cout << left << setw(40) << "Caracteristicas" << setfill(' ') << " \xB3 ";
    color(15);
    cout << left << setw(50) << "Descripcion" << setfill(' ') << " \xB3 ";
    color(11);
    cout << left << setw(30) << "Genero" << setfill(' ') << " \xB3 ";
    color(15);
    cout << "Precio   \xB3 ";
    color(11);
    cout << "Impuesto (16\x25)  \xB3 ";
    color(14);
    cout << "Total    \xB3 \n\n\n";


    for (int i = j; i < y; i++)
    {
        color(3);
        cout << " " << left << setw(3) << registro[i].id << setfill(' ') << " \xB3 "; //Numero del articulo
        color(8);
        cout << left << setw(25) << registro[i].nombre << setfill(' ') << " \xB3 "; //Nombre del videojuego
        color(3);
        cout << left << setw(13) << registro[i].anio << setfill(' ') << " \xB3 "; //Año de lanzamiento
        color(8);
        cout << left << setw(5) << registro[i].clas << setfill(' ') << " \xB3 "; //Clasificacion
        color(3);
        cout << left << setw(40) << registro[i].carac << setfill(' ') << " \xB3 "; //Caracteristicas
        color(8);
        cout << left << setw(50) << registro[i].desc << setfill(' ') << " \xB3 "; //Descripcion
        color(3);
        cout << left << setw(30) << registro[i].gen << setfill(' ') << " \xB3 "; //Genero del juego
        color(8);
        cout << left << "$" << fixed << setprecision(2) << setw(7) << registro[i].precio << setfill(' ') << " \xB3 ";  //Precio unitario
        color(3);
        cout << left << "$" << fixed << setprecision(2) << setw(14) << registro[i].imp << setfill(' ') << " \xB3 ";  //Impuestos
        color(6);
        cout << left << "$" << fixed << setprecision(2) << setw(7) << registro[i].total << setfill(' ') << " \xB3 ";  //Total con impuestos
        cout << "\n\n";
    }

    if (menu == 4)
    {
        color(10);
        cout << "Presione una tecla para continuar...";
    }
    
}

void leerBN()
{
    string linea;
    ifstream listaBL("Videojuegos.txt");

    if (listaBL.fail())
    {
        return;
    }

    b = true;

    while (!getline(listaBL, linea).eof())
    {
        //listaBL >> linea;
        registro[x].id = stoi(linea); //Numero del articulo
        getline(listaBL, linea);
        registro[x].nombre = linea; //Nombre del videojuego
        getline(listaBL, linea);
        registro[x].anio = stoi(linea); //Año de lanzamiento
        getline(listaBL, linea);
        registro[x].clas = linea; //Clasificacion
        getline(listaBL, linea);
        registro[x].carac = linea; //Caracteristicas
        getline(listaBL, linea);
        registro[x].desc = linea; //Descripcion
        getline(listaBL, linea);
        registro[x].gen = linea; //Genero del juego
        getline(listaBL, linea);
        registro[x].precio = stof(linea);  //Precio unitario
        getline(listaBL, linea);
        registro[x].imp = stof(linea);  //Impuestos
        getline(listaBL, linea);
        registro[x].total = stof(linea);  //Total con impuestos

        x++;
    }

}

void saveBN(int y)
{
    string listaJuegos = "Videojuegos.txt";
    ofstream fichero; //fichero solo de salida.

    //abrimos el fichero
    fichero.open(listaJuegos.c_str()); //Esto es un puntero que apunta en que parte estamos dentro del fichero. 

    if (b == false) // validar si hay registros
    {
        return;
    }

    for (int i = 0; i < y; i++)
    {
        fichero << registro[i].id << endl; //Numero del articulo
        fichero << registro[i].nombre << endl; //Nombre del videojuego
        fichero << registro[i].anio << endl; //Año de lanzamiento
        fichero << registro[i].clas << endl; //Clasificacion
        fichero << registro[i].carac << endl; //Caracteristicas
        fichero << registro[i].desc << endl; //Descripcion
        fichero << registro[i].gen << endl; //Genero del juego
        fichero << registro[i].precio << endl;  //Precio unitario
        fichero << registro[i].imp << endl;  //Impuestos
        fichero << registro[i].total << endl;  //Total con impuestos
    }

    //cerramos el fichero
    fichero.close();
}

//registros
void nombreJ(int k)
{
    int c = 0;
    color(11);
    cout << "Ingrese el nombre del juego:\n";       //Nombre del videojuego
    color(15);
    cin.clear();
    cin.ignore();
    getline(cin, registro[k].nombre);
    c = registro[k].nombre.length();
    if (c > 50)
    {
        registro[k].nombre.erase(registro[k].nombre.begin() + 50, registro[k].nombre.end());
    }
}

void anioJ(int k)
{
    color(11);
    cout << "\nIngrese el a\xA4o de lanzamineto:\n";  //Año de lanzamiento
    do
    {
        color(15);
        cin >> registro[k].anio;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore();
            registro[k].anio = 0;
        }

        if (registro[k].anio < 1950 || registro[k].anio > 2050)
        {
            color(12);
            cout << "\x1b[1A" << "\x1b[2K";
            cout << "\rError: esa no es una fecha valida.\n";
        }
    } while (registro[k].anio < 1950 || registro[k].anio > 2050);
}

void clasJ(int k)
{
    color(11);
    cout << "\nClasificacion del juego\n";     //clasificacion
    color(3);
    cout << "[1]. Todos (E)\n" <<
        "[2]. Todos +10 (E10+)\n" <<
        "[3]. Adolescentes (T)\n" <<
        "[4]. Maduro +17 (M)\n" <<
        "[5]. Solo Adultos +18 (A)\n" <<
        "[6]. Aun sin calificar (RP)\n";

    int e = 0;

    do
    {
        color(15);
        cl = _getche() - '0';
        cout << endl;

        switch (cl)
        {
        case 1:
        {
            registro[k].clas = "E";
            break;
        }
        case 2:
        {
            registro[k].clas = "E10+";
            break;
        }
        case 3:
        {
            registro[k].clas = "T";
            break;
        }
        case 4:
        {
            registro[k].clas = "M";
            break;
        }
        case 5:
        {
            registro[k].clas = "A";
            break;
        }
        case 6:
        {
            registro[k].clas = "RP";
            break;
        }
        default:
        {
            color(12);
            cout << "\x1b[1A" << "\x1b[2K";
            cout << "\rError: Esa no es una opcion\n";
            e++;
        }
        }
    } while (cl <= 0 || cl >= 7);

    if (e > 0)
    {
        for (int i = 0; i <= e; i++)
        {
            cout << "\x1b[1A" << "\x1b[2K";
        }
        cout << cl << endl;
    }
}

void caracJ(int k)
{
    int c = 0;
    color(11);
    cout << "\nCaracteristicas del juego:\n";       //Escribir caracteristicas
    cin.ignore();
    color(15);
    getline(cin, registro[k].carac);
    c = registro[k].carac.length();
    if (c > 40)
    {
        registro[k].carac.erase(registro[k].carac.begin() + 40, registro[k].carac.end());
    }
}

void descJ(int k)
{
    int c = 0;
    color(11);
    cout << "\nDescripcion del juego:\n";           //Escribir descripcion
    color(15);
    getline(cin, registro[k].desc);
    c = registro[k].desc.length();
    if (c > 50)
    {
        registro[k].desc.erase(registro[k].desc.begin() + 50, registro[k].desc.end());
    }
}

void generoJ(int k)
{
    int c = 0;
    color(11);
    cout << "\nGenero del juego:\n";                //Genero del juego
    color(15);
    //cin.ignore();
    getline(cin, registro[k].gen);
    c = registro[k].gen.length();
    if (c > 30)
    {
        registro[k].gen.erase(registro[k].gen.begin() + 30, registro[k].gen.end());
    }
}

void precioJ(int k)
{
    color(11);
    cout << "\nIngrese el precio unitario:\n";      //Valor del juego
    color(15);

    do
    {
        color(15);
        cin >> registro[k].precio;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore();
            registro[k].precio = -1;
        }

        if (registro[k].precio < 0)
        {
            color(12);
            cout << "\x1b[1A" << "\x1b[2K";
            cout << "\rError: ese no es un precio valido.\n";
        }
    } while (registro[k].precio < 0);

    registro[k].imp = registro[k].precio * .16;            //Cuanto es de impuestos
    registro[k].total = registro[k].precio + registro[k].imp;   //Total con impuestos
}


//Menu principal
void agregar()
{
    
    b = true;

    do
    {
        system("cls");
        registro[x].id = x + 1; //Numero del articulo

        nombreJ(x);

        anioJ(x);

        clasJ(x);

        caracJ(x);

        descJ(x);

        generoJ(x);

        precioJ(x);

        system("cls");
        color(10);
        cout << "Juego agregado con exito! \1\n";
        do
        {
            color(11);
            cout << "Desea agregar otro juego? si[s] no[n]\n";
            cin.ignore();
            sn = _getch();

            sn.erase(sn.begin() + 1, sn.end());

            if (sn != "s" && sn != "n" && sn != "S" && sn != "N")
            {
                system("cls");
                color(12);
                cout << "Error: esa no es una opcion.\n";
            }

        } while (sn != "s" && sn != "n" && sn != "N" && sn != "S");

        x++;

    } while (sn == "s" || sn == "S");
}

void modificar()
{
    do
    {
        int cat = 0;
        system("cls");
        if (b == false) // validar si hay registros
        {
            color(14);
            cout << "No hay juegos registrados. Presiona una tecla para continuar...";
            system("pause>n");
            return;
        }

        lista(x, 0);

        color(10);
        cout << "Ingresa el ID del juego que desea modificar. Salir[0]\n";
        color(15);
        cin >> mod;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore();
            mod = -1;
        }

        if (mod > 0 && mod <= 100)
        {
            do
            {
                system("cls");
                lista(mod, mod - 1);
                color(11);
                cout << "Que deseas modificar?\n";
                color(3);
                cout << "[1]. Nombre del juego\n" <<
                    "[2]. A\xA4o de lanzamineto:\n" <<
                    "[3]. Clasificacion del juego\n" <<
                    "[4]. Caracteristicas del juego\n" <<
                    "[5]. Descripcion del juego\n" <<
                    "[6]. Precio unitario\n" <<
                    "[0]. Regresar\n";

                cat = _getch() - '0';

                switch (cat)
                {
                case 1:
                {
                    system("cls");
                    cin.ignore();
                    nombreJ(mod - 1);
                    break;
                }
                case 2:
                {
                    system("cls");
                    anioJ(mod - 1);
                    break;
                }
                case 3:
                {
                    system("cls");
                    clasJ(mod - 1);
                    break;
                }
                case 4:
                {
                    system("cls");
                    caracJ(mod - 1);
                    break;
                }
                case 5:
                {
                    system("cls");
                    descJ(mod - 1);
                    break;
                }
                case 6:
                {
                    system("cls");
                    precioJ(mod - 1);
                    break;
                }
                case 0:
                {
                    break;
                }
                default:
                {
                    color(12);
                    cout << "\x1b[1A" << "\x1b[2K";
                    cout << "\rError: Esa no es una opcion\n";
                }
                }
            } while (cat != 0);

        }

        else if (mod != 0)
        {
            system("cls");
            color(12);
            cout << "Error: no existe un juego con ese ID. Presiona una tecla para continuar";
            system("pause>null");
        }

        if (x == 0)
        {
            b = false;
        }
    } while (mod != 0);
}

void eliminar()
{
    do
    {
        system("cls");
        if (b == false) // validar si hay registros
        {
            color(14);
            cout << "No hay juegos registrados. Presiona una tecla para continuar...";
            system("pause>n");
            return;
        }

        lista(x, 0);

        color(10);
        cout << "Ingresa el ID del juego que desea eliminar. Salir[0]\n";
        color(15);
        cin >> mod;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore();
            mod = -1;
        }

        if (mod > 0 && mod <= 100)
        {
            system("cls");
            lista(mod, mod - 1);
            do
            {
                color(14);
                cout << "Seguro que desea eliminar este juego? Si[s] No[n]\n";
                sn = _getch();

                if (sn == "s" || sn == "S")
                {
                    for (int i = mod - 1; i < x; i++)
                    {
                        registro[i].nombre = registro[i + 1].nombre;
                        registro[i].anio = registro[i + 1].anio;
                        registro[i].clas = registro[i + 1].clas;
                        registro[i].carac = registro[i + 1].carac;
                        registro[i].desc = registro[i + 1].desc;
                        registro[i].gen = registro[i + 1].gen;
                        registro[i].precio = registro[i + 1].precio;
                        registro[i].imp = registro[i + 1].imp;
                        registro[i].total = registro[i + 1].total;
                    }
                    x--;
                }
                else if (sn != "s" && sn != "n" && sn != "S" && sn != "N")
                {
                    system("cls");
                    color(12);
                    cout << "Error: esa no es una opcion.\n";
                }
            } while (sn != "s" && sn != "n" && sn != "N" && sn != "S");

        }

        else if (mod != 0)
        {
            system("cls");
            color(12);
            cout << "Error: no existe un juego con ese ID. Presiona una tecla para continuar";
            system("pause>null");
        }

        if (x == 0)
        {
            b = false;
        }
    } while (mod != 0);
}

void main()
{

    leerBN();

    do
    {
        system("cls");
        color(11);
        cout << "============MENU PRINCIPAL============\n";
        color(10);
        cout << "\t[1]. Agregar juego\n" <<
            "\t[2]. Modificar juego\n" <<
            "\t[3]. Eliminar juego\n" <<
            "\t[4]. Lista de juegos vigentes\n" <<
            "\t[5]. Limpiar pantalla\n" <<
            "\t[0]. Salir\n";

        menu = _getch() - '0';

        switch (menu)
        {
        case 1:
        {
            cin.clear();
            agregar();
            break;
        }
        case 2:
        {
            system("cls");
            modificar();
            break;
        }
        case 3:
        {
            system("cls");
            eliminar();
            break;
        }
        case 4:
        {
            system("cls");
            lista(x, 0);
            system("pause>n");
            break;
        }
        case 5:
        {
            system("cls");
            system("pause>null");
            break;
        }
        case 0:
        {
            saveBN(x);
            cout << "Saliendo del sistema";
            for (int i = 0; i < 3; i++)
            {
                Sleep(700);
                cout << ". ";
            }
            Sleep(400);
            break;
        }
        default:
        {
            color(12);
            cout << "Error: esa no es una opcion.\n" << "Presiona enter para continuar...\n";
            system("pause>null");
            break;
        }
        }
    } while (menu != 0);
}