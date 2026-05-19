#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void remover_quebra_linha(char *str) {
    size_t len = strlen(str);
    while (len > 0 && (str[len - 1] == '\n' || str[len - 1] == '\r')) {
        str[len - 1] = '\0';
        len--;
    }
}

char* trim_esquerdo(char *str) {
    while (isspace((unsigned char)*str)) str++;
    return str;
}

// Limpa os asteriscos do markdown para o LaTeX
void limpar_asteriscos(char *str) {
    char resultado[1024] = "";
    int j = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != '*') {
            resultado[j++] = str[i];
        }
    }
    resultado[j] = '\0';
    strcpy(str, resultado);
}

char* limpar_numeracao_titulo(char *titulo) {
    char *p = titulo;
    while (*p && (isdigit((unsigned char)*p) || *p == '.' || isspace((unsigned char)*p))) {
        p++;
    }
    return (*p == '\0') ? titulo : p;
}

void processar_relatorio(int numero, FILE *saida) {
    char nome_arquivo[40];
    sprintf(nome_arquivo, "s%02d-relatorio.md", numero);
    
    FILE *entrada = fopen(nome_arquivo, "r");
    if (entrada == NULL) {
        return; 
    }

    char data_entrega[100] = "";
    char linha[1024];
    
    // Passo 1: Captura estrita da data de entrega (verifica o início real da linha)
    while (fgets(linha, sizeof(linha), entrada)) {
        char *linha_limpa = trim_esquerdo(linha);
        
        // Verifica se a linha começa exatamente com "Recife" ou "**Recife"
        if (strncmp(linha_limpa, "Recife", 6) == 0 || strncmp(linha_limpa, "**Recife", 8) == 0) {
            strcpy(data_entrega, linha_limpa);
            remover_quebra_linha(data_entrega);
            limpar_asteriscos(data_entrega);
            break; 
        }
    }
    
    rewind(entrada);

    fprintf(saida, "\n\\section{Relatório Semanal %02d}\n", numero);
    
    if (strlen(data_entrega) > 0) {
        fprintf(saida, "{\\centering\\noindent\\textit{Data de Entrega: %s}\\par}\\bigskip\n", trim_esquerdo(data_entrega));
    }

    int extraindo = 0;
    int em_lista = 0;

    // Passo 2: Processamento do conteúdo técnico
    while (fgets(linha, sizeof(linha), entrada)) {
        char *linha_limpa = trim_esquerdo(linha);
        remover_quebra_linha(linha_limpa);

        // Se reaparecer o cabeçalho institucional repetido do s01, encerra o arquivo
        if (extraindo && strstr(linha_limpa, "Universidade de Pernambuco") != NULL) {
            break;
        }

        if (!extraindo && (strstr(linha_limpa, "Objetivo") != NULL)) {
            extraindo = 1;
        }

        if (extraindo) {
            if (strcmp(linha_limpa, "---") == 0 || strcmp(linha_limpa, "") == 0) {
                continue;
            }

            if (strncmp(linha_limpa, "## ", 3) == 0) {
                if (em_lista) { fprintf(saida, "\\end{itemize}\n"); em_lista = 0; }
                char *titulo_limpo = limpar_numeracao_titulo(linha_limpa + 3);
                fprintf(saida, "\n\\subsection{%s}\n", titulo_limpo);
            }
            else if (isdigit(linha_limpa[0]) && strstr(linha_limpa, ". ") != NULL && !em_lista) {
                if (em_lista) { fprintf(saida, "\\end{itemize}\n"); em_lista = 0; }
                char *titulo_limpo = limpar_numeracao_titulo(linha_limpa);
                fprintf(saida, "\n\\subsection{%s}\n", titulo_limpo);
            }
            else if (strncmp(linha_limpa, "- ", 2) == 0 || strncmp(linha_limpa, "* ", 2) == 0) {
                if (!em_lista) {
                    fprintf(saida, "\\begin{itemize}\n");
                    em_lista = 1;
                }
                fprintf(saida, "    \\item %s\n", linha_limpa + 2);
            }
            else {
                if (em_lista) { fprintf(saida, "\\end{itemize}\n"); em_lista = 0; }
                fprintf(saida, "%s\n", linha_limpa);
            }
        }
    }

    if (em_lista) {
        fprintf(saida, "\\end{itemize}\n");
    }

    fprintf(saida, "\n\\bigskip\n\\hrule\n\\bigskip\n");
    fclose(entrada);
}

int main(void) {
    FILE *saida = fopen("conteudo_relatorios.tex", "w");
    if (saida == NULL) {
        printf("Erro ao criar arquivo de saída.\n");
        return 1;
    }

    for (int i = 1; i <= 15; i++) {
        processar_relatorio(i, saida);
    }

    fclose(saida);
    printf("Sucesso! O arquivo 'conteudo_relatorios.tex' foi corrigido com as datas dinâmicas independentes.\n");
    return 0;
}