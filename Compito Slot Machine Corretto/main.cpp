#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    unsigned int crediti;
    unsigned int menu;
    bool uscita;
    int numero_casuale1, numero_casuale2, numero_casuale3;
    srand((unsigned)time(NULL));
    crediti = 0;
    uscita = false;
    do {

        cout << "================================" << endl;
        cout << "MENU delle opzioni:" << endl;
        cout << "================================" << endl;
        cout << "Premi 1 per giocare " << endl;
        cout << "Premi 2 per caricare 100 crediti " << endl;
        cout << "Premi 0 per uscire " << endl;
        cout << "================================" << endl;
        cout << "Crediti residui " << crediti << endl;
        cout << "================================" << endl;

        cin >> menu;

        switch (menu)
        {
            case 1:
                if (crediti > 0)
                    {
                        crediti = crediti - 5;
                        numero_casuale1 = rand();
                        numero_casuale1 = numero_casuale1 % 10 +1;
                        numero_casuale2 = rand();
                        numero_casuale2 = numero_casuale2 % 10 +1;
                        numero_casuale3 = rand();
                        numero_casuale3 = numero_casuale3 % 10 +1;
                        cout << "I tre numeri sono: "<<numero_casuale1;
                        cout <<"," <<numero_casuale2 <<","<<numero_casuale3<<endl;
                        if (numero_casuale1==numero_casuale2)
                        {
                            if(numero_casuale2==numero_casuale3)
                            {
                                crediti=crediti+100;
                            }
                            else
                            {
                                crediti=crediti+50;
                            }
                        }
                        else
                        {
                          if (numero_casuale2==numero_casuale3)
                          {
                              crediti=crediti+50;
                          }
                          else
                          {
                              if (numero_casuale1==numero_casuale3)
                              {
                                 crediti=crediti+50;
                              }
                              else
                              {
                                  crediti=crediti+0;
                              }
                          }
                        }
                    }
                else
                        {
                            cout << endl << endl;
                            cout << "Non hai abbastanza crediti per giocare "<<endl;
                            cout << endl << endl;
                        }
                break;
            case 2:
                crediti = crediti + 100;
                break;
            case 0:
                uscita = true;
                break;
            default:
                cout << endl << endl;
                cout << "Non ho capito cosa devo fare, RIPROVA "<<endl;
                cout << endl << endl;


        }


    }  while (uscita == false);


    cout << endl << endl;
    cout << "Hai totalizato "<< crediti << " Euro " << endl;
    cout << endl << endl;
    cout << "Grazie per aver giocato con noi, a presto. "<<endl;
    cout << "(C) Giochi Semplici Ltd 2015"<<endl;

    return 0;
}

