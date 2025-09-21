#include <iostream>
#include <cmath>
#include <unistd.h> // Para usleep
using namespace std;
int stringToInt(const char *str)
{
    int resultado = 0;
    bool negativo = false;

    int i = 0;

    // Maneja numeros negativos

    if (str[0] == '-')
    {
        negativo = true;
        i = 1;
    }

    while (str[i] != '\0')
    {

        resultado = resultado * 10 + (str[i] - '0');

        i = i + 1;
    }

    return negativo ? -resultado : resultado;
}

int main(int argc, char *argv[])
{

    int ancho = stringToInt(argv[1]);
    int alto = stringToInt(argv[2]);

    char background = *argv[3];
    char circleTexture = *argv[4];
    int radio = stringToInt(argv[5]);

    // Orden de los argumentos para el programa
    // Ancho, Alto, BGtexture, CircleTexture, RadioSize

    for (int r = 0; r <= radio; r++)
    {
        for (int y = 0; y < ancho; y++)
        {
            for (int x = 0; x < alto; x++)
            {
                if (sqrt(pow((x - (alto / 2)), 2) + pow(y - (ancho / 2), 2)) < r)
                {
                    cout << circleTexture << ' ';
                }
                else
                {
                    cout << background << ' ';
                }
            }
            cout << endl;
        }
        usleep(100000); // Pausa de 100,000 microsegundos = 0.1 segundos
        system("clear"); // Limpia la pantalla para la animación
    }
}