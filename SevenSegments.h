#ifndef SEVEN_SEGMENTS
#define SEVEN_SEGMENTS

#include <Arduino.h>

/*
 * Driver do display de 7 segmentos de dois dígitos.
 * Saída em código BCD paralelo.
 * Gasta 4 bits para cada dígito.
 * Total de 8 pinos usados.
 * 
 * Ordem dos bits:
 * 
 *   dezena     |    unidade
 * D3 D2 D1 D0  |  A3 A2 A1 A0
 * ^         ^  |  ^         ^
 * MSB     LSB  |  MSB     LSB
 * 
 */

class SevenSegments {
    private:
    // BITS DAS DEZENAS:
    int D0, D1, D2, D3;
    // BITS DAS UNIDADES:
    int U0, U1, U2, U3;
    // AUX
    void num0(int, int, int, int);
    void num1(int, int, int, int);
    void num2(int, int, int, int);
    void num3(int, int, int, int);
    void num4(int, int, int, int);
    void num5(int, int, int, int);
    void num6(int, int, int, int);
    void num7(int, int, int, int);
    void num8(int, int, int, int);
    void num9(int, int, int, int);

    public:
    // MAPEAMENTO DO HARDWARE
    SevenSegments(int, int, int, int, int, int, int, int);
    // COLOCA O NUMERO NO DISPLAY
    void print(int);
    
};


SevenSegments::SevenSegments(int d0, int d1, int d2, int d3, int u0, int u1, int u2, int u3) {
    // atribuicao para lembrar os pinos
    D0 = d0;
    D1 = d1;
    D2 = d2;
    D3 = d3;
    U0 = u0;
    U1 = u1;
    U2 = u2;
    U3 = u3;
    // configuracao dos pinos
    pinMode(D0, OUTPUT);
    pinMode(D1, OUTPUT);
    pinMode(D2, OUTPUT);
    pinMode(D3, OUTPUT);
    pinMode(U0, OUTPUT);
    pinMode(U1, OUTPUT);
    pinMode(U2, OUTPUT);
    pinMode(U3, OUTPUT);
    // comeca com display "00"
    num0(U0, U1, U2, U3);
    num0(D0, D1, D2, D3);
}

void SevenSegments::num0(int A0, int A1, int A2, int A3) {
    // BCD "0000"
    digitalWrite(A0, LOW);
    digitalWrite(A1, LOW);
    digitalWrite(A2, LOW);
    digitalWrite(A3, LOW);
}

void SevenSegments::num1(int A0, int A1, int A2, int A3) {
    // BCD "0001"
    digitalWrite(A0, HIGH);
    digitalWrite(A1, LOW);
    digitalWrite(A2, LOW);
    digitalWrite(A3, LOW);  
}

void SevenSegments::num2(int A0, int A1, int A2, int A3) {
    // BCD "0010"
    digitalWrite(A0, LOW);
    digitalWrite(A1, HIGH);
    digitalWrite(A2, LOW);
    digitalWrite(A3, LOW);  
}

void SevenSegments::num3(int A0, int A1, int A2, int A3) {
    // BCD "0011"
    digitalWrite(A0, HIGH);
    digitalWrite(A1, HIGH);
    digitalWrite(A2, LOW);
    digitalWrite(A3, LOW); 
}

void SevenSegments::num4(int A0, int A1, int A2, int A3) {
    // BCD "0100"
    digitalWrite(A0, LOW);
    digitalWrite(A1, LOW);
    digitalWrite(A2, HIGH);
    digitalWrite(A3, LOW);
}

void SevenSegments::num5(int A0, int A1, int A2, int A3) {
    // BCD "0101"
    digitalWrite(A0, HIGH);
    digitalWrite(A1, LOW);
    digitalWrite(A2, HIGH);
    digitalWrite(A3, LOW);  
}

void SevenSegments::num6(int A0, int A1, int A2, int A3) {
    // BCD "0110"
    digitalWrite(A0, LOW);
    digitalWrite(A1, HIGH);
    digitalWrite(A2, HIGH);
    digitalWrite(A3, LOW); 
}

void SevenSegments::num7(int A0, int A1, int A2, int A3) {
    // BCD "0111"
    digitalWrite(A0, HIGH);
    digitalWrite(A1, HIGH);
    digitalWrite(A2, HIGH);
    digitalWrite(A3, LOW);  
}

void SevenSegments::num8(int A0, int A1, int A2, int A3) {
    // BCD "1000"
    digitalWrite(A0, LOW);
    digitalWrite(A1, LOW);
    digitalWrite(A2, LOW);
    digitalWrite(A3, HIGH);
}

void SevenSegments::num9(int A0, int A1, int A2, int A3) {
    // BCD "1001"
    digitalWrite(A0, HIGH);
    digitalWrite(A1, LOW);
    digitalWrite(A2, LOW);
    digitalWrite(A3, HIGH);
}


void SevenSegments::print(int n) {  
    if (n < 0 or n > 99) {
        // "Invalid number"
        return;
    }
    
    int valor;
        
    valor = n / 10; // dezena
        
    switch (valor) {
        case 1:
            num1(D0, D1, D2, D3);
            break;      
        case 2:
            num2(D0, D1, D2, D3);
            break;
        case 3:
            num3(D0, D1, D2, D3);
            break;
        case 4:
            num4(D0, D1, D2, D3);
            break;
        case 5:
            num5(D0, D1, D2, D3);
            break;
        case 6:
            num6(D0, D1, D2, D3);
            break;
        case 7:
            num7(D0, D1, D2, D3);
            break;
        case 8:
            num8(D0, D1, D2, D3);
            break;
        case 9:
            num9(D0, D1, D2, D3);
            break;
        case 0: 
            num0(D0, D1, D2, D3);
            break;
    }
    
    valor = n % 10; // unidade
    
    switch (valor) {
        case 1:
            num1(U0, U1, U2, U3);
            break;      
        case 2:
            num2(U0, U1, U2, U3);
            break;
        case 3:
            num3(U0, U1, U2, U3);
            break;
        case 4:
            num4(U0, U1, U2, U3);
            break;
        case 5:
            num5(U0, U1, U2, U3);
            break;
        case 6:
            num6(U0, U1, U2, U3);
            break;
        case 7:
            num7(U0, U1, U2, U3);
            break;
        case 8:
            num8(U0, U1, U2, U3);
            break;
        case 9:
            num9(U0, U1, U2, U3);
            break;
        case 0: 
            num0(U0, U1, U2, U3);
            break;
    }  
}

#endif
