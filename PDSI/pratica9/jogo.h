
typedef struct Guerreiro {
    int id_guerreiro;
    int pontos_vida;
    int ataque;
    int defesa;
    int carisma;
} Guerreiro;

int rolaDado();
int rolaDados();
void criaGuerreiro (Guerreiro *g);
int bonusCarisma (int carisma);
void ataca(Guerreiro *g1, Guerreiro *g2);