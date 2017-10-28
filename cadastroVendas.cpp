#include <iostream>
#include <stdlib.h>

using namespace std;

struct Cliente{
    int cod;
    string nome;
    Cliente *prox;
};

struct Produto{
    int cod;
    string nome;
    int quant;
    float preco;
    Produto *prox;
};

struct Venda{
	int codVenda;
	int quant;
	int codCli;
	string nomeCli;
	int codProd;
	string nomeProd;
	Venda *prox;
	float preco;
	float valorTotal;
};


int main(){

    Cliente *inicio=NULL, *tmp, *valor, *consulta;
    Produto *inicioPro=NULL, *tmpPro, *valorPro, *consultaprod, *consultaquant;
    Venda *inicioV=NULL, *novaVenda, *vendas; 
    int codCli = 1, codProd = 1, codVenda = 1;
    int opcao=0, op=0,teste;


    while (op != 5){
    cout<<"Escolha uma opcao do menu: \n\n";
    cout<<"\n 1 - Cliente";
    cout<<"\n 2 - Produto";
    cout<<"\n 3 - Vender";
    cout<<"\n 4 - Consultar todas as vendas";
    cout<<"\n 5 - Sair do sistema \n\n";

    cin>>op;


     //CLIENTE
    if (op ==1){
      while (opcao != 5){

        cout<<"\n\nEscolha uma opcao do menu: \n\n";
        cout<<"\n 1 - Incluir cliente";
        cout<<"\n 2 - Excluir cliente";
        cout<<"\n 3 - Alterar cliente";
        cout<<"\n 4 - Consultar clientes cadastrados";
        cout<<"\n 5 - Voltar ao menu anterior\n\n";

        cin>>opcao;

        if (opcao == 1){
          cout<<"Incluir Cliente\n\n";
          Cliente *novo;
        novo = new Cliente;

        novo->cod = codCli;
        cout<<"Digite o nome: ";
        cin>>novo->nome;
        tmp = novo;

        tmp->prox = NULL;

        if (inicio == NULL){
            inicio = tmp;
            valor = inicio;
            cout<<"Cliente cadastrado\n\n";
        }
        else {
            valor->prox = tmp;
            valor = tmp;
            cout<<"\nCliente cadastrado\n\n";
             }

             codCli++;

        }
         if (opcao == 2){
          cout<<"Excluir Cliente\n\n";
          Cliente *anterior, *atual;
        if (inicio == NULL){
            cout<<"Nao existem clientes cadastrados\n\n";
        }
        else{
            int num;
            cout<<"Digite o codigo do cliente que deseja excluir: ";
            cin>>num;
            anterior = inicio;
            atual = inicio;

        if(inicio->cod == num){
            atual = atual->prox;
            inicio = atual;
            cout<<"Cliente excluido\n\n";
        } // fim if
        else {
        while (1){
            if (atual->cod == num){
                anterior->prox = atual->prox;
                cout<<"Cliente excluido\n\n";
                break;
            } //fim if
            else {
                anterior = atual;
                atual = atual->prox;
            } //fim else
            if (atual == NULL){
            	cout<<"\nCodigo invalido\n\n";
            	break;
			}

        } //fim while
        } // fim else

    } //fim else
        }
        if (opcao == 3){
          cout<<"Alterar Cliente\n\n";
           Cliente *atual;
        if (inicio == NULL){
            cout<<"Sem clientes cadastrados\n\n";
        }
        else{
            int num;
            cout<<"Digite o codigo do cliente que deseja alterar: ";
            cin>>num;
            atual = inicio;
            if(inicio->cod == num){
                cout<<"Digite o novo nome: ";
                cin>>atual->nome;
                inicio = atual;
                cout<<"Cliente alterado\n\n";
            } // fim if
        else{
        while (1){
            if (atual->cod == num){
                cout<<"Digite o novo nome: ";
                cin>>atual->nome;
                cout<<"Cliente alterado\n\n";
                break;
            } //fim if
            else{
                atual = atual->prox;
            } //fim else
            
            if (atual == NULL){
            	cout<<"\nCodigo invalido\n\n";
            	break;
			}

        } //fim while
        } // fim else

        } //fim else
        }
         if (opcao == 4){
         	
          cout<<"Consultar Clientes cadastrados\n\n";
          consulta = inicio;
          if (inicio == NULL){
            cout<<"Sem clientes cadastrados\n\n";
        }
            while (consulta != NULL) {
                cout<<"\nCodigo: "<<consulta->cod;
                cout<<"\nNome: "<<consulta->nome<<endl;
                consulta = consulta->prox;
            }
        }
        
        if (opcao >=6){
        	cout<<"\nOpcao invalida, escolha a opcao correta";
		}
      } //fim while
      opcao=0;
      op=0;
    } //fim if

      //PRODUTO
    if (op ==2){
        while (opcao != 5){

        cout<<"\n\nEscolha uma opcao do menu: \n\n";
        cout<<"\n 1 - Incluir produto";
        cout<<"\n 2 - Excluir produto";
        cout<<"\n 3 - Alterar produto";
        cout<<"\n 4 - Consultar produtos cadastrados";
        cout<<"\n 5 - Voltar ao menu anterior\n\n";

        cin>>opcao;

        if (opcao == 1){
          cout<<"Incluir Produto\n\n";
          
        Produto *novo;
            novo = new Produto;

            novo->cod = codProd;
            cout<<"Digite o nome do produto: ";
            cin>>novo->nome;
            cout<<"Digite quantidade: ";
            cin>>novo->quant;
            cout<<"Digite preco: ";
            cin>>novo->preco;

            tmpPro = novo;
            tmpPro->prox = NULL;

            if (inicioPro == NULL){
            inicioPro = tmpPro;
            valorPro = inicioPro;
            cout<<"\nProduto cadastrado\n\n";
        }
        else {
            valorPro->prox = tmpPro;
            valorPro = tmpPro;
            cout<<"\nProduto cadastrado\n\n";
             }

             codProd++;
        }
         if (opcao == 2){
          cout<<"Excluir Produto\n\n";
          Produto *anterior, *atual;
        if (inicioPro == NULL){
            cout<<"Nao ha produtos cadastrados\n\n";
        }
        else{
            int num;
            cout<<"Digite o codigo do produto que deseja excluir: ";
            cin>>num;
            anterior = inicioPro;
            atual = inicioPro;

        if(inicioPro->cod == num){
            atual = atual->prox;
            inicioPro = atual;
            cout<<"\nProduto excluido\n\n";
        } // fim if
        else {
        while (1){
            if (atual->cod == num){
                anterior->prox = atual->prox;
                cout<<"\nProduto excluido\n\n";
				break;
            } //fim if
            else {
                anterior = atual;
                atual = atual->prox;
            } //fim else

        } //fim while
        } // fim else

    } //fim else
        }
        if (opcao == 3){
          cout<<"Alterar Produto\n\n";
                  Produto *atual;
        if (inicioPro == NULL){
            cout<<"Nao ha produtos cadastrados\n\n";
        }
        else{
            int num;
            cout<<"Digite o codigo que deseja alterar: ";
            cin>>num;
            atual = inicioPro;
            if(inicioPro->cod == num){
                cout<<"Digite o novo nome: ";
                cin>>atual->nome;
                cout<<"Digite o novo preco: ";
                cin>>atual->preco;
                cout<<"Digite a quantidade: ";
                cin>>atual->quant;
                inicioPro = atual;
                cout<<"\nProduto alterado\n\n";
            } // fim if
        else{
        while (1){
            if (atual->cod == num){
                cout<<"Digite o novo nome: ";
                cin>>atual->nome;
                cout<<"Digite o novo preço: ";
                cin>>atual->preco;
                cout<<"Digite a quantidade: ";
                cin>>atual->quant;
                cout<<"\nProduto alterado\n\n";
                break;
            } //fim if
            else{
                atual = atual->prox;
            } //fim else

        } //fim while
        } // fim else

        } //fim else
        }
         if (opcao == 4){
          cout<<"Consultar Produto\n\n";
			consultaprod = inicioPro;
			if (inicioPro == NULL){
            cout<<"Nao ha produtos cadastrados\n\n";
        }
            while (consultaprod != NULL){
                cout<<"\n\nCodigo: "<<consultaprod->cod;
                cout<<"\nNome: "<<consultaprod->nome;
                cout<<"\nPreco: "<<consultaprod->preco;
                cout<<"\nQuantidade: "<<consultaprod->quant;
                consultaprod = consultaprod->prox;
            }

            consultaprod = inicioPro;
        }
        
        if (opcao >= 6){
        	cout<<"\nOpcao invalida, digite a opcao correta\n\n";
		}
        
      } //fim while
      opcao=0;
      op=0;
    } //fim if
     if (op == 3){
     	int numCli;
     	int numProd;
     	int numQuant;
     	Cliente *consultaCli;
     	Produto *consultaProd;		
        novaVenda = new Venda;
        novaVenda->codVenda = codVenda;
        	while(1){
        	consultaCli = inicio;
			consultaProd = inicioPro;        	
 			if (consultaCli == NULL){
        			cout<<"\nVoce ainda nao realizou cadastro de cliente\n\n";
					break;
				}
			if(consultaProd == NULL){
						cout<<"\nVoce ainda nao realizou cadastro de produto\n\n";
						break;
					}	
		cout<<"Digite o codigo do Cliente: ";
        cin>>numCli;
 		while (1){        		
				if (consultaCli->cod == numCli){
        			novaVenda->codCli = consultaCli->cod;
        			novaVenda->nomeCli = consultaCli->nome;
        			cout<<"Cliente encontrado: "<<consultaCli->nome<<"\n\n";
        			break;
				}
				else{
					if (consultaCli == NULL){
						cout<< "Codigo invalido\n\n";
						break;
					}
					else{
						consultaCli = consultaCli->prox;

					}
				}
			} // fim while de cliente
			
			while (1) {
				    if (consultaCli == NULL){
					break;
				}
				cout<<"\nDigite o codigo do produto: ";
				cin>>numProd;
			while (1){		
				if(consultaProd->cod == numProd){
					novaVenda->codProd = consultaProd->cod;
					novaVenda->nomeProd = consultaProd->nome;
					novaVenda->preco = consultaProd->preco;
					cout<<"\nProduto encontrado: "<<consultaProd->nome<<"\n\n";
					break;
				}
			else{
					if(consultaProd->prox == NULL){
						cout<<"\nCodigo do produto invalido\n\n";
						}
						else{
						consultaProd = consultaProd->prox;
						}
					}
					
				}
			break;
			} // fim while de produto
			// quantidade
				while (1){
				cout<<"Digite a quantidade de produto a ser vendido: ";
				cin>>numQuant;
				if (numQuant <= consultaProd->quant){
					novaVenda->quant = numQuant;
					break;
				}
				else{
					cout<<"Quantidade insuficiente em estoque\n\n";
					cout<<"Deseja cancelar a venda?\n";
					cout<<"1- Confirmar cancelamento: \nOutro numero: alterar quantidade: ";
					int cancelaVenda;
					cin>>cancelaVenda;
					if (cancelaVenda==1){
						cout<<"Venda cancelada";
						break;
					}
				}
				} // fim while quantidade
				
				novaVenda->valorTotal = novaVenda->preco * novaVenda->quant;
				cout<<"Informacoes da Venda: \n"<<"Cliente: "<<novaVenda->nomeCli<<"\n";
				cout<<"Produto: "<<novaVenda->nomeProd<<". Preco: "<<novaVenda->preco<<". Quantidade: "<<novaVenda->quant<<"\nValor total: "<<novaVenda->valorTotal;
				cout<<"\n\nDeseja confirmar a venda?\nDigite 1 para confirmar a venda ou outro numero para cancelar a venda: ";
				int confirmaVenda;
				cin>>confirmaVenda;
				if(confirmaVenda==1){
					if(inicioV == NULL){
						inicioV = novaVenda;
						vendas = novaVenda;
						consultaProd->quant = consultaProd->quant - numQuant;						
						cout<<"Venda concluida!\n\n";
					}
					else{
						vendas->prox = novaVenda;
						vendas = novaVenda;
						consultaProd->quant = consultaProd->quant - numQuant;
						cout<<"Venda concluida!\n\n";						
					}
				}
				else{
					cout<<"Venda cancelada\n\n";
					break;
				}
				
			codVenda++;	
			break;
	  	  } // fim while de vender
   		} // fim if de vender
   		
   		if (op == 4){
   			cout<<"Consultar vendas realizadas\n\n";
   			Venda *consultaVenda;
   			consultaVenda = inicioV;
   			if (inicioV == NULL){
   				cout<<"Voce ainda nao realizou nenhuma venda\n\n";
			   }
			   else{
			   	cout<<"Vendas realizadas: \n\n";
			   }
			   
			   while(consultaVenda != NULL){
			   	cout<<"Codigo da venda: "<<consultaVenda->codVenda<<endl;
			   	cout<<"Nome do cliente: "<<consultaVenda->nomeCli<<endl;
			   	cout<<"Nome do produto: "<<consultaVenda->nomeProd<<". Preco unitario: "<<consultaVenda->preco<<". Quantidade comprada: "<<consultaVenda->quant<<endl;
			   	cout<<"Valor da venda: "<<consultaVenda->valorTotal<<endl;
			   	
			   	consultaVenda = consultaVenda->prox;
			   }
			   
			   op = 0;
			   opcao = 0;
			   
		   } // fim if de consultar vendas
   		
   		if (op >=6){
   			cout<<"\nOpcao invalida, digite a opcao correta\n\n";
		   }
   		
    } //fim while
    return 0;
} //fim main
