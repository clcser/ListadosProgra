/*
Claudia Cser
Solucion propia

Escriba un programa que incluya las funciones anteriormente solicitadas: operacion, mcm y mcd y pregunte al 
usuario por la operación que desea realizar. El programa deberá imprimir un mensaje dando instrucciones sobre el
uso del mismo. Posteriormente, el programa aceptará como entrada, únicamente, una de las siguientes cadenas de 
caracteres: operacion, mcm, mcd y salir, en caso de introducir cualquier otra cadena, se limpiará la pantalla y 
se volverá a desplegar el mensaje con las instrucciones. En caso de que el usuario ingrese cualquiera de las 
tres primeras instrucciones, se entrará a un sub-menú con instrucciones propias de la operación. Para el caso de
operacion, se desplegará un menú con la opciones 1: ingresar operacion y 2: Volver al menú principal. En caso de
seleccionar la opción 1, el programa deberá leer los dos números y el caracter correspondiente e imprimir la 
respuesta. Se debe validar la entrada y comprobar que se introdujeron dos números y un caracter. En caso de 
seleccionar la opción 2, el programa deberá limpiar la pantalla y volver a desplegar el mensaje de instrucciones
y esperar una cadena de caracteres. En caso de que el usuario ingrese, en el menú principal, mcm o mcd, el 
programa desplegará un menú análogo al de operacion, pero asociado a las operaciones correspondientes. En ambos 
casos, el menú estará compuesto por las opciones 1: ingresar números y 2: Volver al menú principal. La opción 2 
es análoga a la del menú de operacion y la opción 1, ingresa a una pantalla en la que se piden y se validan dos 
números enteros y se despliega el resultado (ya sea el mcm o el mcd). En el caso de los tres sub-menús, si se 
ingresa una opción inválida, se deberá limpiar la pantalla y seguir mostrando el sub-menú correspondiente. 
Finalmente, si en el menú principal, se ingresa la cadena salir, el programa termina su ejecución. 

No es el codigo mas lindo pero porfi tratarlo con cariño:(
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

double operacion(char op, double v1, double v2) {
    double res;
    if(op == '+') { 
        res = v1 + v2;
        return(res);
    }
    else if(op == '-') {
        res = v1 - v2;
        return(res);
    }
    else if(op == '*') {
    res = v1 * v2;
        return(res);
    }
    else if(op == '/') {
        res = v1 / v2;
        return(res);
    }
}

long long mcm(long long n1, long long n2) { // solo funciona con numeros positivos
    long long i = 2, mcm = 1;
    while(n1 != n2) {
        while((n1%i == 0) || (n2%i == 0)) {
            if(n1%i == 0) {
                n1 /= i;
            }
            if(n2%i == 0) {
                n2 /= i;
            }
            mcm *= i;
        }
        i++;
    }
    return mcm;
}

long long mcd(long long n1, long long n2) { // solo funciona con numeros positivos
    long long i;
    i = n1 > n2 ? n1 : n2;
    while((n1%i != 0) || (n2%i != 0)) {
        i--;
    }
    return i;
}

void man(char *funcion) { // descripcion funciones
    if(strstr(funcion,"operacion") != NULL) {
        printf("Operacion: Calcula la suma, resta, multiplicacion o division de dos numeros decimales.\n");
    } else if(strstr(funcion,"mcm") != NULL) {
        printf("MCM: Calcula el minimo comun multiplo entre dos numeros enteros.\n");
    } else {
        printf("MCD: Calcula el maximo comun divisor entre dos numeros enteros.\n");
    }   
}

bool validarOperacion(char c, char *n1, char *n2) { // validacion para operacion
    if(c != '+' && c != '-' && c != '*' && c != '/') { // validar caracter
        system("clear");
        return false;
    }

    int cont1 = 0,cont2 = 0;
    
    for(int i = 0; i<strlen(n1); i++) { // validar primer numero
        if(i == 0) {
            if(n1[i] == '-') {
                continue;
            }
        }
        if(n1[i] == '.')
            cont1 ++;
        if((n1[i] < '0' || n1[i] > '9') && n1[i] != '.') {
            system("clear");
            return false;
        }
    }
    for(int i = 0; i<strlen(n2); i++) { // validar segundo numero
        if(i == 0) {
            if(n2[i] == '-') {
                continue;
            }
        }
        if(n2[i] == '.')
            cont2 ++;
        if((n2[i] < '0' || n2[i] > '9') && n2[i] != '.') {
            system("clear");
            return false;
        }
    }
    if(cont1 > 1 || cont2 > 1) {
        system("clear");
        return false;
    }
    return true;
}

bool validarEntrada(char *n) { // validacion para mcm y mcd
    for(int i = 0; i < strlen(n); i++) {
        if(i == 0) {
            if(n[i] == '-') {
                break;
            }
        }
        if(n[i] < '0' || n[i] > '9') {
            system("clear");
            return false;
        }
    }
    return true;
}

int main() {
    char func[10];
    int opcion; 
    bool condicion1, condicion2, condicion3;
    
    do { // menu principal
        condicion1 = condicion2 = true;
        system("clear");
        
        printf("Ingrese una de las siguientes opciones: operacion, mcm, mcd, salir.\n\n");
        scanf("%[^\n]", func);
        getchar();

        system("clear");
        
        if(strstr(func,"salir") != NULL) {
            condicion1 = false;

        } else if(strstr(func,"operacion") != NULL || strstr(func,"mcm") != NULL || strstr(func,"mcd") != NULL) {
            do { // menu funciones
                man(func); 
                condicion3 = true;
                printf("\n1: Ingresar numeros.\n2: Volver al menu principal.\n\n");

                scanf("%d", &opcion);
                getchar();
                
                if(opcion == 2) {
                    condicion2 = false;
                } else if(opcion == 1) {
                    if(strstr(func,"operacion") != NULL) {
                        do { // operacion
                            printf("Ingrese uno de los siguientes caracteres: +,-,*,/; y luego dos numeros decimales.\n\n");
                            char c, n1[30], n2[30];
                            scanf("%c", &c);
                            
                            double num1,num2,res;
                            scanf("%s %s", n1, n2);
                            getchar();

                            condicion3 = validarOperacion(c, n1, n2);

                            if(!condicion2) {
                                continue;
                            } else if(condicion3) {
                                num1 = strtod(n1,NULL);
                                num2 = strtod(n2,NULL);
                                res = operacion(c,num1,num2);
        
                                printf("Resultado: %lf\n\n", res);
                                condicion3 = false;

                            }
                        } while(condicion3);

                    } else if(strstr(func,"mcm") != NULL) {
                        do { // mcm
                            printf("Ingrese dos numeros enteros.\n\n");
                            long long num1,num2,res;
                            char n1[30],n2[30];
                            scanf("%s %s", n1, n2);
                            getchar();
    
                            condicion3 = validarEntrada(n1) & validarEntrada(n2);                        
    
                            if(!condicion3) {
                                continue;
                            } else if(condicion3) {
                                num1 = strtod(n1,NULL);
                                num2 = strtod(n2,NULL);
                                res = mcm(num1,num2);
        
                                printf("Resultado: %lld\n\n", res);
                                condicion3 = false;
                            }
                        } while(condicion3);
                    
                    } else if(strstr(func,"mcd") != NULL) {
                        do { // mcd
                            printf("Ingrese dos numeros enteros.\n\n");
                            long long num1,num2,res;
                            char n1[30],n2[30];
                            scanf("%s %s", n1, n2);
                            getchar();
                            
                            condicion3 = validarEntrada(n1) & validarEntrada(n2);
                            
                            if(!condicion3) {
                                continue;
                            } else if(condicion3) {
                                num1 = strtod(n1,NULL);
                                num2 = strtod(n2,NULL);
                                res = mcd(num1,num2);
                                
                                printf("Resultado: %lld\n\n", res);
                                condicion3 = false;
                            }
                        } while(condicion3);
                    }
                }
            } while(condicion2);
        }
    } while(condicion1);

    return 0;
}
