#include "GerenciadorHistoria.h"
#include <string.h>
#include <cstdlib>
#include <ctime>

GerenciadorHistoria::GerenciadorHistoria(){
    srand(time(NULL));
}

void GerenciadorHistoria::iniciador(){
    int resposta;
    cout << "Bem vindo ao jogo." << endl;
    cout << "O que deseja fazer? (1-Novo Jogo | 2-Carregar Jogo)" << endl;
    cin >> resposta;

    switch (resposta) {
        case 1:
            iniciarJogo();
            break;
        case 2:
            carregarJogo();
            break;
        default:
            cout << "Opcao invalida. Tente novamente." << endl;
            iniciador();
            break;
    }
}

void GerenciadorHistoria::iniciarJogo(){

    cout << "Iniciando novo jogo... \n" << endl;

    cout << "Vamos montar um heroi lendario para voce!\n" << endl;

    bool resposta;
    p = p.constroiHeroi(&resposta);
    p.setProvisoes(5);
    salvador.setPersonagem(&p);

    if(resposta){
        abrirCena("#1");
    }
    else{
        encerrador();
    }
}

void GerenciadorHistoria::carregarJogo(){
    salvador.lerArquivo();
    Personagem* per = salvador.getPersonagem();

    p = *per;

    abrirCena(salvador.getCena(salvador.getQtdeCenas()-1));

}

void GerenciadorHistoria::abrirCena(char* arquivo){
    salvador.adicionaCena(arquivo);
    salvador.escreverSalvamento();

    char arquivoFinal[10];
    strcpy(arquivoFinal, arquivo);
    strcat(arquivoFinal, ".txt");
    if (strchr(arquivoFinal, 'M') != NULL) {
        cm = new CenaMonstro(arquivoFinal, true);
        lerRespostaERetornaCenaMonstro(cm);
    } else if(strchr(arquivoFinal, 'I') != NULL){
        ci = new CenaItem(arquivoFinal, true);
        lerRespostaERetornaCenaItem(ci);
    } else{
        c = new Cena(arquivoFinal, true);
        lerRespostaERetornaCena(c);
    }
}

char* GerenciadorHistoria::lerRespostaERetornaCena(Cena* ce){
    ce->imprimeDescricao();
    ce->imprimeOpcoes();
    cout << "0) Acessar Inventario" << endl;
    cout << "-1) Fechar o jogo\n" << endl;
    cout << "Digite a opcao desejada:" << endl;

    int escolha;
    cin >> escolha;

    if(strcmp(ce->getOpcao(escolha-1), "Encerrar Jogo.")==0){
        encerrador();
    }

    switch(escolha){
        case -1:
            encerrador();
        case 0:
            abrirInventario();
            lerRespostaERetornaCena(ce);
        case 1:
            abrirCena(ce->getProximaCena(0));
        case 2:
            abrirCena(ce->getProximaCena(1));
        case 3:
            abrirCena(ce->getProximaCena(2));
        default:
            cout << "Digite um valor valido\n" << endl;
            lerRespostaERetornaCena(ce);
    }
}

char* GerenciadorHistoria::lerRespostaERetornaCenaMonstro(CenaMonstro* ce){
    ce->imprimeDescricao();
    ce->getMonstro()->imprimeInfo();
    cout << endl;
    ce->imprimeOpcoes();
    cout << "0) Acessar Inventario" << endl;
    cout << "-1) Fechar o jogo\n" << endl;
    cout << "Digite a opcao desejada:" << endl;

    int escolha;
    cin >> escolha;


    if(strcmp(ce->getOpcao(escolha-1), "Lutar")==0){
        batalha(&p, ce->getMonstro());
    }
    switch(escolha){
        case -1:
            encerrador();
        case 0:
            abrirInventario();
            lerRespostaERetornaCenaMonstro(ce);
        case 1:
            abrirCena(ce->getProximaCena(0));
        case 2:
            abrirCena(ce->getProximaCena(1));
        case 3:
            abrirCena(ce->getProximaCena(2));
        default:
            cout << "Digite um valor valido\n" << endl;
            lerRespostaERetornaCena(ce);
    }
}

char* GerenciadorHistoria::lerRespostaERetornaCenaItem(CenaItem* ce){
    ce->imprimeDescricao();
    ce->getItem()->imprimeResumo();
    cout << endl;
    ce->imprimeOpcoes();
    cout << "0) Acessar Inventario" << endl;
    cout << "-1) Fechar o jogo\n" << endl;
    cout << "Digite a opcao desejada:" << endl;

    int escolha;
    cin >> escolha;


    if(strcmp(ce->getOpcao(escolha-1), "Pegar")==0){
        pegarObjeto(ce->getItem());
    }

    switch(escolha){
        case -1:
            encerrador();
        case 0:
            abrirInventario();
            lerRespostaERetornaCenaItem(ce);
        case 1:
            abrirCena(ce->getProximaCena(0));
        case 2:
            abrirCena(ce->getProximaCena(1));
        case 3:
            abrirCena(ce->getProximaCena(2));
        default:
            cout << "Digite um valor valido\n" << endl;
            lerRespostaERetornaCena(ce);
    }
}

void GerenciadorHistoria::encerrador() {
    cout << "\nObrigado por jogar! Volte sempre!" << endl;
    exit(0);
}

int GerenciadorHistoria::sortearValor(){
    int numeroSorteado = (rand() % 10) + 1;

    return numeroSorteado;
}

void GerenciadorHistoria::batalha(Personagem* p, Monstro* m){
    int faHeroi = sortearValor() + p->getHabilidade();
    int faOponente = sortearValor() + m->getHabilidade();

    Item* armas[10];
    Item* armaduras[10];
    int qtdeArmas = 0, qtdeArmaduras = 0;

    separaArmas(armas, p, &qtdeArmas);
    separaArmaduras(armaduras, p, &qtdeArmaduras);

    bool vezHeroi = true;

    while(faHeroi == faOponente){
        faHeroi = sortearValor() + p->getHabilidade();
        faOponente = sortearValor() + m->getHabilidade();
    }

    cout << "\n\n COMBATE INICIADO \n\n" << endl;

    cout << "Seu FA: " << faHeroi << endl;
    cout << "FA do oponente: " << faOponente << endl;

    if(faHeroi > faOponente){
        m->perderEnergia(2);
        vezHeroi = true;
    }
    else {
        p->perderEnergia(2);
        vezHeroi = false;
    }

    while(p->getEnergia() > 0 && m->getEnergia() > 0){
        cout << "Energias atuais:" << endl;
        cout << "Sua: " << p->getEnergia() << " | Oponente: " << m->getEnergia() << "\n" <<endl;

        if(vezHeroi){
            cout << "\n Sua vez: \n" << endl;
            vezHeroi = false;
            Item* arma = escolherAcaoBatalha(p, armas, armaduras, &qtdeArmas, &qtdeArmas);
            if(arma != nullptr){
                atacar(arma, faOponente, p, m);
            }
        }
        else{
            cout << "\n Vez do oponente:\n" << endl;
            vezHeroi = true;
            if(m->getEnergia() < 6 && m->getProvisao() > 1){
                m->consumirProvisao();
                cout << "\n Seu oponente consumiu uma provisao!\n" << endl;
            }
            else{
                sofrerAtaque(faHeroi, m, p, armaduras, qtdeArmaduras);
            }
        }
        cout << "-----------------------------------" << endl;
    }

    cout << "\n FIM DO COMBATE \n" << endl;
    if(m->getEnergia() < 0){
        cout << "\nVoce venceu!\n" << endl;
        abrirCena(m->getVitoria());
    }
    else{
        cout << "\nVoce foi derrotado!\n" << endl;
        abrirCena(m->getDerrota());
    }
}

int GerenciadorHistoria::getDanoReduzido(Item* armaduras[10], int qtde){
    int dano = 0;
    for(int i = 0; i < qtde; i++){
        dano += armaduras[i]->getDano();
    }
    cout << "\n\nDANO REDUZIDO: " << dano << "\n\n" << endl;
    return dano;
}

Item* GerenciadorHistoria::escolherAcaoBatalha(Personagem* p, Item* armas[10], Item* armaduras[10], int* qtdeArmas, int *qtdeArmaduras){
    int resposta = 0;

    cout << "\n O que voce deseja fazer? \n" << endl;
    cout << "1) Consumir provisao (voce possui " << p->getProvisao() << ")" << endl;

    imprimeAtaque(armas, *qtdeArmas);

    cin >> resposta;

    if(resposta > 0 && resposta < *qtdeArmas+2){
        if(resposta == 1){
                if(p->getProvisao() > 0){
                    p->consumirProvisao();
                    cout << "\nProvisao consumido!\n" << endl;
                    return nullptr;
                } else{
                    cout << "Voce nao tenho provisoes disponiveis. \n" << endl;
                    escolherAcaoBatalha(p, armas, armaduras, qtdeArmas, qtdeArmaduras);
                }
        }
        else{
            return armas[resposta-2];
        }

    }

    else{
        escolherAcaoBatalha(p, armas, armaduras, qtdeArmas, qtdeArmaduras);
    }


}

void GerenciadorHistoria::separaArmas(Item* armas[10], Personagem* p, int* qtde){
    int cont = 0;
    for(int i = 0; i < p->getQtdeItens(); i++){
        if(p->getItem(i)->getTipo() == W){
            armas[cont] = p->getItem(i);
            cont++;
        }
    }
    *qtde = cont;
}

void GerenciadorHistoria::separaArmaduras(Item* armaduras[10], Personagem* p, int* qtde){
    int cont = 0;
    for(int i = 0; i < p->getQtdeItens(); i++){
        if(p->getItem(i)->getTipo() == R){
            armaduras[cont] = p->getItem(i);
            cont++;
        }
    }
    *qtde = cont;
}

void GerenciadorHistoria::imprimeAtaque(Item* armas[10], int qtde){
    int escolha = 0;
    for(int i = 0; i < qtde; i++){
        cout << i+2 << ") Atacar com " << armas[i]->getNome() << endl;
    }
    cout << "\n" << endl;
}

void GerenciadorHistoria::atacar(Item* arma, int faDefesa, Personagem* ataque, Personagem* defesa){
    int valorDado = sortearValor();
    int dano = arma->getDano();

    cout << "\nValor do dado: " << valorDado << "\n" << endl;
    int golpe = valorDado + ataque->getHabilidade();
    if(golpe >= faDefesa){
        cout << "Acertou o golpe!\n" << endl;
        cout << "Dano total: " << dano << "\n" << endl;
        defesa->perderEnergia(dano);
    }
    else{
        cout << "Errou o golpe!\n" << endl;
    }
}

void GerenciadorHistoria::sofrerAtaque(int faDefesa, Personagem* ataque, Personagem* defesa, Item* armaduras[10], int qtdeArmadura){
    int valorDado = sortearValor();
    int dano = 6 - getDanoReduzido(armaduras, qtdeArmadura);

    if(dano < 0){
        dano = 0;
    }

    cout << "\nValor do dado: " << valorDado << "\n" << endl;
    int golpe = valorDado + ataque->getHabilidade();
    if(golpe >= faDefesa){
        cout << "Acertou o golpe!\n" << endl;
        cout << "Dano total: " << dano << "\n" << endl;
        defesa->perderEnergia(dano);
    }
    else{
        cout << "Errou o golpe!\n" << endl;
    }
}

void GerenciadorHistoria::pegarObjeto(Item* item){
    cout << "\n\nItem recolhido!\n" << endl;
    p.adicionaItem(item);
}

int GerenciadorHistoria::abrirInventario(){
    int decisao = -1, i = -1;

    while(decisao != 0){
        cout << "\n------------------------------\n" << endl;

        cout << "Provisoes: " << p.getProvisao() << "\n" << endl;

        p.imprimeListaItens();

        cout << "\n------------------------------\n" << endl;


        cout << "1) Remover um item do inventario " << endl;
        cout << "2) Detalhar item" << endl;
        cout << "0) Voltar" << endl;

        cin >> decisao;

        if(decisao == 1){
            while(i < 0 || i > p.getQtdeItens()){
                p.imprimeListaItens();

                cout << "Digite o ID do item que deseja remover:\n" << endl;
                cin >> i;

                if(i > 0 && i < p.getQtdeItens()){
                    break;
                }

            }
            p.descartarItem(i-1);
        }
        if(decisao == 2){
            while(i < 0 || i > p.getQtdeItens()){
                p.imprimeListaItens();

                cout << "Digite o ID do item que deseja detalhar:\n" << endl;
                cin >> i;
                if(i > 0 && i < p.getQtdeItens()){
                    break;
                }
            }
            p.getItem(i-1)->imprimeDetalhe();
        }
    }

    return 0;

}
