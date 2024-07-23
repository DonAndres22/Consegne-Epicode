#include <stdio.h>

// Funzione per calcolare l'ALE
float calculate_ale(float value, float exposure_factor, float aro) {
    float sle = value * exposure_factor;
    float ale = sle * aro;
    return ale;
}

int main() {
    // Definire i dati relativi agli eventi
    char* eventNames[3] = {"Terremoto", "Incendio", "Inondazione"};
    float aro[3] = {1.0 / 30, 1.0 / 20, 1.0 / 50};
    float exposureFactorsPrimary[3] = {0.80, 0.60, 0.55};
    float exposureFactorsSecondary[3] = {0.80, 0.50, 0.40};
    float exposureFactorsDatacenter[3] = {0.95, 0.60, 0.35};

    float valuePrimary, valueSecondary, valueDatacenter;

    // Input dei valori degli asset da parte dell'utente
    printf("Inserisci il valore dell'Edificio Primario (€): ");
    scanf("%f", &valuePrimary);
    printf("Inserisci il valore dell'Edificio Secondario (€): ");
    scanf("%f", &valueSecondary);
    printf("Inserisci il valore del Datacenter (€): ");
    scanf("%f", &valueDatacenter);

    // Calcolare e stampare l'ALE per ciascun scenario
    for (int i = 0; i < 3; i++) {
        printf("\n%s:\n", eventNames[i]);
        float alePrimary = calculate_ale(valuePrimary, exposureFactorsPrimary[i], aro[i]);
        float aleSecondary = calculate_ale(valueSecondary, exposureFactorsSecondary[i], aro[i]);
        float aleDatacenter = calculate_ale(valueDatacenter, exposureFactorsDatacenter[i], aro[i]);
        printf(" - Edificio Primario: %.2f €\n", alePrimary);
        printf(" - Edificio Secondario: %.2f €\n", aleSecondary);
        printf(" - Datacenter: %.2f €\n", aleDatacenter);
    }

    return 0;
}
