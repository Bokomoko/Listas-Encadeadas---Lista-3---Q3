struct lista{
  int info;
  struct lista* prox;
};
typedef struct lista Lista;

Lista* crialista();
Lista* insere(Lista* ref, int valor);
void imprime(Lista* ref);
Lista* apaga(Lista* ref, int valor);
void libera(Lista** lista);
Lista* inserenofim(Lista* ref, int valor);
