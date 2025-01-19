#pragma once

typedef int fat_t;

typedef struct Pilha_t *PilhaPtr;

PilhaPtr criaPilha();

void terminaPilha(PilhaPtr p);

int push(PilhaPtr p, fat_t numero);

int pop(PilhaPtr p, fat_t *numero);

fat_t calculaFat(int num);

void imprimirPilha(PilhaPtr p);