/* Gustavo Michaloski - Yuri Laranja*/

#define FILEIRAS 40
#define POLTRONAS 10
#include <stdio.h>
#include <ctype.h>
int QualFilme()
{
    int Filme;
    while (1)
    {
        printf("Bem Vindo(a) ao Cinema!!\n");
        printf("Filmes em Cartaz 1 (Star Trek), 2 (Star Wars) e 3 (Avengers)\nDigite 0 caso deseje encerrar\n");
        scanf("%d", &Filme);
        if (Filme == 1 || Filme == 2 || Filme == 3)
        {
            printf("Voce escolheu a sala %d!\n", Filme);
            return Filme;
            break;
        }
        else if (Filme == 0)
        {
            printf("Programa encerrado...");
            return Filme;
            break;
        }
        else
        {
            printf("Ops! Sala invalida, digite novamente!\n");
        }
    }
    return Filme;
}

int QuantasCadeiras()
{
    int X, SalasTamanho = FILEIRAS * POLTRONAS, Filme = 0;

    printf("Quantos ingressos voce deseja comprar??\n");
    scanf("%d", &X);
    if (X == 0)
    {
        return Filme;
    }

    if (X > SalasTamanho || X <= 0)
    {
        printf("Quantidade Invalida! Tente Novamente:\n");
        X = QuantasCadeiras();
        return X;
    }
    else
        return X;
}

int MeiaEntrada(int ingresso)
{
    int meia, verifica = 1, carteira, PrimeiroDigito, SegundoDigito, TerceiroDigito, QuartoDigito, DigitoComparada, SomaDigitos, DigitoFinal, DescontosAplicados = 0, PossoUsar = 1;

    while (verifica == 1)
    {
        printf("Quantos ingressos serao meia entrada?\n");
        scanf("%d", &meia);
        //Verificação se o input meia é valido//
        if (meia > ingresso)
        {
            printf("A quantidade de meias entradas e maior que o numero de ingressos, por favor digite novamente\n");
            printf("Digite 0 caso deseje cancelar a meia entrada\n");
        }
        else
        {
            verifica = 0;
        }
    }

    for (int i = 0; i < meia; i++)
    {
        //Armazenando o numero da carteira estudante para não se repetir//
        printf("Por favor digite o numero da carteira de estudante: \nDigite 0 caso deseje cancelar\n");
        scanf("%d", &carteira);
        int CarteirasUsadas[carteira];

        for (int W = 0; W < meia; W++)
        {
            CarteirasUsadas[W] = 0;
        }
        for (int j = 0; j < meia; j++)
        {
            if (carteira == CarteirasUsadas[j])
            {
                PossoUsar = 0;
                break;
            }
            else
                PossoUsar = 1;
        }
        if (carteira == 0)
        {
            printf("Codigo cancelado!\n");
            continue;
        }

        if (carteira >= 10000 && carteira <= 99999)
        {
            //Cálculo da carteira estudante em módulo de 10//
            PrimeiroDigito = carteira / 10000;
            SegundoDigito = (carteira / 1000) - PrimeiroDigito * 10;
            TerceiroDigito = (carteira / 100) - (((PrimeiroDigito * 10) + SegundoDigito) * 10);
            QuartoDigito = (carteira / 10) - ((PrimeiroDigito * 1000) + (SegundoDigito * 100) + (TerceiroDigito * 10));
            DigitoComparada = carteira - ((PrimeiroDigito * 10000) + (SegundoDigito * 1000) + (TerceiroDigito * 100) + QuartoDigito * 10);
            SomaDigitos = QuartoDigito * 2 + TerceiroDigito * 1 + SegundoDigito * 2 + PrimeiroDigito * 1;
            DigitoFinal = 10 - (SomaDigitos % 10);

            if (PossoUsar == 0)
            {
                printf("Opa! Esse codigo ja foi utilizado! Tente outro ou digite 0 para cancelar!\n");
                i--;
                continue;
                // i-- para refazer essa mesma rotação do código
            }
            else if (DigitoFinal == DigitoComparada)
            {
                printf("Desconto aplicado!\n");
                DescontosAplicados++;
                CarteirasUsadas[i] = carteira;
                continue;
            }
            else
            {
                printf("Ops! Esse codigo e invalido! Tente novamente!\n");
                i--;
                continue;
                // i-- para refazer essa mesma rotação do código
            }
        }
    }

    return DescontosAplicados;
}
int ClienteItasil(int Ingressos, int MeiaEntrada)
{
    int X;
    unsigned int Codigo, DescontosAplicados = 0, PossoUsar = 1;

    while (1)
    {

        printf("Quantos ingressos para cliente Itasil?\n");
        scanf("%d", &X);
        unsigned int CodigosUsados[X];
        for (int W = 0; W < X; W++)
        {
            CodigosUsados[W] = 0;
        }
        if ((X > (Ingressos - MeiaEntrada)) || (X < 0))
        {
            printf("Ops! Valor invalido, tente novamente!\n");
        }
        else if (X == 0)
        {
            printf("Considere se tornar um cliente Itasil!\n");
            break;
        }
        else
        {
            for (int i = 0; i < X; i++)
            {
                printf("Digite o seu codigo de cliente Itasil: \n");
                scanf("%d", &Codigo);
                // Esse For é pra verificar se o código já foi usado
                for (int j = 0; j < X; j++)
                {

                    if (Codigo == CodigosUsados[j])
                    {
                        PossoUsar = 0;
                        break;
                    }
                    else
                        PossoUsar = 1;
                }
                if (Codigo == 0)
                {
                    printf("Desconto cancelado!\n");
                    continue;
                }
                //Verificar se codigo ja foi usado
                else if (PossoUsar == 0)
                {
                    printf("Opa! Esse codigo ja foi utilizado! Tente outro ou digite 0 para cancelar!\n");
                    i--;
                    continue;
                    // i-- para refazer essa mesma rotação do código
                }
                else if ((Codigo % 341) == 0)
                {
                    printf("Desconto aplicado!\n");
                    DescontosAplicados++;
                    CodigosUsados[i] = Codigo;
                    continue;
                }
                else
                {
                    printf("Ops! Esse codigo e invalido! Tente novamente!\n");
                    i--;
                    continue;
                    // i-- para refazer essa mesma rotação do código
                }
            }
            break;
        }
    }
    return DescontosAplicados;
}

void DesenharCadeiras(char cadeiras[FILEIRAS][POLTRONAS])
{
    //Imprimir os assentos
    printf("    A   B   C   D   E   F   G   H   I   J \n");
    for (int i = 0; i < FILEIRAS; i++)
    {
        printf("%02d", i);
        for (int j = 0; j < POLTRONAS; j++)
        {
            printf("  %c ", cadeiras[i][j]);
        }
        printf("\n");
    }
}
float ValorTotal(int ingressos, int meias, int Ditasil)
{
    //Calculo do valor a ser pago, aplicando a porcentagem dos descontos
    float TotalSemDesconto, TotalDescontoMeias, TotalDescontoItasil, Total;

    TotalSemDesconto = (ingressos - meias - Ditasil) * 20.00;
    TotalDescontoMeias = meias * 10.00;
    TotalDescontoItasil = Ditasil * 14.00;
    Total = TotalSemDesconto + TotalDescontoMeias + TotalDescontoItasil;
    printf("O Valor total a pagar e R$ %.2f\n", Total);
    printf("Obrigado Pela Preferencia\n");
    return 0;
}
int EscolhaAssento(int Ingressos)
{
    int Fileira, IntPoltrona;
    char cadeiras[FILEIRAS][POLTRONAS], Poltrona;
    for (int i = 0; i < FILEIRAS; i++)
    {
        for (int j = 0; j < POLTRONAS; j++)
        {
            cadeiras[i][j] = '0';
        }
    }
    DesenharCadeiras(cadeiras);
    for (int i = 0; i < Ingressos; i++)
    {
        printf("Escolha o seu assento! Utilize o formato FILEIRA[ESPACO]POLTRONA, ex: '2 E'\n");
        scanf("%d %c", &Fileira, &Poltrona);
        IntPoltrona = tolower(Poltrona) - 'a';
        //transformei o char em int para utilizar no index da matriz;
        if (cadeiras[Fileira][IntPoltrona] == 'X')
        {
            printf("Lugar ocupado! Selecione outro!\n");
            i--;
        }
        cadeiras[Fileira][IntPoltrona] = 'X';
        DesenharCadeiras(cadeiras);
    }
    return 0;
}

int main(void)
{

    while (1)
    {
        int Filme = QualFilme();
        if (Filme == 0)
            break;

        int Ingressos = QuantasCadeiras();
        if (Ingressos == 0)
        {
            printf("Programa encerrado...\n");
            break;
        }
        int Meias = MeiaEntrada(Ingressos);
        int DItasil = ClienteItasil(Ingressos, Meias);
        EscolhaAssento(Ingressos);

        ValorTotal(Ingressos, Meias, DItasil);
    }

    return 0;
}