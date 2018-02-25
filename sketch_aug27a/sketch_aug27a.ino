// BITS DAS DEZENAS:
#define D0 2
#define D1 3
#define D2 4
#define D3 5

// BITS DAS UNIDADES:
#define U0 8
#define U1 9
#define U2 10
#define U3 11


// DISPLAY 7 SEG
void numInvalido() {
  digitalWrite(U0, HIGH);
  digitalWrite(U1, HIGH);
  digitalWrite(U2, HIGH);
  digitalWrite(U3, HIGH);
  digitalWrite(D0, HIGH);
  digitalWrite(D1, HIGH);
  digitalWrite(D2, HIGH);
  digitalWrite(D3, HIGH);
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
    numInvalido();
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

void setup() {
  pinMode(D0, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(U0, OUTPUT);
  pinMode(U1, OUTPUT);
  pinMode(U2, OUTPUT);
  pinMode(U3, OUTPUT);
  int x = 0;
}

void loop() {
  displayOut(x);
  x = (x + 1) % 100;
  delay(125);
}



