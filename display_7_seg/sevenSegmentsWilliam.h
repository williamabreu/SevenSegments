#ifndef SEVEN_SEGMENTS_WILLIAM
#define SEVEN_SEGMENTS_WILLIAM 1

// BITS DAS DEZENAS:
const int D0 = 2;
const int D1 = 3;
const int D2 = 4;
const int D3 = 5;

// BITS DAS UNIDADES:
const int U0 = 8;
const int U1 = 9;
const int U2 = 10;
const int U3 = 11;

void setup() {
  pinMode(D0, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(U0, OUTPUT);
  pinMode(U1, OUTPUT);
  pinMode(U2, OUTPUT);
  pinMode(U3, OUTPUT);

  Serial.begin(9600);
}

void num0(int A0, int A1, int A2, int A3) {
  digitalWrite(A0, LOW);
  digitalWrite(A1, LOW);
  digitalWrite(A2, LOW);
  digitalWrite(A3, LOW);
}

void num1(int A0, int A1, int A2, int A3) {
  digitalWrite(A0, HIGH);
  digitalWrite(A1, LOW);
  digitalWrite(A2, LOW);
  digitalWrite(A3, LOW);  
}

void num2(int A0, int A1, int A2, int A3) {
  digitalWrite(A0, LOW);
  digitalWrite(A1, HIGH);
  digitalWrite(A2, LOW);
  digitalWrite(A3, LOW);  
}

void num3(int A0, int A1, int A2, int A3) {
  digitalWrite(A0, HIGH);
  digitalWrite(A1, HIGH);
  digitalWrite(A2, LOW);
  digitalWrite(A3, LOW); 
}

void num4(int A0, int A1, int A2, int A3) {
  digitalWrite(A0, LOW);
  digitalWrite(A1, LOW);
  digitalWrite(A2, HIGH);
  digitalWrite(A3, LOW);
}

void num5(int A0, int A1, int A2, int A3) {
  digitalWrite(A0, HIGH);
  digitalWrite(A1, LOW);
  digitalWrite(A2, HIGH);
  digitalWrite(A3, LOW);  
}

void num6(int A0, int A1, int A2, int A3) {
  digitalWrite(A0, LOW);
  digitalWrite(A1, HIGH);
  digitalWrite(A2, HIGH);
  digitalWrite(A3, LOW); 
}

void num7(int A0, int A1, int A2, int A3) {
  digitalWrite(A0, HIGH);
  digitalWrite(A1, HIGH);
  digitalWrite(A2, HIGH);
  digitalWrite(A3, LOW);  
}

void num8(int A0, int A1, int A2, int A3) {
  digitalWrite(A0, LOW);
  digitalWrite(A1, LOW);
  digitalWrite(A2, LOW);
  digitalWrite(A3, HIGH);
}

void num9(int A0, int A1, int A2, int A3) {
  digitalWrite(A0, HIGH);
  digitalWrite(A1, LOW);
  digitalWrite(A2, LOW);
  digitalWrite(A3, HIGH);
}

// CHAMADA ALTO NIVEL
void displayOut(int n) {
  
  if (n < 0 or n > 99) {
    // "Invalid number"
    return;
  }

  int dezena = n / 10;
  int unidade = n % 10;

  if (unidade == 1) {
    num1(U0, U1, U2, U3);
  }
  else if (unidade == 2) {
    num2(U0, U1, U2, U3);
  }
  else if (unidade == 3) {
    num3(U0, U1, U2, U3);
  }
  else if (unidade == 4) {
    num4(U0, U1, U2, U3);
  }
  else if (unidade == 5) {
    num5(U0, U1, U2, U3);
  }
  else if (unidade == 6) {
    num6(U0, U1, U2, U3);
  }
  else if (unidade == 7) {
    num7(U0, U1, U2, U3);
  }
  else if (unidade == 8) {
    num8(U0, U1, U2, U3);
  }
  else if (unidade == 9) {
    num9(U0, U1, U2, U3);
  }
  else { // unidade == 0
    num0(U0, U1, U2, U3);
  }

  if (dezena == 1) {
    num1(D0, D1, D2, D3);
  }
  else if (dezena == 2) {
    num2(D0, D1, D2, D3);
  }
  else if (dezena == 3) {
    num3(D0, D1, D2, D3);
  }
  else if (dezena == 4) {
    num4(D0, D1, D2, D3);
  }
  else if (dezena == 5) {
    num5(D0, D1, D2, D3);
  }
  else if (dezena == 6) {
    num6(D0, D1, D2, D3);
  }
  else if (dezena == 7) {
    num7(D0, D1, D2, D3);
  }
  else if (dezena == 8) {
    num8(D0, D1, D2, D3);
  }
  else if (dezena == 9) {
    num9(D0, D1, D2, D3);
  }
  else { // dezena == 0
    num0(D0, D1, D2, D3);
  }
  
}

#endif
