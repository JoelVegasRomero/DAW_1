#include <stdio.h>
#include <stdlib.h>
#include <time.h>

///FUNCIONES
int pedirNumeroFilasYColumnas (void);
void mensajeErrorCantidadFilasYColumnas(void);
int pedirOpcionInicializacion (void);
void mensajeOpcionMenuIncorrecta(void);
void menuInicializarArry(int numeroFilas, int numeroColumnas,int numeroFilasB,int numeroColumnasB);
int **InicializacionArrayAFormaAutomatica(int numeroFilas,int numeroColumnas);
int **InicializacionArrayAFormaManual(int numeroFilas,int numeroColumnas);
void mostrarMensajeUsuario(void);
int guardarNumeroUsuarioArray(void);
void menuOpcionesMatematicas(void);
int elegirOpcionMatematica(void);
bool comprobacionTamanyoArray(int arrayA,int arrayB);

void menuOperacionMatematica(int operacionMatematicaUsuario,int **MatrizA,int **MatrizB,int numeroFilas,int numeroColumnas,bool comprobacionTamayo,int numeroFilasB,int numeroColumnasB);
int **sumarMatrices(int **MatrizA,int **MatrizB,int numeroFilas, int numeroColumnas);
int **restaMatrices(int **MatrizA,int **MatrizB,int numeroFilas, int numeroColumnas);
int **multiplicarMatricesA (int **MatrizA,int **MatrizB,int numeroFilas, int numeroColumnas, int numeroFilasB, int numeroColumnasB);
int **multiplicarMatricesB (int **MatrizA,int **MatrizB,int numeroFilas, int numeroColumnas, int numeroFilasB, int numeroColumnasB);

void mensajeErrorTamanyoArrayDiferente(void);
void mostrarArray(int numeroFilas,int numeroColumnas, int **MatrizA);

/// COMENTAR EL CODIGO
int main (void){
    /// INICIALIZAR SEMILLA
    srand(time(NULL));
    printf("Tamanyo Tabla A \n");
    printf("Filas: \n");
    int numeroFilas = pedirNumeroFilasYColumnas();
    printf("Columnas: \n");
    int numeroColumnas = pedirNumeroFilasYColumnas();

    printf("Tamanyo Tabla B \n");
    printf("Filas: \n");
    int numeroFilasB = pedirNumeroFilasYColumnas();
    printf("Columnas: \n");
    int numeroColumnasB = pedirNumeroFilasYColumnas();
    menuInicializarArry(numeroFilas,numeroColumnas,numeroFilasB,numeroColumnasB);
}

/// Pedimos la cantidad de filas. El rango de filas es de 1 al 5
int pedirNumeroFilasYColumnas (void){
    int cantidad;
    printf("Indicame la cantidad: ");
    scanf("%i",&cantidad);

    ///Usamos recursión para asegurar que el número de filas esté en el rango de 1 a 5.
    if(cantidad<= 0 || cantidad > 5){
      mensajeErrorCantidadFilasYColumnas();
      return pedirNumeroFilasYColumnas();
    } else return cantidad;
}

void mensajeErrorCantidadFilasYColumnas(void){
    printf("Error: El numero debe ser entre el 1 y el 5. Intentalo de nuevo\n");
}

int pedirOpcionInicializacion (void){
    int opcionUsuario;
    do{
        printf("1. Automatica \n2. Manual \nIndica una opcion: ");
        scanf("%i",&opcionUsuario);
        if (opcionUsuario <= 0 || opcionUsuario >= 3) mensajeOpcionMenuIncorrecta();
    }while(opcionUsuario <= 0 || opcionUsuario >= 3);
    return opcionUsuario;
}

void mensajeOpcionMenuIncorrecta(void){
    printf("Error: la opcion es entre el 1 y el 2. Prueba otra vez. \n");
}


void menuInicializarArry(int numeroFilas, int numeroColumnas,int numeroFilasB,int numeroColumnasB){
    bool comprobacionTamayo = false;
    bool comprobacionTamanyoFilasIguales = comprobacionTamanyoArray(numeroFilas,numeroFilasB);
    bool comprobacionTamanyoColumnasIguales = comprobacionTamanyoArray(numeroColumnas,numeroColumnasB);
    if(comprobacionTamanyoFilasIguales == comprobacionTamanyoColumnasIguales) comprobacionTamayo=true; else comprobacionTamayo=false;

    switch (pedirOpcionInicializacion()){
        case 1:
            int **MatrizA,**MatrizB;
            int operacionMatematicaUsuario;

            MatrizA = InicializacionArrayAFormaAutomatica(numeroFilas,numeroColumnas);
            MatrizB = InicializacionArrayAFormaAutomatica(numeroFilasB,numeroColumnasB);

            printf("Tabla A: \n");
            mostrarArray(numeroFilas,numeroColumnas,MatrizA);
            printf("Tabla B: \n");
            mostrarArray(numeroFilasB,numeroColumnasB,MatrizB);

            menuOpcionesMatematicas();
            operacionMatematicaUsuario = elegirOpcionMatematica();
            menuOperacionMatematica(operacionMatematicaUsuario,MatrizA,MatrizB,numeroFilas,numeroColumnas,comprobacionTamayo,numeroFilasB,numeroColumnasB);
        break;

        case 2:
            int **MatrizAManual, **MatrizBManual;
            int operacionMatematicaUsuarioManual;

            printf("Numeros Tabla A \n");
            MatrizAManual = InicializacionArrayAFormaManual(numeroFilas,numeroColumnas);
            printf("Numeros Tabla B \n");
            MatrizBManual = InicializacionArrayAFormaManual(numeroFilasB,numeroColumnasB);

            printf("Tabla A: \n");
            mostrarArray(numeroFilas,numeroColumnas,MatrizAManual);
            printf("Tabla B: \n");
            mostrarArray(numeroFilasB,numeroColumnasB,MatrizBManual);

            menuOpcionesMatematicas();
            operacionMatematicaUsuarioManual = elegirOpcionMatematica();
            menuOperacionMatematica(operacionMatematicaUsuarioManual,MatrizAManual,MatrizBManual,numeroFilas,numeroColumnas,comprobacionTamayo,numeroFilasB,numeroColumnasB);
        break;

        default:
            mensajeOpcionMenuIncorrecta();
        break;
    };
}


///DE MOMENTO NO ENVIAREMOS NADA
int **InicializacionArrayAFormaAutomatica(int numeroFilas,int numeroColumnas){
    int **Matriz;
    Matriz= (int **) malloc(sizeof(int *) * numeroFilas);
    for (int i = 0; i < numeroFilas; i++){
        Matriz[i] = (int *) malloc(sizeof(int) * numeroColumnas);
    }

    for(int fila = 0; fila < numeroFilas;fila++){
        for(int columna = 0; columna < numeroColumnas;columna ++){
            Matriz[fila][columna] = rand()%19-9;
        }
    }

    return Matriz;
}

int **InicializacionArrayAFormaManual(int numeroFilas,int numeroColumnas){
    int **Matriz;
    Matriz = (int **) malloc(sizeof (int *) * numeroFilas);
    for (int i = 0; i < numeroFilas; i++){
        Matriz[i] = (int *) malloc(sizeof (int) * numeroColumnas);
    }

    for(int fila = 0; fila < numeroFilas;fila++){
        for(int columna = 0; columna < numeroColumnas; columna++){
            mostrarMensajeUsuario();
            Matriz[fila][columna] = guardarNumeroUsuarioArray();
        }
    }
    return Matriz;
}

void mostrarMensajeUsuario(void){
    printf("Indicame Un Numero: ");
}

int guardarNumeroUsuarioArray(void){
    int numeroUsuario;
    scanf("%i",&numeroUsuario);
    return numeroUsuario;
}

void mostrarArray(int numeroFilas,int numeroColumnas,int **Matriz){
    for(int fila = 0; fila < numeroFilas;fila++){
        for(int columna = 0; columna < numeroColumnas;columna ++){
            /// ALINEAMOS LOS NUMEROS AL CENTRO, YA QUE SI ES NEGATIVO SE DESCUADRAN
            if (Matriz[fila][columna] >= 0) printf(" %i \t",Matriz[fila][columna]);
            else printf("%i \t",Matriz[fila][columna]);
        }
        printf("\n");
    }
}


void menuOpcionesMatematicas(void){
    printf("OPERACIONES MATEMATICAS \n1. Sumar les Matrius \n2. Restar les Matrius \n3. Multiplicar les matrius AxB\n4. Multiplicar les matrius BxA\n");
}

int elegirOpcionMatematica(void){
    int opcionUsuario;
    mostrarMensajeUsuario();
    scanf("%i",&opcionUsuario);
    if(opcionUsuario <= 0 || opcionUsuario >= 5) printf("Error, las opciones son del 1 al 4. \n"),elegirOpcionMatematica();
    else return opcionUsuario;
}
bool comprobacionTamanyoArray(int arrayA,int arrayB){
    if (arrayA == arrayB) return true; else false;
}

void menuOperacionMatematica(int operacionMatematicaUsuario,int **MatrizA,int **MatrizB,int numeroFilas,int numeroColumnas,bool comprobacionTamayo,int numeroFilasB,int numeroColumnasB){
    switch(operacionMatematicaUsuario){
        case 1:
            if (comprobacionTamayo){
                MatrizA = sumarMatrices(MatrizA,MatrizB,numeroFilas,numeroColumnas);
                mostrarArray(numeroFilas,numeroColumnas,MatrizA);
            }else{
                mensajeErrorTamanyoArrayDiferente();
            }
        break;

        case 2:
            if (comprobacionTamayo){
                MatrizA = restaMatrices(MatrizA,MatrizB,numeroFilas,numeroColumnas);
                mostrarArray(numeroFilas,numeroColumnas,MatrizA);
            }else{
                mensajeErrorTamanyoArrayDiferente();
            }
        break;

        case 3:
            if(numeroFilas == numeroColumnasB || numeroFilasB == numeroColumnas){
                MatrizA = multiplicarMatricesA(MatrizA,MatrizB,numeroFilas,numeroColumnas,numeroFilasB,numeroColumnasB);
                mostrarArray(numeroFilas,numeroColumnas,MatrizA);
            } else{
                //printf("ERROR");
            }
        break;

        case 4:
            if(numeroFilas == numeroColumnasB || numeroFilasB == numeroColumnas){
                MatrizA = multiplicarMatricesB(MatrizA,MatrizB,numeroFilas,numeroColumnas,numeroFilasB,numeroColumnasB);
                mostrarArray(numeroFilas,numeroColumnas,MatrizA);
            }else{
                printf("ERROR");
            }

        break;

        default:
            printf("ERROR");
        break;
    }
}
void mensajeErrorTamanyoArrayDiferente(void){
    printf("Nomes es poden fer si tenen el mateix ordre");
}
int **sumarMatrices(int **MatrizA,int **MatrizB,int numeroFilas, int numeroColumnas){
    for (int fila = 0; fila < numeroFilas; fila ++){
        for (int columna = 0; columna < numeroColumnas; columna ++){
            MatrizA[fila][columna] += MatrizB[fila][columna];
        }
    }
    return MatrizA;
}

int **restaMatrices(int **MatrizA,int **MatrizB,int numeroFilas, int numeroColumnas){
    for (int fila = 0; fila < numeroFilas; fila ++){
        for (int columna = 0; columna < numeroColumnas; columna ++){
            MatrizA[fila][columna] -= MatrizB[fila][columna];
        }
    }
    return MatrizA;
}

int **multiplicarMatricesA (int **MatrizA,int **MatrizB,int numeroFilas, int numeroColumnas, int numeroFilasB, int numeroColumnasB){
    int suma = 0;
    int numeroFilasTotal, numeroColumnasTotal;
    if (numeroFilas < numeroFilasB) numeroFilasTotal = numeroFilasB; else numeroFilasTotal = numeroFilas;
    if (numeroColumnas < numeroColumnasB) numeroColumnasTotal = numeroColumnasB; else numeroColumnasTotal = numeroColumnas;

    int **array3;
    array3 = (int **) malloc(sizeof (int *) * numeroFilasTotal);
    for (int i = 0; i < numeroFilasTotal; i++){
        array3[i] = (int *) malloc(sizeof(int) * numeroColumnasTotal);
    }

    /// el if del tamaño del array tiene que estar aqui
    /// y filas / columnas tiene que tener su valor original .
    for(int filas = 0; filas < numeroFilas; filas ++){
        for( int columnaB = 0; columnaB <  numeroFilas ; columnaB ++){
            for (int columnas = 0; columnas  < numeroColumnas; columnas ++ ){
                suma += (MatrizA[filas][columnas] * MatrizB[columnas][columnaB]);
            }
            array3[filas][columnaB]= suma;

        suma = 0;
        }
    }
    return array3;
}

int **multiplicarMatricesB (int **MatrizA,int **MatrizB,int numeroFilas, int numeroColumnas, int numeroFilasB, int numeroColumnasB){
    int suma = 0;
    int numeroFilasTotal, numeroColumnasTotal;
    if (numeroFilas < numeroFilasB) numeroFilasTotal = numeroFilasB; else numeroFilasTotal = numeroFilas;
    if (numeroColumnas < numeroColumnasB) numeroColumnasTotal = numeroColumnasB; else numeroColumnasTotal = numeroColumnas;

    int **array3;
    array3 = (int **) malloc(sizeof (int *) * numeroFilasTotal);
    for (int i = 0; i < numeroFilasTotal; i++){
        array3[i] = (int *) malloc(sizeof(int) * numeroColumnasTotal);
    }

    for(int filas = 0; filas < numeroFilasTotal; filas ++){

        for( int columnaB = 0; columnaB <  numeroFilasB ; columnaB ++){
            for (int columnas = 0; columnas  < numeroColumnas; columnas ++ ){
                suma += (MatrizA[columnaB][columnas] * MatrizB[columnas][filas]);
            }
        array3[filas][columnaB]= suma;
        suma = 0;
        }
    }
    return array3;
}

