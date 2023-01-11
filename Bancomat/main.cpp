#include <iostream>

using namespace std;



string  cc_nome[8]    = {"Mario","Giovanni","Marco","Paolo","Luigi","","",""};
string  cc_cognome[8] = {"Rossi","Verdi","Bianchi","Neri","Gialli","","",""};
int     cc_saldo[8]   = {100,0,-1000,-200,2200,0,0,0};
int     cc_pin[8]     = {1111,2222,1234,3333,9999,0,0,0};
int     current_user  = -1;
int     correntisti   = 5;
bool    cc_aperti[8]     ={true,true,true,true,true,false,false,false};


void login()
{
    int conto;
    int pin;
    if (current_user==-1)
    {

        cout << "Inserisci il tuo numero di conto"<<endl;
        cin >> conto;
        if (cc_aperti[conto]==true)
        {cout << "Inserisci il tuo numero PIN" << endl;
        cin >> pin;

        if (cc_pin[conto]==pin)
        {
            current_user = conto;
        }
        else cout << "PIN errato !" << endl;
        }
        cout<<"Questo conto corrente e' stato chiuso oppure non è esistente"<<endl;
    } else cout << "Hai gia' effettuato il login " << cc_nome[current_user] << endl;

    cout << endl << endl;
}
void logout ()
{
if (current_user==-1)
    cout << "Per fare il logout devi prima effettuare il login"<<endl;
else
{
current_user=-1;
cout <<"Logout eseguito" <<endl;
}
cout << endl << endl;
}


void preleva(int n)
{

    if (current_user!=-1)
    {
        if(cc_saldo[current_user]>=n)
    {
        cc_saldo[current_user]=cc_saldo[current_user]-n;
        cout << "Hai prelevato "<< n << " euro. Ora il tuo saldo ammonta a " << cc_saldo[current_user];
    }
    else
        cout <<"Non hai abbastanza denaro sul conto per prelevare questa cifra";
    }
    else
        cout<<"Per prelevare devi prima effettuare il login"<<endl;
    cout << endl << endl;
}

void versa(int n)
{
        if (current_user!=-1)
    {
        cc_saldo[current_user]=cc_saldo[current_user]+n;
        cout << "Hai versato "<< n << " euro. Ora il tuo saldo ammonta a " << cc_saldo[current_user];
    }
    else
        cout<<"Per versare devi prima effettuare il login"<<endl;
    cout << endl << endl;

}

void stima()
{   int i,massimo,minimo,somma;
    float media;

    for (i=0; i<=correntisti-1; i++)
    {
        somma=somma+cc_saldo[i];
         media= somma /(i+1);
    }

    minimo = cc_saldo[0];
    for (i=1;i<correntisti-1;i++)
        if (cc_saldo[i]<minimo)
            minimo=cc_saldo[i];

     massimo = cc_saldo[0];
    for (i=1;i<correntisti;i++)
        if (cc_saldo[i]>massimo)
            massimo=cc_saldo[i];

    cout << "Nella banca dell'ITIS VOLTA sono presenti "<< correntisti<<" correntisti" <<endl;
    cout << "Il saldo medio dei correntisti e' "<< media << endl;
    cout << "Il capitale totale della banca e' " << somma <<  endl;
    cout << "La giacenza massima su un conto corrente e'" << massimo<<endl;
    cout << "La giacenza minima su un conto corrente e'" << minimo<<endl;
    cout << endl << endl;
}
int aggiungi_cc(string nome, string cognome, int saldo, int pin, int correntisti)
{
    cc_aperti[correntisti]==true;
    cout << endl << endl;
}
void chiudi_cc(int current_user)
{

    cout <<"Ora il tuo conto corrente verrà svuotato dal suo saldo"<<endl;
    preleva(cc_saldo[current_user]);
    cout<<endl;
    cout <<"Addio "<<cc_nome[current_user]<<endl;
    current_user==-1;
    cc_aperti[current_user]=false;

    correntisti=correntisti-1;
    cout << endl << endl;
}
int main()
{
    int n,i;
    do
    {
        cout << "*** VOLTAMAT, il BANCOMAT dell'ITIS A.VOLTA ***"<<endl;
        cout << endl;

        if (current_user == -1)
            cout<<""<<endl;
        else
        {
            cout << "****************************************************************" << endl <<endl;
            cout << "** Benvenuto " << cc_nome[current_user] << " "<< cc_cognome[current_user] <<endl;
            cout << "** Il tuo credito residuo e': " << cc_saldo[current_user] << endl << endl;
            cout << "****************************************************************" << endl;
            cout << endl;
        }



            cout << "Selezionare una voce dal seguente menu:"<<endl;
            cout << endl;
            cout << "Premere 1 per fare LOGIN"              <<endl;
            cout << "Premere 2 per prelevare Euro 5,00"     <<endl;
            cout << "Premere 3 per prelevare Euro 10,00"    <<endl;
            cout << "Premere 4 per prelevare Euro 20,00"    <<endl;
            cout << "Premere 5 per prelevare Euro 50,00"    <<endl;
            cout << "Premere 6 per versare   Euro 100,00"   <<endl;
            cout << "Premere 7 per stimare il capitale della sua banca"   <<endl;
            cout << "Premere 8 per fare LOGOUT"             <<endl;
            cout << "Premere 9 per aprire un nuovo conto corrente"        <<endl;
            cout << "Premere 10 per chiudere un conto corrente esistente" <<endl;
            cout << "Premere 0 per USCIRE"<<endl;

        cin >> n;

        switch (n)
        {
            case 0:
                cout << "ARRIVEDERCI !! " << endl;
                break;
            case 1:
                login();
                break;
            case 2:
                preleva(5);
                break;
            case 3:
                preleva(10);
                break;
            case 4:
                preleva(20);
                break;
            case 5:
                preleva(50);
                break;
            case 6:
                versa(100);
                break;
            case 7:
                stima();
                break;
            case 8:
                logout();
                break;
            case 9:
                 for (i=0; i<8; i++)
         if (!cc_aperti[i]) break;
             current_user= i;

              correntisti= correntisti+1;

    cout << "Il conto che stai per aprire e' il numero " << i <<endl;
    cout << "Inserire nome intestatario: " <<endl;
    cin >> cc_nome[i];
    cout << "Inserire cognome intestatario: " <<endl;
    cin >> cc_cognome[i];
    cout << "Inserire il saldo iniziale: " <<endl;
    cin >> cc_saldo[i];
    cout << "Inserire il codice pin: " <<endl;
    cin >> cc_pin[i];
    cout << "Grazie per aver aperto un conto corrente nella nostra banca" <<endl;
    cout << "Ora puoi effettuare il login con i tuoi nuovi dati di accesso" <<endl;
    current_user==i;
   aggiungi_cc(cc_nome[correntisti], cc_cognome[correntisti], cc_saldo[correntisti], cc_pin[correntisti],correntisti);
    cout << endl << endl;
                break;
            case 10:
                if (current_user==-1)
                    cout<<"Per chiudere il conto corrente devi prima effettuare il login"<<endl;
                else
              {
                  chiudi_cc( current_user);
              }

            if (n>10)
                cout << "Scusa, non ho capito .." << endl;
                cout << endl <<endl;
        }
    } while (n!=0);

    cout << endl;
    cout << "Grazie per aver usufruito dei nostri servizi. " << endl;
    cout << endl;

    return 0;
}
