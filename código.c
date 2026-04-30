#include <stdio.h>

//Função para converter a porcentagem da bateria em kwh
float conversao_para_kwh(float bateria_inicial, float capacidade_bateria) {

    return (bateria_inicial / 100) * capacidade_bateria;

}

int main() {

    //Variáveis
    float bateria_inicial;
    float bateria_final;
    float total_pagar;
    float energia_necessaria;
    float capacidade_bateria;
    float temp_recarga;

    //Menu
    printf("=================================\n");
    printf("        Estacao De Recarga\n");
    printf("Conecte O Carregador Ao Seu Carro\n");
    printf("=================================\n");
    printf("Digite a capacidade da bateria do seu carro: ");
    scanf("%f", &capacidade_bateria);
    printf("Digite a porcentagem da bateria do seu carro: ");
    scanf("%f", &bateria_inicial);

    //Verificando se o valor da portcentagem da bateria é válido
    if (bateria_inicial < 0 ||  bateria_inicial > 100)
    {
        printf("Valor Invalido!");
        return 0;
    }

    //Tempo de recarga estimado, Potência do carregador: 75kW  
    temp_recarga = capacidade_bateria / 75;


    //Cálculo do total de energia consumida
    energia_necessaria = capacidade_bateria - conversao_para_kwh(bateria_inicial, capacidade_bateria);

    //Cálculo da cobrança do carregamento, preço médio do Kwh em SP é R$0,80
    total_pagar = energia_necessaria * 0.8;
    
    //Carregamento da bateria
    bateria_final = bateria_inicial;
    while (bateria_final <100)
    {
        bateria_final ++;
    }

    //Formatação da saída e registros da sessão de recarga
    printf("=============================================\n");
    printf("             Relatorio Da Sessao\n");
    printf("Carga inicial da bateria: %.2f%%\n", bateria_inicial);
    printf("Carga atual da bateria: %.0f%%\n", bateria_final);
    printf("Carga adicionada: %.2f kwh\n", energia_necessaria);
    printf("Preco da recarga: R$%.2f\n", total_pagar);
    printf("Tempo de recarga estimado: %.0f min\n", temp_recarga);
    printf("=============================================");
    
    return 0;
}
