#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void calc_esfera (float r, float* area, float* volume);
int raizes (float a, float b, float c, float* x1, float* x2);
int pares (int n, int* vet);
void inverte (int n, int* vet);
double avalia (double* poli, int grau, double x);

const double PI = 3.14159;

/* questao 2.1
int main(void)
{
	float raio = 0.0;
	float area_esfera = 0.0;
	float volume_esfera = 0.0;

	printf("Digite o raio r da esfera: ");
	scanf("%f", &raio);

	calc_esfera(raio, &area_esfera, &volume_esfera);

	printf("Area da esfera: %f\n", area_esfera);
	printf("Volume da esfera: %f\n", volume_esfera);

	return 0;
}
*/

/* questao 2.2
int main(void)
{
	float a = 0.0;
	float b = 0.0;
	float c = 0.0;
	float x1 = 0.0;
	float x2 = 0.0;

	printf("Digite os parametros a, b, e c da equacao de segundo grau: ");
	scanf("%f%f%f", &a, &b, &c);

	if (raizes(a, b, c, &x1, &x2))
		printf("A equação nao tem raizes reais\n");
	else
		printf("As raizes da equação sao\nx1 = %f\nx2 = %f\n", x1, x2);

	return 0;
}
*/

/* questao 2.3
int main(void)
{
	int i, n = 0;
	int numPares = 0;

	printf("Digite o tamanho do vetor: ");
	scanf("%d", &n);

	int* vet = (int *) malloc(n * sizeof(int));

	printf("Digite os numeros inteiros do vetor:\n");
	for(i = 0; i < n; i++)
		scanf("%d", &vet[i]);

	numPares = pares(n, vet);

	printf("Estao armanezados %d numeros pares no vetor\n", numPares);

	free(vet);
	return 0;
}
*/

/* questao 2.4
int main(void)
{
	int i, n;

	printf("Digite a quantidade de numeros do vetor: \n");
	scanf("%d", &n);

	int* vet = (int *) malloc(n * sizeof(int));

	printf("Digite os numeros do vetor:\n");
	for(i = 0; i < n; i++)
		scanf("%d", &vet[i]);

	printf("Vetor original:\n");
	for(i = 0; i < n; i++)
		printf("%d ", vet[i]);

	inverte(n, vet);

	printf("\nVetor invertido:\n");
	for(i = 0; i < n; i++)
		printf("%d ", vet[i]);

	printf("\n");

	free(vet)
	return 0;
}
*/

// questa 2.5
int main(void)
{
	int i;
	int grau = 0;
	double x;
	double resultado;

	printf("Digite o grau do polinomio: ");
	scanf("%d", &grau);

	double* polinomio = (double *) malloc((grau+1) * sizeof(double));

	printf("Digite os coeficientes do polinômio P(x)=a0+a1*x+a2*x^2+...+an*x^n comecando pelo coeficiente a0 e terminando em an:\n");
	for(i = 0; i <= grau; i++)
		scanf("%lf", &polinomio[i]);

	printf("Digite o numero x em que o polinomio P(x) sera avaliado: ");
	scanf("%lf", &x);

	resultado = avalia(polinomio, grau, x);

	printf("P(x) = %lf\n", resultado);

	free(polinomio);
	return 0;
}

void calc_esfera (float r, float* area, float* volume)
{
	*area = 4.0 * PI * r * r;
	*volume = 4.0 * PI * r * r * r / 3.0;
}

int raizes (float a, float b, float c, float* x1, float* x2)
{
	int delta = (b * b) - (4.0 * a * c);

	if (delta < 0)
		return 1;

	*x1 = (-b + sqrt(delta)) / (2.0 * a);
	*x2 = (-b - sqrt(delta)) / (2.0 * a);

	return 0;
}

int pares (int n, int* vet)
{
	int i, nPares = 0;

	for(i = 0; i < n; i++)
		if (vet[i] % 2 == 0)
			nPares++;

	return nPares;
}

void inverte (int n, int* vet)
{
	int i, aux;

	for(i = 0; i < n/2; i++)
	{
		aux = vet[i];
		vet[i] = vet[(n - 1) - i];
		vet[(n - 1) -i] = aux;
	}
}

double avalia (double* poli, int grau, double x)
{
	int i;
	double resultado = 0.0;

	for(i = 0; i <= grau; i++)
	{
		resultado += poli[i] * pow(x, i);
	}

	return resultado;
}
