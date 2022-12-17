/*=========================================== Prática com ALLEGRO =====================================
12. tela.c​: DESAFIO PARA OS FORTES (para o TP!): preencher a tela com quatro tipos
de objetos: elipses, retângulos, retângulos com borda redonda, e triângulos. Para isso,
divida a tela em uma matriz (ou grid) nxm, e em cada célula da matriz desenhe um dos objetos 
anteriores. O objeto e a sua cor devem ser escolhidos de forma aleatória.
Depois, permita que o usuário troque objetos de lugar com o mouse. O usuário
pressiona e segura o botão esquerdo do mouse sobre um dado objeto e solta o botão
sobre a posição que gostaria de movê-la. O objeto que está nessa posição deverá
automaticamente ir para a posição inicial do objeto que moveu, ou seja, ocorre uma
troca de posições entre esses dois objetos.
=======================================================================================================*/

#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <stdlib.h>
#include <math.h>


#define SCREEN_W 480
#define SCREEN_H 640
#define FPS 60



void draw_scenario(ALLEGRO_DISPLAY *display) {
	
	ALLEGRO_COLOR BKG_COLOR = al_map_rgb(0,0,0); 
	al_set_target_bitmap(al_get_backbuffer(display));
	al_clear_to_color(BKG_COLOR);   
	
}

void draw_ellipse(float x, float y) {
	ALLEGRO_COLOR cor = al_map_rgb(255, 255, 0);
	al_draw_filled_ellipse(x, y, 20, 30, cor);
}

void draw_rectangle(float x, float y) {
	ALLEGRO_COLOR cor = al_map_rgb(255, 0, 255);
	al_draw_filled_rectangle(x-25, y-25, x+25, y+25, cor);
}

void draw_rounded_rectangle(float x, float y) {
	ALLEGRO_COLOR cor = al_map_rgb(0, 255, 255);
	al_draw_filled_rounded_rectangle(x-25, y-25, x+25, y+25, 10, 10, cor);
}

void draw_triangle(float x, float y) {
	ALLEGRO_COLOR cor = al_map_rgb(0, 255, 0);
	al_draw_filled_triangle(x, y-50/3, x-25, y+100/3, x+25, y+100/3, cor);
}

int main(int argc, char **argv){

	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;


	//----------------------- rotinas de inicializacao ---------------------------------------
	if(!al_init()) {
		fprintf(stderr, "failed to initialize allegro!\n");
		return -1;
	}

	if(!al_init_primitives_addon()){
		fprintf(stderr, "failed to initialize primitives!\n");
		return -1;
	}

	timer = al_create_timer(1.0 / FPS);
	if(!timer) {
		fprintf(stderr, "failed to create timer!\n");
		return -1;
	}

	display = al_create_display(SCREEN_W, SCREEN_H);
	if(!display) {
		fprintf(stderr, "failed to create display!\n");
		al_destroy_timer(timer);
		return -1;
	}

	if(!al_install_mouse())
		fprintf(stderr, "failed to initialize mouse!\n");   


	event_queue = al_create_event_queue();
	if(!event_queue) {
		fprintf(stderr, "failed to create event_queue!\n");
		al_destroy_display(display);
		al_destroy_timer(timer);
		return -1;
	}
	al_install_keyboard();
   //registra na fila de eventos que eu quero identificar quando a tela foi alterada
	al_register_event_source(event_queue, al_get_display_event_source(display));
   //registra na fila de eventos que eu quero identificar quando o tempo alterou de t para t+1
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	//registra o teclado na fila de eventos:
	al_register_event_source(event_queue, al_get_keyboard_event_source());   
	//registra mouse na fila de eventos:
	al_register_event_source(event_queue, al_get_mouse_event_source());    
   //inicia o temporizador
	al_start_timer(timer);

	int playing = 1;
	//enquanto playing for verdadeiro, faca:
	while(playing) {
		ALLEGRO_EVENT ev;
	  //espera por um evento e o armazena na variavel de evento ev
		al_wait_for_event(event_queue, &ev);

		if(ev.type == ALLEGRO_EVENT_KEY_DOWN) {
			if(ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
				playing = 0;
			}

		}
		else if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
			printf("\nclicou em (%d, %d)", ev.mouse.x, ev.mouse.y);
		}
		else if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
			printf("\nsoltou em (%d, %d)", ev.mouse.x, ev.mouse.y);
		}		
	    //se o tipo de evento for um evento do temporizador, ou seja, se o tempo passou de t para t+1
		else if(ev.type == ALLEGRO_EVENT_TIMER) {
		    draw_scenario(display);
			// draw_scenario(display);
			draw_ellipse(50,50);
			draw_rectangle(100,100);
			draw_rounded_rectangle(150,150);
			draw_triangle(200,200);
			// al_flip_display();
			al_flip_display();
		}
	    //se o tipo de evento for o fechamento da tela (clique no x da janela)
		else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			playing = 0;
		}

	} 

	al_rest(1);

	al_destroy_timer(timer);
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);

	return 0;
}