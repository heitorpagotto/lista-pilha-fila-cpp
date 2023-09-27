#include <iostream>
#include <windows.h>

//#region Constants
#define MAX_FILA 5
#define MAX_PILE 5
#define MAX_LIST 5
//#endregion Constants

//#region GlobalVariables
int shouldRun = 1;
//#endregion GlobalVariables

//#region Structs
typedef struct {
    int key;
} REGISTRO;
typedef struct {
    REGISTRO elementos[MAX_PILE];
    int topo;
} PILE;
typedef struct {
    REGISTRO elementos[MAX_LIST];
    int nroElem;
} LIST;
typedef struct {
    REGISTRO elementos[MAX_FILA];
    int inicio;
    int nroElem;
} FILA;
//#endregion Structs

//#region MethodsDeclarations
int renderMainMenu(FILA *f, LIST *l, PILE *p);
int calcFactorial(int factorial);
void renderFilaSubMenu(FILA *f);
void renderListaSubMenu(LIST *l);
void renderPilhaSubMenu(PILE *p);
void inicializarFila(FILA *f);
void listFila(FILA *f);
int tamanhoFila(FILA *f);
bool inserirElemFila(FILA *f, REGISTRO reg);
void iniciarLista(LIST *l);
void listarList(LIST *l);
int tamanhoList(LIST *l);
bool inserirList(LIST *l, REGISTRO reg);
void inicializarPilha(PILE *p);
void listarPilha(PILE *p);
int tamanhoPilha(PILE *p);
bool inserirPilha(PILE *p, REGISTRO reg);
//#endregion MethodsDeclarations

int main() {
    FILA fila;
    inicializarFila(&fila);
    LIST lista;
    iniciarLista(&lista);
    PILE pilha;
    inicializarPilha(&pilha);
    while(shouldRun == 1) {
        shouldRun = renderMainMenu(&fila, &lista,&pilha);
    }
}

int renderMainMenu(FILA *f, LIST *l, PILE *p) {
    std::cout << "1- Funcao Recursiva" << '\n';
    std::cout << "2- Pilha" << '\n';
    std::cout << "3- Lista" << '\n';
    std::cout << "4- Fila" << '\n';
    std::cout << "5- Sair" << '\n';
    std::cout << "Escolha uma das opcoes: ";

    int opt;
    std::cin >> opt;

    system("cls");

    switch (opt) {
        case 1:
            int factorial;
            std::cout << "Insira um numero para se calcular o fatorial: ";
            std::cin >> factorial;
            std::cout << std::endl;
            std::cout << "Fatorial de " << factorial << ": " << calcFactorial(factorial) << '\n';
            system("pause");
            system("cls");
            break;
        case 2:
            renderPilhaSubMenu(p);
            break;
        case 3:
            renderListaSubMenu(l);
            break;
        case 4:
            renderFilaSubMenu(f);
            break;
        default:
            std::cout << "Finalizando...";
            Sleep(500);
            return 0;
    }

    return 1;
}

int calcFactorial(int factorial) {
    if (factorial <= 0)
        return 1;
    else
        return (factorial * calcFactorial(factorial - 1));
}

void renderFilaSubMenu(FILA *f) {
    std::cout << "1- Inserir na Fila" << std::endl;
    std::cout << "2- Lista Fila" <<std::endl;
    std::cout << "3- Tamanho Fila" << std::endl;
    std::cout << "4- Retornar" << std::endl;
    std::cout << "Escolha uma opcao: ";

    int opt;
    std::cin >> opt;

    std::cout << std::endl;

    switch (opt) {
        case 1:
            REGISTRO reg;
            std::cout << "Digite uma chave para o registro: ";
            std::cin >> reg.key;
            std::cout<<std::endl;

            if (inserirElemFila(f, reg))
                std::cout << "Elemento inserido com sucesso!" << std::endl;
            else
                std::cout << "Fila cheia." << std::endl;

            Sleep(500);
            system("cls");
            renderFilaSubMenu(f);
            break;
        case 2:
            listFila(f);
            std::cout << std::endl;
            system("pause");
            system("cls");
            renderFilaSubMenu(f);
            break;
        case 3:
            std::cout << "Tamanho da Fila: " << tamanhoFila(f) << std::endl;
            system("pause");
            system("cls");
            renderFilaSubMenu(f);
            break;
        default:
            system("cls");
    }
}

//#region Fila
void inicializarFila(FILA *f) {
    f->inicio=0;
    f->nroElem=0;
}
void listFila(FILA *f) {
    if (f->nroElem == 0)
        std::cout << "Não existe elementos na fila" << std::endl;
    else {
        int i = f->inicio;
        int temp;
        for (temp = 0;temp < f->nroElem;temp++) {
            std::cout << f->elementos[i].key << std::endl;
            i = (i+1) % MAX_FILA;
        }
    }
}
int tamanhoFila(FILA *f) {
    return f->nroElem;
}
bool inserirElemFila(FILA *f, REGISTRO reg) {
    if (f->nroElem >= MAX_FILA) return false;

    int pos = (f->inicio+f->nroElem) % MAX_FILA;
    f->elementos[pos] = reg;
    f->nroElem++;
    return true;
}
//#endregion Fila

void renderListaSubMenu(LIST *l) {
    std::cout << "1- Inserir na Lista" << std::endl;
    std::cout << "2- Exibir Lista" <<std::endl;
    std::cout << "3- Tamanho Lista" << std::endl;
    std::cout << "4- Retornar" << std::endl;
    std::cout << "Escolha uma opcao: ";

    int opt;
    std::cin >> opt;

    std::cout << std::endl;

    switch (opt) {
        case 1:
            REGISTRO reg;
            std::cout << "Digite uma chave para o registro: ";
            std::cin >> reg.key;
            std::cout<<std::endl;

            if (inserirList(l, reg))
                std::cout << "Elemento inserido com sucesso!" << std::endl;
            else
                std::cout << "Lista cheia." << std::endl;

            Sleep(500);
            system("cls");
            renderListaSubMenu(l);
            break;
        case 2:
            listarList(l);
            std::cout << std::endl;
            system("pause");
            system("cls");
            renderListaSubMenu(l);
            break;
        case 3:
            std::cout << "Tamanho da Lista: " << tamanhoList(l) << std::endl;
            system("pause");
            system("cls");
            renderListaSubMenu(l);
            break;
        default:
            system("cls");
    }
}

//#region Lista
void iniciarLista(LIST *l) {
    l->nroElem =0;
}
void listarList(LIST *l) {
    int i;
    for (i =0;i<l->nroElem;i++){
        std::cout << l->elementos[i].key << std::endl;
    }
}
int tamanhoList(LIST *l) {
    return l->nroElem;
}
bool inserirList(LIST *l, REGISTRO reg) {
    if (l->nroElem >= MAX_LIST) return false;
    l->elementos[l->nroElem] = reg;
    l->nroElem++;
    return true;
}
//#endregion Lista

void renderPilhaSubMenu(PILE *p) {
    std::cout << "1- Inserir na Pilha" << std::endl;
    std::cout << "2- Exibir Pilha" <<std::endl;
    std::cout << "3- Tamanho Pilha" << std::endl;
    std::cout << "4- Retornar" << std::endl;
    std::cout << "Escolha uma opcao: ";

    int opt;
    std::cin >> opt;

    std::cout << std::endl;

    switch (opt) {
        case 1:
            REGISTRO reg;
            std::cout << "Digite uma chave para o registro: ";
            std::cin >> reg.key;
            std::cout<<std::endl;

            if (inserirPilha(p, reg))
                std::cout << "Elemento inserido com sucesso!" << std::endl;
            else
                std::cout << "Pilha cheia." << std::endl;

            Sleep(500);
            system("cls");
            renderPilhaSubMenu(p);
            break;
        case 2:
            listarPilha(p);
            std::cout << std::endl;
            system("pause");
            system("cls");
            renderPilhaSubMenu(p);
            break;
        case 3:
            std::cout << "Tamanho da Pilha: " << tamanhoPilha(p) << std::endl;
            system("pause");
            system("cls");
            renderPilhaSubMenu(p);
            break;
        default:
            system("cls");
    }
}

//#region Pilha
void inicializarPilha(PILE *p) {
    p->topo =-1;
}

void listarPilha(PILE *p) {
    int i;
    for (i = p->topo;i >= 0;i--) {
        std::cout << p->elementos[i].key << std::endl;
    }
}
int tamanhoPilha(PILE *p) {
    return p->topo + 1;
}
bool inserirPilha(PILE *p, REGISTRO reg) {
    if (p->topo == MAX_PILE - 1) return false;
    p->topo++;
    p->elementos[p->topo] = reg;
    return true;
}
//#endregion Pilha