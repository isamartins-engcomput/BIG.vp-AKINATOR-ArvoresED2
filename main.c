#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "raylib.h"

// --- PALETA DE CORES EXTRAÍDA DA IMAGEM ---
#define PALETTE_BG      (Color){ 247, 247, 247, 255 } 
#define PALETTE_BLUE    (Color){ 78, 111, 241, 255 }  
#define PALETTE_LIGHTB  (Color){ 142, 212, 235, 255 } 
#define PALETTE_RED     (Color){ 237, 28, 36, 255 }   
#define PALETTE_DARKRED (Color){ 144, 12, 39, 255 }   
#define PALETTE_YELLOW  (Color){ 251, 192, 14, 255 }  

// --- ESTRUTURA DO BACKEND ---
typedef struct No
{
    char eh_personagem; 
    struct No * sim;
    struct No * nao;
    char conteudo[51]; 
} No;

int testa_no(struct No * no)
{
    if(no == NULL) return 0;
    return 1;
}

void preenche_arvore(struct No ** raiz,  char pergunta[][51], int pergunta_atual, int total_perguntas)
{  
    if(pergunta_atual < total_perguntas)
    { 
        *raiz = malloc(sizeof(No));
        if(!testa_no(*raiz)) { printf("Deu gangrena :D\n"); return; }

        (*raiz)->eh_personagem = 'N'; 
        strcpy((*raiz)->conteudo, pergunta[pergunta_atual]);
        (*raiz)->sim = NULL;
        (*raiz)->nao = NULL;
        
        preenche_arvore(&(*raiz)->sim, pergunta, pergunta_atual+1, total_perguntas);
        preenche_arvore(&(*raiz)->nao, pergunta, pergunta_atual+1, total_perguntas);
    }
    else
    {
        *raiz = malloc(sizeof(No));
        if(!testa_no(*raiz)) { printf("Deu gangrena :D\n"); return; }
        (*raiz)->eh_personagem = 'S';
        strcpy((*raiz)->conteudo, "Ninguém (Banco Vazio)"); 
        (*raiz)->sim = NULL;
        (*raiz)->nao = NULL;
    }
}

void processa_linha(struct No ** raiz, char * linha)
{
    char *token = strtok(linha, ",");
    struct No * atual = *raiz;
    char nome[51];
    nome[0] = '\0';

    while(token != NULL)
    {
        if(strlen(token) == 1 && (token[0] == 'S' || token[0] == 'N' || token[0] == 's' || token[0] == 'n'))
        {
            if(atual == NULL) break;
            if(token[0] == 'S' || token[0] == 's') atual = atual->sim;
            else atual = atual->nao;
        }
        else
        {
            if(strlen(token) > 2) strcpy(nome, token);
        }
        token = strtok(NULL, ",");
    }
    if(atual != NULL && atual->eh_personagem == 'S' && nome[0] != '\0') 
    {
        strcpy(atual->conteudo, nome);
    }
}

void preenche_folhas(struct No ** raiz)
{
    FILE * filmes_e_series;
    char filename[] = "filmes_e_series.txt"; 
    filmes_e_series = fopen(filename, "r");
    
    if(filmes_e_series == NULL)
    {
        filmes_e_series = fopen(filename, "w");
        // ATENÇÃO AQUI: Agora são 6 vírgulas (6 respostas) antes do nome do filme!
        fprintf(filmes_e_series, "S,N,N,N,N,N,Interestelar\n"); 
        fprintf(filmes_e_series, "S,S,N,S,S,N,Scott Pilgrim contra o Mundo\n");        
        fprintf(filmes_e_series, "S,S,S,N,N,N,Tropa de Elite\n");    
        fprintf(filmes_e_series, "N,N,S,S,S,N,Todas as Flores\n");  
        fprintf(filmes_e_series, "S,N,S,S,S,N,Lisbela e o Prisioneiro\n"); 
        fprintf(filmes_e_series, "S,S,N,S,N,S,Homem-Aranha no Aranhaverso\n"); // Exemplo respondendo SIM para animação
        fclose(filmes_e_series);
        filmes_e_series = fopen(filename, "r"); 
    }

    if(filmes_e_series != NULL)
    {
        char linha[256];
        while(fgets(linha,sizeof(linha),filmes_e_series) != NULL)
        {
            linha[strcspn(linha, "\n")] = 0; 
            processa_linha(raiz, linha);
        }
        fclose(filmes_e_series); 
    }
}

void libera_arvore(No * no)
{
    if (no == NULL) return;
    libera_arvore(no->sim);
    libera_arvore(no->nao);
    free(no);
}

// --- FRONTEND (RAYLIB) ---
bool DrawButton(Rectangle rec, const char *text, int fontSize, Color color, Color textColor)
{
    Vector2 mousePoint = GetMousePosition();
    bool clicked = false;
    Color currentBtnColor = color;

    if (CheckCollisionPointRec(mousePoint, rec))
    {
        currentBtnColor = ColorBrightness(color, -0.15f); 
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) clicked = true;
    }

    DrawRectangleRounded((Rectangle){ rec.x + 4, rec.y + 4, rec.width, rec.height }, 0.2f, 8, Fade(PALETTE_DARKRED, 0.2f));
    DrawRectangleRounded(rec, 0.2f, 8, currentBtnColor);
    DrawRectangleRoundedLines(rec, 0.2f, 8, textColor); 

    int textWidth = MeasureText(text, fontSize);
    DrawText(text, rec.x + (rec.width/2 - textWidth/2), rec.y + (rec.height/2 - fontSize/2), fontSize, textColor);

    return clicked;
}

int main(void)
{ 
    const int screenWidth = 800;
    const int screenHeight = 700;
    
    InitWindow(screenWidth, screenHeight, "MORPHEUS");
    SetTargetFPS(60);

    // Array aumentado para tamanho 6 e aspas corrigidas na nova pergunta
    char perguntas[6][51] = {"É um filme?", "Tem ação?", "É nacional?", "O tom é leve?", "Tem romance?", "É animação?"};
    int total_perguntas = 6;
    struct No *raiz = NULL;
    preenche_arvore(&raiz, perguntas, 0, total_perguntas);
    preenche_folhas(&raiz); 

    // Textura principal
    Texture2D textura_morpheus = LoadTexture("begin_end.png");
    
    // Array aumentado para armazenar as 6 imagens (0 a 5)
    Texture2D texturas_perguntas[6];
    texturas_perguntas[0] = LoadTexture("pergunta1.png");
    texturas_perguntas[1] = LoadTexture("pergunta2.png");
    texturas_perguntas[2] = LoadTexture("pergunta3.png");
    texturas_perguntas[3] = LoadTexture("pergunta4.png");
    texturas_perguntas[4] = LoadTexture("pergunta5.png");
    texturas_perguntas[5] = LoadTexture("pergunta6.png"); // Nova imagem
 
    No *noAtual = raiz;
    int pergunta_contador = 0;
    bool fim_de_jogo = false;
    bool tela_inicial = true;

    float escala = 0.25f;

    while (!WindowShouldClose())
    {
        if (tela_inicial)
        {
            Rectangle recJogar = { screenWidth/2 - 125, 580, 250, 60 };
            if (DrawButton(recJogar, "Jogar", 24, PALETTE_YELLOW, PALETTE_DARKRED)) tela_inicial = false;
        }
        else if (fim_de_jogo)
        {
            Rectangle recRestart = { screenWidth/2 - 125, 580, 250, 60 };
            if (DrawButton(recRestart, "Jogar Novamente", 24, PALETTE_YELLOW, PALETTE_DARKRED)) 
            {
                noAtual = raiz;
                pergunta_contador = 0;
                fim_de_jogo = false;
                tela_inicial = true;
            }
        }
        else if (noAtual->eh_personagem == 'N') 
        {
            Rectangle recSim = { screenWidth/2 - 200, 560, 150, 70 };
            Rectangle recNao = { screenWidth/2 + 50, 560, 150, 70 };

            if (DrawButton(recSim, "SIM", 32, PALETTE_BLUE, PALETTE_BG)) 
            {
                noAtual = noAtual->sim;
                pergunta_contador++;
            }
            else if (DrawButton(recNao, "NÃO", 32, PALETTE_RED, PALETTE_BG)) 
            {
                noAtual = noAtual->nao;
                pergunta_contador++;
            }
        }
        else 
        {
            fim_de_jogo = true;
        }

        BeginDrawing();
        ClearBackground(BLACK);

        if (tela_inicial)
        {
            int textY = 120;
            DrawText("Olá, eu sou MORPHEUS!", screenWidth/2 - MeasureText("Olá, eu sou MORPHEUS!", 34)/2, textY, 34, PALETTE_BLUE);
            const char* subtexto = "Pense em um filme ou uma série e eu irei tentar adivinhar qual é.";
            DrawText(subtexto, screenWidth/2 - MeasureText(subtexto, 20)/2, textY + 60, 20, WHITE);

            if (textura_morpheus.id > 0) {
                float imgLargura = textura_morpheus.width * escala;
                Vector2 pos = { (screenWidth / 2.0f) - (imgLargura / 2.0f), 220.0f };
                DrawTextureEx(textura_morpheus, pos, 0.0f, escala, WHITE);
            }

            DrawButton((Rectangle){ screenWidth/2 - 125, 580, 250, 60 }, "Jogar", 24, PALETTE_YELLOW, PALETTE_DARKRED);
        }
        else
        {
            float progress = fim_de_jogo ? 1.0f : (float)pergunta_contador / total_perguntas;
            DrawRectangle(0, 0, (int)(screenWidth * progress), 12, PALETTE_YELLOW); 

            int textY = 120;
            int fontSizeTitle = 22;
            int fontSizeContent = 34;

            if (fim_de_jogo)
            {
                DrawText("MORPHEUS determinou...", screenWidth/2 - MeasureText("MORPHEUS determinou...", fontSizeTitle)/2, textY, fontSizeTitle, WHITE);
                int nameWidth = MeasureText(noAtual->conteudo, fontSizeContent);
                int nameX = screenWidth/2 - nameWidth/2;
                DrawText(noAtual->conteudo, nameX, textY + 40, fontSizeContent, PALETTE_BLUE);
                
                if (textura_morpheus.id > 0) {
                    float imgLargura = textura_morpheus.width * escala;
                    Vector2 pos = { (screenWidth / 2.0f) - (imgLargura / 2.0f), 220.0f };
                    DrawTextureEx(textura_morpheus, pos, 0.0f, escala, WHITE);
                }

                DrawButton((Rectangle){ screenWidth/2 - 125, 580, 250, 60 }, "Jogar Novamente", 24, PALETTE_YELLOW, PALETTE_DARKRED);
            }
            else if (noAtual->eh_personagem == 'N')
            {
                char titleBuf[32];
                sprintf(titleBuf, "Pergunta %d de %d:", pergunta_contador+1, total_perguntas);
                DrawText(titleBuf, screenWidth/2 - MeasureText(titleBuf, fontSizeTitle)/2, 60, fontSizeTitle, Fade(WHITE, 0.7f));
                int qWidth = MeasureText(noAtual->conteudo, fontSizeContent);
                DrawText(noAtual->conteudo, screenWidth/2 - qWidth/2, textY, fontSizeContent, WHITE);
                
                // Puxa a imagem correta baseada no número da pergunta atual
                Texture2D textura_atual = texturas_perguntas[pergunta_contador];
                if (textura_atual.id > 0) {
                    float imgLargura = textura_atual.width * escala;
                    Vector2 pos = { (screenWidth / 2.0f) - (imgLargura / 2.0f), 220.0f };
                    DrawTextureEx(textura_atual, pos, 0.0f, escala, WHITE);
                }
                
                DrawButton((Rectangle){ screenWidth/2 - 200, 560, 150, 70 }, "SIM", 32, PALETTE_BLUE, PALETTE_BG);
                DrawButton((Rectangle){ screenWidth/2 + 50, 560, 150, 70 }, "NÃO", 32, PALETTE_RED, PALETTE_BG);
            }
        }

        EndDrawing();
    }

    UnloadTexture(textura_morpheus);
    // Loop ajustado para limpar as 6 imagens da memória
    for (int i = 0; i < 6; i++) 
    {
        UnloadTexture(texturas_perguntas[i]);
    }
    
    libera_arvore(raiz); 
    CloseWindow();

    return 0;
}
