#include <cstdlib>
#include <iostream>

using namespace std;

class elevador {
    public:
        elevador();
            elevador(int, int);
            int set_inicializa(int, int);
            int get_entrar();
            int set_entrar(int);
            int get_sair();
            int set_sair(int);
            int get_subir();
            int set_subir(int);
            int get_descer();
            int set_descer(int);

    private:
        int capacidade;
        int capacidade_total;
        int total_andares;
        int andar_atual;
};

//declaração das variáveis
elevador::elevador(int c, int a)
{
    capacidade = c;
    andar_atual = a;
}

//seta as variáveis com a capacidade e número de andares informados pelo usuários
int elevador::set_inicializa(int c,int a)
{
    capacidade_total = c;
    capacidade = c; 
    total_andares = a;
    andar_atual = a;
    
    return 0;
}


int elevador::get_entrar()
{
    return capacidade;
}

//entra: para acrescentar uma pessoa no elevador (só deve acrescentar se ainda houver espaço);
int elevador::set_entrar(int c)
{
    if(capacidade > 0)
    {
    capacidade = capacidade -1;
    
        cout << endl;
        cout << "No momento a ocupação do elevador é de..: " << capacidade_total - capacidade << " pessoas." << endl;
        cout << "A capacidade máxima para a ocupação é de: " << capacidade_total << " pessoas." << endl;
        cout << "O elevador está no " << total_andares - andar_atual << "º andar." << endl;
        cout << endl;
    } 
    else 
    {
        cout << endl;
        cout << " * * * * * ALERTA * * * * * " << endl;
        cout << "Capacidade do elevador excedida, por favor aguarde o próximo." << endl;
        cout << endl;
    } 

    return capacidade;
}

int elevador::get_sair()
{
    return capacidade;
}

//sai: para remover uma pessoa do elevador (só deve remover se houver alguém dentro dele);
int elevador::set_sair(int c)
{
    if(capacidade < capacidade_total)
    {
        capacidade = capacidade +1;

        cout << endl;
        cout << "No momento a ocupação do elevador é de..: " << capacidade_total - capacidade << " pessoas." << endl;
        cout << "A capacidade máxima para a ocupação é de: " << capacidade_total << " pessoas." << endl;
        cout << "O elevador está no " << total_andares - andar_atual << "º andar." << endl;
    } 
    else 
    {
        cout << endl;
        cout << " * * * * * ATENÇÃO * * * * * " << endl;
        cout << "O elevador está vazio. " << endl;
        cout << endl;
    }

    return capacidade;
}

int elevador::get_subir()
{
    return andar_atual;
}

//sobe: para subir um andar (não deve subir se já estiver no último andar);
int elevador::set_subir(int a)
{
    if(andar_atual > 0)
    {
        andar_atual = andar_atual - 1;

        cout << endl;
        cout << "No momento a ocupação do elevador é de..: " << capacidade_total - capacidade << " pessoas." << endl;
        cout << "A capacidade máxima para a ocupação é de: " << capacidade_total << " pessoas." << endl;
        cout << "O elevador está no " << total_andares - andar_atual << "º andar." << endl;
        cout << endl;
    } 
    else 
    {
        cout << endl;
        cout << "* * * * * ATENÇÃO * * * * * " << endl;
        cout << "O elevador chegou ao último andar, por favor selecione a opção descer." << endl;
        cout << endl;
    }  
        return andar_atual;
}

int elevador::get_descer()
{
    return andar_atual;
}

//desce: para descer um andar (não deve descer se já estiver no térreo);
int elevador::set_descer(int a)
{
    if(andar_atual < total_andares)
    {
        andar_atual = andar_atual + 1;

        cout << endl;
        cout << "No momento a ocupação do elevador é de..: " << capacidade_total - capacidade << " pessoas." << endl;
        cout << "A capacidade máxima para a ocupação é de: " << capacidade_total << " pessoas." << endl;
        cout << "O elevador está no " << total_andares - andar_atual << "º andar." << endl;
        cout << endl;
    } 
    else 
    {
        cout << endl;
        cout << " * * * * * ATENÇÃO ***** " << endl;
        cout << "O elevador está no térreo, por favor selecione a opção subir." << endl;
        cout << endl;
    }   
        return andar_atual;
}


int main()
{
    //declaração das variáveis
    int opc, c, a;

    //inicializa o elevador (número de andares e capacidade zerados)
    elevador e (0, 0);

    cout << "Informa a capacidade total do elevador: " << endl;
    cin >> c;
    cout << "Informe a quantidade de andares que o edifício possui: " << endl;
    cin >> a;
    e.set_inicializa(c, a);
    cout << endl;
    cout << endl;
    
    
    while (opc != 5)
    {
        cout << "***** ELEVADORES UP-DOWN ******" << endl;
        cout << endl;
        cout << "Para operar o elevador escolha uma das opções abaixo: " << endl;
        cout << "1 - Entrar no elevador " << endl;
        cout << "2 - Sair do elevador " << endl;
        cout << "3 - Subir " << endl;
        cout << "4 - Descer " << endl;
        cout << "5 - Sair " << endl;
        cin >> opc;
        cout << endl;
            
        switch(opc)
        {
            case 1:
                e.set_entrar(c);
                break;
            case 2:
                e.set_sair(c);
                break;
            case 3: 
                e.set_subir(a);
                break;
            case 4:
                e.set_descer(a);
                break;
            case 5:
                exit;
                break;
            default:
                cout << "Escolha uma opção válida" << endl;
                cout << endl;
                break;
        }
    }    
    return 0;
}
